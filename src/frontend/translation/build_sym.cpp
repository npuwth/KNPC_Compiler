/*****************************************************
 *  Implementation of the first pass.
 *  This pass will:
 *      1. semantic analysis
 *      2. generate IR (TAC)
 *
 */

#include "SysYBaseVisitor.h"
#include "config.hpp"
#include "scope/scope.hpp"
#include "scope/scope_stack.hpp"
#include "symb/symbol.hpp"
#include "type/type.hpp"
#include "backend/asm/offset_counter.hpp"
#include "backend/asm/arm_md.hpp"
#include "tac/tac.hpp"
#include "tac/trans_helper.hpp"

using namespace knpc;
using namespace knpc::scope;
using namespace knpc::symb;
using namespace knpc::type;
using namespace knpc::err;
using namespace knpc::tac;
using namespace knpc::assembly;

#define POINTER_SIZE 4
#define WORD_SIZE 4

class SemPass1 : public SysYBaseVisitor { // total 48
    virtual antlrcpp::Any visitChildren(antlr4::tree::ParseTree *ctx) override;
    // visit program, 2
    virtual antlrcpp::Any visitProgram(SysYParser::ProgramContext *ctx) override;
    virtual antlrcpp::Any visitCompUnit(SysYParser::CompUnitContext *ctx) override;
    // visit variable declarations, 11
    virtual antlrcpp::Any visitDecl(SysYParser::DeclContext *ctx) override;
    virtual antlrcpp::Any visitConstDecl(SysYParser::ConstDeclContext *ctx) override;
    virtual antlrcpp::Any visitVarDecl(SysYParser::VarDeclContext *ctx) override;
    virtual antlrcpp::Any visitConstDefLi(SysYParser::ConstDefLiContext *ctx) override;
    virtual antlrcpp::Any visitVarDefLi(SysYParser::VarDefLiContext *ctx) override;
    virtual antlrcpp::Any visitConstDef(SysYParser::ConstDefContext *ctx) override;
    virtual antlrcpp::Any visitVarDef(SysYParser::VarDefContext *ctx) override;    
    util::Vector<int> get_array_dims(SysYParser::ConstExpLiContext *ctx);
    util::Vector<int> get_array_dims(SysYParser::ExpLiContext *ctx);
    virtual antlrcpp::Any visitConstInitVal(SysYParser::ConstInitValContext *ctx) override;
    virtual antlrcpp::Any visitConstInitValLi(SysYParser::ConstInitValLiContext *ctx) override;
    virtual antlrcpp::Any visitInitVal(SysYParser::InitValContext *ctx) override;
    virtual antlrcpp::Any visitInitValLi (SysYParser::InitValLiContext *ctx) override;
    // visit expressions, 18
    virtual antlrcpp::Any visitConstExpLi(SysYParser::ConstExpLiContext *ctx) override;
    virtual antlrcpp::Any visitExpLi(SysYParser::ExpLiContext *ctx) override;
    virtual antlrcpp::Any visitConstExp(SysYParser::ConstExpContext *ctx) override;
    virtual antlrcpp::Any visitExp(SysYParser::ExpContext *ctx) override;
    virtual antlrcpp::Any visitCond(SysYParser::CondContext *ctx) override;
    virtual antlrcpp::Any visitLVal(SysYParser::LValContext *ctx) override;
    virtual antlrcpp::Any visitPrimaryExp(SysYParser::PrimaryExpContext *ctx) override;
    virtual antlrcpp::Any visitNumber(SysYParser::NumberContext *ctx) override;
    virtual antlrcpp::Any visitUnary1(SysYParser::Unary1Context *ctx) override;
    virtual antlrcpp::Any visitUnary2(SysYParser::Unary2Context *ctx) override;
    virtual antlrcpp::Any visitUnary3(SysYParser::Unary3Context *ctx) override;
    virtual antlrcpp::Any visitUnaryOp(SysYParser::UnaryOpContext *ctx) override;
    virtual antlrcpp::Any visitMulExp(SysYParser::MulExpContext *ctx) override;
    virtual antlrcpp::Any visitAddExp(SysYParser::AddExpContext *ctx) override;
    virtual antlrcpp::Any visitRelExp(SysYParser::RelExpContext *ctx) override;
    virtual antlrcpp::Any visitEqExp(SysYParser::EqExpContext *ctx) override;
    virtual antlrcpp::Any visitLAndExp(SysYParser::LAndExpContext *ctx) override;
    virtual antlrcpp::Any visitLOrExp(SysYParser::LOrExpContext *ctx) override;
    // visit function declarations, 8
    virtual antlrcpp::Any visitFuncDef(SysYParser::FuncDefContext *ctx) override;
    virtual antlrcpp::Any visitFuncType(SysYParser::FuncTypeContext *ctx) override;
    virtual antlrcpp::Any visitFuncFParams(SysYParser::FuncFParamsContext *ctx) override;
    virtual antlrcpp::Any visitFuncFParam(SysYParser::FuncFParamContext *ctx) override;
    virtual antlrcpp::Any visitFuncRParams(SysYParser::FuncRParamsContext *ctx) override;
    virtual antlrcpp::Any visitBlock(SysYParser::BlockContext *ctx) override;
    virtual antlrcpp::Any visitBlockItemLi(SysYParser::BlockItemLiContext *ctx) override;
    virtual antlrcpp::Any visitBlockItem(SysYParser::BlockItemContext *ctx) override;
    // visit statements, 8
    virtual antlrcpp::Any visitIfStmt(SysYParser::IfStmtContext *ctx) override;
    virtual antlrcpp::Any visitExpStmt(SysYParser::ExpStmtContext *ctx) override;
    virtual antlrcpp::Any visitBlockStmt(SysYParser::BlockStmtContext *ctx) override;
    virtual antlrcpp::Any visitBreakStmt(SysYParser::BreakStmtContext *ctx) override;
    virtual antlrcpp::Any visitWhileStmt(SysYParser::WhileStmtContext *ctx) override;
    virtual antlrcpp::Any visitReturnStmt(SysYParser::ReturnStmtContext *ctx) override;    
    virtual antlrcpp::Any visitContinueStmt(SysYParser::ContinueStmtContext *ctx) override;
    virtual antlrcpp::Any visitAssignment(SysYParser::AssignmentContext *ctx) override;
    // visit types, 1
    virtual antlrcpp::Any visitBType(SysYParser::BTypeContext *ctx) override;
};

TransHelper *tr = new TransHelper(new ArmDesc());
#define RESET_OFFSET() tr->getOffsetCounter()->reset(OffsetCounter::PARAMETER)
#define NEXT_OFFSET(x) tr->getOffsetCounter()->next(OffsetCounter::PARAMETER, x)

// global tmp value for use in translation(as the ret value of the previous function)
Type *p_type = NULL;
Temp p_temp = NULL;
size_t p_unaryOp = 0;
util::Stack<Temp> tempStack;

tac::Label current_break_label;
tac::Label current_continue_label;

antlrcpp::Any SemPass1::visitChildren(antlr4::tree::ParseTree *ctx) {
    size_t n = ctx->children.size();
    for (size_t i = 0; i < n; ++i) ctx->children[i]->accept(this);
    return nullptr;
}
// TODO: somewhere not use this function may have NULL-> bug! (eg.some Li nodes)

util::Vector<int> SemPass1::get_array_dims(SysYParser::ConstExpLiContext *ctx) {
    util::Vector<int> ret;
    std::vector<SysYParser::ConstExpContext *> dims = ctx->constExp();
    for(auto i : dims) {
        int cur = i->accept(this); // TODO: the first dim is null, the length need guess!
        if( i < 0) throw ZeroLengthedArrayError();
        ret.push_back(cur);
    }
    return ret;
}

util::Vector<int> SemPass1::get_array_dims(SysYParser::ExpLiContext *ctx) {
    util::Vector<int> ret;
    std::vector<SysYParser::ExpContext *> dims = ctx->exp();
    for(auto i : dims) {
        int cur = i->accept(this); //TODO: the first dim is null, the length need guess!
        if( i < 0) throw ZeroLengthedArrayError();
        ret.push_back(cur);
    }
    return ret;
}

// visit program node
antlrcpp::Any SemPass1::visitProgram(SysYParser::ProgramContext *ctx) {
    GlobalScope *gscope = new GlobalScope(); // gscope for use
    scopes->open(gscope);

    for(auto it = ctx->compUnit().begin();
    it != ctx->compUnit().end(); ++it) {
        (*it)->accept(this);
    }

    scopes->close();
    return nullptr;
}

// visit compunit node
antlrcpp::Any SemPass1::visitCompUnit(SysYParser::CompUnitContext *ctx) {
    return visitChildren(ctx);
}

// visit decl node
antlrcpp::Any SemPass1::visitDecl(SysYParser::DeclContext *ctx) {
    return visitChildren(ctx);
}

// visit const decl node
antlrcpp::Any SemPass1::visitConstDecl(SysYParser::ConstDeclContext *ctx) {
    return visitChildren(ctx);
}

// visit var decl node
antlrcpp::Any SemPass1::visitVarDecl(SysYParser::VarDeclContext *ctx) {
    return visitChildren(ctx);
}

// visit btype node
antlrcpp::Any SemPass1::visitBType(SysYParser::BTypeContext *ctx) {
    if(ctx->getRuleIndex() == 0) {
        p_type = BaseType::Int;
    } else {
        p_type = BaseType::Float;
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitConstDefLi(SysYParser::ConstDefLiContext *ctx) {
    for(auto it = ctx->constDef().begin();
    it != ctx->constDef().end(); ++it) {
        (*it)->accept(this);
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitVarDefLi(SysYParser::VarDefLiContext *ctx) {
    for(auto it = ctx->varDef().begin();
    it != ctx->varDef().end(); ++it) {
        (*it)->accept(this);
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitConstDef(SysYParser::ConstDefContext *ctx) {
    std::string name = ctx->Identifier()->getText();
    util::Vector<int> dims = get_array_dims(ctx->constExpLi());
    Variable *sym;
    if(dims.size() == 0) {
        sym = new Variable(name, p_type, NULL);
    } else {
        Type *arrayType = new ArrayType(p_type, dims);
        sym = new Variable(name, arrayType, NULL);
    }
    Symbol *s = scopes->lookup(name, 0);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    // TODO: deal with initVal
    return nullptr;
}

antlrcpp::Any SemPass1::visitVarDef(SysYParser::VarDefContext *ctx) {
    std::string name = ctx->Identifier()->getText();
    util::Vector<int> dims = get_array_dims(ctx->constExpLi());
    Variable *sym;
    if(dims.size() == 0) {
        sym = new Variable(name, p_type, NULL);
    } else {
        Type *arrayType = new ArrayType(p_type, dims);
        sym = new Variable(name, arrayType, NULL);
    }
    Symbol *s = scopes->lookup(name, 0);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    // TODO: deal with initVal
    return nullptr;
}    

antlrcpp::Any SemPass1::visitFuncDef(SysYParser::FuncDefContext *ctx) {
    ctx->funcType()->accept(this);
    std::string name = ctx->Identifier()->getText();
    Function *sym = new Function(name, p_type, NULL);
    Symbol *s = scopes->lookup(name, 0);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    scopes->open(sym->getAssociatedScope());
    // util::List<Type *> paramTypes = get_func_paramtypes(ctx->funcFParams());
    ctx->funcFParams()->accept(this); // formal params

    tr->startFunc(sym);
    ctx->block()->accept(this);
    tr->genReturn(tr->genLoadImm4(0)); // Return 0 by default
    tr->endFunc();

    scopes->close();
    return nullptr;
}

antlrcpp::Any SemPass1::visitFuncType(SysYParser::FuncTypeContext *ctx) {
    if(ctx->getRuleIndex() == 0) {
        ctx->bType()->accept(this);
    }
    else p_type = BaseType::Void;
    return nullptr;
}

antlrcpp::Any SemPass1::visitConstExp(SysYParser::ConstExpContext *ctx) {
//TODO:
    return nullptr;
}

antlrcpp::Any SemPass1::visitExp(SysYParser::ExpContext *ctx) {
//TODO:
    return nullptr;
}

antlrcpp::Any SemPass1::visitFuncFParams(SysYParser::FuncFParamsContext *ctx) {
    for(auto it = ctx->funcFParam().begin();
    it != ctx->funcFParam().end(); ++it) {
        (*it)->accept(this);
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitFuncFParam(SysYParser::FuncFParamContext *ctx) {
    ctx->bType()->accept(this);
    std::string name = ctx->Identifier()->getText();
    util::Vector<int> dims = get_array_dims(ctx->expLi());
    dims.insert(dims.begin(), 0); // TODO: first dim length need to be guessed!
    Variable *sym;
    if(dims.size() == 0) {
        sym = new Variable(name, p_type, NULL);
    } else {
        Type *arrayType = new ArrayType(p_type, dims);
        sym = new Variable(name, arrayType, NULL);
    }
    Symbol *s = scopes->lookup(name, 0);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    return nullptr;
}

antlrcpp::Any SemPass1::visitBlock(SysYParser::BlockContext *ctx) {
    Scope *blockScope = new LocalScope();
    scopes->open(blockScope);
    ctx->blockItemLi()->accept(this); // add local scope here
    scopes->close();
    return nullptr;
}

antlrcpp::Any SemPass1::visitBlockItemLi(SysYParser::BlockItemLiContext *ctx) {
    for(auto it = ctx->blockItem().begin();
    it != ctx->blockItem().end(); ++it) {
        (*it)->accept(this);
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitBlockItem(SysYParser::BlockItemContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitIfStmt (SysYParser::IfStmtContext *ctx) {
    Label L1 = tr->getNewLabel();
    Label L2 = tr->getNewLabel();
    ctx->cond()->accept(this);
    tr->genJumpOnZero(L1, p_temp);
    auto it = ctx->stmt().begin();
    (*it)->accept(this);++it; // true branch
    tr->genJump(L2);
    tr->genMarkLabel(L1);
    if(it != ctx->stmt().end()) 
        (*it)->accept(this); // false branch
    tr->genMarkLabel(L2);
    return nullptr;
}

antlrcpp::Any SemPass1::visitExpStmt (SysYParser::ExpStmtContext *ctx) {
    ctx->exp()->accept(this);
    return nullptr;
}

antlrcpp::Any SemPass1::visitBlockStmt (SysYParser::BlockStmtContext *ctx) {
    ctx->block()->accept(this);
    return nullptr;
}

antlrcpp::Any SemPass1::visitBreakStmt (SysYParser::BreakStmtContext *ctx) {
    // "break" here, but nothing to do in symbtable
    tr->genJump(current_break_label);
    return nullptr;
}

antlrcpp::Any SemPass1::visitWhileStmt (SysYParser::WhileStmtContext *ctx) {
    Label L1 = tr->getNewLabel();
    Label L2 = tr->getNewLabel();
    Label old_break = current_break_label;
    Label old_continue = current_continue_label;

    current_break_label = L2;
    current_continue_label = L1;
    
    tr->genMarkLabel(L1);
    ctx->cond()->accept(this);
    tr->genJumpOnZero(L2, p_temp); // if flase goto L2, loop end
    ctx->stmt()->accept(this);
    tr->genJump(L1);
    tr->genMarkLabel(L2);

    current_break_label = old_break; // restore break&continue label
    current_continue_label = old_continue;
    return nullptr;
}

antlrcpp::Any SemPass1::visitReturnStmt (SysYParser::ReturnStmtContext *ctx) {
    ctx->exp()->accept(this);
    tr->genReturn(p_temp);
    return nullptr;
}   

antlrcpp::Any SemPass1::visitContinueStmt (SysYParser::ContinueStmtContext *ctx) {
    // "continue" here, but nothing to do in symbtable
    tr->genJump(current_continue_label);
    return nullptr;
}

antlrcpp::Any SemPass1::visitAssignment (SysYParser::AssignmentContext *ctx) {
    ctx->lVal()->accept(this);
    ctx->exp()->accept(this);
    return nullptr;
}

antlrcpp::Any SemPass1::visitCond(SysYParser::CondContext *ctx) {


}
antlrcpp::Any SemPass1::visitLVal(SysYParser::LValContext *ctx) {

}
antlrcpp::Any SemPass1::visitPrimaryExp(SysYParser::PrimaryExpContext *ctx) {

}
antlrcpp::Any SemPass1::visitNumber(SysYParser::NumberContext *ctx) {

}

antlrcpp::Any SemPass1::visitUnary1(SysYParser::Unary1Context *ctx) {
    ctx->primaryExp()->accept(this);
    return nullptr;
}

antlrcpp::Any SemPass1::visitUnary2(SysYParser::Unary2Context *ctx) {
    // tr->genCall();
    // TODO: call function here. a little complex
    return nullptr;
}

antlrcpp::Any SemPass1::visitUnary3(SysYParser::Unary3Context *ctx) {
    ctx->unaryOp()->accept(this);
    ctx->unaryExp()->accept(this);
    Temp r = tempStack.top();tempStack.pop();
    Temp n;
    if(p_unaryOp == 0) {
        n = r;
    } else if(p_unaryOp == 1) {
        n = tr->genNeg(r);
    } else {
        n = tr->genLNot(r); // TODO: how this really do in instr?
    }
    tempStack.push(n);
}

antlrcpp::Any SemPass1::visitUnaryOp(SysYParser::UnaryOpContext *ctx) {
    p_unaryOp = ctx->getRuleIndex();
    return nullptr;
}

antlrcpp::Any SemPass1::visitMulExp(SysYParser::MulExpContext *ctx) {
    ctx->unaryExp()->accept(this);
    ctx->mulExp()->accept(this);
    size_t op = ctx->getRuleIndex();
    Temp r = tempStack.top();tempStack.pop();
    Temp l = tempStack.top();tempStack.pop();
    Temp n;
    if(op == 0) {
        n = tr->genMul(l, r);
    } else if(op == 1) {
        n = tr->genDiv(l, r);
    } else {
        n = tr->genMod(l, r);
    }
    tempStack.push(n);
}
antlrcpp::Any SemPass1::visitAddExp(SysYParser::AddExpContext *ctx) {
    ctx->mulExp()->accept(this);
    ctx->addExp()->accept(this);
    size_t op = ctx->getRuleIndex();
    Temp r = tempStack.top();tempStack.pop();
    Temp l = tempStack.top();tempStack.pop();
    Temp n;
    if(op == 0) {
        n = tr->genAdd(l, r);
    } else {
        n = tr->genSub(l, r);
    }
    tempStack.push(n);
}
antlrcpp::Any SemPass1::visitRelExp(SysYParser::RelExpContext *ctx) {
    ctx->addExp()->accept(this);
    ctx->relExp()->accept(this);
    size_t op = ctx->getRuleIndex();
    Temp r = tempStack.top();tempStack.pop();
    Temp l = tempStack.top();tempStack.pop();
    Temp n;
    if(op == 0) { // <
        n = tr->genLes(l, r);
    } else if(op == 1) { // >
        n = tr->genGtr(l, r);
    } else if(op == 2) { // <=
        n = tr->genLeq(l, r);
    } else { // >=
        n = tr->genGeq(l, r);
    }
    tempStack.push(n);
}
antlrcpp::Any SemPass1::visitEqExp(SysYParser::EqExpContext *ctx) {
    ctx->relExp()->accept(this);
    ctx->eqExp()->accept(this);
    size_t op = ctx->getRuleIndex();
    Temp r = tempStack.top();tempStack.pop();
    Temp l = tempStack.top();tempStack.pop();
    Temp n;
    if(op == 0) {
        n = tr->genEqu(l, r);
    } else {
        n = tr->genNeq(l, r);
    }
    tempStack.push(n);
}

antlrcpp::Any SemPass1::visitLAndExp(SysYParser::LAndExpContext *ctx) { // TODO: 短路求值
    ctx->eqExp()->accept(this);
    ctx->lAndExp()->accept(this);
    Temp r = tempStack.top();tempStack.pop();
    Temp l = tempStack.top();tempStack.pop();
    Temp n = tr->genLAnd(l, r);
    tempStack.push(n);
}

antlrcpp::Any SemPass1::visitLOrExp(SysYParser::LOrExpContext *ctx) { // TODO: 短路求值
    ctx->lAndExp()->accept(this);
    ctx->lOrExp()->accept(this);
    Temp r = tempStack.top();tempStack.pop();
    Temp l = tempStack.top();tempStack.pop();
    Temp n = tr->genLOr(l, r);
    tempStack.push(n);
}

// root function, called by main
void runSemPass1(SysYParser::ProgramContext *tree) {
    tree->accept(new SemPass1());
}
/*****************************************************
 *  Implementation of the first semantic analysis pass.
 *
 *  In the first pass, we will:
 *    1. create appropriate type::Type instances for the types;
 *    2. create and manage scope::Scope instances;
 *    3. create symb::Symbol instances;
 *    4. manage the symbol tables.
 *  After this pass, the ATTR(sym) or ATTR(type) attributs of the visited nodes
 *  should have been set.
 *
 */

#include "SysYBaseVisitor.h"
#include "config.hpp"
#include "scope/scope.hpp"
#include "scope/scope_stack.hpp"
#include "symb/symbol.hpp"
#include "type/type.hpp"

using namespace knpc;
using namespace knpc::scope;
using namespace knpc::symb;
using namespace knpc::type;
using namespace knpc::err;

class SemPass1 : public SysYBaseVisitor {
    // visit program
    virtual antlrcpp::Any visitProgram(SysYParser::ProgramContext *ctx) override;
    virtual antlrcpp::Any visitCompUnit(SysYParser::CompUnitContext *ctx) override;

    // visit variable declarations
    virtual antlrcpp::Any visitDecl(SysYParser::DeclContext *ctx) override;
    virtual antlrcpp::Any visitConstDecl(SysYParser::ConstDeclContext *ctx) override;
    virtual antlrcpp::Any visitVarDecl(SysYParser::VarDeclContext *ctx) override;
    virtual antlrcpp::Any visitConstDefLi(SysYParser::ConstDefLiContext *ctx) override;
    virtual antlrcpp::Any visitVarDefLi(SysYParser::VarDefLiContext *ctx) override;
    virtual antlrcpp::Any visitConstDef(SysYParser::ConstDefContext *ctx) override;
    virtual antlrcpp::Any visitVarDef(SysYParser::VarDefContext *ctx) override;    
    util::Vector<int> get_array_dims(SysYParser::ConstExpLiContext *ctx);
    util::Vector<int> get_array_dims(SysYParser::ExpLiContext *ctx);

    // visit expression
    virtual antlrcpp::Any visitConstExp(SysYParser::ConstExpContext *ctx) override;
    virtual antlrcpp::Any visitExp(SysYParser::ExpContext *ctx) override;

    // visit function declarations
    virtual antlrcpp::Any visitFuncDef(SysYParser::FuncDefContext *ctx) override;
    virtual antlrcpp::Any visitFuncType(SysYParser::FuncTypeContext *ctx) override;
    // util::List<Type *> get_func_paramtypes(SysYParser::FuncFParamsContext *ctx);
    virtual antlrcpp::Any visitFuncFParams(SysYParser::FuncFParamsContext *ctx) override;
    virtual antlrcpp::Any visitFuncFParam(SysYParser::FuncFParamContext *ctx) override;
    virtual antlrcpp::Any visitBlock(SysYParser::BlockContext *ctx) override;
    virtual antlrcpp::Any visitBlockItemLi(SysYParser::BlockItemLiContext *ctx) override;
    virtual antlrcpp::Any visitBlockItem(SysYParser::BlockItemContext *ctx) override;

    // visit statements
    // virtual antlrcpp::Any visitStmt(SysYParser::StmtContext *ctx) override;
    virtual antlrcpp::Any visitIfStmt (SysYParser::IfStmtContext *ctx) override;
    virtual antlrcpp::Any visitExpStmt (SysYParser::ExpStmtContext *ctx) override;
    virtual antlrcpp::Any visitBlockStmt (SysYParser::BlockStmtContext *ctx) override;
    virtual antlrcpp::Any visitBreakStmt (SysYParser::BreakStmtContext *ctx) override;
    virtual antlrcpp::Any visitWhileStmt (SysYParser::WhileStmtContext *ctx) override;
    virtual antlrcpp::Any visitReturnStmt (SysYParser::ReturnStmtContext *ctx) override;    
    virtual antlrcpp::Any visitContinueStmt (SysYParser::ContinueStmtContext *ctx) override;
    virtual antlrcpp::Any visitAssignment (SysYParser::AssignmentContext *ctx) override;

    // visit types
    virtual antlrcpp::Any visitBType(SysYParser::BTypeContext *ctx) override;
};

Type *t = NULL;

util::Vector<int> SemPass1::get_array_dims(SysYParser::ConstExpLiContext *ctx) {
    util::Vector<int> ret;
    std::vector<SysYParser::ConstExpContext *> dims = ctx->constExp();
    for(auto i : dims) {
        int cur = i->accept(this);
        if( i < 0) throw ZeroLengthedArrayError();
        ret.push_back(cur);
    }
    return ret;
}

util::Vector<int> SemPass1::get_array_dims(SysYParser::ExpLiContext *ctx) {
    util::Vector<int> ret;
    std::vector<SysYParser::ExpContext *> dims = ctx->exp();
    for(auto i : dims) {
        int cur = i->accept(this); //TODO:
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
    ctx->funcDef()->accept(this);
    ctx->decl()->accept(this);
    ctx->compUnit()->accept(this);
    return nullptr;
}

// visit decl node
antlrcpp::Any SemPass1::visitDecl(SysYParser::DeclContext *ctx) {
    ctx->constDecl()->accept(this);
    ctx->varDecl()->accept(this);
    return nullptr;
}

// visit const decl node
antlrcpp::Any SemPass1::visitConstDecl(SysYParser::ConstDeclContext *ctx) {
    if(ctx->bType()->accept(this) == 0) {
        t = BaseType::Int;
    } else {
        t = BaseType::Float;
    }
    ctx->constDefLi()->accept(this);
    return nullptr;
}

// visit var decl node
antlrcpp::Any SemPass1::visitVarDecl(SysYParser::VarDeclContext *ctx) {
    if(ctx->bType()->accept(this) == 0) {
        t = BaseType::Int;
    } else {
        t = BaseType::Float;
    }
    ctx->varDefLi()->accept(this);
    return nullptr;
}

// visit btype node
antlrcpp::Any SemPass1::visitBType(SysYParser::BTypeContext *ctx) {
    return ctx->getRuleIndex();
}

antlrcpp::Any SemPass1::visitConstDefLi(SysYParser::ConstDefLiContext *ctx) {
    ctx->constDef()->accept(this);
    ctx->constDefLi()->accept(this);
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
        sym = new Variable(name, t, NULL);
    } else {
        Type *arrayType = new ArrayType(t, dims);
        sym = new Variable(name, arrayType, NULL);
    }
    Symbol *s = scopes->lookup(name, 0);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    // TODO: deal with initVal
}

antlrcpp::Any SemPass1::visitVarDef(SysYParser::VarDefContext *ctx) {
    std::string name = ctx->Identifier()->getText();
    util::Vector<int> dims = get_array_dims(ctx->constExpLi());
    Variable *sym;
    if(dims.size() == 0) {
        sym = new Variable(name, t, NULL);
    } else {
        Type *arrayType = new ArrayType(t, dims);
        sym = new Variable(name, arrayType, NULL);
    }
    Symbol *s = scopes->lookup(name, 0);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    // TODO: deal with initVal
}    

antlrcpp::Any SemPass1::visitFuncDef(SysYParser::FuncDefContext *ctx) {
    ctx->funcType()->accept(this);
    std::string name = ctx->Identifier()->getText();
    Function *sym = new Function(name, t, NULL);
    Symbol *s = scopes->lookup(name, 0);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    scopes->open(sym->getAssociatedScope());
    // util::List<Type *> paramTypes = get_func_paramtypes(ctx->funcFParams());
    ctx->funcFParams()->accept(this); // formal params
    ctx->block()->accept(this);
    scopes->close();
}

antlrcpp::Any SemPass1::visitFuncType(SysYParser::FuncTypeContext *ctx) {
    if(ctx->getRuleIndex() == 0) {
        if(ctx->bType()->accept(this) == 0) {
            t = BaseType::Int;
        } else {
            t = BaseType::Float;
        }
    }
    else t = BaseType::Void;
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
    Variable *sym;
    if(dims.size() == 0) {
        sym = new Variable(name, t, NULL);
    } else {
        Type *arrayType = new ArrayType(t, dims);
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
    ctx->decl()->accept(this);
    ctx->stmt()->accept(this);
    return nullptr;
}

antlrcpp::Any SemPass1::visitIfStmt (SysYParser::IfStmtContext *ctx) {
    ctx->cond()->accept(this);
    for(auto it = ctx->stmt().begin();
    it != ctx->stmt().end(); ++it) {
        (*it)->accept(this);
    }
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
    return nullptr;
}

antlrcpp::Any SemPass1::visitWhileStmt (SysYParser::WhileStmtContext *ctx) {
    ctx->cond()->accept(this);
    ctx->stmt()->accept(this);
    return nullptr;
}

antlrcpp::Any SemPass1::visitReturnStmt (SysYParser::ReturnStmtContext *ctx) {
    ctx->exp()->accept(this);
    return nullptr;
}   

antlrcpp::Any SemPass1::visitContinueStmt (SysYParser::ContinueStmtContext *ctx) {
    // "continue" here, but nothing to do in symbtable
    return nullptr;
}

antlrcpp::Any SemPass1::visitAssignment (SysYParser::AssignmentContext *ctx) {
    ctx->lVal()->accept(this);
    ctx->exp()->accept(this);
    return nullptr;
}


// root function, called by main
void buildSymbols(SysYParser::ProgramContext *tree) {
    tree->accept(new SemPass1());
}
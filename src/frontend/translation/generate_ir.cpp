/*****************************************************
 *  Implementation of the first pass.
 *  This pass1 will:
 *      1. semantic analysis
 *      2. generate IR (TAC)
 *
 */

#include "generate_ir.hpp"

#define RESET_OFFSET() tr->getOffsetCounter()->reset(OffsetCounter::PARAMETER)
#define NEXT_OFFSET(x) tr->getOffsetCounter()->next(OffsetCounter::PARAMETER, x)

// global tmp value for use in translation(as the ret value of the previous function)
Type *p_type = NULL;
std::string p_name = "helloworld";
size_t p_unaryOp = 0;
int order = 0; // used in funcDef
util::Stack<Temp> tempStack;

tac::Label current_break_label;
tac::Label current_continue_label;

SemPass1::SemPass1(TransHelper *helper) {
    tr = helper;
}

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
        i->accept(this); // the first dim is not null(according to the SysY Def)
        int cur = tempStack.top()->ctval;tempStack.pop();
        if( i < 0) throw ZeroLengthedArrayError();
        ret.push_back(cur);
    }
    return ret;
}

antlrcpp::Any SemPass1::visitProgram(SysYParser::ProgramContext *ctx) {
    GlobalScope *gscope = new GlobalScope(); // gscope for use
    scopes->open(gscope);

    for(auto it : ctx->compUnit()) {
        it->accept(this);
    }

    scopes->close();
    return nullptr;
}

antlrcpp::Any SemPass1::visitCompUnit(SysYParser::CompUnitContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitDecl(SysYParser::DeclContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitConstDecl(SysYParser::ConstDeclContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitVarDecl(SysYParser::VarDeclContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitBType(SysYParser::BTypeContext *ctx) {
    if(ctx->Int()) {
        p_type = BaseType::Int;
    } else {
        p_type = BaseType::Float;
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitConstDefLi(SysYParser::ConstDefLiContext *ctx) {
    for(auto it : ctx->constDef()) {
        it->accept(this);
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitVarDefLi(SysYParser::VarDefLiContext *ctx) {
    for(auto it : ctx->varDef()) {
        it->accept(this);
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitConstDef(SysYParser::ConstDefContext *ctx) {
    std::string name = ctx->Identifier()->getText();
    Variable *sym;
    if(ctx->constExpLi()) {
        util::Vector<int> dims = get_array_dims(ctx->constExpLi());
        Type *arrayType = new ArrayType(p_type, dims);
        sym = new Variable(name, arrayType);
    } else {
        sym = new Variable(name, p_type);
    }
    Symbol *s = scopes->lookup(name, false);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    // const variable must be init here.
    if(sym->getType()->isBaseType()) {
        ctx->constInitVal()->accept(this);
        Temp n = tempStack.top();tempStack.pop();
        if(sym->isGlobalVar()) {
            tr->genGlobalVarible(name, n->ctval, sym->getType()->getSize());
        } else {
            sym->attachTemp(tr->getNewTempI4());
            tr->genAssign(sym->getTemp(), n);
        }
    } else {
        //TODO: array init to do
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitConstInitValLi(SysYParser::ConstInitValLiContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitConstInitVal(SysYParser::ConstInitValContext *ctx) {
    //TODO: array init to do
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitVarDef(SysYParser::VarDefContext *ctx) {
    std::string name = ctx->Identifier()->getText();
    Variable *sym;
    if(ctx->constExpLi()) {
        util::Vector<int> dims = get_array_dims(ctx->constExpLi());
        Type *arrayType = new ArrayType(p_type, dims);
        sym = new Variable(name, arrayType);
    } else {
        sym = new Variable(name, p_type);
    }
    Symbol *s = scopes->lookup(name, false);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    if(ctx->initVal()) {
        if(sym->getType()->isBaseType()) {
            ctx->initVal()->accept(this);
            Temp n = tempStack.top();tempStack.pop();
            if(sym->isGlobalVar()) {
                tr->genGlobalVarible(name, n->ctval, sym->getType()->getSize());
            } else {
                sym->attachTemp(tr->getNewTempI4());
                tr->genAssign(sym->getTemp(), n);
            }
        } else {
            //TODO: array init to do
        }
    } else {
        if(sym->getType()->isBaseType()) {
            if(sym->isGlobalVar()) {
                tr->genGlobalVarible(name, 0, sym->getType()->getSize());
            } else {
                sym->attachTemp(tr->getNewTempI4());
            }
        } else {
            //TODO: array to do here
        }
    }
    return nullptr;
}    

antlrcpp::Any SemPass1::visitInitValLi(SysYParser::InitValLiContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitInitVal(SysYParser::InitValContext *ctx) {
    //TODO: array init to do
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitFuncDef(SysYParser::FuncDefContext *ctx) {
    ctx->funcType()->accept(this);
    std::string name = ctx->Identifier()->getText();
    Function *sym = new Function(name, p_type);
    sym->attachEntryLabel(tr->getNewEntryLabel(sym));
    Symbol *s = scopes->lookup(name, false);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    scopes->open(sym->getAssociatedScope());

    order = 0;    
    if(ctx->funcFParams()) ctx->funcFParams()->accept(this); // formal params
    sym->offset = sym->getOrder()*POINTER_SIZE;
    RESET_OFFSET();
    // TODO: other formal arguments
    tr->startFunc(sym);
    ctx->block()->accept(this);
    if(sym->getResultType()->equal(BaseType::Int)) 
        tr->genReturn(tr->genLoadImm4(0)); // Return 0 by default
    tr->endFunc();

    scopes->close();
    return nullptr;
}

antlrcpp::Any SemPass1::visitFuncType(SysYParser::FuncTypeContext *ctx) {
    if(ctx->Void()) {
        p_type = BaseType::Void;
    }
    else ctx->bType()->accept(this);
    return nullptr;
}

antlrcpp::Any SemPass1::visitConstExpLi(SysYParser::ConstExpLiContext *ctx) {
    for(auto it : ctx->constExp()) {
        it->accept(this);
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitExpLi(SysYParser::ExpLiContext *ctx) {
    for(auto it : ctx->exp()) {
        it->accept(this);
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitConstExp(SysYParser::ConstExpContext *ctx) {
//TODO: need const propagation here
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitExp(SysYParser::ExpContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitFuncFParams(SysYParser::FuncFParamsContext *ctx) {
    for(auto it : ctx->funcFParam()) {
        it->accept(this);
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitFuncFParam(SysYParser::FuncFParamContext *ctx) {
    ctx->bType()->accept(this);
    std::string name = ctx->Identifier()->getText();
    util::Vector<int> dims = get_array_dims(ctx->constExpLi());
    // dims.insert(dims.begin(), 0); // TODO: first dim length need to be guessed!
    Variable *sym;
    if(dims.size() == 0) {
        sym = new Variable(name, p_type);
    } else {
        Type *arrayType = new ArrayType(p_type, dims);
        sym = new Variable(name, arrayType);
    }
    Symbol *s = scopes->lookup(name, false);
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    sym->setOrder(order++);
    sym->attachTemp(tr->allocNewTempI4(sym->getType()->getSize()));
    return nullptr;
}

antlrcpp::Any SemPass1::visitFuncRParams(SysYParser::FuncRParamsContext *ctx) {
    for(auto it : ctx->exp()) {
        it->accept(this);
        Temp n = tempStack.top();tempStack.pop();
        tr->genParam(n);
    }
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
    for(auto it : ctx->blockItem()) {
        it->accept(this);
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
    tr->genJumpOnZero(L1, tempStack.top());
    tempStack.pop();
    auto it = ctx->stmt()[0];
    it->accept(this); // true branch
    tr->genJump(L2);
    tr->genMarkLabel(L1);
    it = ctx->stmt()[1];
    if(it) it->accept(this); // false branch
    tr->genMarkLabel(L2);
    return nullptr;
}

antlrcpp::Any SemPass1::visitExpStmt (SysYParser::ExpStmtContext *ctx) {
    visitChildren(ctx);
    tempStack.pop(); // remove redundant value
    return nullptr;
}

antlrcpp::Any SemPass1::visitBlockStmt (SysYParser::BlockStmtContext *ctx) {
    return visitChildren(ctx);
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
    tr->genJumpOnZero(L2, tempStack.top()); // if flase goto L2, loop end
    tempStack.pop();
    ctx->stmt()->accept(this);
    tr->genJump(L1);
    tr->genMarkLabel(L2);

    current_break_label = old_break; // restore break&continue label
    current_continue_label = old_continue;
    return nullptr;
}

antlrcpp::Any SemPass1::visitReturnStmt (SysYParser::ReturnStmtContext *ctx) {
    ctx->exp()->accept(this);
    tr->genReturn(tempStack.top());
    tempStack.pop();
    return nullptr;
}   

antlrcpp::Any SemPass1::visitContinueStmt (SysYParser::ContinueStmtContext *ctx) {
    // "continue" here, but nothing to do in symbtable
    tr->genJump(current_continue_label);
    return nullptr;
}

antlrcpp::Any SemPass1::visitAssignment (SysYParser::AssignmentContext *ctx) {
    // differ according to the lval(array? global?)
    ctx->exp()->accept(this);
    Temp r = tempStack.top();tempStack.pop();
    ctx->lVal()->accept(this);
    // tempStack.pop(); // move redundant temp from lVal
    Variable *sym = (Variable *)(scopes->lookup(p_name, true));
    if(sym->isGlobalVar()) {
        Temp n = tr->genLoadSymbol(p_name);
        if(sym->getType()->isArrayType()) {
            int c_dim = 1;
            Temp x, y;
            ArrayType *c_type = (ArrayType *)(sym->getType());
            for(auto it = c_type->getLength().rbegin();
            it != c_type->getLength().rend(); --it) {
                x = tr->genLoadImm4(c_dim);
                y = tr->genMul(x, tempStack.top());tempStack.pop();
                n = tr->genAdd(n, y);
                c_dim = c_dim*(*it);
            }
        }
        tr->genStore(r, n, 0);
    } else {
        Temp n = sym->getTemp();
        if(sym->getType()->isArrayType()) {
            int c_dim = 1;
            Temp x, y;
            ArrayType *c_type = (ArrayType *)(sym->getType());
            for(auto it = c_type->getLength().rbegin();
            it != c_type->getLength().rend(); --it) {
                x = tr->genLoadImm4(c_dim);
                y = tr->genMul(x, tempStack.top());tempStack.pop();
                n = tr->genAdd(n, y);
                c_dim = c_dim*(*it);
            }
            tr->genStore(r, n, 0);
        } else {
            tr->genAssign(n, r);
        }
    }
    return nullptr; // TODO: overlook typecheck
}

antlrcpp::Any SemPass1::visitCond(SysYParser::CondContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitLVal(SysYParser::LValContext *ctx) {
    std::string name = ctx->Identifier()->getText();
    visitChildren(ctx);
    p_name = name;
    return nullptr;
}

antlrcpp::Any SemPass1::visitPrimary1(SysYParser::Primary1Context *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitPrimary2(SysYParser::Primary2Context *ctx) {
    // special case here, need to gen value manually
    ctx->lVal()->accept(this);
    Temp n;
    Variable *sym = (Variable *)(scopes->lookup(p_name, true));
    if(sym->isGlobalVar()) {
        n = tr->genLoadSymbol(p_name);
        bool isConst = n->isConst;
        if(sym->getType()->isArrayType()) {
            int c_dim = 1;
            Temp x, y;
            ArrayType *c_type = (ArrayType *)(sym->getType());
            for(auto it = c_type->getLength().rbegin();
            it != c_type->getLength().rend(); --it) {
                x = tr->genLoadImm4(c_dim);
                y = tr->genMul(x, tempStack.top());tempStack.pop();
                n = tr->genAdd(n, y);
                c_dim = c_dim*(*it);
            }
        }
        n = tr->genLoad(n, 0);
        n->isConst = isConst;
    } else {
        n = sym->getTemp();
        bool isConst = n->isConst;
        if(sym->getType()->isArrayType()) {
            int c_dim = 1;
            Temp x, y;
            ArrayType *c_type = (ArrayType *)(sym->getType());
            for(auto it = c_type->getLength().rbegin();
            it != c_type->getLength().rend(); --it) {
                x = tr->genLoadImm4(c_dim);
                y = tr->genMul(x, tempStack.top());tempStack.pop();
                n = tr->genAdd(n, y);
                c_dim = c_dim*(*it);
            }
            n = tr->genLoad(n, 0);
        }
        n->isConst = isConst;
    }
    tempStack.push(n);
    return nullptr;
}

antlrcpp::Any SemPass1::visitPrimary3(SysYParser::Primary3Context *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitNumber(SysYParser::NumberContext *ctx) {
    Temp n;
    if(ctx->Decimal()) {
        std::string str = ctx->Decimal()->getText();
        int ans = 0, len = str.length();
        for(int i = 0; i < len; ++i) ans = ans*10 + (str[i]^48);
        n = tr->genLoadImm4(ans);
        n->ctval = ans;
        n->ctval = true;
    } else if(ctx->Octal()) {
        std::string str = ctx->Octal()->getText();
        int ans = 0, len = str.length();
        for(int i = 1; i < len; ++i) ans = ans*8 + (str[i]^48);
        n = tr->genLoadImm4(ans);
        n->ctval = ans;
        n->ctval = true;
    } else if(ctx->Hexadecimal()) {
        std::string str = ctx->Hexadecimal()->getText();
        int ans = 0, len = str.length();
        for(int i = 2; i < len; ++i)
        {
            if(str[i] < 'A') ans = ans*16 + (str[i]^48);
            else if(str[i] < 'Z')ans = ans*16 + 10 + (str[i]-'A');
            else ans = ans*16 + 10 + (str[i]-'a');
        }
        n = tr->genLoadImm4(ans);
        n->ctval = ans;
        n->ctval = true;
    } else {
        std::string str = ctx->FloatLiteral()->getText();
        n = tr->genLoadImm4(0); // TODO: Float here! now return 0
        n->ctval = 0;
        n->ctval = true;
    }
    tempStack.push(n);
    return nullptr;
}

antlrcpp::Any SemPass1::visitUnary1(SysYParser::Unary1Context *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitUnary2(SysYParser::Unary2Context *ctx) {
    visitChildren(ctx);
    std::string name = ctx->Identifier()->getText();
    Function *sym = (Function *)(scopes->lookup(name, true));
    tr->genCall(sym->getEntryLabel());
    // TODO: call function here. a little complex
    return nullptr;
}

antlrcpp::Any SemPass1::visitUnary3(SysYParser::Unary3Context *ctx) {
    ctx->unaryExp()->accept(this); // first visit exp, then visit op
    ctx->unaryOp()->accept(this);
    Temp r = tempStack.top();tempStack.pop();
    Temp n;
    if(p_unaryOp == 0) {
        n = r;
    } else if(p_unaryOp == 1) {
        n = tr->genNeg(r);
        n->ctval = -1*r->ctval;
        n->isConst = r->isConst;
    } else {
        n = tr->genLNot(r); // seqz
        n->ctval = (r->ctval == 0);
        n->isConst = r->isConst;
    }
    tempStack.push(n);
    return nullptr;
}

antlrcpp::Any SemPass1::visitUnaryOp(SysYParser::UnaryOpContext *ctx) {
    if(ctx->getText()[0] == '+') {
        p_unaryOp = 0;
    } else if(ctx->getText()[0] == '-') {
        p_unaryOp = 1;
    } else {
        p_unaryOp = 2;
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitMulExp(SysYParser::MulExpContext *ctx) {
    Temp n;
    if(ctx->mulExp()) {
        ctx->unaryExp()->accept(this);
        ctx->mulExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        Temp l = tempStack.top();tempStack.pop();
        if(ctx->children[1]->getText()[0] == '*') {
            n = tr->genMul(l, r);
            n->ctval = l->ctval*r->ctval;
        } else if(ctx->children[1]->getText()[0] == '/') {
            n = tr->genDiv(l, r);
            if(r->ctval != 0) n->ctval = l->ctval / r->ctval;
        } else {
            n = tr->genMod(l, r);
            if(r->ctval != 0) n->ctval = l->ctval % r->ctval;
        }
        n->isConst = l->isConst && r->isConst;
    } else {
        ctx->unaryExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        n = r;
    }
    tempStack.push(n);
    return nullptr;
}
antlrcpp::Any SemPass1::visitAddExp(SysYParser::AddExpContext *ctx) {
    Temp n;
    if(ctx->addExp()) {
        ctx->mulExp()->accept(this);
        ctx->addExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        Temp l = tempStack.top();tempStack.pop();
        if(ctx->children[1]->getText()[0] == '+') {
            n = tr->genAdd(l, r);
            n->ctval = l->ctval + r->ctval;
        } else {
            n = tr->genSub(l, r);
            n->ctval = l->ctval - r->ctval;
        }
        n->isConst = l->isConst && r->isConst;
    } else {
        ctx->mulExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        n = r;
    }
    tempStack.push(n);
    return nullptr;
}
antlrcpp::Any SemPass1::visitRelExp(SysYParser::RelExpContext *ctx) {
    Temp n;
    if(ctx->relExp()) {
        ctx->addExp()->accept(this);
        ctx->relExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        Temp l = tempStack.top();tempStack.pop();
        if(ctx->children[1]->getText()[0] == '<') { // <
            if(ctx->children[1]->getText().length() == 1) n = tr->genLes(l, r);
            else n = tr->genLeq(l, r);
        } else { // >
            if(ctx->children[1]->getText().length() == 1) n = tr->genGtr(l, r);
            else n = tr->genGeq(l, r);
        }
    } else {
        ctx->addExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        n = r;
    }
    tempStack.push(n);
    return nullptr;
}
antlrcpp::Any SemPass1::visitEqExp(SysYParser::EqExpContext *ctx) {
    Temp n;
    if(ctx->eqExp()) {
        ctx->relExp()->accept(this);
        ctx->eqExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        Temp l = tempStack.top();tempStack.pop();
        if(ctx->children[1]->getText()[0] == '=') {
            n = tr->genEqu(l, r);
        } else {
            n = tr->genNeq(l, r);
        }
    } else {
        ctx->relExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        n = r;
    }
    tempStack.push(n);
    return nullptr;
}

// LAnd, LOr, LNot: "L" means "Logic"
antlrcpp::Any SemPass1::visitLAndExp(SysYParser::LAndExpContext *ctx) { // TODO: 短路求值
    Temp n;
    if(ctx->lAndExp()) {
        ctx->eqExp()->accept(this);
        ctx->lAndExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        Temp l = tempStack.top();tempStack.pop();
        n = tr->genLAnd(l, r);
    } else {
        ctx->eqExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        n = r;
    }
    tempStack.push(n);
    return nullptr;
}

antlrcpp::Any SemPass1::visitLOrExp(SysYParser::LOrExpContext *ctx) { // TODO: 短路求值
    Temp n;
    if(ctx->lOrExp()) {
        ctx->lAndExp()->accept(this);
        ctx->lOrExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        Temp l = tempStack.top();tempStack.pop();
        n = tr->genLOr(l, r);
    } else {
        ctx->lAndExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        n = r;
    }
    tempStack.push(n);
    return nullptr;
}

// root function, called by main
Piece *runSemPass1(SysYParser::ProgramContext *tree, MachineDesc *md) {
    TransHelper *helper = new TransHelper(md);
    tree->accept(new SemPass1(helper));
    return helper->getPiece();
}
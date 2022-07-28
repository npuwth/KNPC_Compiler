/*****************************************************
 *  Implementation of the first pass.
 *  This pass1 will:
 *      1. semantic analysis
 *      2. generate IR (TAC)
 *
 */

#include "generate_ir.hpp"
// #define debug_on

#define RESET_OFFSET() tr->getOffsetCounter()->reset(OffsetCounter::PARAMETER)
#define NEXT_OFFSET(x) tr->getOffsetCounter()->next(OffsetCounter::PARAMETER, x)

// global tmp value for use in translation(as the ret value of the previous function)
Type *p_type = NULL;
std::string p_name = "initial";
size_t p_unaryOp = 0;
int order = 0; // used in funcDef
util::Stack<Temp> tempStack;
Label runtimeLabels[16];

tac::Label current_break_label;
tac::Label current_continue_label;

SemPass1::SemPass1(TransHelper *helper) {
    tr = helper;
}

// visit all children of the node
antlrcpp::Any SemPass1::visitChildren(antlr4::tree::ParseTree *ctx) {
    knpc_assert(ctx);
    size_t n = ctx->children.size();
    for (size_t i = 0; i < n; ++i) ctx->children[i]->accept(this);
    return nullptr;
}
// somewhere not use this function may have NULL-> bug! (eg.some Li nodes)

util::Vector<int> SemPass1::get_array_dims(SysYParser::ConstExpLiContext *ctx) {
    util::Vector<int> ret;
    knpc_assert(ctx);
    std::vector<SysYParser::ConstExpContext *> dims = ctx->constExp();
    for(auto i : dims) {
        i->accept(this); // the first dim is not null(according to the SysY Def)
        knpc_assert(tempStack.top()->isConst);
        int cur = tempStack.top()->ctval;tempStack.pop();
        if(cur <= 0) throw ZeroLengthedArrayError();
        ret.push_back(cur);
    }
    #ifdef debug_on
    printf("array dims are: "); // debug
    for(size_t i = 0; i < ret.size(); i++) printf("%d ", ret[i]); // debug
    #endif
    return ret;
}

util::Vector<int> SemPass1::get_array_constInitVals(SysYParser::ConstInitValContext *ctx, util::Vector<int> dims, util::Vector<int> dimSize, int d) {
    util::Vector<int> ret;
    if(ctx->constExp()) {
        ctx->constExp()->accept(this);
        Temp n = tempStack.top();tempStack.pop();
        knpc_assert(n->isConst);
        ret.push_back(n->ctval); // TODO: implicit convert needed? from float to int?
    } else {
        for(auto it : ctx->constInitVal()) {
            util::Vector<int> temp = get_array_constInitVals(it, dims, dimSize, d + 1); // dfs
            for(size_t i = 0; i < temp.size(); i++) {
                ret.push_back(temp[i]);
            }
        }
        int j = ret.size();
        while(j < dims[d] * dimSize[d]) { // pad zero in a { }
            ret.push_back(0);
            j++;
        }
    }
    return ret;
}

util::Vector<float> SemPass1::get_array_constInitValsf(SysYParser::ConstInitValContext *ctx, util::Vector<int> dims, util::Vector<int> dimSize, int d) {
    util::Vector<float> ret;
    if(ctx->constExp()) {
        ctx->constExp()->accept(this);
        Temp n = tempStack.top();tempStack.pop();
        knpc_assert(n->isConst);
        // knpc_assert(n->isFloat); // must be a float? no! TODO:implicit convert! from int to float!
        if(n->isFloat) ret.push_back(n->ctvalf);
        else ret.push_back(n->ctval);
    } else {
        for(auto it : ctx->constInitVal()) {
            util::Vector<float> temp = get_array_constInitValsf(it, dims, dimSize, d + 1); // dfs
            for(size_t i = 0; i < temp.size(); i++) {
                ret.push_back(temp[i]);
            }
        }
        int j = ret.size();
        while(j < dims[d] * dimSize[d]) { // pad zero in a { }
            ret.push_back(0.0);
            j++;
        }
    }
    return ret;
}

util::Vector<Temp> SemPass1::get_array_initVals(SysYParser::InitValContext *ctx, util::Vector<int> dims, util::Vector<int> dimSize, int d) {
    util::Vector<Temp> ret;
    if(ctx->exp()) {
        ctx->exp()->accept(this);
        Temp n = tempStack.top();tempStack.pop();
        ret.push_back(n);
    } else {
        for(auto it : ctx->initVal()) {
            util::Vector<Temp> temp = get_array_initVals(it, dims, dimSize, d + 1); // dfs
            for(size_t i = 0; i < temp.size(); i++) {
                ret.push_back(temp[i]);
            }
        }
        int j = ret.size();
        while(j < dims[d] * dimSize[d]) { // pad zero in a { }
            Temp imm = tr->genLoadImm4NoChainUp(0);
            ret.push_back(imm);
            j++;
        }
    }
    return ret;
}

util::Vector<Temp> SemPass1::get_array_initValsf(SysYParser::InitValContext *ctx, util::Vector<int> dims, util::Vector<int> dimSize, int d) {
    util::Vector<Temp> ret;
    if(ctx->exp()) {
        ctx->exp()->accept(this);
        Temp n = tempStack.top();tempStack.pop();
        ret.push_back(n);
    } else {
        for(auto it : ctx->initVal()) {
            util::Vector<Temp> temp = get_array_initValsf(it, dims, dimSize, d + 1); // dfs
            for(size_t i = 0; i < temp.size(); i++) {
                ret.push_back(temp[i]);
            }
        }
        int j = ret.size();
        while(j < dims[d] * dimSize[d]) { // pad zero in a { }
            Temp imm = tr->genLoadImm4FNoChainUp(0.0);
            ret.push_back(imm);
            j++;
        }
    }
    return ret;
}

void SemPass1::initRunTimeLabels() { // 9 runtime library functions
    runtimeLabels[0] = tr->getNewEntryLabel("getint");
    runtimeLabels[1] = tr->getNewEntryLabel("getch");
    runtimeLabels[2] = tr->getNewEntryLabel("getarray");
    runtimeLabels[3] = tr->getNewEntryLabel("putint");
    runtimeLabels[4] = tr->getNewEntryLabel("putch");
    runtimeLabels[5] = tr->getNewEntryLabel("putarray");
    runtimeLabels[6] = tr->getNewEntryLabel("putf");
    runtimeLabels[7] = tr->getNewEntryLabel("_sysy_starttime");
    runtimeLabels[8] = tr->getNewEntryLabel("_sysy_stoptime");
    runtimeLabels[9] = tr->getNewEntryLabel("memset");
    runtimeLabels[10] = tr->getNewEntryLabel("getfloat");
    runtimeLabels[11] = tr->getNewEntryLabel("getfarray");
    runtimeLabels[12] = tr->getNewEntryLabel("putfloat");
    runtimeLabels[13] = tr->getNewEntryLabel("putfarray");
    runtimeLabels[14] = tr->getNewEntryLabel("__aeabi_f2iz");
    runtimeLabels[15] = tr->getNewEntryLabel("__aeabi_i2f");
}

void SemPass1::callMemset(Temp addr, Temp val, Temp size) { // assign n bytes starting from addr as val
    tr->genParam(addr);
    tr->genParam(val);
    tr->genParam(size);
    tr->genCall(runtimeLabels[9]);
}

Temp SemPass1::callFloat2Int(Temp src) { // call this function to convert from float to int
    knpc_assert(src->isFloat);
    if(src->isConst) {
        return tr->genLoadImm4(src->ctvalf);
    } else {
        tr->genParam(src);
        return tr->genCall(runtimeLabels[14]);
    }
}

Temp SemPass1::callInt2Float(Temp src) { // call this function to convert from int to float
    knpc_assert(!src->isFloat);
    if(src->isConst) {
        return tr->genLoadImm4F(src->ctval);
    } else {
        tr->genParam(src);
        return tr->genCall(runtimeLabels[15]); // TODO: Need to modify in genCall for float support!
    }
}

antlrcpp::Any SemPass1::visitProgram(SysYParser::ProgramContext *ctx) {
    initRunTimeLabels();
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

antlrcpp::Any SemPass1::visitConstDef(SysYParser::ConstDefContext *ctx) {            // const
    std::string name = ctx->Identifier()->getText();
    Variable *sym;
    util::Vector<int> dims;
    if(ctx->constExpLi()) { // is array variable
        dims = get_array_dims(ctx->constExpLi());
        Type *arrayType = new ArrayType(p_type, dims);
        sym = new Variable(name, arrayType);
    } else {                // is base variable
        sym = new Variable(name, p_type);
    }
    Symbol *s = scopes->lookup(name, false); // symbol name check
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    // const variable must be init here.
    knpc_assert(ctx->constInitVal());
    if(sym->getType()->isBaseType()) {                                              // 1 base type
        ctx->constInitVal()->accept(this);
        Temp n = tempStack.top();tempStack.pop();
        knpc_assert(n->isConst); // must be a const
        util::Vector<int> initVal;
        initVal.push_back(n->ctval);
        sym->setConst();
        sym->setGlobalInit(initVal);
        if(sym->isGlobalVar()) {                                                    // 1.1 basetype && global
            tr->genGlobalVarible(name, n->ctval, sym->getType()->getSize(), true);
        } else {                                                                    // 1.2 basetype && local
            Temp imm = tr->genLoadImm4(n->ctval);
            sym->attachTemp(imm); // if not global, alloc a temp variable to it
        } // don't need? yes! have const propagation now. but will not effect performance, will be eliminated in dead code elimination.
    } else {                                                                        // 2 array type
        util::Vector<int> dimSize;
        int c_dim = 1;
        for(auto it = dims.rbegin();
        it != dims.rend(); it++) {
            dimSize.insert(dimSize.begin(), c_dim);
            c_dim = c_dim * (*it); 
        }
        util::Vector<int> initVals = get_array_constInitVals(ctx->constInitVal(), dims, dimSize, 0);
        sym->setConst();
        sym->setGlobalInit(initVals);
        int tag = 0;
        for(int i : initVals) {
            if(i != 0) tag = 1;
        }
        if(tag == 0) initVals.clear(); // if all zero then bss
        #ifdef debug_on
        printf("The array init values are: "); // debug
        for(size_t i = 0; i < initVals.size(); i++) printf("%d ", initVals[i]); // debug
        #endif
        if(sym->isGlobalVar()) {                                                    // 2.1 arraytype && global
            tr->genGlobalArray(name, initVals, sym->getType()->getSize(), true);
        } else {                                                                    // 2.2 arraytype && local
            int offset = 0;
            Temp arr = tr->allocNewTempI4(sym->getType()->getSize()); // alloc space in stack
            arr->isConst = true;
            sym->attachTemp(arr);
            Temp val = tr->genLoadImm4(0);
            Temp size = tr->genLoadImm4(sym->getType()->getSize()); // no need to *4, already bytes size
            callMemset(arr, val, size); // use memset to optimize codeGen
            for(int initVal : initVals) {
                if(initVal != 0) {
                    Temp x = tr->genLoadImm4(initVal);
                    tr->genStore(x, arr, offset); // store initVals to arr in stack
                }
                offset += 4;
            }
        } // don't need? no! if the index is not a const!
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitConstInitVal(SysYParser::ConstInitValContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitVarDef(SysYParser::VarDefContext *ctx) {// not const
    std::string name = ctx->Identifier()->getText();
    Variable *sym;
    util::Vector<int> dims;
    if(ctx->constExpLi()) {
        dims = get_array_dims(ctx->constExpLi());
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
    if(ctx->initVal()) {                                           // has initVal
        if(sym->getType()->isBaseType()) {                         // 1 base type
            ctx->initVal()->accept(this);
            Temp n = tempStack.top();tempStack.pop();
            if(sym->isGlobalVar()) {                               // 1.1 basetype && global
                if(n->isConst) {
                    tr->genGlobalVarible(name, n->ctval, sym->getType()->getSize(), false);
                } else {
                    tr->genGlobalVarible(name, 0, sym->getType()->getSize(), false);
                    Temp val = tr->genLoadSymbol(name);
                    tr->genStore(n, val, 0);
                }
            } else {                                               // 1.2 basetype && local
                sym->attachTemp(tr->getNewTempI4()); // get local object then assign
                tr->genAssign(sym->getTemp(), n);
            }
        } else {                                                   // 2 array type
            util::Vector<int> dimSize;
            int c_dim = 1;
            for(auto it = dims.rbegin();
            it != dims.rend(); it++) {
                dimSize.insert(dimSize.begin(), c_dim);
                c_dim = c_dim * (*it); 
            }
            util::Vector<Temp> initVals = get_array_initVals(ctx->initVal(), dims, dimSize, 0);
            if(sym->isGlobalVar()) {                               // 2.1 arraytype && global
                util::Vector<int> vals;
                int tag = 0;
                for(size_t i = 0; i < initVals.size(); i++) {
                    // knpc_assert(initVals[i]->isConst);
                    vals.push_back(initVals[i]->ctval);
                    if(initVals[i]->ctval != 0) tag = 1;
                }
                if(tag == 0) vals.clear(); // if all zero then bss
                tr->genGlobalArray(name, vals, sym->getType()->getSize(), false); 
                // TODO: global arr's initval must be const? no, but must has a init val
                // here if use genStore to assign initval, the code where be generated nowhere(because not in a function)

                // Temp n = tr->genLoadSymbol(name);
                // int offset = 0;
                // for(Temp initVal : initVals) {
                //     tr->genStore(initVal, n, offset);
                //     offset += 4;
                // }
            } else {                                               // 2.2 arraytype && local
                int offset = 0;
                Temp arr = tr->allocNewTempI4(sym->getType()->getSize());
                sym->attachTemp(arr);
                Temp val = tr->genLoadImm4(0);
                Temp size = tr->genLoadImm4(sym->getType()->getSize());
                callMemset(arr, val, size); // use memset to optimize codeGen
                for(Temp initVal : initVals) {
                    if(initVal->isConst && initVal->ctval == 0) {
                        ;
                    } else {
                        tr->genStore(initVal, arr, offset);
                    }
                    offset += 4;
                }
            }
        }
    } else {                                                        // no init val
        if(sym->getType()->isBaseType()) {                          // 1 base type
            if(sym->isGlobalVar()) {                                // 1.1 basetype && global
                tr->genGlobalVarible(name, 0, sym->getType()->getSize(), false); // initVal is 0
            } else {                                                // 1.2 basetype && local
                sym->attachTemp(tr->getNewTempI4());
            }
        } else {                                                    // 2 array type
            if(sym->isGlobalVar()) {                                // 2.1 arraytype && global
                util::Vector<int> p; // p is empty
                tr->genGlobalArray(name, p, sym->getType()->getSize(), false); // initVal is 0
            } else {                                                // 2.2 arraytype && local
                sym->attachTemp(tr->allocNewTempI4(sym->getType()->getSize()));
            }
        }
    }
    return nullptr;
}    

antlrcpp::Any SemPass1::visitInitVal(SysYParser::InitValContext *ctx) {
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

    RESET_OFFSET();
    order = 0;    
    if(ctx->funcFParams()) ctx->funcFParams()->accept(this); // formal params

    sym->offset = sym->getOrder()*POINTER_SIZE;
    
    tr->startFunc(sym);
    ctx->block()->accept(this);
    // here must have a return val, or will not return even if the type is "void"
    // will error in generate_basic_block otherwise
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
    return ctx->constExp().size();
}

antlrcpp::Any SemPass1::visitExpLi(SysYParser::ExpLiContext *ctx) {
    for(auto it : ctx->exp()) {
        it->accept(this);
    }
    return ctx->exp().size();
}

antlrcpp::Any SemPass1::visitConstExp(SysYParser::ConstExpContext *ctx) {
    visitChildren(ctx);
    knpc_assert(tempStack.top()->isConst);
    return nullptr;
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
    Variable *sym;
    if(ctx->constExpLi()) { // is array type
        util::Vector<int> dims = get_array_dims(ctx->constExpLi());
        dims.insert(dims.begin(), 0); // first dim length can be assigned as 0, won't influence correctness in assign stmt.
        Type *arrayType = new ArrayType(p_type, dims);
        sym = new Variable(name, arrayType);
    } else if(ctx->getText().find("[") != std::string::npos) { // is array type
        util::Vector<int> dims;
        dims.push_back(0);
        Type *arrayType = new ArrayType(p_type, dims);
        sym = new Variable(name, arrayType);
    } else {
        sym = new Variable(name, p_type);
    }
    Symbol *s = scopes->lookup(name, false); // symbol check
    if(s != NULL) {
        throw new DeclConflictError(name, sym);
    }
    scopes->declare(sym);
    sym->setOrder(order++);
    sym->attachTemp(tr->getNewTempI4()); // if array, will pass pointer(head address), so also I4
    sym->offset = NEXT_OFFSET(sym->getTemp()->size);
    sym->setParameter();
    return nullptr;
}

antlrcpp::Any SemPass1::visitFuncRParams(SysYParser::FuncRParamsContext *ctx) {
    util::Vector<Temp> params;
    for(auto it : ctx->exp()) {
        it->accept(this);
        Temp n = tempStack.top();tempStack.pop();
        params.push_back(n);
    }
    for(size_t i = 0; i < ctx->exp().size(); i++) {
        tr->genParam(params[i]); // from left to right, push into stack
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitBlock(SysYParser::BlockContext *ctx) {
    Scope *blockScope = new LocalScope();
    scopes->open(blockScope);
    visitChildren(ctx); // add local scope here
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
    knpc_assert(ctx->cond());
    ctx->cond()->accept(this);
    Temp n = tempStack.top();tempStack.pop();
    if(n->isConst) { // constant folding
        if(n->ctval) { // true branch
            auto it = ctx->stmt()[0];
            knpc_assert(it);
            it->accept(this);
        } else { // false branch
            auto it = ctx->stmt()[1];
            if(it) it->accept(this);
        }
    } else {
        Label L1 = tr->getNewLabel();
        Label L2 = tr->getNewLabel();
        tr->genJumpOnZero(L1, n);
        { // true branch
            auto it = ctx->stmt()[0];
            knpc_assert(it);
            it->accept(this);
        }
        tr->genJump(L2);
        tr->genMarkLabel(L1);
        { // false branch
            auto it = ctx->stmt()[1];
            if(it) it->accept(this);
        }
        tr->genMarkLabel(L2);
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitExpStmt (SysYParser::ExpStmtContext *ctx) {
    visitChildren(ctx);
    if(ctx->exp()) tempStack.pop(); // remove redundant value
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
    knpc_assert(ctx->cond());
    ctx->cond()->accept(this);
    Temp n = tempStack.top();tempStack.pop();
    if(n->isConst) {
        if(n->ctval) { // always true, in this case, cond()'s compute is unneed, and it will be removed in alive val analysis, so there's no influence.  
            if(ctx->stmt()) ctx->stmt()->accept(this);
            tr->genJump(L1);
        } else { // always false
            ;
        }
    } else {
        tr->genJumpOnZero(L2, n); // if flase goto L2, loop end
        if(ctx->stmt()) ctx->stmt()->accept(this);
        tr->genJump(L1);
        tr->genMarkLabel(L2);
    }
    
    current_break_label = old_break; // restore break&continue label
    current_continue_label = old_continue;
    return nullptr;
}

antlrcpp::Any SemPass1::visitReturnStmt (SysYParser::ReturnStmtContext *ctx) {
    if(ctx->exp()) {
        ctx->exp()->accept(this);
        tr->genReturn(tempStack.top());
        tempStack.pop();
    } else {
        tr->genReturn(tr->genLoadImm4(0)); // must gen return tac here!
    }
    return nullptr;
}   

antlrcpp::Any SemPass1::visitContinueStmt (SysYParser::ContinueStmtContext *ctx) {
    // "continue" here, but nothing to do in symbtable
    tr->genJump(current_continue_label);
    return nullptr;
}

antlrcpp::Any SemPass1::visitAssignment (SysYParser::AssignmentContext *ctx) {
    // differ according to the lval(array? global?)
    // need to do implicit conversion here between int and float!
    ctx->exp()->accept(this);
    Temp r = tempStack.top();tempStack.pop(); // right_val
    size_t r_dim = ctx->lVal()->accept(this);
    Variable *sym = (Variable *)(scopes->lookup(p_name, true));
    if(sym->getType()->isArrayType()) {
        ArrayType *c_type = (ArrayType *)(sym->getType());
        knpc_assert(r_dim == c_type->getLength().size());
        // if array as assignment's left val, must locate to a single element
    }
    if(sym->isGlobalVar()) {                                       // 1 global val
        Temp n = tr->genLoadSymbol(p_name);
        if(sym->getType()->isArrayType()) {                        // 1.1 global && arraytype
            int c_dim = 4;
            Temp x, y;
            ArrayType *c_type = (ArrayType *)(sym->getType());
            for(int it = c_type->getLength().size() - 1;
            it >= 0; it--) {
                x = tr->genLoadImm4(c_dim);
                y = tr->genMul(x, tempStack.top());tempStack.pop();
                n = tr->genAdd(n, y);
                c_dim = c_dim*(c_type->getLength()[it]);
            }
            tr->genStore(r, n, 0);
        } else {                                                   // 1.2 global && basetype
            tr->genStore(r, n, 0);
        }
    } else {                                                       // 2 local val 
        Temp n = sym->getTemp();
        if(sym->getType()->isArrayType()) {                        // 2.1 local && arraytype
            int c_dim = 4;
            Temp x, y;
            ArrayType *c_type = (ArrayType *)(sym->getType());
            for(int it = c_type->getLength().size() - 1;
            it >= 0; it--) {
                x = tr->genLoadImm4(c_dim);
                y = tr->genMul(x, tempStack.top());tempStack.pop();
                n = tr->genAdd(n, y);
                c_dim = c_dim*(c_type->getLength()[it]);
            }
            tr->genStore(r, n, 0);
        } else {
            tr->genAssign(n, r);
        }
    }
    return nullptr;
}

antlrcpp::Any SemPass1::visitCond(SysYParser::CondContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitLVal(SysYParser::LValContext *ctx) {
    std::string name = ctx->Identifier()->getText();
    size_t ret = 0;
    if(ctx->expLi()) {
        ret = ctx->expLi()->accept(this);
    }
    p_name = name;
    return ret;
}

antlrcpp::Any SemPass1::visitPrimary1(SysYParser::Primary1Context *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitPrimary2(SysYParser::Primary2Context *ctx) {
    // must deal with const in this function!!!
    size_t r_dim = ctx->lVal()->accept(this); // not always r_dim == array dim
    Temp n;
    Variable *sym = (Variable *)(scopes->lookup(p_name, true));
    if(sym->isGlobalVar()) {                                    // 1 global val
        n = tr->genLoadSymbol(p_name);
        if(sym->getType()->isArrayType()) {                     // 1.1 global && arraytype
            Temp x, y;
            int tag = 0;
            ArrayType *c_type = (ArrayType *)(sym->getType());
            util::Vector<int> dimSize;
            util::Vector<int> dims = c_type->getLength();
            util::Vector<Temp> nums;
            int c_dim = 4;
            for(auto it = dims.rbegin();
            it != dims.rend(); it++) {
                dimSize.insert(dimSize.begin(), c_dim);
                c_dim = c_dim * (*it); 
            }
            for(int i = r_dim - 1; i >= 0; i--) {
                Temp tmp = tempStack.top();tempStack.pop();
                if(!tmp->isConst) tag = 1;
                nums.insert(nums.begin(), tmp);
            }
            if(sym->isConst() && tag == 0 && r_dim == c_type->getLength().size()) { // 1.1.1 global array && const
                int index = 0;
                for(int i = r_dim - 1; i >= 0; i--) {
                    index += nums[i]->ctval * (dimSize[i] / 4);
                }
                n = tr->genLoadImm4(sym->getGlobalInit(index));
            } else {                                                                // 1.1.2 global array not const
                for(int i = r_dim - 1; i >= 0; i--) {
                    x = tr->genLoadImm4(dimSize[i]);
                    y = tr->genMul(x, nums[i]);
                    n = tr->genAdd(n, y);
                }
                if(r_dim == c_type->getLength().size()) n = tr->genLoad(n, 0); // only dim equal should load data
            }
        } else {                                                 // 1.2 global && basetype
            if(sym->isConst()) {
                n = tr->genLoadImm4(sym->getGlobalInit(0));
            } else {
                n = tr->genLoad(n, 0);
            }
        }
    } else {                                                     // 2 local val
        n = sym->getTemp();
        if(sym->getType()->isArrayType()) {                      // 2.1 local && arraytype
            Temp x, y;
            int tag = 0;
            ArrayType *c_type = (ArrayType *)(sym->getType());
            util::Vector<int> dimSize;
            util::Vector<int> dims = c_type->getLength();
            util::Vector<Temp> nums;
            int c_dim = 4;
            for(auto it = dims.rbegin();
            it != dims.rend(); it++) {
                dimSize.insert(dimSize.begin(), c_dim);
                c_dim = c_dim * (*it); 
            }
            for(int i = r_dim - 1; i >= 0; i--) {
                Temp tmp = tempStack.top();tempStack.pop();
                if(!tmp->isConst) tag = 1;
                nums.insert(nums.begin(), tmp);
            }
            if(sym->isConst() && tag == 0 && r_dim == c_type->getLength().size()) { // 2.1.1 local array && const
                int index = 0;
                for(int i = r_dim - 1; i >= 0; i--) {
                    index += nums[i]->ctval * (dimSize[i] / 4);
                }
                n = tr->genLoadImm4(sym->getGlobalInit(index));
            } else {                                                                // 2.1.2 local array not const
                for(int i = r_dim - 1; i >= 0; i--) {
                    x = tr->genLoadImm4(dimSize[i]);
                    y = tr->genMul(x, nums[i]);
                    n = tr->genAdd(n, y);
                }
                if(r_dim == c_type->getLength().size()) n = tr->genLoad(n, 0); // only dim equal should load data
            }
        } else {                                                  // 2.2 local && basetype
            if(sym->isConst()) {
                n = tr->genLoadImm4(sym->getGlobalInit(0));
            }
        }
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
    } else if(ctx->Octal()) {
        std::string str = ctx->Octal()->getText();
        int ans = 0, len = str.length();
        for(int i = 1; i < len; ++i) ans = ans*8 + (str[i]^48);
        n = tr->genLoadImm4(ans);
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
    } else {
        std::string str = ctx->FloatLiteral()->getText();
        n = tr->genLoadImm4(0); // TODO: Float here! now return 0
        n->ctval = 0;
        n->isConst = true;
    }
    tempStack.push(n);
    return nullptr;
}

antlrcpp::Any SemPass1::visitUnary1(SysYParser::Unary1Context *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any SemPass1::visitUnary2(SysYParser::Unary2Context *ctx) {
    visitChildren(ctx); // 1. set params
    std::string name = ctx->Identifier()->getText();
    Temp n;
    if(name == "getint") {
        n = tr->genCall(runtimeLabels[0]);
    } else if(name == "getch") {
        n = tr->genCall(runtimeLabels[1]);
    } else if(name == "getarray") {
        n = tr->genCall(runtimeLabels[2]);
    } else if(name == "putint") {
        n = tr->genCall(runtimeLabels[3]);
    } else if(name == "putch") {
        n = tr->genCall(runtimeLabels[4]);
    } else if(name == "putarray") {
        n = tr->genCall(runtimeLabels[5]);
    } else if(name == "putf") {
        n = tr->genCall(runtimeLabels[6]);
    } else if(name == "starttime") {
        n = tr->genCall(runtimeLabels[7]);
    } else if(name == "stoptime") {
        n = tr->genCall(runtimeLabels[8]);
    } else if(name == "memset") {
        n = tr->genCall(runtimeLabels[9]);
    } else if(name == "getfloat") {
        n = tr->genCall(runtimeLabels[10]);
    } else if(name == "getfarray") {
        n = tr->genCall(runtimeLabels[11]);
    } else if(name == "putfloat") {
        n = tr->genCall(runtimeLabels[12]);
    } else if(name == "putfarray") {
        n = tr->genCall(runtimeLabels[13]);
    } else {
        Function *sym = (Function *)(scopes->lookup(name, true));
        knpc_assert(sym);
        n = tr->genCall(sym->getEntryLabel()); // 2. call function
    }
    tempStack.push(n);
    return nullptr;
}

antlrcpp::Any SemPass1::visitUnary3(SysYParser::Unary3Context *ctx) {
    ctx->unaryExp()->accept(this); // first visit exp, then visit op
    ctx->unaryOp()->accept(this);
    Temp r = tempStack.top();tempStack.pop();
    Temp n;
    if(r->isConst) {
        if(p_unaryOp == 0) {
            n = r;
        } else if(p_unaryOp == 1) {
            n = tr->genLoadImm4(-1*r->ctval);
        } else {
            n = tr->genLoadImm4(r->ctval == 0); // seqz
        }
    } else {
        if(p_unaryOp == 0) {
            n = r;
        } else if(p_unaryOp == 1) {
            n = tr->genNeg(r);
        } else {
            n = tr->genLNot(r); // seqz
        }
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
        ctx->mulExp()->accept(this);
        ctx->unaryExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        Temp l = tempStack.top();tempStack.pop();
        if(r->isConst && l->isConst) {
            if(ctx->children[1]->getText()[0] == '*') {
                n = tr->genLoadImm4(l->ctval*r->ctval);
            } else if(ctx->children[1]->getText()[0] == '/') {
                knpc_assert(r->ctval);
                n = tr->genLoadImm4(l->ctval / r->ctval);
            } else {
                knpc_assert(r->ctval);
                n = tr->genLoadImm4(l->ctval % r->ctval);
            }
        } else {
            if(ctx->children[1]->getText()[0] == '*') {
                n = tr->genMul(l, r);
            } else if(ctx->children[1]->getText()[0] == '/') {
                n = tr->genDiv(l, r);
            } else {
                n = tr->genMod(l, r);
            }
        }
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
        ctx->addExp()->accept(this);
        ctx->mulExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        Temp l = tempStack.top();tempStack.pop();
        if(r->isConst && l->isConst) {
            if(ctx->children[1]->getText()[0] == '+') {
                n = tr->genLoadImm4(l->ctval + r->ctval);
            } else {
                n = tr->genLoadImm4(l->ctval - r->ctval);
            }
        } else {
            if(ctx->children[1]->getText()[0] == '+') {
                n = tr->genAdd(l, r);
            } else {
                n = tr->genSub(l, r);
            }
        }
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
        ctx->relExp()->accept(this);
        ctx->addExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        Temp l = tempStack.top();tempStack.pop();
        if(r->isConst && l->isConst) {
            if(ctx->children[1]->getText()[0] == '<') { // <
                if(ctx->children[1]->getText().length() == 1) {
                    n = tr->genLoadImm4(l->ctval < r->ctval);
                }    
                else {
                    n = tr->genLoadImm4(l->ctval <= r->ctval);
                }
            } else { // >
                if(ctx->children[1]->getText().length() == 1) {
                    n = tr->genLoadImm4(l->ctval > r->ctval);
                }
                else {
                    n = tr->genLoadImm4(l->ctval >= r->ctval);
                }
            }
        } else {
            if(ctx->children[1]->getText()[0] == '<') { // <
                if(ctx->children[1]->getText().length() == 1) {
                    n = tr->genLes(l, r);
                }    
                else {
                    n = tr->genLeq(l, r);
                }
            } else { // >
                if(ctx->children[1]->getText().length() == 1) {
                    n = tr->genGtr(l, r);
                }
                else {
                    n = tr->genGeq(l, r);
                }
            }
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
        ctx->eqExp()->accept(this);
        ctx->relExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        Temp l = tempStack.top();tempStack.pop();
        if(r->isConst && l->isConst) {
            if(ctx->children[1]->getText()[0] == '=') {
                n = tr->genLoadImm4(l->ctval == r->ctval);
            } else {
                n = tr->genLoadImm4(l->ctval != r->ctval);
            }
        } else {
            if(ctx->children[1]->getText()[0] == '=') {
                n = tr->genEqu(l, r);
            } else {
                n = tr->genNeq(l, r);
            }
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
antlrcpp::Any SemPass1::visitLAndExp(SysYParser::LAndExpContext *ctx) {
    Temp n;
    if(ctx->lAndExp()) { // TODO: const propagation
        ctx->lAndExp()->accept(this); // compute lreg
        Temp l = tempStack.top();tempStack.pop();
        if(l->isConst) {              // if lreg is const
            if(l->ctval == 0) {
                n = tr->genLoadImm4(0);
            } else {                  // lreg is 1, the result depends on rreg
                ctx->eqExp()->accept(this); // compute rreg
                Temp r = tempStack.top();tempStack.pop();
                n = r;
            }
        } else {
            Temp v = tr->getNewTempI4();
            tr->genAssign(v, l);
            Label label = tr->getNewLabel();
            tr->genJumpOnZero(label, l); // if left val false, jump
            {
                ctx->eqExp()->accept(this); // compute rreg
                Temp r = tempStack.top();tempStack.pop();
                n = tr->genLAnd(l, r); // get "and" result use lreg, rreg
                tr->genAssign(v, n);   // assign result to vreg
            }
            tr->genMarkLabel(label); // jump here, not compute rreg
            n = v; // return vreg
        }
    } else {
        ctx->eqExp()->accept(this);
        Temp r = tempStack.top();tempStack.pop();
        n = r;
    }
    tempStack.push(n);
    return nullptr;
}

antlrcpp::Any SemPass1::visitLOrExp(SysYParser::LOrExpContext *ctx) {
    Temp n;
    if(ctx->lOrExp()) { // TODO: const propagation
        ctx->lOrExp()->accept(this);
        Temp l = tempStack.top();tempStack.pop();
        if(l->isConst) {
            if(l->ctval != 0) {
                n = tr->genLoadImm4(1);
            } else {                  // lreg is 0, the result depends on rreg
                ctx->lAndExp()->accept(this);
                Temp r = tempStack.top();tempStack.pop();
                n = r;
            }
        } else {
            Temp v = tr->getNewTempI4();
            tr->genAssign(v, l);
            Label label = tr->getNewLabel();
            Temp nl = tr->genLNot(l);
            tr->genJumpOnZero(label, nl);
            {
                ctx->lAndExp()->accept(this);
                Temp r = tempStack.top();tempStack.pop();
                n = tr->genLOr(l, r);
                tr->genAssign(v, n);
            }
            tr->genMarkLabel(label);
            n = v;
        }
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
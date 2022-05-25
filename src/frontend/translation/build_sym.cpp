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
    // visit declarations
    virtual antlrcpp::Any visitProgram(SysYParser::ProgramContext *ctx) override;
    virtual antlrcpp::Any visitCompUnit(SysYParser::CompUnitContext *ctx) override;
    virtual antlrcpp::Any visitDecl(SysYParser::DeclContext *cex) override;
    virtual antlrcpp::Any visitConstDecl(SysYParser::ConstDeclContext *ctx) override;
    virtual antlrcpp::Any visitVarDecl(SysYParser::VarDeclContext *ctx) override;
    virtual antlrcpp::Any visitFuncDef(SysYParser::FuncDefContext *ctx) override;
    // visit types
    virtual antlrcpp::Any visitBType(SysYParser::BTypeContext *ctx) override;
};

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
    Type *t = NULL;
    bool isFloat = false;
    if(ctx->bType()->accept(this) == 0) {
        isFloat = false;
    } else {
        isFloat = true;
    }
    int len = ctx->constDefLi()->accept(this);
    if(len == 0) {
        if(isFloat) t = BaseType::Float;
        else t = BaseType::Int;
    } else {
        if(isFloat) t = new ArrayType(BaseType::Float, len);
        else t = new ArrayType(BaseType::Int, len);
    }
    // TODO: now only implement one dim array

    // insert into symboltable
    
    return nullptr;
}

// visit var decl node
antlrcpp::Any SemPass1::visitVarDecl(SysYParser::VarDeclContext *ctx) {

    return nullptr;
}

// visit btype node
antlrcpp::Any visitBType(SysYParser::BTypeContext *ctx) {
    return ctx->getRuleIndex();
}

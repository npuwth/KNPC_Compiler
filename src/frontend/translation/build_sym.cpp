/**
 * @file build_sym.cpp
 * @author your name (you@domain.com)
 * @brief 1st PASS of semantic analysis
 * @version 0.1
 * @date 2022-05-21
 * 
 * @copyright Copyright (c) 2022
 * 
 * After this pass, the symbol table will be constructed!
 */

#include "SysYBaseVisitor.h"

#include<memory>

class SemPass1 : public SysYVisitor {
    // visit declarations
    virtual antlrcpp::Any visitProgram(SysYParser::ProgramContext *context);
    virtual antlrcpp::Any visitCompUnit(SysYParser::CompUnitContext *context);
    virtual antlrcpp::Any visitDecl(SysYParser::DeclContext *context);
    virtual antlrcpp::Any visitConstDecl(SysYParser::ConstDeclContext *context);
    virtual antlrcpp::Any visitVarDecl(SysYParser::VarDeclContext *context);
    virtual antlrcpp::Any visitFuncDef(SysYParser::FuncDefContext *context);
    // visit types
    virtual antlrcpp::Any visitBType(SysYParser::BTypeContext *context);
}

// visit program node
antlrcpp::Any visitProgram(SysYParser::ProgramContext *context) {
    for(auto it = context->compUnit()->begin();
    it != context->CompUnit->end(); ++it) {
        (*it)->accept(this);
    }
    return nullptr;
}

// visit compunit node
antlrcpp::Any visitCompUnit(SysYParser::CompUnitContext *context) {
    context->funcDef()->accept(this);
    context->decl()->accept(this);
    context->compUnit()->accept(this);
    return nullptr;
}

// visit decl node
antlrcpp::Any visitDecl(SysYParser::DeclContext *context) {
    context->constDecl()->accept(this);
    context->varDecl()->accept(this);
    return nullptr;
}

// visit const decl node
antlrcpp::Any visitConstDecl(SysYParser::ConstDeclContext *context) {
    Type t = context->bType()->visit(this);
    string name = context->
}

// visit 
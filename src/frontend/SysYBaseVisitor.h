
// Generated from SysY.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "SysYVisitor.h"


/**
 * This class provides an empty implementation of SysYVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SysYBaseVisitor : public SysYVisitor {
public:
    
  virtual std::any visitProgram(SysYParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompUnit(SysYParser::CompUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(SysYParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(SysYParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBType(SysYParser::BTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDefLi(SysYParser::ConstDefLiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDef(SysYParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleConstInitVal(SysYParser::SingleConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListConstInitVal(SysYParser::ListConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstInitValLi(SysYParser::ConstInitValLiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExpLi(SysYParser::ConstExpLiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(SysYParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDefLi(SysYParser::VarDefLiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUninitVarDef(SysYParser::UninitVarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitVarDef(SysYParser::InitVarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleInitVal(SysYParser::SingleInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListInitVal(SysYParser::ListInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitValLi(SysYParser::InitValLiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(SysYParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncType(SysYParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFParams(SysYParser::FuncFParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFParam(SysYParser::FuncFParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpLi(SysYParser::ExpLiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(SysYParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItemLi(SysYParser::BlockItemLiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItem(SysYParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignStmt(SysYParser::AssignStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpStmt(SysYParser::ExpStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockStmt(SysYParser::BlockStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(SysYParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(SysYParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStmt(SysYParser::BreakStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStmt(SysYParser::ContinueStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(SysYParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp(SysYParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCond(SysYParser::CondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLVal(SysYParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesizedExp(SysYParser::ParenthesizedExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLvalExp(SysYParser::LvalExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberExp(SysYParser::NumberExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(SysYParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpWithoutOp(SysYParser::UnaryExpWithoutOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(SysYParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpWithOp(SysYParser::UnaryExpWithOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOp(SysYParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncRParams(SysYParser::FuncRParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulExp(SysYParser::MulExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddExp(SysYParser::AddExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelExp(SysYParser::RelExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqExp(SysYParser::EqExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLAndExp(SysYParser::LAndExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLOrExp(SysYParser::LOrExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExp(SysYParser::ConstExpContext *ctx) override {
    return visitChildren(ctx);
  }


};


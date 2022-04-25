
// Generated from SysY.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"
#include "SysYParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SysYParser.
 */
class  SysYVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SysYParser.
   */
    virtual std::any visitProgram(SysYParser::ProgramContext *context) = 0;

    virtual std::any visitCompUnit(SysYParser::CompUnitContext *context) = 0;

    virtual std::any visitDecl(SysYParser::DeclContext *context) = 0;

    virtual std::any visitConstDecl(SysYParser::ConstDeclContext *context) = 0;

    virtual std::any visitBType(SysYParser::BTypeContext *context) = 0;

    virtual std::any visitConstDefLi(SysYParser::ConstDefLiContext *context) = 0;

    virtual std::any visitConstDef(SysYParser::ConstDefContext *context) = 0;

    virtual std::any visitSingleConstInitVal(SysYParser::SingleConstInitValContext *context) = 0;

    virtual std::any visitListConstInitVal(SysYParser::ListConstInitValContext *context) = 0;

    virtual std::any visitConstInitValLi(SysYParser::ConstInitValLiContext *context) = 0;

    virtual std::any visitConstExpLi(SysYParser::ConstExpLiContext *context) = 0;

    virtual std::any visitVarDecl(SysYParser::VarDeclContext *context) = 0;

    virtual std::any visitVarDefLi(SysYParser::VarDefLiContext *context) = 0;

    virtual std::any visitUninitVarDef(SysYParser::UninitVarDefContext *context) = 0;

    virtual std::any visitInitVarDef(SysYParser::InitVarDefContext *context) = 0;

    virtual std::any visitSingleInitVal(SysYParser::SingleInitValContext *context) = 0;

    virtual std::any visitListInitVal(SysYParser::ListInitValContext *context) = 0;

    virtual std::any visitInitValLi(SysYParser::InitValLiContext *context) = 0;

    virtual std::any visitFuncDef(SysYParser::FuncDefContext *context) = 0;

    virtual std::any visitFuncType(SysYParser::FuncTypeContext *context) = 0;

    virtual std::any visitFuncFParams(SysYParser::FuncFParamsContext *context) = 0;

    virtual std::any visitFuncFParam(SysYParser::FuncFParamContext *context) = 0;

    virtual std::any visitExpLi(SysYParser::ExpLiContext *context) = 0;

    virtual std::any visitBlock(SysYParser::BlockContext *context) = 0;

    virtual std::any visitBlockItemLi(SysYParser::BlockItemLiContext *context) = 0;

    virtual std::any visitBlockItem(SysYParser::BlockItemContext *context) = 0;

    virtual std::any visitAssignStmt(SysYParser::AssignStmtContext *context) = 0;

    virtual std::any visitExpStmt(SysYParser::ExpStmtContext *context) = 0;

    virtual std::any visitBlockStmt(SysYParser::BlockStmtContext *context) = 0;

    virtual std::any visitIfStmt(SysYParser::IfStmtContext *context) = 0;

    virtual std::any visitWhileStmt(SysYParser::WhileStmtContext *context) = 0;

    virtual std::any visitBreakStmt(SysYParser::BreakStmtContext *context) = 0;

    virtual std::any visitContinueStmt(SysYParser::ContinueStmtContext *context) = 0;

    virtual std::any visitReturnStmt(SysYParser::ReturnStmtContext *context) = 0;

    virtual std::any visitExp(SysYParser::ExpContext *context) = 0;

    virtual std::any visitCond(SysYParser::CondContext *context) = 0;

    virtual std::any visitLVal(SysYParser::LValContext *context) = 0;

    virtual std::any visitParenthesizedExp(SysYParser::ParenthesizedExpContext *context) = 0;

    virtual std::any visitLvalExp(SysYParser::LvalExpContext *context) = 0;

    virtual std::any visitNumberExp(SysYParser::NumberExpContext *context) = 0;

    virtual std::any visitNumber(SysYParser::NumberContext *context) = 0;

    virtual std::any visitUnaryExpWithoutOp(SysYParser::UnaryExpWithoutOpContext *context) = 0;

    virtual std::any visitFunctionCall(SysYParser::FunctionCallContext *context) = 0;

    virtual std::any visitUnaryExpWithOp(SysYParser::UnaryExpWithOpContext *context) = 0;

    virtual std::any visitUnaryOp(SysYParser::UnaryOpContext *context) = 0;

    virtual std::any visitFuncRParams(SysYParser::FuncRParamsContext *context) = 0;

    virtual std::any visitMulExp(SysYParser::MulExpContext *context) = 0;

    virtual std::any visitAddExp(SysYParser::AddExpContext *context) = 0;

    virtual std::any visitRelExp(SysYParser::RelExpContext *context) = 0;

    virtual std::any visitEqExp(SysYParser::EqExpContext *context) = 0;

    virtual std::any visitLAndExp(SysYParser::LAndExpContext *context) = 0;

    virtual std::any visitLOrExp(SysYParser::LOrExpContext *context) = 0;

    virtual std::any visitConstExp(SysYParser::ConstExpContext *context) = 0;


};


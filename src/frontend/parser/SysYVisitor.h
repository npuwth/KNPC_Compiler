
// Generated from SysY.g4 by ANTLR 4.8

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
    virtual antlrcpp::Any visitProgram(SysYParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitCompUnit(SysYParser::CompUnitContext *context) = 0;

    virtual antlrcpp::Any visitDecl(SysYParser::DeclContext *context) = 0;

    virtual antlrcpp::Any visitConstDecl(SysYParser::ConstDeclContext *context) = 0;

    virtual antlrcpp::Any visitBType(SysYParser::BTypeContext *context) = 0;

    virtual antlrcpp::Any visitConstDefLi(SysYParser::ConstDefLiContext *context) = 0;

    virtual antlrcpp::Any visitConstDef(SysYParser::ConstDefContext *context) = 0;

    virtual antlrcpp::Any visitConstInitVal(SysYParser::ConstInitValContext *context) = 0;

    virtual antlrcpp::Any visitConstExpLi(SysYParser::ConstExpLiContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(SysYParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarDefLi(SysYParser::VarDefLiContext *context) = 0;

    virtual antlrcpp::Any visitVarDef(SysYParser::VarDefContext *context) = 0;

    virtual antlrcpp::Any visitInitVal(SysYParser::InitValContext *context) = 0;

    virtual antlrcpp::Any visitFuncDef(SysYParser::FuncDefContext *context) = 0;

    virtual antlrcpp::Any visitFuncType(SysYParser::FuncTypeContext *context) = 0;

    virtual antlrcpp::Any visitFuncFParams(SysYParser::FuncFParamsContext *context) = 0;

    virtual antlrcpp::Any visitFuncFParam(SysYParser::FuncFParamContext *context) = 0;

    virtual antlrcpp::Any visitExpLi(SysYParser::ExpLiContext *context) = 0;

    virtual antlrcpp::Any visitBlock(SysYParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitBlockItemLi(SysYParser::BlockItemLiContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(SysYParser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(SysYParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitExpStmt(SysYParser::ExpStmtContext *context) = 0;

    virtual antlrcpp::Any visitBlockStmt(SysYParser::BlockStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(SysYParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(SysYParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitBreakStmt(SysYParser::BreakStmtContext *context) = 0;

    virtual antlrcpp::Any visitContinueStmt(SysYParser::ContinueStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(SysYParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitExp(SysYParser::ExpContext *context) = 0;

    virtual antlrcpp::Any visitCond(SysYParser::CondContext *context) = 0;

    virtual antlrcpp::Any visitLVal(SysYParser::LValContext *context) = 0;

    virtual antlrcpp::Any visitPrimary1(SysYParser::Primary1Context *context) = 0;

    virtual antlrcpp::Any visitPrimary2(SysYParser::Primary2Context *context) = 0;

    virtual antlrcpp::Any visitPrimary3(SysYParser::Primary3Context *context) = 0;

    virtual antlrcpp::Any visitNumber(SysYParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitUnary1(SysYParser::Unary1Context *context) = 0;

    virtual antlrcpp::Any visitUnary2(SysYParser::Unary2Context *context) = 0;

    virtual antlrcpp::Any visitUnary3(SysYParser::Unary3Context *context) = 0;

    virtual antlrcpp::Any visitUnaryOp(SysYParser::UnaryOpContext *context) = 0;

    virtual antlrcpp::Any visitFuncRParams(SysYParser::FuncRParamsContext *context) = 0;

    virtual antlrcpp::Any visitMulExp(SysYParser::MulExpContext *context) = 0;

    virtual antlrcpp::Any visitAddExp(SysYParser::AddExpContext *context) = 0;

    virtual antlrcpp::Any visitRelExp(SysYParser::RelExpContext *context) = 0;

    virtual antlrcpp::Any visitEqExp(SysYParser::EqExpContext *context) = 0;

    virtual antlrcpp::Any visitLAndExp(SysYParser::LAndExpContext *context) = 0;

    virtual antlrcpp::Any visitLOrExp(SysYParser::LOrExpContext *context) = 0;

    virtual antlrcpp::Any visitConstExp(SysYParser::ConstExpContext *context) = 0;


};


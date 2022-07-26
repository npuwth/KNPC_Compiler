#include "frontend/parser/SysYBaseVisitor.h"
#include "util/config.hpp"
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

class SemPass1 : public SysYBaseVisitor { // total 50

    private:
    TransHelper *tr;

    public:
    SemPass1(TransHelper *helper);
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
    util::Vector<int> get_array_constInitVals(SysYParser::ConstInitValContext *ctx, util::Vector<int> dims, util::Vector<int> dimSize, int d);    
    util::Vector<float> get_array_constInitValsf(SysYParser::ConstInitValContext *ctx, util::Vector<int> dims, util::Vector<int> dimSize, int d);    
    util::Vector<Temp> get_array_initVals(SysYParser::InitValContext *ctx, util::Vector<int> dims, util::Vector<int> dimSize, int d);
    util::Vector<Temp> get_array_initValsf(SysYParser::InitValContext *ctx, util::Vector<int> dims, util::Vector<int> dimSize, int d);
    virtual antlrcpp::Any visitConstInitVal(SysYParser::ConstInitValContext *ctx) override;
    virtual antlrcpp::Any visitInitVal(SysYParser::InitValContext *ctx) override;
    // visit expressions, 20
    virtual antlrcpp::Any visitConstExpLi(SysYParser::ConstExpLiContext *ctx) override;
    virtual antlrcpp::Any visitExpLi(SysYParser::ExpLiContext *ctx) override;
    virtual antlrcpp::Any visitConstExp(SysYParser::ConstExpContext *ctx) override;
    virtual antlrcpp::Any visitExp(SysYParser::ExpContext *ctx) override;
    virtual antlrcpp::Any visitCond(SysYParser::CondContext *ctx) override;
    virtual antlrcpp::Any visitLVal(SysYParser::LValContext *ctx) override;
    virtual antlrcpp::Any visitPrimary1(SysYParser::Primary1Context *ctx) override;
    virtual antlrcpp::Any visitPrimary2(SysYParser::Primary2Context *ctx) override;
    virtual antlrcpp::Any visitPrimary3(SysYParser::Primary3Context *ctx) override;
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
    // init 9 runtime library function
    void initRunTimeLabels();
    void callMemset(Temp addr, Temp val, Temp size);
    Temp callFloat2Int(Temp src);
    Temp callInt2Float(Temp src);
    // Temp constPropagation(Temp x);
};

Piece *runSemPass1(SysYParser::ProgramContext *tree, MachineDesc *md);
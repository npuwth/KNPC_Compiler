
// Generated from SysY.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  SysYParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, WhiteSpace = 24, LineComment = 25, 
    BlockComment = 26, Void = 27, Int = 28, Float = 29, Const = 30, If = 31, 
    Else = 32, While = 33, Break = 34, Continue = 35, Return = 36, Decimal = 37, 
    Octal = 38, Hexadecimal = 39, FloatLiteral = 40, Identifier = 41
  };

  enum {
    RuleProgram = 0, RuleCompUnit = 1, RuleDecl = 2, RuleConstDecl = 3, 
    RuleBType = 4, RuleConstDefLi = 5, RuleConstDef = 6, RuleConstInitVal = 7, 
    RuleConstInitValLi = 8, RuleConstExpLi = 9, RuleVarDecl = 10, RuleVarDefLi = 11, 
    RuleVarDef = 12, RuleInitVal = 13, RuleInitValLi = 14, RuleFuncDef = 15, 
    RuleFuncType = 16, RuleFuncFParams = 17, RuleFuncFParam = 18, RuleExpLi = 19, 
    RuleBlock = 20, RuleBlockItemLi = 21, RuleBlockItem = 22, RuleStmt = 23, 
    RuleExp = 24, RuleCond = 25, RuleLVal = 26, RulePrimaryExp = 27, RuleNumber = 28, 
    RuleUnaryExp = 29, RuleUnaryOp = 30, RuleFuncRParams = 31, RuleMulExp = 32, 
    RuleAddExp = 33, RuleRelExp = 34, RuleEqExp = 35, RuleLAndExp = 36, 
    RuleLOrExp = 37, RuleConstExp = 38
  };

  explicit SysYParser(antlr4::TokenStream *input);

  SysYParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~SysYParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class CompUnitContext;
  class DeclContext;
  class ConstDeclContext;
  class BTypeContext;
  class ConstDefLiContext;
  class ConstDefContext;
  class ConstInitValContext;
  class ConstInitValLiContext;
  class ConstExpLiContext;
  class VarDeclContext;
  class VarDefLiContext;
  class VarDefContext;
  class InitValContext;
  class InitValLiContext;
  class FuncDefContext;
  class FuncTypeContext;
  class FuncFParamsContext;
  class FuncFParamContext;
  class ExpLiContext;
  class BlockContext;
  class BlockItemLiContext;
  class BlockItemContext;
  class StmtContext;
  class ExpContext;
  class CondContext;
  class LValContext;
  class PrimaryExpContext;
  class NumberContext;
  class UnaryExpContext;
  class UnaryOpContext;
  class FuncRParamsContext;
  class MulExpContext;
  class AddExpContext;
  class RelExpContext;
  class EqExpContext;
  class LAndExpContext;
  class LOrExpContext;
  class ConstExpContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CompUnitContext *> compUnit();
    CompUnitContext* compUnit(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  CompUnitContext : public antlr4::ParserRuleContext {
  public:
    CompUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncDefContext *funcDef();
    DeclContext *decl();
    CompUnitContext *compUnit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompUnitContext* compUnit();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstDeclContext *constDecl();
    VarDeclContext *varDecl();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclContext* decl();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Const();
    BTypeContext *bType();
    ConstDefLiContext *constDefLi();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDeclContext* constDecl();

  class  BTypeContext : public antlr4::ParserRuleContext {
  public:
    BTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Float();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BTypeContext* bType();

  class  ConstDefLiContext : public antlr4::ParserRuleContext {
  public:
    ConstDefLiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConstDefContext *> constDef();
    ConstDefContext* constDef(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDefLiContext* constDefLi();

  class  ConstDefContext : public antlr4::ParserRuleContext {
  public:
    ConstDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    ConstInitValContext *constInitVal();
    ConstExpLiContext *constExpLi();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDefContext* constDef();

  class  ConstInitValContext : public antlr4::ParserRuleContext {
  public:
    ConstInitValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ConstInitValContext() = default;
    void copyFrom(ConstInitValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ListConstInitValContext : public ConstInitValContext {
  public:
    ListConstInitValContext(ConstInitValContext *ctx);

    ConstInitValLiContext *constInitValLi();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SingleConstInitValContext : public ConstInitValContext {
  public:
    SingleConstInitValContext(ConstInitValContext *ctx);

    ConstExpContext *constExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConstInitValContext* constInitVal();

  class  ConstInitValLiContext : public antlr4::ParserRuleContext {
  public:
    ConstInitValLiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConstInitValContext *> constInitVal();
    ConstInitValContext* constInitVal(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstInitValLiContext* constInitValLi();

  class  ConstExpLiContext : public antlr4::ParserRuleContext {
  public:
    ConstExpLiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConstExpContext *> constExp();
    ConstExpContext* constExp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstExpLiContext* constExpLi();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    VarDefLiContext *varDefLi();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclContext* varDecl();

  class  VarDefLiContext : public antlr4::ParserRuleContext {
  public:
    VarDefLiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDefLiContext* varDefLi();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    VarDefContext() = default;
    void copyFrom(VarDefContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UninitVarDefContext : public VarDefContext {
  public:
    UninitVarDefContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    ConstExpLiContext *constExpLi();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InitVarDefContext : public VarDefContext {
  public:
    InitVarDefContext(VarDefContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    InitValContext *initVal();
    ConstExpLiContext *constExpLi();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  VarDefContext* varDef();

  class  InitValContext : public antlr4::ParserRuleContext {
  public:
    InitValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    InitValContext() = default;
    void copyFrom(InitValContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SingleInitValContext : public InitValContext {
  public:
    SingleInitValContext(InitValContext *ctx);

    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListInitValContext : public InitValContext {
  public:
    ListInitValContext(InitValContext *ctx);

    InitValLiContext *initValLi();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  InitValContext* initVal();

  class  InitValLiContext : public antlr4::ParserRuleContext {
  public:
    InitValLiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<InitValContext *> initVal();
    InitValContext* initVal(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InitValLiContext* initValLi();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FuncTypeContext *funcType();
    antlr4::tree::TerminalNode *Identifier();
    BlockContext *block();
    FuncFParamsContext *funcFParams();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncDefContext* funcDef();

  class  FuncTypeContext : public antlr4::ParserRuleContext {
  public:
    FuncTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    antlr4::tree::TerminalNode *Void();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncTypeContext* funcType();

  class  FuncFParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncFParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FuncFParamContext *> funcFParam();
    FuncFParamContext* funcFParam(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncFParamsContext* funcFParams();

  class  FuncFParamContext : public antlr4::ParserRuleContext {
  public:
    FuncFParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BTypeContext *bType();
    antlr4::tree::TerminalNode *Identifier();
    ExpLiContext *expLi();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncFParamContext* funcFParam();

  class  ExpLiContext : public antlr4::ParserRuleContext {
  public:
    ExpLiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpLiContext* expLi();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockItemLiContext *blockItemLi();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  BlockItemLiContext : public antlr4::ParserRuleContext {
  public:
    BlockItemLiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockItemContext *> blockItem();
    BlockItemContext* blockItem(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockItemLiContext* blockItemLi();

  class  BlockItemContext : public antlr4::ParserRuleContext {
  public:
    BlockItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclContext *decl();
    StmtContext *stmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockItemContext* blockItem();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WhileStmtContext : public StmtContext {
  public:
    WhileStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *While();
    CondContext *cond();
    StmtContext *stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfStmtContext : public StmtContext {
  public:
    IfStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *If();
    CondContext *cond();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    antlr4::tree::TerminalNode *Else();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BlockStmtContext : public StmtContext {
  public:
    BlockStmtContext(StmtContext *ctx);

    BlockContext *block();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignStmtContext : public StmtContext {
  public:
    AssignStmtContext(StmtContext *ctx);

    LValContext *lVal();
    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BreakStmtContext : public StmtContext {
  public:
    BreakStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *Break();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExpStmtContext : public StmtContext {
  public:
    ExpStmtContext(StmtContext *ctx);

    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnStmtContext : public StmtContext {
  public:
    ReturnStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *Return();
    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ContinueStmtContext : public StmtContext {
  public:
    ContinueStmtContext(StmtContext *ctx);

    antlr4::tree::TerminalNode *Continue();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StmtContext* stmt();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpContext* exp();

  class  CondContext : public antlr4::ParserRuleContext {
  public:
    CondContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LOrExpContext *lOrExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CondContext* cond();

  class  LValContext : public antlr4::ParserRuleContext {
  public:
    LValContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    ExpLiContext *expLi();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LValContext* lVal();

  class  PrimaryExpContext : public antlr4::ParserRuleContext {
  public:
    PrimaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryExpContext() = default;
    void copyFrom(PrimaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumberExpContext : public PrimaryExpContext {
  public:
    NumberExpContext(PrimaryExpContext *ctx);

    NumberContext *number();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesizedExpContext : public PrimaryExpContext {
  public:
    ParenthesizedExpContext(PrimaryExpContext *ctx);

    ExpContext *exp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LvalExpContext : public PrimaryExpContext {
  public:
    LvalExpContext(PrimaryExpContext *ctx);

    LValContext *lVal();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PrimaryExpContext* primaryExp();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Decimal();
    antlr4::tree::TerminalNode *Octal();
    antlr4::tree::TerminalNode *Hexadecimal();
    antlr4::tree::TerminalNode *FloatLiteral();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  UnaryExpContext : public antlr4::ParserRuleContext {
  public:
    UnaryExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExpContext() = default;
    void copyFrom(UnaryExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryExpWithOpContext : public UnaryExpContext {
  public:
    UnaryExpWithOpContext(UnaryExpContext *ctx);

    UnaryOpContext *unaryOp();
    UnaryExpContext *unaryExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallContext : public UnaryExpContext {
  public:
    FunctionCallContext(UnaryExpContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    FuncRParamsContext *funcRParams();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryExpWithoutOpContext : public UnaryExpContext {
  public:
    UnaryExpWithoutOpContext(UnaryExpContext *ctx);

    PrimaryExpContext *primaryExp();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  UnaryExpContext* unaryExp();

  class  UnaryOpContext : public antlr4::ParserRuleContext {
  public:
    UnaryOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnaryOpContext* unaryOp();

  class  FuncRParamsContext : public antlr4::ParserRuleContext {
  public:
    FuncRParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncRParamsContext* funcRParams();

  class  MulExpContext : public antlr4::ParserRuleContext {
  public:
    MulExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryExpContext *unaryExp();
    MulExpContext *mulExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MulExpContext* mulExp();

  class  AddExpContext : public antlr4::ParserRuleContext {
  public:
    AddExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MulExpContext *mulExp();
    AddExpContext *addExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddExpContext* addExp();

  class  RelExpContext : public antlr4::ParserRuleContext {
  public:
    RelExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();
    RelExpContext *relExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelExpContext* relExp();

  class  EqExpContext : public antlr4::ParserRuleContext {
  public:
    EqExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelExpContext *relExp();
    EqExpContext *eqExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqExpContext* eqExp();

  class  LAndExpContext : public antlr4::ParserRuleContext {
  public:
    LAndExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EqExpContext *eqExp();
    LAndExpContext *lAndExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LAndExpContext* lAndExp();

  class  LOrExpContext : public antlr4::ParserRuleContext {
  public:
    LOrExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LAndExpContext *lAndExp();
    LOrExpContext *lOrExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LOrExpContext* lOrExp();

  class  ConstExpContext : public antlr4::ParserRuleContext {
  public:
    ConstExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AddExpContext *addExp();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstExpContext* constExp();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};


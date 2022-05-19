
// Generated from SysY.g4 by ANTLR 4.8


#include "SysYVisitor.h"

#include "SysYParser.h"


using namespace antlrcpp;
using namespace antlr4;

SysYParser::SysYParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SysYParser::~SysYParser() {
  delete _interpreter;
}

std::string SysYParser::getGrammarFileName() const {
  return "SysY.g4";
}

const std::vector<std::string>& SysYParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SysYParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

SysYParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::CompUnitContext *> SysYParser::ProgramContext::compUnit() {
  return getRuleContexts<SysYParser::CompUnitContext>();
}

SysYParser::CompUnitContext* SysYParser::ProgramContext::compUnit(size_t i) {
  return getRuleContext<SysYParser::CompUnitContext>(i);
}


size_t SysYParser::ProgramContext::getRuleIndex() const {
  return SysYParser::RuleProgram;
}


antlrcpp::Any SysYParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ProgramContext* SysYParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, SysYParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(78);
      compUnit();
      setState(81); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::Void)
      | (1ULL << SysYParser::Int)
      | (1ULL << SysYParser::Float)
      | (1ULL << SysYParser::Const))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompUnitContext ------------------------------------------------------------------

SysYParser::CompUnitContext::CompUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::FuncDefContext* SysYParser::CompUnitContext::funcDef() {
  return getRuleContext<SysYParser::FuncDefContext>(0);
}

SysYParser::DeclContext* SysYParser::CompUnitContext::decl() {
  return getRuleContext<SysYParser::DeclContext>(0);
}

SysYParser::CompUnitContext* SysYParser::CompUnitContext::compUnit() {
  return getRuleContext<SysYParser::CompUnitContext>(0);
}


size_t SysYParser::CompUnitContext::getRuleIndex() const {
  return SysYParser::RuleCompUnit;
}


antlrcpp::Any SysYParser::CompUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitCompUnit(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::CompUnitContext* SysYParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 2, SysYParser::RuleCompUnit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(83);
      funcDef();
      break;
    }

    case 2: {
      setState(84);
      decl();
      break;
    }

    }
    setState(88);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(87);
      compUnit();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

SysYParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstDeclContext* SysYParser::DeclContext::constDecl() {
  return getRuleContext<SysYParser::ConstDeclContext>(0);
}

SysYParser::VarDeclContext* SysYParser::DeclContext::varDecl() {
  return getRuleContext<SysYParser::VarDeclContext>(0);
}


size_t SysYParser::DeclContext::getRuleIndex() const {
  return SysYParser::RuleDecl;
}


antlrcpp::Any SysYParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::DeclContext* SysYParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, SysYParser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Const: {
        enterOuterAlt(_localctx, 1);
        setState(90);
        constDecl();
        break;
      }

      case SysYParser::Int:
      case SysYParser::Float: {
        enterOuterAlt(_localctx, 2);
        setState(91);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

SysYParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::ConstDeclContext::Const() {
  return getToken(SysYParser::Const, 0);
}

SysYParser::BTypeContext* SysYParser::ConstDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

SysYParser::ConstDefLiContext* SysYParser::ConstDeclContext::constDefLi() {
  return getRuleContext<SysYParser::ConstDefLiContext>(0);
}


size_t SysYParser::ConstDeclContext::getRuleIndex() const {
  return SysYParser::RuleConstDecl;
}


antlrcpp::Any SysYParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDeclContext* SysYParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, SysYParser::RuleConstDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    match(SysYParser::Const);
    setState(95);
    bType();
    setState(96);
    constDefLi();
    setState(97);
    match(SysYParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BTypeContext ------------------------------------------------------------------

SysYParser::BTypeContext::BTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::BTypeContext::Int() {
  return getToken(SysYParser::Int, 0);
}

tree::TerminalNode* SysYParser::BTypeContext::Float() {
  return getToken(SysYParser::Float, 0);
}


size_t SysYParser::BTypeContext::getRuleIndex() const {
  return SysYParser::RuleBType;
}


antlrcpp::Any SysYParser::BTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBType(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BTypeContext* SysYParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, SysYParser::RuleBType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    _la = _input->LA(1);
    if (!(_la == SysYParser::Int

    || _la == SysYParser::Float)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefLiContext ------------------------------------------------------------------

SysYParser::ConstDefLiContext::ConstDefLiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstDefContext* SysYParser::ConstDefLiContext::constDef() {
  return getRuleContext<SysYParser::ConstDefContext>(0);
}

SysYParser::ConstDefLiContext* SysYParser::ConstDefLiContext::constDefLi() {
  return getRuleContext<SysYParser::ConstDefLiContext>(0);
}


size_t SysYParser::ConstDefLiContext::getRuleIndex() const {
  return SysYParser::RuleConstDefLi;
}


antlrcpp::Any SysYParser::ConstDefLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstDefLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDefLiContext* SysYParser::constDefLi() {
  ConstDefLiContext *_localctx = _tracker.createInstance<ConstDefLiContext>(_ctx, getState());
  enterRule(_localctx, 10, SysYParser::RuleConstDefLi);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    constDef();
    setState(104);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__1) {
      setState(102);
      match(SysYParser::T__1);
      setState(103);
      constDefLi();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDefContext ------------------------------------------------------------------

SysYParser::ConstDefContext::ConstDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::ConstDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

SysYParser::ConstInitValContext* SysYParser::ConstDefContext::constInitVal() {
  return getRuleContext<SysYParser::ConstInitValContext>(0);
}

SysYParser::ConstExpLiContext* SysYParser::ConstDefContext::constExpLi() {
  return getRuleContext<SysYParser::ConstExpLiContext>(0);
}


size_t SysYParser::ConstDefContext::getRuleIndex() const {
  return SysYParser::RuleConstDef;
}


antlrcpp::Any SysYParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDefContext* SysYParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 12, SysYParser::RuleConstDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(SysYParser::Identifier);
    setState(108);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__5) {
      setState(107);
      constExpLi();
    }
    setState(110);
    match(SysYParser::T__2);
    setState(111);
    constInitVal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValContext ------------------------------------------------------------------

SysYParser::ConstInitValContext::ConstInitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ConstExpContext* SysYParser::ConstInitValContext::constExp() {
  return getRuleContext<SysYParser::ConstExpContext>(0);
}

SysYParser::ConstInitValLiContext* SysYParser::ConstInitValContext::constInitValLi() {
  return getRuleContext<SysYParser::ConstInitValLiContext>(0);
}


size_t SysYParser::ConstInitValContext::getRuleIndex() const {
  return SysYParser::RuleConstInitVal;
}


antlrcpp::Any SysYParser::ConstInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstInitVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstInitValContext* SysYParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 14, SysYParser::RuleConstInitVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__7:
      case SysYParser::T__9:
      case SysYParser::T__10:
      case SysYParser::T__11:
      case SysYParser::Decimal:
      case SysYParser::Octal:
      case SysYParser::Hexadecimal:
      case SysYParser::FloatLiteral:
      case SysYParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(113);
        constExp();
        break;
      }

      case SysYParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(114);
        match(SysYParser::T__3);
        setState(116);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SysYParser::T__3)
          | (1ULL << SysYParser::T__7)
          | (1ULL << SysYParser::T__9)
          | (1ULL << SysYParser::T__10)
          | (1ULL << SysYParser::T__11)
          | (1ULL << SysYParser::Decimal)
          | (1ULL << SysYParser::Octal)
          | (1ULL << SysYParser::Hexadecimal)
          | (1ULL << SysYParser::FloatLiteral)
          | (1ULL << SysYParser::Identifier))) != 0)) {
          setState(115);
          constInitValLi();
        }
        setState(118);
        match(SysYParser::T__4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstInitValLiContext ------------------------------------------------------------------

SysYParser::ConstInitValLiContext::ConstInitValLiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::ConstInitValContext *> SysYParser::ConstInitValLiContext::constInitVal() {
  return getRuleContexts<SysYParser::ConstInitValContext>();
}

SysYParser::ConstInitValContext* SysYParser::ConstInitValLiContext::constInitVal(size_t i) {
  return getRuleContext<SysYParser::ConstInitValContext>(i);
}


size_t SysYParser::ConstInitValLiContext::getRuleIndex() const {
  return SysYParser::RuleConstInitValLi;
}


antlrcpp::Any SysYParser::ConstInitValLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstInitValLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstInitValLiContext* SysYParser::constInitValLi() {
  ConstInitValLiContext *_localctx = _tracker.createInstance<ConstInitValLiContext>(_ctx, getState());
  enterRule(_localctx, 16, SysYParser::RuleConstInitValLi);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    constInitVal();
    setState(126);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(122);
      match(SysYParser::T__1);
      setState(123);
      constInitVal();
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstExpLiContext ------------------------------------------------------------------

SysYParser::ConstExpLiContext::ConstExpLiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::ConstExpContext *> SysYParser::ConstExpLiContext::constExp() {
  return getRuleContexts<SysYParser::ConstExpContext>();
}

SysYParser::ConstExpContext* SysYParser::ConstExpLiContext::constExp(size_t i) {
  return getRuleContext<SysYParser::ConstExpContext>(i);
}


size_t SysYParser::ConstExpLiContext::getRuleIndex() const {
  return SysYParser::RuleConstExpLi;
}


antlrcpp::Any SysYParser::ConstExpLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstExpLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstExpLiContext* SysYParser::constExpLi() {
  ConstExpLiContext *_localctx = _tracker.createInstance<ConstExpLiContext>(_ctx, getState());
  enterRule(_localctx, 18, SysYParser::RuleConstExpLi);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(129);
      match(SysYParser::T__5);
      setState(130);
      constExp();
      setState(131);
      match(SysYParser::T__6);
      setState(135); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SysYParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

SysYParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::VarDeclContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

SysYParser::VarDefLiContext* SysYParser::VarDeclContext::varDefLi() {
  return getRuleContext<SysYParser::VarDefLiContext>(0);
}


size_t SysYParser::VarDeclContext::getRuleIndex() const {
  return SysYParser::RuleVarDecl;
}


antlrcpp::Any SysYParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::VarDeclContext* SysYParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, SysYParser::RuleVarDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    bType();
    setState(138);
    varDefLi();
    setState(139);
    match(SysYParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefLiContext ------------------------------------------------------------------

SysYParser::VarDefLiContext::VarDefLiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::VarDefContext *> SysYParser::VarDefLiContext::varDef() {
  return getRuleContexts<SysYParser::VarDefContext>();
}

SysYParser::VarDefContext* SysYParser::VarDefLiContext::varDef(size_t i) {
  return getRuleContext<SysYParser::VarDefContext>(i);
}


size_t SysYParser::VarDefLiContext::getRuleIndex() const {
  return SysYParser::RuleVarDefLi;
}


antlrcpp::Any SysYParser::VarDefLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitVarDefLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::VarDefLiContext* SysYParser::varDefLi() {
  VarDefLiContext *_localctx = _tracker.createInstance<VarDefLiContext>(_ctx, getState());
  enterRule(_localctx, 22, SysYParser::RuleVarDefLi);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    varDef();
    setState(146);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(142);
      match(SysYParser::T__1);
      setState(143);
      varDef();
      setState(148);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

SysYParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::VarDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

SysYParser::ConstExpLiContext* SysYParser::VarDefContext::constExpLi() {
  return getRuleContext<SysYParser::ConstExpLiContext>(0);
}

SysYParser::InitValContext* SysYParser::VarDefContext::initVal() {
  return getRuleContext<SysYParser::InitValContext>(0);
}


size_t SysYParser::VarDefContext::getRuleIndex() const {
  return SysYParser::RuleVarDef;
}


antlrcpp::Any SysYParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::VarDefContext* SysYParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 24, SysYParser::RuleVarDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    match(SysYParser::Identifier);
    setState(151);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__5) {
      setState(150);
      constExpLi();
    }
    setState(155);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__2) {
      setState(153);
      match(SysYParser::T__2);
      setState(154);
      initVal();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitValContext ------------------------------------------------------------------

SysYParser::InitValContext::InitValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ExpContext* SysYParser::InitValContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::InitValLiContext* SysYParser::InitValContext::initValLi() {
  return getRuleContext<SysYParser::InitValLiContext>(0);
}


size_t SysYParser::InitValContext::getRuleIndex() const {
  return SysYParser::RuleInitVal;
}


antlrcpp::Any SysYParser::InitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitInitVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::InitValContext* SysYParser::initVal() {
  InitValContext *_localctx = _tracker.createInstance<InitValContext>(_ctx, getState());
  enterRule(_localctx, 26, SysYParser::RuleInitVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__7:
      case SysYParser::T__9:
      case SysYParser::T__10:
      case SysYParser::T__11:
      case SysYParser::Decimal:
      case SysYParser::Octal:
      case SysYParser::Hexadecimal:
      case SysYParser::FloatLiteral:
      case SysYParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(157);
        exp();
        break;
      }

      case SysYParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(158);
        match(SysYParser::T__3);
        setState(160);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << SysYParser::T__3)
          | (1ULL << SysYParser::T__7)
          | (1ULL << SysYParser::T__9)
          | (1ULL << SysYParser::T__10)
          | (1ULL << SysYParser::T__11)
          | (1ULL << SysYParser::Decimal)
          | (1ULL << SysYParser::Octal)
          | (1ULL << SysYParser::Hexadecimal)
          | (1ULL << SysYParser::FloatLiteral)
          | (1ULL << SysYParser::Identifier))) != 0)) {
          setState(159);
          initValLi();
        }
        setState(162);
        match(SysYParser::T__4);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitValLiContext ------------------------------------------------------------------

SysYParser::InitValLiContext::InitValLiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::InitValContext *> SysYParser::InitValLiContext::initVal() {
  return getRuleContexts<SysYParser::InitValContext>();
}

SysYParser::InitValContext* SysYParser::InitValLiContext::initVal(size_t i) {
  return getRuleContext<SysYParser::InitValContext>(i);
}


size_t SysYParser::InitValLiContext::getRuleIndex() const {
  return SysYParser::RuleInitValLi;
}


antlrcpp::Any SysYParser::InitValLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitInitValLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::InitValLiContext* SysYParser::initValLi() {
  InitValLiContext *_localctx = _tracker.createInstance<InitValLiContext>(_ctx, getState());
  enterRule(_localctx, 28, SysYParser::RuleInitValLi);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    initVal();
    setState(170);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(166);
      match(SysYParser::T__1);
      setState(167);
      initVal();
      setState(172);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

SysYParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::FuncTypeContext* SysYParser::FuncDefContext::funcType() {
  return getRuleContext<SysYParser::FuncTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

SysYParser::BlockContext* SysYParser::FuncDefContext::block() {
  return getRuleContext<SysYParser::BlockContext>(0);
}

SysYParser::FuncFParamsContext* SysYParser::FuncDefContext::funcFParams() {
  return getRuleContext<SysYParser::FuncFParamsContext>(0);
}


size_t SysYParser::FuncDefContext::getRuleIndex() const {
  return SysYParser::RuleFuncDef;
}


antlrcpp::Any SysYParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncDefContext* SysYParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 30, SysYParser::RuleFuncDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    funcType();
    setState(174);
    match(SysYParser::Identifier);
    setState(175);
    match(SysYParser::T__7);
    setState(177);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::Int

    || _la == SysYParser::Float) {
      setState(176);
      funcFParams();
    }
    setState(179);
    match(SysYParser::T__8);
    setState(180);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

SysYParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::FuncTypeContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncTypeContext::Void() {
  return getToken(SysYParser::Void, 0);
}


size_t SysYParser::FuncTypeContext::getRuleIndex() const {
  return SysYParser::RuleFuncType;
}


antlrcpp::Any SysYParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncTypeContext* SysYParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 32, SysYParser::RuleFuncType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(184);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Int:
      case SysYParser::Float: {
        enterOuterAlt(_localctx, 1);
        setState(182);
        bType();
        break;
      }

      case SysYParser::Void: {
        enterOuterAlt(_localctx, 2);
        setState(183);
        match(SysYParser::Void);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamsContext ------------------------------------------------------------------

SysYParser::FuncFParamsContext::FuncFParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::FuncFParamContext *> SysYParser::FuncFParamsContext::funcFParam() {
  return getRuleContexts<SysYParser::FuncFParamContext>();
}

SysYParser::FuncFParamContext* SysYParser::FuncFParamsContext::funcFParam(size_t i) {
  return getRuleContext<SysYParser::FuncFParamContext>(i);
}


size_t SysYParser::FuncFParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncFParams;
}


antlrcpp::Any SysYParser::FuncFParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncFParams(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncFParamsContext* SysYParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 34, SysYParser::RuleFuncFParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    funcFParam();
    setState(191);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(187);
      match(SysYParser::T__1);
      setState(188);
      funcFParam();
      setState(193);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncFParamContext ------------------------------------------------------------------

SysYParser::FuncFParamContext::FuncFParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BTypeContext* SysYParser::FuncFParamContext::bType() {
  return getRuleContext<SysYParser::BTypeContext>(0);
}

tree::TerminalNode* SysYParser::FuncFParamContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

SysYParser::ExpLiContext* SysYParser::FuncFParamContext::expLi() {
  return getRuleContext<SysYParser::ExpLiContext>(0);
}


size_t SysYParser::FuncFParamContext::getRuleIndex() const {
  return SysYParser::RuleFuncFParam;
}


antlrcpp::Any SysYParser::FuncFParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncFParam(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncFParamContext* SysYParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 36, SysYParser::RuleFuncFParam);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    bType();
    setState(195);
    match(SysYParser::Identifier);
    setState(201);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__5) {
      setState(196);
      match(SysYParser::T__5);
      setState(197);
      match(SysYParser::T__6);
      setState(199);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SysYParser::T__5) {
        setState(198);
        expLi();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpLiContext ------------------------------------------------------------------

SysYParser::ExpLiContext::ExpLiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::ExpContext *> SysYParser::ExpLiContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::ExpLiContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}


size_t SysYParser::ExpLiContext::getRuleIndex() const {
  return SysYParser::RuleExpLi;
}


antlrcpp::Any SysYParser::ExpLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitExpLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ExpLiContext* SysYParser::expLi() {
  ExpLiContext *_localctx = _tracker.createInstance<ExpLiContext>(_ctx, getState());
  enterRule(_localctx, 38, SysYParser::RuleExpLi);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(203);
      match(SysYParser::T__5);
      setState(204);
      exp();
      setState(205);
      match(SysYParser::T__6);
      setState(209); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SysYParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

SysYParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::BlockItemLiContext* SysYParser::BlockContext::blockItemLi() {
  return getRuleContext<SysYParser::BlockItemLiContext>(0);
}


size_t SysYParser::BlockContext::getRuleIndex() const {
  return SysYParser::RuleBlock;
}


antlrcpp::Any SysYParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockContext* SysYParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 40, SysYParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    match(SysYParser::T__3);
    setState(213);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__0)
      | (1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__7)
      | (1ULL << SysYParser::T__9)
      | (1ULL << SysYParser::T__10)
      | (1ULL << SysYParser::T__11)
      | (1ULL << SysYParser::Int)
      | (1ULL << SysYParser::Float)
      | (1ULL << SysYParser::Const)
      | (1ULL << SysYParser::If)
      | (1ULL << SysYParser::While)
      | (1ULL << SysYParser::Break)
      | (1ULL << SysYParser::Continue)
      | (1ULL << SysYParser::Return)
      | (1ULL << SysYParser::Decimal)
      | (1ULL << SysYParser::Octal)
      | (1ULL << SysYParser::Hexadecimal)
      | (1ULL << SysYParser::FloatLiteral)
      | (1ULL << SysYParser::Identifier))) != 0)) {
      setState(212);
      blockItemLi();
    }
    setState(215);
    match(SysYParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemLiContext ------------------------------------------------------------------

SysYParser::BlockItemLiContext::BlockItemLiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SysYParser::BlockItemContext *> SysYParser::BlockItemLiContext::blockItem() {
  return getRuleContexts<SysYParser::BlockItemContext>();
}

SysYParser::BlockItemContext* SysYParser::BlockItemLiContext::blockItem(size_t i) {
  return getRuleContext<SysYParser::BlockItemContext>(i);
}


size_t SysYParser::BlockItemLiContext::getRuleIndex() const {
  return SysYParser::RuleBlockItemLi;
}


antlrcpp::Any SysYParser::BlockItemLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlockItemLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockItemLiContext* SysYParser::blockItemLi() {
  BlockItemLiContext *_localctx = _tracker.createInstance<BlockItemLiContext>(_ctx, getState());
  enterRule(_localctx, 42, SysYParser::RuleBlockItemLi);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(217);
      blockItem();
      setState(220); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__0)
      | (1ULL << SysYParser::T__3)
      | (1ULL << SysYParser::T__7)
      | (1ULL << SysYParser::T__9)
      | (1ULL << SysYParser::T__10)
      | (1ULL << SysYParser::T__11)
      | (1ULL << SysYParser::Int)
      | (1ULL << SysYParser::Float)
      | (1ULL << SysYParser::Const)
      | (1ULL << SysYParser::If)
      | (1ULL << SysYParser::While)
      | (1ULL << SysYParser::Break)
      | (1ULL << SysYParser::Continue)
      | (1ULL << SysYParser::Return)
      | (1ULL << SysYParser::Decimal)
      | (1ULL << SysYParser::Octal)
      | (1ULL << SysYParser::Hexadecimal)
      | (1ULL << SysYParser::FloatLiteral)
      | (1ULL << SysYParser::Identifier))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockItemContext ------------------------------------------------------------------

SysYParser::BlockItemContext::BlockItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::DeclContext* SysYParser::BlockItemContext::decl() {
  return getRuleContext<SysYParser::DeclContext>(0);
}

SysYParser::StmtContext* SysYParser::BlockItemContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}


size_t SysYParser::BlockItemContext::getRuleIndex() const {
  return SysYParser::RuleBlockItem;
}


antlrcpp::Any SysYParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockItemContext* SysYParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 44, SysYParser::RuleBlockItem);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(224);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Int:
      case SysYParser::Float:
      case SysYParser::Const: {
        enterOuterAlt(_localctx, 1);
        setState(222);
        decl();
        break;
      }

      case SysYParser::T__0:
      case SysYParser::T__3:
      case SysYParser::T__7:
      case SysYParser::T__9:
      case SysYParser::T__10:
      case SysYParser::T__11:
      case SysYParser::If:
      case SysYParser::While:
      case SysYParser::Break:
      case SysYParser::Continue:
      case SysYParser::Return:
      case SysYParser::Decimal:
      case SysYParser::Octal:
      case SysYParser::Hexadecimal:
      case SysYParser::FloatLiteral:
      case SysYParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(223);
        stmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

SysYParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::StmtContext::getRuleIndex() const {
  return SysYParser::RuleStmt;
}

void SysYParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::WhileStmtContext::While() {
  return getToken(SysYParser::While, 0);
}

SysYParser::CondContext* SysYParser::WhileStmtContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

SysYParser::StmtContext* SysYParser::WhileStmtContext::stmt() {
  return getRuleContext<SysYParser::StmtContext>(0);
}

SysYParser::WhileStmtContext::WhileStmtContext(StmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::IfStmtContext::If() {
  return getToken(SysYParser::If, 0);
}

SysYParser::CondContext* SysYParser::IfStmtContext::cond() {
  return getRuleContext<SysYParser::CondContext>(0);
}

std::vector<SysYParser::StmtContext *> SysYParser::IfStmtContext::stmt() {
  return getRuleContexts<SysYParser::StmtContext>();
}

SysYParser::StmtContext* SysYParser::IfStmtContext::stmt(size_t i) {
  return getRuleContext<SysYParser::StmtContext>(i);
}

tree::TerminalNode* SysYParser::IfStmtContext::Else() {
  return getToken(SysYParser::Else, 0);
}

SysYParser::IfStmtContext::IfStmtContext(StmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BlockStmtContext ------------------------------------------------------------------

SysYParser::BlockContext* SysYParser::BlockStmtContext::block() {
  return getRuleContext<SysYParser::BlockContext>(0);
}

SysYParser::BlockStmtContext::BlockStmtContext(StmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::BlockStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlockStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignmentContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::AssignmentContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::ExpContext* SysYParser::AssignmentContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::AssignmentContext::AssignmentContext(StmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::BreakStmtContext::Break() {
  return getToken(SysYParser::Break, 0);
}

SysYParser::BreakStmtContext::BreakStmtContext(StmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBreakStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExpStmtContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::ExpStmtContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::ExpStmtContext::ExpStmtContext(StmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::ExpStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitExpStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ReturnStmtContext::Return() {
  return getToken(SysYParser::Return, 0);
}

SysYParser::ExpContext* SysYParser::ReturnStmtContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::ReturnStmtContext::ReturnStmtContext(StmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::ContinueStmtContext::Continue() {
  return getToken(SysYParser::Continue, 0);
}

SysYParser::ContinueStmtContext::ContinueStmtContext(StmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::StmtContext* SysYParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 46, SysYParser::RuleStmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(260);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::AssignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(226);
      lVal();
      setState(227);
      match(SysYParser::T__2);
      setState(228);
      exp();
      setState(229);
      match(SysYParser::T__0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::ExpStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(232);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__7)
        | (1ULL << SysYParser::T__9)
        | (1ULL << SysYParser::T__10)
        | (1ULL << SysYParser::T__11)
        | (1ULL << SysYParser::Decimal)
        | (1ULL << SysYParser::Octal)
        | (1ULL << SysYParser::Hexadecimal)
        | (1ULL << SysYParser::FloatLiteral)
        | (1ULL << SysYParser::Identifier))) != 0)) {
        setState(231);
        exp();
      }
      setState(234);
      match(SysYParser::T__0);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::BlockStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(235);
      block();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(236);
      match(SysYParser::If);
      setState(237);
      match(SysYParser::T__7);
      setState(238);
      cond();
      setState(239);
      match(SysYParser::T__8);
      setState(240);
      stmt();
      setState(243);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
      case 1: {
        setState(241);
        match(SysYParser::Else);
        setState(242);
        stmt();
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(245);
      match(SysYParser::While);
      setState(246);
      match(SysYParser::T__7);
      setState(247);
      cond();
      setState(248);
      match(SysYParser::T__8);
      setState(249);
      stmt();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::BreakStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(251);
      match(SysYParser::Break);
      setState(252);
      match(SysYParser::T__0);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::ContinueStmtContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(253);
      match(SysYParser::Continue);
      setState(254);
      match(SysYParser::T__0);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StmtContext *>(_tracker.createInstance<SysYParser::ReturnStmtContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(255);
      match(SysYParser::Return);
      setState(257);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__7)
        | (1ULL << SysYParser::T__9)
        | (1ULL << SysYParser::T__10)
        | (1ULL << SysYParser::T__11)
        | (1ULL << SysYParser::Decimal)
        | (1ULL << SysYParser::Octal)
        | (1ULL << SysYParser::Hexadecimal)
        | (1ULL << SysYParser::FloatLiteral)
        | (1ULL << SysYParser::Identifier))) != 0)) {
        setState(256);
        exp();
      }
      setState(259);
      match(SysYParser::T__0);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

SysYParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::AddExpContext* SysYParser::ExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}


size_t SysYParser::ExpContext::getRuleIndex() const {
  return SysYParser::RuleExp;
}


antlrcpp::Any SysYParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ExpContext* SysYParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 48, SysYParser::RuleExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    addExp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

SysYParser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::LOrExpContext* SysYParser::CondContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}


size_t SysYParser::CondContext::getRuleIndex() const {
  return SysYParser::RuleCond;
}


antlrcpp::Any SysYParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::CondContext* SysYParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 50, SysYParser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    lOrExp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LValContext ------------------------------------------------------------------

SysYParser::LValContext::LValContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::LValContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

SysYParser::ExpLiContext* SysYParser::LValContext::expLi() {
  return getRuleContext<SysYParser::ExpLiContext>(0);
}


size_t SysYParser::LValContext::getRuleIndex() const {
  return SysYParser::RuleLVal;
}


antlrcpp::Any SysYParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LValContext* SysYParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 52, SysYParser::RuleLVal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(266);
    match(SysYParser::Identifier);
    setState(268);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__5) {
      setState(267);
      expLi();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExpContext ------------------------------------------------------------------

SysYParser::PrimaryExpContext::PrimaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ExpContext* SysYParser::PrimaryExpContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::LValContext* SysYParser::PrimaryExpContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::NumberContext* SysYParser::PrimaryExpContext::number() {
  return getRuleContext<SysYParser::NumberContext>(0);
}


size_t SysYParser::PrimaryExpContext::getRuleIndex() const {
  return SysYParser::RulePrimaryExp;
}


antlrcpp::Any SysYParser::PrimaryExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitPrimaryExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::PrimaryExpContext* SysYParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 54, SysYParser::RulePrimaryExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(276);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(270);
        match(SysYParser::T__7);
        setState(271);
        exp();
        setState(272);
        match(SysYParser::T__8);
        break;
      }

      case SysYParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(274);
        lVal();
        break;
      }

      case SysYParser::Decimal:
      case SysYParser::Octal:
      case SysYParser::Hexadecimal:
      case SysYParser::FloatLiteral: {
        enterOuterAlt(_localctx, 3);
        setState(275);
        number();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

SysYParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SysYParser::NumberContext::Decimal() {
  return getToken(SysYParser::Decimal, 0);
}

tree::TerminalNode* SysYParser::NumberContext::Octal() {
  return getToken(SysYParser::Octal, 0);
}

tree::TerminalNode* SysYParser::NumberContext::Hexadecimal() {
  return getToken(SysYParser::Hexadecimal, 0);
}

tree::TerminalNode* SysYParser::NumberContext::FloatLiteral() {
  return getToken(SysYParser::FloatLiteral, 0);
}


size_t SysYParser::NumberContext::getRuleIndex() const {
  return SysYParser::RuleNumber;
}


antlrcpp::Any SysYParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::NumberContext* SysYParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 56, SysYParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::Decimal)
      | (1ULL << SysYParser::Octal)
      | (1ULL << SysYParser::Hexadecimal)
      | (1ULL << SysYParser::FloatLiteral))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExpContext ------------------------------------------------------------------

SysYParser::UnaryExpContext::UnaryExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::UnaryExpContext::getRuleIndex() const {
  return SysYParser::RuleUnaryExp;
}

void SysYParser::UnaryExpContext::copyFrom(UnaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Unary1Context ------------------------------------------------------------------

SysYParser::PrimaryExpContext* SysYParser::Unary1Context::primaryExp() {
  return getRuleContext<SysYParser::PrimaryExpContext>(0);
}

SysYParser::Unary1Context::Unary1Context(UnaryExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::Unary1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnary1(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Unary2Context ------------------------------------------------------------------

tree::TerminalNode* SysYParser::Unary2Context::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

SysYParser::FuncRParamsContext* SysYParser::Unary2Context::funcRParams() {
  return getRuleContext<SysYParser::FuncRParamsContext>(0);
}

SysYParser::Unary2Context::Unary2Context(UnaryExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::Unary2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnary2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Unary3Context ------------------------------------------------------------------

SysYParser::UnaryOpContext* SysYParser::Unary3Context::unaryOp() {
  return getRuleContext<SysYParser::UnaryOpContext>(0);
}

SysYParser::UnaryExpContext* SysYParser::Unary3Context::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::Unary3Context::Unary3Context(UnaryExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any SysYParser::Unary3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnary3(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::UnaryExpContext* SysYParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 58, SysYParser::RuleUnaryExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(290);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<SysYParser::Unary1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(280);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<SysYParser::Unary2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(281);
      match(SysYParser::Identifier);
      setState(282);
      match(SysYParser::T__7);
      setState(284);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__7)
        | (1ULL << SysYParser::T__9)
        | (1ULL << SysYParser::T__10)
        | (1ULL << SysYParser::T__11)
        | (1ULL << SysYParser::Decimal)
        | (1ULL << SysYParser::Octal)
        | (1ULL << SysYParser::Hexadecimal)
        | (1ULL << SysYParser::FloatLiteral)
        | (1ULL << SysYParser::Identifier))) != 0)) {
        setState(283);
        funcRParams();
      }
      setState(286);
      match(SysYParser::T__8);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<UnaryExpContext *>(_tracker.createInstance<SysYParser::Unary3Context>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(287);
      unaryOp();
      setState(288);
      unaryExp();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpContext ------------------------------------------------------------------

SysYParser::UnaryOpContext::UnaryOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SysYParser::UnaryOpContext::getRuleIndex() const {
  return SysYParser::RuleUnaryOp;
}


antlrcpp::Any SysYParser::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::UnaryOpContext* SysYParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 60, SysYParser::RuleUnaryOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__9)
      | (1ULL << SysYParser::T__10)
      | (1ULL << SysYParser::T__11))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncRParamsContext ------------------------------------------------------------------

SysYParser::FuncRParamsContext::FuncRParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::ExpContext* SysYParser::FuncRParamsContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::FuncRParamsContext* SysYParser::FuncRParamsContext::funcRParams() {
  return getRuleContext<SysYParser::FuncRParamsContext>(0);
}


size_t SysYParser::FuncRParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncRParams;
}


antlrcpp::Any SysYParser::FuncRParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncRParams(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncRParamsContext* SysYParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 62, SysYParser::RuleFuncRParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    exp();
    setState(297);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__1) {
      setState(295);
      match(SysYParser::T__1);
      setState(296);
      funcRParams();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulExpContext ------------------------------------------------------------------

SysYParser::MulExpContext::MulExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::UnaryExpContext* SysYParser::MulExpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::MulExpContext* SysYParser::MulExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}


size_t SysYParser::MulExpContext::getRuleIndex() const {
  return SysYParser::RuleMulExp;
}


antlrcpp::Any SysYParser::MulExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitMulExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::MulExpContext* SysYParser::mulExp() {
  MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, getState());
  enterRule(_localctx, 64, SysYParser::RuleMulExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    unaryExp();
    setState(302);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__12)
      | (1ULL << SysYParser::T__13)
      | (1ULL << SysYParser::T__14))) != 0)) {
      setState(300);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__12)
        | (1ULL << SysYParser::T__13)
        | (1ULL << SysYParser::T__14))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(301);
      mulExp();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddExpContext ------------------------------------------------------------------

SysYParser::AddExpContext::AddExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::MulExpContext* SysYParser::AddExpContext::mulExp() {
  return getRuleContext<SysYParser::MulExpContext>(0);
}

SysYParser::AddExpContext* SysYParser::AddExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}


size_t SysYParser::AddExpContext::getRuleIndex() const {
  return SysYParser::RuleAddExp;
}


antlrcpp::Any SysYParser::AddExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitAddExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::AddExpContext* SysYParser::addExp() {
  AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, getState());
  enterRule(_localctx, 66, SysYParser::RuleAddExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    mulExp();
    setState(307);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__9

    || _la == SysYParser::T__10) {
      setState(305);
      _la = _input->LA(1);
      if (!(_la == SysYParser::T__9

      || _la == SysYParser::T__10)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(306);
      addExp();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelExpContext ------------------------------------------------------------------

SysYParser::RelExpContext::RelExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::AddExpContext* SysYParser::RelExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}

SysYParser::RelExpContext* SysYParser::RelExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}


size_t SysYParser::RelExpContext::getRuleIndex() const {
  return SysYParser::RuleRelExp;
}


antlrcpp::Any SysYParser::RelExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitRelExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::RelExpContext* SysYParser::relExp() {
  RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, getState());
  enterRule(_localctx, 68, SysYParser::RuleRelExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    addExp();
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__15)
      | (1ULL << SysYParser::T__16)
      | (1ULL << SysYParser::T__17)
      | (1ULL << SysYParser::T__18))) != 0)) {
      setState(310);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SysYParser::T__15)
        | (1ULL << SysYParser::T__16)
        | (1ULL << SysYParser::T__17)
        | (1ULL << SysYParser::T__18))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(311);
      relExp();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqExpContext ------------------------------------------------------------------

SysYParser::EqExpContext::EqExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::RelExpContext* SysYParser::EqExpContext::relExp() {
  return getRuleContext<SysYParser::RelExpContext>(0);
}

SysYParser::EqExpContext* SysYParser::EqExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}


size_t SysYParser::EqExpContext::getRuleIndex() const {
  return SysYParser::RuleEqExp;
}


antlrcpp::Any SysYParser::EqExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitEqExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::EqExpContext* SysYParser::eqExp() {
  EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, getState());
  enterRule(_localctx, 70, SysYParser::RuleEqExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    relExp();
    setState(317);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__19

    || _la == SysYParser::T__20) {
      setState(315);
      _la = _input->LA(1);
      if (!(_la == SysYParser::T__19

      || _la == SysYParser::T__20)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(316);
      eqExp();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LAndExpContext ------------------------------------------------------------------

SysYParser::LAndExpContext::LAndExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::EqExpContext* SysYParser::LAndExpContext::eqExp() {
  return getRuleContext<SysYParser::EqExpContext>(0);
}

SysYParser::LAndExpContext* SysYParser::LAndExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}


size_t SysYParser::LAndExpContext::getRuleIndex() const {
  return SysYParser::RuleLAndExp;
}


antlrcpp::Any SysYParser::LAndExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLAndExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LAndExpContext* SysYParser::lAndExp() {
  LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, getState());
  enterRule(_localctx, 72, SysYParser::RuleLAndExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    eqExp();
    setState(322);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__21) {
      setState(320);
      match(SysYParser::T__21);
      setState(321);
      lAndExp();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LOrExpContext ------------------------------------------------------------------

SysYParser::LOrExpContext::LOrExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::LAndExpContext* SysYParser::LOrExpContext::lAndExp() {
  return getRuleContext<SysYParser::LAndExpContext>(0);
}

SysYParser::LOrExpContext* SysYParser::LOrExpContext::lOrExp() {
  return getRuleContext<SysYParser::LOrExpContext>(0);
}


size_t SysYParser::LOrExpContext::getRuleIndex() const {
  return SysYParser::RuleLOrExp;
}


antlrcpp::Any SysYParser::LOrExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLOrExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LOrExpContext* SysYParser::lOrExp() {
  LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, getState());
  enterRule(_localctx, 74, SysYParser::RuleLOrExp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    lAndExp();
    setState(327);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__22) {
      setState(325);
      match(SysYParser::T__22);
      setState(326);
      lOrExp();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstExpContext ------------------------------------------------------------------

SysYParser::ConstExpContext::ConstExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SysYParser::AddExpContext* SysYParser::ConstExpContext::addExp() {
  return getRuleContext<SysYParser::AddExpContext>(0);
}


size_t SysYParser::ConstExpContext::getRuleIndex() const {
  return SysYParser::RuleConstExp;
}


antlrcpp::Any SysYParser::ConstExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstExpContext* SysYParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 76, SysYParser::RuleConstExp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    addExp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> SysYParser::_decisionToDFA;
atn::PredictionContextCache SysYParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SysYParser::_atn;
std::vector<uint16_t> SysYParser::_serializedATN;

std::vector<std::string> SysYParser::_ruleNames = {
  "program", "compUnit", "decl", "constDecl", "bType", "constDefLi", "constDef", 
  "constInitVal", "constInitValLi", "constExpLi", "varDecl", "varDefLi", 
  "varDef", "initVal", "initValLi", "funcDef", "funcType", "funcFParams", 
  "funcFParam", "expLi", "block", "blockItemLi", "blockItem", "stmt", "exp", 
  "cond", "lVal", "primaryExp", "number", "unaryExp", "unaryOp", "funcRParams", 
  "mulExp", "addExp", "relExp", "eqExp", "lAndExp", "lOrExp", "constExp"
};

std::vector<std::string> SysYParser::_literalNames = {
  "", "';'", "','", "'='", "'{'", "'}'", "'['", "']'", "'('", "')'", "'+'", 
  "'-'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "'<='", "'>='", "'=='", 
  "'!='", "'&&'", "'||'", "", "", "", "'void'", "'int'", "'float'", "'const'", 
  "'if'", "'else'", "'while'", "'break'", "'continue'", "'return'"
};

std::vector<std::string> SysYParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "WhiteSpace", "LineComment", "BlockComment", "Void", 
  "Int", "Float", "Const", "If", "Else", "While", "Break", "Continue", "Return", 
  "Decimal", "Octal", "Hexadecimal", "FloatLiteral", "Identifier"
};

dfa::Vocabulary SysYParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SysYParser::_tokenNames;

SysYParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2b, 0x14e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x3, 0x2, 0x6, 0x2, 0x52, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x53, 0x3, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0x58, 0xa, 0x3, 0x3, 0x3, 0x5, 0x3, 0x5b, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5f, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0x6b, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6f, 0xa, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 
    0x9, 0x77, 0xa, 0x9, 0x3, 0x9, 0x5, 0x9, 0x7a, 0xa, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x7, 0xa, 0x7f, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x82, 0xb, 
    0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x6, 0xb, 0x88, 0xa, 0xb, 
    0xd, 0xb, 0xe, 0xb, 0x89, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x93, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 
    0x96, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x9a, 0xa, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x5, 0xe, 0x9e, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0xa3, 0xa, 0xf, 0x3, 0xf, 0x5, 0xf, 0xa6, 0xa, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xab, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 
    0xae, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0xb4, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x5, 0x12, 0xbb, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 
    0xc0, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0xc3, 0xb, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xca, 0xa, 0x14, 0x5, 
    0x14, 0xcc, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x6, 
    0x15, 0xd2, 0xa, 0x15, 0xd, 0x15, 0xe, 0x15, 0xd3, 0x3, 0x16, 0x3, 0x16, 
    0x5, 0x16, 0xd8, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x6, 0x17, 
    0xdd, 0xa, 0x17, 0xd, 0x17, 0xe, 0x17, 0xde, 0x3, 0x18, 0x3, 0x18, 0x5, 
    0x18, 0xe3, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x5, 0x19, 0xeb, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x5, 0x19, 0xf6, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x5, 0x19, 0x104, 0xa, 0x19, 0x3, 0x19, 0x5, 0x19, 
    0x107, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x5, 0x1c, 0x10f, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x117, 0xa, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x11f, 
    0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x125, 
    0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 
    0x21, 0x12c, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 
    0x131, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 0x23, 0x136, 
    0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x13b, 0xa, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x140, 0xa, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 0x145, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x5, 0x27, 0x14a, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 
    0x2, 0x2, 0x29, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
    0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x2, 0x9, 0x3, 0x2, 0x1e, 0x1f, 0x3, 0x2, 
    0x27, 0x2a, 0x3, 0x2, 0xc, 0xe, 0x3, 0x2, 0xf, 0x11, 0x3, 0x2, 0xc, 
    0xd, 0x3, 0x2, 0x12, 0x15, 0x3, 0x2, 0x16, 0x17, 0x2, 0x156, 0x2, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x57, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x60, 0x3, 0x2, 0x2, 0x2, 0xa, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x67, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x12, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x87, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x8f, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x97, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x20, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0xba, 0x3, 0x2, 0x2, 0x2, 0x24, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0xc4, 0x3, 0x2, 0x2, 0x2, 0x28, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0xd5, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x106, 0x3, 0x2, 0x2, 0x2, 0x32, 0x108, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x36, 0x10c, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x116, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x118, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x124, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x126, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x128, 0x3, 0x2, 0x2, 0x2, 0x42, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x132, 0x3, 0x2, 0x2, 0x2, 0x46, 0x137, 0x3, 0x2, 0x2, 0x2, 0x48, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x141, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x146, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x5, 0x4, 
    0x3, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x3, 0x3, 0x2, 0x2, 0x2, 0x55, 0x58, 0x5, 0x20, 0x11, 0x2, 0x56, 
    0x58, 0x5, 0x6, 0x4, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x56, 
    0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5b, 0x5, 
    0x4, 0x3, 0x2, 0x5a, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5f, 0x5, 0x8, 0x5, 
    0x2, 0x5d, 0x5f, 0x5, 0x16, 0xc, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x61, 0x7, 0x20, 0x2, 0x2, 0x61, 0x62, 0x5, 0xa, 0x6, 0x2, 0x62, 0x63, 
    0x5, 0xc, 0x7, 0x2, 0x63, 0x64, 0x7, 0x3, 0x2, 0x2, 0x64, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x66, 0x9, 0x2, 0x2, 0x2, 0x66, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x6a, 0x5, 0xe, 0x8, 0x2, 0x68, 0x69, 0x7, 0x4, 0x2, 
    0x2, 0x69, 0x6b, 0x5, 0xc, 0x7, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x6e, 0x7, 0x2b, 0x2, 0x2, 0x6d, 0x6f, 0x5, 0x14, 0xb, 0x2, 0x6e, 0x6d, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 0x5, 0x2, 0x2, 0x71, 0x72, 0x5, 0x10, 
    0x9, 0x2, 0x72, 0xf, 0x3, 0x2, 0x2, 0x2, 0x73, 0x7a, 0x5, 0x4e, 0x28, 
    0x2, 0x74, 0x76, 0x7, 0x6, 0x2, 0x2, 0x75, 0x77, 0x5, 0x12, 0xa, 0x2, 
    0x76, 0x75, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 
    0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7a, 0x7, 0x7, 0x2, 0x2, 0x79, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0x79, 0x74, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x7b, 0x80, 0x5, 0x10, 0x9, 0x2, 0x7c, 0x7d, 0x7, 0x4, 
    0x2, 0x2, 0x7d, 0x7f, 0x5, 0x10, 0x9, 0x2, 0x7e, 0x7c, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x82, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x13, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x80, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x7, 0x8, 0x2, 0x2, 0x84, 0x85, 
    0x5, 0x4e, 0x28, 0x2, 0x85, 0x86, 0x7, 0x9, 0x2, 0x2, 0x86, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x87, 0x83, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x15, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0xa, 0x6, 0x2, 
    0x8c, 0x8d, 0x5, 0x18, 0xd, 0x2, 0x8d, 0x8e, 0x7, 0x3, 0x2, 0x2, 0x8e, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x94, 0x5, 0x1a, 0xe, 0x2, 0x90, 0x91, 
    0x7, 0x4, 0x2, 0x2, 0x91, 0x93, 0x5, 0x1a, 0xe, 0x2, 0x92, 0x90, 0x3, 
    0x2, 0x2, 0x2, 0x93, 0x96, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 
    0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 0x2, 0x95, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 0x97, 0x99, 0x7, 0x2b, 0x2, 0x2, 
    0x98, 0x9a, 0x5, 0x14, 0xb, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 
    0x7, 0x5, 0x2, 0x2, 0x9c, 0x9e, 0x5, 0x1c, 0xf, 0x2, 0x9d, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0xa6, 0x5, 0x32, 0x1a, 0x2, 0xa0, 0xa2, 0x7, 0x6, 0x2, 
    0x2, 0xa1, 0xa3, 0x5, 0x1e, 0x10, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xa6, 0x7, 0x7, 0x2, 0x2, 0xa5, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0xa6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xac, 0x5, 
    0x1c, 0xf, 0x2, 0xa8, 0xa9, 0x7, 0x4, 0x2, 0x2, 0xa9, 0xab, 0x5, 0x1c, 
    0xf, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xab, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 
    0xad, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x5, 0x22, 0x12, 0x2, 0xb0, 0xb1, 0x7, 0x2b, 0x2, 0x2, 0xb1, 0xb3, 
    0x7, 0xa, 0x2, 0x2, 0xb2, 0xb4, 0x5, 0x24, 0x13, 0x2, 0xb3, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xb6, 0x7, 0xb, 0x2, 0x2, 0xb6, 0xb7, 0x5, 0x2a, 0x16, 
    0x2, 0xb7, 0x21, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xbb, 0x5, 0xa, 0x6, 0x2, 
    0xb9, 0xbb, 0x7, 0x1d, 0x2, 0x2, 0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x23, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xc1, 
    0x5, 0x26, 0x14, 0x2, 0xbd, 0xbe, 0x7, 0x4, 0x2, 0x2, 0xbe, 0xc0, 0x5, 
    0x26, 0x14, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 
    0x2, 0xc2, 0x25, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xc4, 0xc5, 0x5, 0xa, 0x6, 0x2, 0xc5, 0xcb, 0x7, 0x2b, 0x2, 0x2, 0xc6, 
    0xc7, 0x7, 0x8, 0x2, 0x2, 0xc7, 0xc9, 0x7, 0x9, 0x2, 0x2, 0xc8, 0xca, 
    0x5, 0x28, 0x15, 0x2, 0xc9, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0xce, 0x7, 0x8, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x32, 0x1a, 0x2, 
    0xcf, 0xd0, 0x7, 0x9, 0x2, 0x2, 0xd0, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xd7, 0x7, 0x6, 0x2, 0x2, 0xd6, 0xd8, 0x5, 0x2c, 
    0x17, 0x2, 0xd7, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x7, 0x2, 0x2, 
    0xda, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 0x5, 0x2e, 0x18, 0x2, 0xdc, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 
    0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xe3, 0x5, 0x6, 0x4, 0x2, 0xe1, 0xe3, 0x5, 0x30, 
    0x19, 0x2, 0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x36, 0x1c, 0x2, 
    0xe5, 0xe6, 0x7, 0x5, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x32, 0x1a, 0x2, 0xe7, 
    0xe8, 0x7, 0x3, 0x2, 0x2, 0xe8, 0x107, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xeb, 
    0x5, 0x32, 0x1a, 0x2, 0xea, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 
    0x2, 0x2, 0x2, 0xeb, 0xec, 0x3, 0x2, 0x2, 0x2, 0xec, 0x107, 0x7, 0x3, 
    0x2, 0x2, 0xed, 0x107, 0x5, 0x2a, 0x16, 0x2, 0xee, 0xef, 0x7, 0x21, 
    0x2, 0x2, 0xef, 0xf0, 0x7, 0xa, 0x2, 0x2, 0xf0, 0xf1, 0x5, 0x34, 0x1b, 
    0x2, 0xf1, 0xf2, 0x7, 0xb, 0x2, 0x2, 0xf2, 0xf5, 0x5, 0x30, 0x19, 0x2, 
    0xf3, 0xf4, 0x7, 0x22, 0x2, 0x2, 0xf4, 0xf6, 0x5, 0x30, 0x19, 0x2, 0xf5, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0x23, 0x2, 0x2, 0xf8, 0xf9, 0x7, 
    0xa, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0x34, 0x1b, 0x2, 0xfa, 0xfb, 0x7, 0xb, 
    0x2, 0x2, 0xfb, 0xfc, 0x5, 0x30, 0x19, 0x2, 0xfc, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0xfd, 0xfe, 0x7, 0x24, 0x2, 0x2, 0xfe, 0x107, 0x7, 0x3, 0x2, 0x2, 
    0xff, 0x100, 0x7, 0x25, 0x2, 0x2, 0x100, 0x107, 0x7, 0x3, 0x2, 0x2, 
    0x101, 0x103, 0x7, 0x26, 0x2, 0x2, 0x102, 0x104, 0x5, 0x32, 0x1a, 0x2, 
    0x103, 0x102, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x107, 0x7, 0x3, 0x2, 0x2, 
    0x106, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x106, 0xea, 0x3, 0x2, 0x2, 0x2, 0x106, 
    0xed, 0x3, 0x2, 0x2, 0x2, 0x106, 0xee, 0x3, 0x2, 0x2, 0x2, 0x106, 0xf7, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x106, 0xff, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x101, 0x3, 0x2, 0x2, 0x2, 0x107, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x108, 0x109, 0x5, 0x44, 0x23, 0x2, 0x109, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x10b, 0x5, 0x4c, 0x27, 0x2, 0x10b, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x10c, 0x10e, 0x7, 0x2b, 0x2, 0x2, 0x10d, 0x10f, 0x5, 0x28, 
    0x15, 0x2, 0x10e, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x37, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x7, 0xa, 0x2, 
    0x2, 0x111, 0x112, 0x5, 0x32, 0x1a, 0x2, 0x112, 0x113, 0x7, 0xb, 0x2, 
    0x2, 0x113, 0x117, 0x3, 0x2, 0x2, 0x2, 0x114, 0x117, 0x5, 0x36, 0x1c, 
    0x2, 0x115, 0x117, 0x5, 0x3a, 0x1e, 0x2, 0x116, 0x110, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 
    0x2, 0x117, 0x39, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x9, 0x3, 0x2, 0x2, 
    0x119, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x125, 0x5, 0x38, 0x1d, 0x2, 
    0x11b, 0x11c, 0x7, 0x2b, 0x2, 0x2, 0x11c, 0x11e, 0x7, 0xa, 0x2, 0x2, 
    0x11d, 0x11f, 0x5, 0x40, 0x21, 0x2, 0x11e, 0x11d, 0x3, 0x2, 0x2, 0x2, 
    0x11e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x120, 0x125, 0x7, 0xb, 0x2, 0x2, 0x121, 0x122, 0x5, 0x3e, 0x20, 0x2, 
    0x122, 0x123, 0x5, 0x3c, 0x1f, 0x2, 0x123, 0x125, 0x3, 0x2, 0x2, 0x2, 
    0x124, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x124, 0x11b, 0x3, 0x2, 0x2, 0x2, 
    0x124, 0x121, 0x3, 0x2, 0x2, 0x2, 0x125, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x126, 
    0x127, 0x9, 0x4, 0x2, 0x2, 0x127, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12b, 
    0x5, 0x32, 0x1a, 0x2, 0x129, 0x12a, 0x7, 0x4, 0x2, 0x2, 0x12a, 0x12c, 
    0x5, 0x40, 0x21, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 
    0x3, 0x2, 0x2, 0x2, 0x12c, 0x41, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x130, 0x5, 
    0x3c, 0x1f, 0x2, 0x12e, 0x12f, 0x9, 0x5, 0x2, 0x2, 0x12f, 0x131, 0x5, 
    0x42, 0x22, 0x2, 0x130, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x131, 0x43, 0x3, 0x2, 0x2, 0x2, 0x132, 0x135, 0x5, 0x42, 
    0x22, 0x2, 0x133, 0x134, 0x9, 0x6, 0x2, 0x2, 0x134, 0x136, 0x5, 0x44, 
    0x23, 0x2, 0x135, 0x133, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 
    0x2, 0x2, 0x136, 0x45, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13a, 0x5, 0x44, 
    0x23, 0x2, 0x138, 0x139, 0x9, 0x7, 0x2, 0x2, 0x139, 0x13b, 0x5, 0x46, 
    0x24, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 
    0x2, 0x2, 0x13b, 0x47, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13f, 0x5, 0x46, 
    0x24, 0x2, 0x13d, 0x13e, 0x9, 0x8, 0x2, 0x2, 0x13e, 0x140, 0x5, 0x48, 
    0x25, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 
    0x2, 0x2, 0x140, 0x49, 0x3, 0x2, 0x2, 0x2, 0x141, 0x144, 0x5, 0x48, 
    0x25, 0x2, 0x142, 0x143, 0x7, 0x18, 0x2, 0x2, 0x143, 0x145, 0x5, 0x4a, 
    0x26, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 
    0x2, 0x2, 0x145, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x146, 0x149, 0x5, 0x4a, 
    0x26, 0x2, 0x147, 0x148, 0x7, 0x19, 0x2, 0x2, 0x148, 0x14a, 0x5, 0x4c, 
    0x27, 0x2, 0x149, 0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x5, 0x44, 
    0x23, 0x2, 0x14c, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x53, 0x57, 0x5a, 
    0x5e, 0x6a, 0x6e, 0x76, 0x79, 0x80, 0x89, 0x94, 0x99, 0x9d, 0xa2, 0xa5, 
    0xac, 0xb3, 0xba, 0xc1, 0xc9, 0xcb, 0xd3, 0xd7, 0xde, 0xe2, 0xea, 0xf5, 
    0x103, 0x106, 0x10e, 0x116, 0x11e, 0x124, 0x12b, 0x130, 0x135, 0x13a, 
    0x13f, 0x144, 0x149, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SysYParser::Initializer SysYParser::_init;


// Generated from SysY.g4 by ANTLR 4.10.1


#include "SysYVisitor.h"

#include "SysYParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SysYParserStaticData final {
  SysYParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SysYParserStaticData(const SysYParserStaticData&) = delete;
  SysYParserStaticData(SysYParserStaticData&&) = delete;
  SysYParserStaticData& operator=(const SysYParserStaticData&) = delete;
  SysYParserStaticData& operator=(SysYParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag sysyParserOnceFlag;
SysYParserStaticData *sysyParserStaticData = nullptr;

void sysyParserInitialize() {
  assert(sysyParserStaticData == nullptr);
  auto staticData = std::make_unique<SysYParserStaticData>(
    std::vector<std::string>{
      "program", "compUnit", "decl", "constDecl", "bType", "constDefLi", 
      "constDef", "constInitVal", "constInitValLi", "constExpLi", "varDecl", 
      "varDefLi", "varDef", "initVal", "initValLi", "funcDef", "funcType", 
      "funcFParams", "funcFParam", "expLi", "block", "blockItemLi", "blockItem", 
      "stmt", "exp", "cond", "lVal", "primaryExp", "number", "unaryExp", 
      "unaryOp", "funcRParams", "mulExp", "addExp", "relExp", "eqExp", "lAndExp", 
      "lOrExp", "constExp"
    },
    std::vector<std::string>{
      "", "';'", "','", "'='", "'{'", "'}'", "'['", "']'", "'('", "')'", 
      "'+'", "'-'", "'!'", "'*'", "'/'", "'%'", "'<'", "'>'", "'<='", "'>='", 
      "'=='", "'!='", "'&&'", "'||'", "", "", "", "'void'", "'int'", "'float'", 
      "'const'", "'if'", "'else'", "'while'", "'break'", "'continue'", "'return'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "WhiteSpace", "LineComment", "BlockComment", 
      "Void", "Int", "Float", "Const", "If", "Else", "While", "Break", "Continue", 
      "Return", "Decimal", "Octal", "Hexadecimal", "FloatLiteral", "Identifier"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,41,342,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,1,0,4,0,80,8,0,11,0,12,0,81,1,1,1,1,
  	3,1,86,8,1,1,1,3,1,89,8,1,1,2,1,2,3,2,93,8,2,1,3,1,3,1,3,1,3,1,3,1,4,
  	1,4,1,5,1,5,1,5,5,5,105,8,5,10,5,12,5,108,9,5,1,6,1,6,3,6,112,8,6,1,6,
  	1,6,1,6,1,7,1,7,1,7,3,7,120,8,7,1,7,3,7,123,8,7,1,8,1,8,1,8,5,8,128,8,
  	8,10,8,12,8,131,9,8,1,9,1,9,1,9,1,9,4,9,137,8,9,11,9,12,9,138,1,10,1,
  	10,1,10,1,10,1,11,1,11,1,11,5,11,148,8,11,10,11,12,11,151,9,11,1,12,1,
  	12,3,12,155,8,12,1,12,1,12,3,12,159,8,12,1,12,1,12,3,12,163,8,12,1,13,
  	1,13,1,13,3,13,168,8,13,1,13,3,13,171,8,13,1,14,1,14,1,14,5,14,176,8,
  	14,10,14,12,14,179,9,14,1,15,1,15,1,15,1,15,3,15,185,8,15,1,15,1,15,1,
  	15,1,16,1,16,3,16,192,8,16,1,17,1,17,1,17,5,17,197,8,17,10,17,12,17,200,
  	9,17,1,18,1,18,1,18,1,18,1,18,3,18,207,8,18,3,18,209,8,18,1,19,1,19,1,
  	19,1,19,4,19,215,8,19,11,19,12,19,216,1,20,1,20,3,20,221,8,20,1,20,1,
  	20,1,21,4,21,226,8,21,11,21,12,21,227,1,22,1,22,3,22,232,8,22,1,23,1,
  	23,1,23,1,23,1,23,1,23,3,23,240,8,23,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	23,1,23,1,23,3,23,251,8,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,
  	23,1,23,1,23,1,23,3,23,265,8,23,1,23,3,23,268,8,23,1,24,1,24,1,25,1,25,
  	1,26,1,26,3,26,276,8,26,1,27,1,27,1,27,1,27,1,27,1,27,3,27,284,8,27,1,
  	28,1,28,1,29,1,29,1,29,1,29,3,29,292,8,29,1,29,1,29,1,29,1,29,3,29,298,
  	8,29,1,30,1,30,1,31,1,31,1,31,5,31,305,8,31,10,31,12,31,308,9,31,1,32,
  	1,32,1,32,3,32,313,8,32,1,33,1,33,1,33,3,33,318,8,33,1,34,1,34,1,34,3,
  	34,323,8,34,1,35,1,35,1,35,3,35,328,8,35,1,36,1,36,1,36,3,36,333,8,36,
  	1,37,1,37,1,37,3,37,338,8,37,1,38,1,38,1,38,0,0,39,0,2,4,6,8,10,12,14,
  	16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,
  	62,64,66,68,70,72,74,76,0,7,1,0,28,29,1,0,37,40,1,0,10,12,1,0,13,15,1,
  	0,10,11,1,0,16,19,1,0,20,21,351,0,79,1,0,0,0,2,85,1,0,0,0,4,92,1,0,0,
  	0,6,94,1,0,0,0,8,99,1,0,0,0,10,101,1,0,0,0,12,109,1,0,0,0,14,122,1,0,
  	0,0,16,124,1,0,0,0,18,136,1,0,0,0,20,140,1,0,0,0,22,144,1,0,0,0,24,162,
  	1,0,0,0,26,170,1,0,0,0,28,172,1,0,0,0,30,180,1,0,0,0,32,191,1,0,0,0,34,
  	193,1,0,0,0,36,201,1,0,0,0,38,214,1,0,0,0,40,218,1,0,0,0,42,225,1,0,0,
  	0,44,231,1,0,0,0,46,267,1,0,0,0,48,269,1,0,0,0,50,271,1,0,0,0,52,273,
  	1,0,0,0,54,283,1,0,0,0,56,285,1,0,0,0,58,297,1,0,0,0,60,299,1,0,0,0,62,
  	301,1,0,0,0,64,309,1,0,0,0,66,314,1,0,0,0,68,319,1,0,0,0,70,324,1,0,0,
  	0,72,329,1,0,0,0,74,334,1,0,0,0,76,339,1,0,0,0,78,80,3,2,1,0,79,78,1,
  	0,0,0,80,81,1,0,0,0,81,79,1,0,0,0,81,82,1,0,0,0,82,1,1,0,0,0,83,86,3,
  	30,15,0,84,86,3,4,2,0,85,83,1,0,0,0,85,84,1,0,0,0,86,88,1,0,0,0,87,89,
  	3,2,1,0,88,87,1,0,0,0,88,89,1,0,0,0,89,3,1,0,0,0,90,93,3,6,3,0,91,93,
  	3,20,10,0,92,90,1,0,0,0,92,91,1,0,0,0,93,5,1,0,0,0,94,95,5,30,0,0,95,
  	96,3,8,4,0,96,97,3,10,5,0,97,98,5,1,0,0,98,7,1,0,0,0,99,100,7,0,0,0,100,
  	9,1,0,0,0,101,106,3,12,6,0,102,103,5,2,0,0,103,105,3,12,6,0,104,102,1,
  	0,0,0,105,108,1,0,0,0,106,104,1,0,0,0,106,107,1,0,0,0,107,11,1,0,0,0,
  	108,106,1,0,0,0,109,111,5,41,0,0,110,112,3,18,9,0,111,110,1,0,0,0,111,
  	112,1,0,0,0,112,113,1,0,0,0,113,114,5,3,0,0,114,115,3,14,7,0,115,13,1,
  	0,0,0,116,123,3,76,38,0,117,119,5,4,0,0,118,120,3,16,8,0,119,118,1,0,
  	0,0,119,120,1,0,0,0,120,121,1,0,0,0,121,123,5,5,0,0,122,116,1,0,0,0,122,
  	117,1,0,0,0,123,15,1,0,0,0,124,129,3,14,7,0,125,126,5,2,0,0,126,128,3,
  	14,7,0,127,125,1,0,0,0,128,131,1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,
  	0,130,17,1,0,0,0,131,129,1,0,0,0,132,133,5,6,0,0,133,134,3,76,38,0,134,
  	135,5,7,0,0,135,137,1,0,0,0,136,132,1,0,0,0,137,138,1,0,0,0,138,136,1,
  	0,0,0,138,139,1,0,0,0,139,19,1,0,0,0,140,141,3,8,4,0,141,142,3,22,11,
  	0,142,143,5,1,0,0,143,21,1,0,0,0,144,149,3,24,12,0,145,146,5,2,0,0,146,
  	148,3,24,12,0,147,145,1,0,0,0,148,151,1,0,0,0,149,147,1,0,0,0,149,150,
  	1,0,0,0,150,23,1,0,0,0,151,149,1,0,0,0,152,154,5,41,0,0,153,155,3,18,
  	9,0,154,153,1,0,0,0,154,155,1,0,0,0,155,163,1,0,0,0,156,158,5,41,0,0,
  	157,159,3,18,9,0,158,157,1,0,0,0,158,159,1,0,0,0,159,160,1,0,0,0,160,
  	161,5,3,0,0,161,163,3,26,13,0,162,152,1,0,0,0,162,156,1,0,0,0,163,25,
  	1,0,0,0,164,171,3,48,24,0,165,167,5,4,0,0,166,168,3,28,14,0,167,166,1,
  	0,0,0,167,168,1,0,0,0,168,169,1,0,0,0,169,171,5,5,0,0,170,164,1,0,0,0,
  	170,165,1,0,0,0,171,27,1,0,0,0,172,177,3,26,13,0,173,174,5,2,0,0,174,
  	176,3,26,13,0,175,173,1,0,0,0,176,179,1,0,0,0,177,175,1,0,0,0,177,178,
  	1,0,0,0,178,29,1,0,0,0,179,177,1,0,0,0,180,181,3,32,16,0,181,182,5,41,
  	0,0,182,184,5,8,0,0,183,185,3,34,17,0,184,183,1,0,0,0,184,185,1,0,0,0,
  	185,186,1,0,0,0,186,187,5,9,0,0,187,188,3,40,20,0,188,31,1,0,0,0,189,
  	192,3,8,4,0,190,192,5,27,0,0,191,189,1,0,0,0,191,190,1,0,0,0,192,33,1,
  	0,0,0,193,198,3,36,18,0,194,195,5,2,0,0,195,197,3,36,18,0,196,194,1,0,
  	0,0,197,200,1,0,0,0,198,196,1,0,0,0,198,199,1,0,0,0,199,35,1,0,0,0,200,
  	198,1,0,0,0,201,202,3,8,4,0,202,208,5,41,0,0,203,204,5,6,0,0,204,206,
  	5,7,0,0,205,207,3,38,19,0,206,205,1,0,0,0,206,207,1,0,0,0,207,209,1,0,
  	0,0,208,203,1,0,0,0,208,209,1,0,0,0,209,37,1,0,0,0,210,211,5,6,0,0,211,
  	212,3,48,24,0,212,213,5,7,0,0,213,215,1,0,0,0,214,210,1,0,0,0,215,216,
  	1,0,0,0,216,214,1,0,0,0,216,217,1,0,0,0,217,39,1,0,0,0,218,220,5,4,0,
  	0,219,221,3,42,21,0,220,219,1,0,0,0,220,221,1,0,0,0,221,222,1,0,0,0,222,
  	223,5,5,0,0,223,41,1,0,0,0,224,226,3,44,22,0,225,224,1,0,0,0,226,227,
  	1,0,0,0,227,225,1,0,0,0,227,228,1,0,0,0,228,43,1,0,0,0,229,232,3,4,2,
  	0,230,232,3,46,23,0,231,229,1,0,0,0,231,230,1,0,0,0,232,45,1,0,0,0,233,
  	234,3,52,26,0,234,235,5,3,0,0,235,236,3,48,24,0,236,237,5,1,0,0,237,268,
  	1,0,0,0,238,240,3,48,24,0,239,238,1,0,0,0,239,240,1,0,0,0,240,241,1,0,
  	0,0,241,268,5,1,0,0,242,268,3,40,20,0,243,244,5,31,0,0,244,245,5,8,0,
  	0,245,246,3,50,25,0,246,247,5,9,0,0,247,250,3,46,23,0,248,249,5,32,0,
  	0,249,251,3,46,23,0,250,248,1,0,0,0,250,251,1,0,0,0,251,268,1,0,0,0,252,
  	253,5,33,0,0,253,254,5,8,0,0,254,255,3,50,25,0,255,256,5,9,0,0,256,257,
  	3,46,23,0,257,268,1,0,0,0,258,259,5,34,0,0,259,268,5,1,0,0,260,261,5,
  	35,0,0,261,268,5,1,0,0,262,264,5,36,0,0,263,265,3,48,24,0,264,263,1,0,
  	0,0,264,265,1,0,0,0,265,266,1,0,0,0,266,268,5,1,0,0,267,233,1,0,0,0,267,
  	239,1,0,0,0,267,242,1,0,0,0,267,243,1,0,0,0,267,252,1,0,0,0,267,258,1,
  	0,0,0,267,260,1,0,0,0,267,262,1,0,0,0,268,47,1,0,0,0,269,270,3,66,33,
  	0,270,49,1,0,0,0,271,272,3,74,37,0,272,51,1,0,0,0,273,275,5,41,0,0,274,
  	276,3,38,19,0,275,274,1,0,0,0,275,276,1,0,0,0,276,53,1,0,0,0,277,278,
  	5,8,0,0,278,279,3,48,24,0,279,280,5,9,0,0,280,284,1,0,0,0,281,284,3,52,
  	26,0,282,284,3,56,28,0,283,277,1,0,0,0,283,281,1,0,0,0,283,282,1,0,0,
  	0,284,55,1,0,0,0,285,286,7,1,0,0,286,57,1,0,0,0,287,298,3,54,27,0,288,
  	289,5,41,0,0,289,291,5,8,0,0,290,292,3,62,31,0,291,290,1,0,0,0,291,292,
  	1,0,0,0,292,293,1,0,0,0,293,298,5,9,0,0,294,295,3,60,30,0,295,296,3,58,
  	29,0,296,298,1,0,0,0,297,287,1,0,0,0,297,288,1,0,0,0,297,294,1,0,0,0,
  	298,59,1,0,0,0,299,300,7,2,0,0,300,61,1,0,0,0,301,306,3,48,24,0,302,303,
  	5,2,0,0,303,305,3,48,24,0,304,302,1,0,0,0,305,308,1,0,0,0,306,304,1,0,
  	0,0,306,307,1,0,0,0,307,63,1,0,0,0,308,306,1,0,0,0,309,312,3,58,29,0,
  	310,311,7,3,0,0,311,313,3,64,32,0,312,310,1,0,0,0,312,313,1,0,0,0,313,
  	65,1,0,0,0,314,317,3,64,32,0,315,316,7,4,0,0,316,318,3,66,33,0,317,315,
  	1,0,0,0,317,318,1,0,0,0,318,67,1,0,0,0,319,322,3,66,33,0,320,321,7,5,
  	0,0,321,323,3,68,34,0,322,320,1,0,0,0,322,323,1,0,0,0,323,69,1,0,0,0,
  	324,327,3,68,34,0,325,326,7,6,0,0,326,328,3,70,35,0,327,325,1,0,0,0,327,
  	328,1,0,0,0,328,71,1,0,0,0,329,332,3,70,35,0,330,331,5,22,0,0,331,333,
  	3,72,36,0,332,330,1,0,0,0,332,333,1,0,0,0,333,73,1,0,0,0,334,337,3,72,
  	36,0,335,336,5,23,0,0,336,338,3,74,37,0,337,335,1,0,0,0,337,338,1,0,0,
  	0,338,75,1,0,0,0,339,340,3,66,33,0,340,77,1,0,0,0,41,81,85,88,92,106,
  	111,119,122,129,138,149,154,158,162,167,170,177,184,191,198,206,208,216,
  	220,227,231,239,250,264,267,275,283,291,297,306,312,317,322,327,332,337
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sysyParserStaticData = staticData.release();
}

}

SysYParser::SysYParser(TokenStream *input) : SysYParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SysYParser::SysYParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SysYParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *sysyParserStaticData->atn, sysyParserStaticData->decisionToDFA, sysyParserStaticData->sharedContextCache, options);
}

SysYParser::~SysYParser() {
  delete _interpreter;
}

const atn::ATN& SysYParser::getATN() const {
  return *sysyParserStaticData->atn;
}

std::string SysYParser::getGrammarFileName() const {
  return "SysY.g4";
}

const std::vector<std::string>& SysYParser::getRuleNames() const {
  return sysyParserStaticData->ruleNames;
}

const dfa::Vocabulary& SysYParser::getVocabulary() const {
  return sysyParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SysYParser::getSerializedATN() const {
  return sysyParserStaticData->serializedATN;
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


std::any SysYParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ProgramContext* SysYParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, SysYParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any SysYParser::CompUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitCompUnit(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::CompUnitContext* SysYParser::compUnit() {
  CompUnitContext *_localctx = _tracker.createInstance<CompUnitContext>(_ctx, getState());
  enterRule(_localctx, 2, SysYParser::RuleCompUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

    default:
      break;
    }
    setState(88);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(87);
      compUnit();
      break;
    }

    default:
      break;
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


std::any SysYParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::DeclContext* SysYParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 4, SysYParser::RuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any SysYParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDeclContext* SysYParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, SysYParser::RuleConstDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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


std::any SysYParser::BTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBType(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BTypeContext* SysYParser::bType() {
  BTypeContext *_localctx = _tracker.createInstance<BTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, SysYParser::RuleBType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

std::vector<SysYParser::ConstDefContext *> SysYParser::ConstDefLiContext::constDef() {
  return getRuleContexts<SysYParser::ConstDefContext>();
}

SysYParser::ConstDefContext* SysYParser::ConstDefLiContext::constDef(size_t i) {
  return getRuleContext<SysYParser::ConstDefContext>(i);
}


size_t SysYParser::ConstDefLiContext::getRuleIndex() const {
  return SysYParser::RuleConstDefLi;
}


std::any SysYParser::ConstDefLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstDefLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDefLiContext* SysYParser::constDefLi() {
  ConstDefLiContext *_localctx = _tracker.createInstance<ConstDefLiContext>(_ctx, getState());
  enterRule(_localctx, 10, SysYParser::RuleConstDefLi);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    constDef();
    setState(106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(102);
      match(SysYParser::T__1);
      setState(103);
      constDef();
      setState(108);
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


std::any SysYParser::ConstDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstDefContext* SysYParser::constDef() {
  ConstDefContext *_localctx = _tracker.createInstance<ConstDefContext>(_ctx, getState());
  enterRule(_localctx, 12, SysYParser::RuleConstDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(SysYParser::Identifier);
    setState(111);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__5) {
      setState(110);
      constExpLi();
    }
    setState(113);
    match(SysYParser::T__2);
    setState(114);
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


size_t SysYParser::ConstInitValContext::getRuleIndex() const {
  return SysYParser::RuleConstInitVal;
}

void SysYParser::ConstInitValContext::copyFrom(ConstInitValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ListConstInitValContext ------------------------------------------------------------------

SysYParser::ConstInitValLiContext* SysYParser::ListConstInitValContext::constInitValLi() {
  return getRuleContext<SysYParser::ConstInitValLiContext>(0);
}

SysYParser::ListConstInitValContext::ListConstInitValContext(ConstInitValContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ListConstInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitListConstInitVal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SingleConstInitValContext ------------------------------------------------------------------

SysYParser::ConstExpContext* SysYParser::SingleConstInitValContext::constExp() {
  return getRuleContext<SysYParser::ConstExpContext>(0);
}

SysYParser::SingleConstInitValContext::SingleConstInitValContext(ConstInitValContext *ctx) { copyFrom(ctx); }


std::any SysYParser::SingleConstInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitSingleConstInitVal(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::ConstInitValContext* SysYParser::constInitVal() {
  ConstInitValContext *_localctx = _tracker.createInstance<ConstInitValContext>(_ctx, getState());
  enterRule(_localctx, 14, SysYParser::RuleConstInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(122);
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
        _localctx = _tracker.createInstance<SysYParser::SingleConstInitValContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(116);
        constExp();
        break;
      }

      case SysYParser::T__3: {
        _localctx = _tracker.createInstance<SysYParser::ListConstInitValContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(117);
        match(SysYParser::T__3);
        setState(119);
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
          setState(118);
          constInitValLi();
        }
        setState(121);
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


std::any SysYParser::ConstInitValLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstInitValLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstInitValLiContext* SysYParser::constInitValLi() {
  ConstInitValLiContext *_localctx = _tracker.createInstance<ConstInitValLiContext>(_ctx, getState());
  enterRule(_localctx, 16, SysYParser::RuleConstInitValLi);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    constInitVal();
    setState(129);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(125);
      match(SysYParser::T__1);
      setState(126);
      constInitVal();
      setState(131);
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


std::any SysYParser::ConstExpLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstExpLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstExpLiContext* SysYParser::constExpLi() {
  ConstExpLiContext *_localctx = _tracker.createInstance<ConstExpLiContext>(_ctx, getState());
  enterRule(_localctx, 18, SysYParser::RuleConstExpLi);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(132);
      match(SysYParser::T__5);
      setState(133);
      constExp();
      setState(134);
      match(SysYParser::T__6);
      setState(138); 
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


std::any SysYParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::VarDeclContext* SysYParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, SysYParser::RuleVarDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    bType();
    setState(141);
    varDefLi();
    setState(142);
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


std::any SysYParser::VarDefLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitVarDefLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::VarDefLiContext* SysYParser::varDefLi() {
  VarDefLiContext *_localctx = _tracker.createInstance<VarDefLiContext>(_ctx, getState());
  enterRule(_localctx, 22, SysYParser::RuleVarDefLi);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    varDef();
    setState(149);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(145);
      match(SysYParser::T__1);
      setState(146);
      varDef();
      setState(151);
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


size_t SysYParser::VarDefContext::getRuleIndex() const {
  return SysYParser::RuleVarDef;
}

void SysYParser::VarDefContext::copyFrom(VarDefContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UninitVarDefContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::UninitVarDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

SysYParser::ConstExpLiContext* SysYParser::UninitVarDefContext::constExpLi() {
  return getRuleContext<SysYParser::ConstExpLiContext>(0);
}

SysYParser::UninitVarDefContext::UninitVarDefContext(VarDefContext *ctx) { copyFrom(ctx); }


std::any SysYParser::UninitVarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUninitVarDef(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InitVarDefContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::InitVarDefContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

SysYParser::InitValContext* SysYParser::InitVarDefContext::initVal() {
  return getRuleContext<SysYParser::InitValContext>(0);
}

SysYParser::ConstExpLiContext* SysYParser::InitVarDefContext::constExpLi() {
  return getRuleContext<SysYParser::ConstExpLiContext>(0);
}

SysYParser::InitVarDefContext::InitVarDefContext(VarDefContext *ctx) { copyFrom(ctx); }


std::any SysYParser::InitVarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitInitVarDef(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::VarDefContext* SysYParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 24, SysYParser::RuleVarDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SysYParser::UninitVarDefContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(152);
      match(SysYParser::Identifier);
      setState(154);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SysYParser::T__5) {
        setState(153);
        constExpLi();
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SysYParser::InitVarDefContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(156);
      match(SysYParser::Identifier);
      setState(158);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SysYParser::T__5) {
        setState(157);
        constExpLi();
      }
      setState(160);
      match(SysYParser::T__2);
      setState(161);
      initVal();
      break;
    }

    default:
      break;
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


size_t SysYParser::InitValContext::getRuleIndex() const {
  return SysYParser::RuleInitVal;
}

void SysYParser::InitValContext::copyFrom(InitValContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SingleInitValContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::SingleInitValContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::SingleInitValContext::SingleInitValContext(InitValContext *ctx) { copyFrom(ctx); }


std::any SysYParser::SingleInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitSingleInitVal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListInitValContext ------------------------------------------------------------------

SysYParser::InitValLiContext* SysYParser::ListInitValContext::initValLi() {
  return getRuleContext<SysYParser::InitValLiContext>(0);
}

SysYParser::ListInitValContext::ListInitValContext(InitValContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ListInitValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitListInitVal(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::InitValContext* SysYParser::initVal() {
  InitValContext *_localctx = _tracker.createInstance<InitValContext>(_ctx, getState());
  enterRule(_localctx, 26, SysYParser::RuleInitVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(170);
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
        _localctx = _tracker.createInstance<SysYParser::SingleInitValContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(164);
        exp();
        break;
      }

      case SysYParser::T__3: {
        _localctx = _tracker.createInstance<SysYParser::ListInitValContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(165);
        match(SysYParser::T__3);
        setState(167);
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
          setState(166);
          initValLi();
        }
        setState(169);
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


std::any SysYParser::InitValLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitInitValLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::InitValLiContext* SysYParser::initValLi() {
  InitValLiContext *_localctx = _tracker.createInstance<InitValLiContext>(_ctx, getState());
  enterRule(_localctx, 28, SysYParser::RuleInitValLi);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    initVal();
    setState(177);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(173);
      match(SysYParser::T__1);
      setState(174);
      initVal();
      setState(179);
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


std::any SysYParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncDefContext* SysYParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 30, SysYParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    funcType();
    setState(181);
    match(SysYParser::Identifier);
    setState(182);
    match(SysYParser::T__7);
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::Int

    || _la == SysYParser::Float) {
      setState(183);
      funcFParams();
    }
    setState(186);
    match(SysYParser::T__8);
    setState(187);
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


std::any SysYParser::FuncTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncType(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncTypeContext* SysYParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 32, SysYParser::RuleFuncType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(191);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Int:
      case SysYParser::Float: {
        enterOuterAlt(_localctx, 1);
        setState(189);
        bType();
        break;
      }

      case SysYParser::Void: {
        enterOuterAlt(_localctx, 2);
        setState(190);
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


std::any SysYParser::FuncFParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncFParams(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncFParamsContext* SysYParser::funcFParams() {
  FuncFParamsContext *_localctx = _tracker.createInstance<FuncFParamsContext>(_ctx, getState());
  enterRule(_localctx, 34, SysYParser::RuleFuncFParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    funcFParam();
    setState(198);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(194);
      match(SysYParser::T__1);
      setState(195);
      funcFParam();
      setState(200);
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


std::any SysYParser::FuncFParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncFParam(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncFParamContext* SysYParser::funcFParam() {
  FuncFParamContext *_localctx = _tracker.createInstance<FuncFParamContext>(_ctx, getState());
  enterRule(_localctx, 36, SysYParser::RuleFuncFParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    bType();
    setState(202);
    match(SysYParser::Identifier);
    setState(208);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__5) {
      setState(203);
      match(SysYParser::T__5);
      setState(204);
      match(SysYParser::T__6);
      setState(206);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SysYParser::T__5) {
        setState(205);
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


std::any SysYParser::ExpLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitExpLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ExpLiContext* SysYParser::expLi() {
  ExpLiContext *_localctx = _tracker.createInstance<ExpLiContext>(_ctx, getState());
  enterRule(_localctx, 38, SysYParser::RuleExpLi);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(210);
      match(SysYParser::T__5);
      setState(211);
      exp();
      setState(212);
      match(SysYParser::T__6);
      setState(216); 
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


std::any SysYParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockContext* SysYParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 40, SysYParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(SysYParser::T__3);
    setState(220);
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
      setState(219);
      blockItemLi();
    }
    setState(222);
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


std::any SysYParser::BlockItemLiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlockItemLi(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockItemLiContext* SysYParser::blockItemLi() {
  BlockItemLiContext *_localctx = _tracker.createInstance<BlockItemLiContext>(_ctx, getState());
  enterRule(_localctx, 42, SysYParser::RuleBlockItemLi);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(224);
      blockItem();
      setState(227); 
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


std::any SysYParser::BlockItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlockItem(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::BlockItemContext* SysYParser::blockItem() {
  BlockItemContext *_localctx = _tracker.createInstance<BlockItemContext>(_ctx, getState());
  enterRule(_localctx, 44, SysYParser::RuleBlockItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(231);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::Int:
      case SysYParser::Float:
      case SysYParser::Const: {
        enterOuterAlt(_localctx, 1);
        setState(229);
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
        setState(230);
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


std::any SysYParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any SysYParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any SysYParser::BlockStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitBlockStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::AssignStmtContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::ExpContext* SysYParser::AssignStmtContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::AssignStmtContext::AssignStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakStmtContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::BreakStmtContext::Break() {
  return getToken(SysYParser::Break, 0);
}

SysYParser::BreakStmtContext::BreakStmtContext(StmtContext *ctx) { copyFrom(ctx); }


std::any SysYParser::BreakStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any SysYParser::ExpStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any SysYParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
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


std::any SysYParser::ContinueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitContinueStmt(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::StmtContext* SysYParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 46, SysYParser::RuleStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(267);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SysYParser::AssignStmtContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(233);
      lVal();
      setState(234);
      match(SysYParser::T__2);
      setState(235);
      exp();
      setState(236);
      match(SysYParser::T__0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SysYParser::ExpStmtContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(239);
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
        setState(238);
        exp();
      }
      setState(241);
      match(SysYParser::T__0);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SysYParser::BlockStmtContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(242);
      block();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<SysYParser::IfStmtContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(243);
      match(SysYParser::If);
      setState(244);
      match(SysYParser::T__7);
      setState(245);
      cond();
      setState(246);
      match(SysYParser::T__8);
      setState(247);
      stmt();
      setState(250);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
      case 1: {
        setState(248);
        match(SysYParser::Else);
        setState(249);
        stmt();
        break;
      }

      default:
        break;
      }
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<SysYParser::WhileStmtContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(252);
      match(SysYParser::While);
      setState(253);
      match(SysYParser::T__7);
      setState(254);
      cond();
      setState(255);
      match(SysYParser::T__8);
      setState(256);
      stmt();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<SysYParser::BreakStmtContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(258);
      match(SysYParser::Break);
      setState(259);
      match(SysYParser::T__0);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<SysYParser::ContinueStmtContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(260);
      match(SysYParser::Continue);
      setState(261);
      match(SysYParser::T__0);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<SysYParser::ReturnStmtContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(262);
      match(SysYParser::Return);
      setState(264);
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
        setState(263);
        exp();
      }
      setState(266);
      match(SysYParser::T__0);
      break;
    }

    default:
      break;
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


std::any SysYParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ExpContext* SysYParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 48, SysYParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
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


std::any SysYParser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::CondContext* SysYParser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 50, SysYParser::RuleCond);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(271);
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


std::any SysYParser::LValContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLVal(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LValContext* SysYParser::lVal() {
  LValContext *_localctx = _tracker.createInstance<LValContext>(_ctx, getState());
  enterRule(_localctx, 52, SysYParser::RuleLVal);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    match(SysYParser::Identifier);
    setState(275);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__5) {
      setState(274);
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


size_t SysYParser::PrimaryExpContext::getRuleIndex() const {
  return SysYParser::RulePrimaryExp;
}

void SysYParser::PrimaryExpContext::copyFrom(PrimaryExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NumberExpContext ------------------------------------------------------------------

SysYParser::NumberContext* SysYParser::NumberExpContext::number() {
  return getRuleContext<SysYParser::NumberContext>(0);
}

SysYParser::NumberExpContext::NumberExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::NumberExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitNumberExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedExpContext ------------------------------------------------------------------

SysYParser::ExpContext* SysYParser::ParenthesizedExpContext::exp() {
  return getRuleContext<SysYParser::ExpContext>(0);
}

SysYParser::ParenthesizedExpContext::ParenthesizedExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::ParenthesizedExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitParenthesizedExp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LvalExpContext ------------------------------------------------------------------

SysYParser::LValContext* SysYParser::LvalExpContext::lVal() {
  return getRuleContext<SysYParser::LValContext>(0);
}

SysYParser::LvalExpContext::LvalExpContext(PrimaryExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::LvalExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLvalExp(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::PrimaryExpContext* SysYParser::primaryExp() {
  PrimaryExpContext *_localctx = _tracker.createInstance<PrimaryExpContext>(_ctx, getState());
  enterRule(_localctx, 54, SysYParser::RulePrimaryExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SysYParser::T__7: {
        _localctx = _tracker.createInstance<SysYParser::ParenthesizedExpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(277);
        match(SysYParser::T__7);
        setState(278);
        exp();
        setState(279);
        match(SysYParser::T__8);
        break;
      }

      case SysYParser::Identifier: {
        _localctx = _tracker.createInstance<SysYParser::LvalExpContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(281);
        lVal();
        break;
      }

      case SysYParser::Decimal:
      case SysYParser::Octal:
      case SysYParser::Hexadecimal:
      case SysYParser::FloatLiteral: {
        _localctx = _tracker.createInstance<SysYParser::NumberExpContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(282);
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


std::any SysYParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::NumberContext* SysYParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 56, SysYParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
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

//----------------- UnaryExpWithOpContext ------------------------------------------------------------------

SysYParser::UnaryOpContext* SysYParser::UnaryExpWithOpContext::unaryOp() {
  return getRuleContext<SysYParser::UnaryOpContext>(0);
}

SysYParser::UnaryExpContext* SysYParser::UnaryExpWithOpContext::unaryExp() {
  return getRuleContext<SysYParser::UnaryExpContext>(0);
}

SysYParser::UnaryExpWithOpContext::UnaryExpWithOpContext(UnaryExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::UnaryExpWithOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnaryExpWithOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallContext ------------------------------------------------------------------

tree::TerminalNode* SysYParser::FunctionCallContext::Identifier() {
  return getToken(SysYParser::Identifier, 0);
}

SysYParser::FuncRParamsContext* SysYParser::FunctionCallContext::funcRParams() {
  return getRuleContext<SysYParser::FuncRParamsContext>(0);
}

SysYParser::FunctionCallContext::FunctionCallContext(UnaryExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExpWithoutOpContext ------------------------------------------------------------------

SysYParser::PrimaryExpContext* SysYParser::UnaryExpWithoutOpContext::primaryExp() {
  return getRuleContext<SysYParser::PrimaryExpContext>(0);
}

SysYParser::UnaryExpWithoutOpContext::UnaryExpWithoutOpContext(UnaryExpContext *ctx) { copyFrom(ctx); }


std::any SysYParser::UnaryExpWithoutOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnaryExpWithoutOp(this);
  else
    return visitor->visitChildren(this);
}
SysYParser::UnaryExpContext* SysYParser::unaryExp() {
  UnaryExpContext *_localctx = _tracker.createInstance<UnaryExpContext>(_ctx, getState());
  enterRule(_localctx, 58, SysYParser::RuleUnaryExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(297);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<SysYParser::UnaryExpWithoutOpContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(287);
      primaryExp();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SysYParser::FunctionCallContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(288);
      match(SysYParser::Identifier);
      setState(289);
      match(SysYParser::T__7);
      setState(291);
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
        setState(290);
        funcRParams();
      }
      setState(293);
      match(SysYParser::T__8);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<SysYParser::UnaryExpWithOpContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(294);
      unaryOp();
      setState(295);
      unaryExp();
      break;
    }

    default:
      break;
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


std::any SysYParser::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::UnaryOpContext* SysYParser::unaryOp() {
  UnaryOpContext *_localctx = _tracker.createInstance<UnaryOpContext>(_ctx, getState());
  enterRule(_localctx, 60, SysYParser::RuleUnaryOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
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

std::vector<SysYParser::ExpContext *> SysYParser::FuncRParamsContext::exp() {
  return getRuleContexts<SysYParser::ExpContext>();
}

SysYParser::ExpContext* SysYParser::FuncRParamsContext::exp(size_t i) {
  return getRuleContext<SysYParser::ExpContext>(i);
}


size_t SysYParser::FuncRParamsContext::getRuleIndex() const {
  return SysYParser::RuleFuncRParams;
}


std::any SysYParser::FuncRParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitFuncRParams(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::FuncRParamsContext* SysYParser::funcRParams() {
  FuncRParamsContext *_localctx = _tracker.createInstance<FuncRParamsContext>(_ctx, getState());
  enterRule(_localctx, 62, SysYParser::RuleFuncRParams);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    exp();
    setState(306);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SysYParser::T__1) {
      setState(302);
      match(SysYParser::T__1);
      setState(303);
      exp();
      setState(308);
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


std::any SysYParser::MulExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitMulExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::MulExpContext* SysYParser::mulExp() {
  MulExpContext *_localctx = _tracker.createInstance<MulExpContext>(_ctx, getState());
  enterRule(_localctx, 64, SysYParser::RuleMulExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    unaryExp();
    setState(312);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__12)
      | (1ULL << SysYParser::T__13)
      | (1ULL << SysYParser::T__14))) != 0)) {
      setState(310);
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
      setState(311);
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


std::any SysYParser::AddExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitAddExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::AddExpContext* SysYParser::addExp() {
  AddExpContext *_localctx = _tracker.createInstance<AddExpContext>(_ctx, getState());
  enterRule(_localctx, 66, SysYParser::RuleAddExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    mulExp();
    setState(317);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__9

    || _la == SysYParser::T__10) {
      setState(315);
      _la = _input->LA(1);
      if (!(_la == SysYParser::T__9

      || _la == SysYParser::T__10)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(316);
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


std::any SysYParser::RelExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitRelExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::RelExpContext* SysYParser::relExp() {
  RelExpContext *_localctx = _tracker.createInstance<RelExpContext>(_ctx, getState());
  enterRule(_localctx, 68, SysYParser::RuleRelExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    addExp();
    setState(322);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SysYParser::T__15)
      | (1ULL << SysYParser::T__16)
      | (1ULL << SysYParser::T__17)
      | (1ULL << SysYParser::T__18))) != 0)) {
      setState(320);
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
      setState(321);
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


std::any SysYParser::EqExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitEqExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::EqExpContext* SysYParser::eqExp() {
  EqExpContext *_localctx = _tracker.createInstance<EqExpContext>(_ctx, getState());
  enterRule(_localctx, 70, SysYParser::RuleEqExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(324);
    relExp();
    setState(327);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__19

    || _la == SysYParser::T__20) {
      setState(325);
      _la = _input->LA(1);
      if (!(_la == SysYParser::T__19

      || _la == SysYParser::T__20)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(326);
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


std::any SysYParser::LAndExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLAndExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LAndExpContext* SysYParser::lAndExp() {
  LAndExpContext *_localctx = _tracker.createInstance<LAndExpContext>(_ctx, getState());
  enterRule(_localctx, 72, SysYParser::RuleLAndExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(329);
    eqExp();
    setState(332);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__21) {
      setState(330);
      match(SysYParser::T__21);
      setState(331);
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


std::any SysYParser::LOrExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitLOrExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::LOrExpContext* SysYParser::lOrExp() {
  LOrExpContext *_localctx = _tracker.createInstance<LOrExpContext>(_ctx, getState());
  enterRule(_localctx, 74, SysYParser::RuleLOrExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(334);
    lAndExp();
    setState(337);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SysYParser::T__22) {
      setState(335);
      match(SysYParser::T__22);
      setState(336);
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


std::any SysYParser::ConstExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SysYVisitor*>(visitor))
    return parserVisitor->visitConstExp(this);
  else
    return visitor->visitChildren(this);
}

SysYParser::ConstExpContext* SysYParser::constExp() {
  ConstExpContext *_localctx = _tracker.createInstance<ConstExpContext>(_ctx, getState());
  enterRule(_localctx, 76, SysYParser::RuleConstExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    addExp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void SysYParser::initialize() {
  std::call_once(sysyParserOnceFlag, sysyParserInitialize);
}

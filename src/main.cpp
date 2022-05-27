#include <iostream>
#include <fstream>

#include "frontend/parser/SysYLexer.h"
#include "frontend/parser/SysYParser.h"
#include "define.hpp"
#include "config.hpp"
#include "translation/generate_ir.hpp"

using namespace antlr4;
using namespace knpc;

int main(int argc, char **argv) {

    GC_INIT();

    // if (argc != 2) {
    //     std::cerr << "[error] Input sourcefile required: ./SysY <sourcefile>\n";
    //     return 1;
    // }
    std::ifstream sourceFile;
    // sourceFile.open(argv[1]);
    sourceFile.open("../test/000_main.c");
    
    // lexer & parser part of antlr4
    ANTLRInputStream input(sourceFile);
    SysYLexer lexer(&input);
    lexer.addErrorListener(new BaseErrorListener());
    CommonTokenStream tokens(&lexer);
    SysYParser parser(&tokens);
    std::shared_ptr<antlr4::ANTLRErrorStrategy> handler = std::make_shared<BailErrorStrategy>();
    parser.setErrorHandler(handler);

    // generate ir
    MachineDesc *md = new ArmDesc();
    SysYParser::ProgramContext* treeNode = parser.program(); // root node
    tac::Piece *p = runSemPass1(treeNode, md);

    // p->dump(std::cout); // debug
    // generate asm
    md->emitPieces(NULL, p, std::cout);
    std::cout.flush();

    return 0;
}


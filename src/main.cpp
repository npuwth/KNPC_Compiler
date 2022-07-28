#include <iostream>
#include <fstream>

#include "frontend/parser/SysYLexer.h"
#include "frontend/parser/SysYParser.h"
#include "util/define.hpp"
#include "util/config.hpp"
#include "translation/generate_ir.hpp"

using namespace antlr4;
using namespace knpc;

int main(int argc, char **argv) {
    if(argc == 5) { // functional test
        ;
    } else if(argc == 6) { // performance test
        ;
    } else {
        std::cerr<<"[ERROR] Input Format Error!\nThe Correct Example is as Follows:\n";
        std::cerr<<"[Functional Test] compiler testcase.sysy -S -o testcase.s\n";
        std::cerr<<"[Performance Test] compiler testcase.sysy -S -o testcase.s -O1\n"; 
        knpc_assert(false);
    }
    std::ifstream sourceFile;
    sourceFile.open(argv[1]);
    if(!sourceFile.is_open()) {
        std::cerr<<"[ERROR] Cannot Open Input File!\n";
        knpc_assert(false);
    }
    std::ofstream destFile;
    destFile.open(argv[4]);
    if(!destFile.is_open()) {
        std::cerr<<"[ERROR] Cannot Open Output File!\n";
        knpc_assert(false);
    }
    int module = 0;
    if(argv[2][1] == 'S') { // generate asm code
        module = 0;
    } else if(argv[2][1] == 'T') { // generate TAC (IR)
        module = 1;
    } else {
        std::cerr<<"[ERROR] Module Not Supported!\nUse -S or -T Instead\n";
        knpc_assert(false);
    }
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
    tac::Piece *p = runSemPass1(treeNode, md); // get head piece of IR
    if(module == 0) {
        md->emitPieces(NULL, p, destFile); // generate asm code
        destFile.flush();
    } else if(module == 1) { // generate TAC (IR)
        while(p != NULL) {
            p->dump(destFile);
            p = p->next;
        }
        destFile.flush();
    } else {
        std::cerr<<"[ERROR] Module Not Supported!\nUse -S or -T Instead\n";
        knpc_assert(false);
    }
    return 0;
}

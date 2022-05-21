#include <iostream>

#include "SysYLexer.h"
#include "SysYParser.h"
// #include "Allocator.h"
// #include "CodeGenVisitor.h"
// #include "utils.h"

using namespace antlr4;
using namespace std;

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        std::cerr << "[error] Input sourcefile required: ./SysY <sourcefile>\n";
        return 1;
    }
    ifstream sourceFile;
    sourceFile.open(argv[1]);
    
    // lexer & parser part of antlr4
    ANTLRInputStream input(sourceFile);
    SysYLexer lexer(&input);
    lexer.addErrorListener(new BaseErrorListener());

    CommonTokenStream tokens(&lexer);
    SysYParser parser(&tokens);
    
    
    shared_ptr<antlr4::ANTLRErrorStrategy> handler = make_shared<BailErrorStrategy>();
    parser.setErrorHandler(handler);
    // SysYParser::ProgContext* treeNode = parser.prog();
    SysYParser::ProgramContext* treeNode = parser.program(); // root node

    // customized pass: allocator, typer, codegen and etc.
    // Allocator allocatorVisitor;
    // CodeGenVisitor codeGenVisitor;
    
    // allocatorVisitor.visitProg(treeNode);
    // string asmCode = codeGenVisitor.visitProg(treeNode);

    // We get the asm code!
    // cout << asmCode << endl;
    return 0;
}


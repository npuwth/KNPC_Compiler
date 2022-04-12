#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include "ast.h"
#include "../codegen/codegen.h"
using namespace std;
extern FILE *yyin;
extern int yyparse(std::unique_ptr<BaseAST> &ast);
extern char *optarg;
string readFileIntoString(const string &path)
{
    ifstream input_file(path);
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}
int main(int argc, char *argv[])
{
    assert(argc == 5);
    //输入参数不是5个时报错
    int r_flag = 0;
    const char *input;
    const char *output;
    int opt; 
    int option_index = 0;
    const char *optstring = "o:";
    static struct option long_options[] = {
        {"koopa", required_argument, NULL, 'k'},
        {"riscv", required_argument, NULL, 'r'},
        {0, 0, 0, 0} //防止输入空值

    };
    while ((opt = getopt_long_only(argc,
                                   argv,
                                   optstring,
                                   long_options,
                                   &option_index)) != -1)
    {
        switch (opt)
        {
        case 'o':
            output = optarg;

            break;
        case 'k':
            input = optarg;
            break;
        case 'r':
        {
            input = optarg;
            r_flag = 1;
            break;
        }
        case '?':
            perror("Wrong arg!\n");
            return 1;
            break;
        }
    }

    const char *output_r;
    const char *output_IR;
    if (r_flag == 1)
    {
        string output_IR_s = string(output);
        int pos = output_IR_s.find('.');
        string raw_name_s = output_IR_s.substr(0, pos);
        output_IR_s = raw_name_s + ".koopa";
        output_IR = output_IR_s.c_str();
        output_r = output;
    }
    else
    {
        output_IR = output;
    }

    yyin = fopen(input, "r");
    assert(yyin);
    unique_ptr<BaseAST> ast;
    auto ret = yyparse(ast);
    assert(!ret);

    stringstream IR;
    streambuf *buffer = cout.rdbuf(); // oldbuffer,STDOUT的缓冲区
    cout.rdbuf(IR.rdbuf());
    ast->Dump();
    string string_ir(IR.str());
    cout.rdbuf(buffer); // 重置，重新载入STDOUT的缓冲区
    //cout << string_ir ;
    /*ofstream out;
    out.open(output_IR);
    out << s;
    out.close();*/

    if (r_flag)
    {
        stringstream ASM;
        streambuf *buffer = cout.rdbuf(); // oldbuffer,STDOUT的缓冲区
        cout.rdbuf(ASM.rdbuf());
        print(string_ir.c_str());
        string string_asm(ASM.str());
        cout.rdbuf(buffer); // 重置，重新载入STDOUT的缓冲区
        //cout << string_asm << endl;
        ofstream out;
        out.open(output_r);
        out << string_asm;
        out.close();
    }
    else{
        ofstream out;
        out.open(output_IR);
        out << string_ir;
        out.close();
    }
    return 0;
}

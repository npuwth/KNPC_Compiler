#pragma once
#include <memory>
#include <string>
#include <iostream>
// 所有 AST 的基类
class BaseAST
{
public:
    virtual ~BaseAST() = default;
    virtual void Dump() const = 0;
};

class CompUnitAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> func_def;

    void Dump() const override
    {
        /*std::cout << "CompUnitAST { ";
        func_def->Dump();
        std::cout << " }";*/
        func_def->Dump();
    }
};

class FuncDefAST : public BaseAST
{
public:
    std::unique_ptr<BaseAST> func_type;
    std::string ident;
    std::unique_ptr<BaseAST> block;

    void Dump() const override
    {
        /*std::cout << "FuncDefAST { ";
        func_type->Dump();
        std::cout << ", " << ident << ", ";
        block->Dump();
        std::cout << " }";*/
        std::cout << "fun @";
        std::cout << ident << "(): ";
        func_type->Dump();
        block->Dump();
    }
};

class FuncTypeAST : public BaseAST
{
public:
    void Dump() const override
    {
        /*std::cout << "FuncTypeAST { int }";*/
        std::cout << "i32 ";
    }
};

class BlockAST : public BaseAST 
{
public:
    std::unique_ptr<BaseAST> stmt;
    void Dump() const override
    {
        /*std::cout << "BlockAST { ";
        stmt->Dump();
        std::cout << "}";*/
        std::cout << "{" << std::endl;
        std::cout << "%entry:" << std::endl;
        stmt->Dump();
        std::cout << "}" << std::endl;
    }
};

class StmtAST : public BaseAST
{
public:
    std::string num;
    void Dump() const override
    {
        /*std::cout << " ret ";
        std::cout << num;*/
        std::cout << "  ret ";
        std::cout << num << std::endl;
    }
};

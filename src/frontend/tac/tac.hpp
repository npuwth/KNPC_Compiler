#ifndef __KNPC_TAC__
#define __KNPC_TAC__
#include <iostream>
#include "util/define.hpp"
#include "3rdparty/set.hpp"
#include "3rdparty/vector.hpp"
namespace knpc{
#define KNPC_TAC_DEFINED
namespace tac{
    typedef struct TempVariable
    {
        int id;               // 临时变量的编号
        int size;             // 所占字节数
        bool is_offset_fixed; // 临时变量是否被分配空间
        int offset;           // FP寄存器的偏移量
        int ctval;            // 编译时刻的静态值
        float ctvalf;         // 编译时刻的静态值
        bool isFloat;         // 是否浮点
        bool isConst;         // 是否常量
        int param_ord;        // 是第几个参数（从1开始，若不是参数为0）
    } * Temp;

    typedef struct LabelObject
    {
        int id;               // Label的编号
        std::string str_form; // Label的string形式
        bool target;          // 是否是目标Label
        Tac *where;           // The TAC which marks this Label (for dataflow analysis)
    } * Label;
    
    typedef struct FunctyObject
    {
        Label entry;        // 函数的入口Label
        Tac *code;          // 函数所对应的TAC
    } * Functy;

    typedef struct GlobalObject
    {
        std::string name;   //全局变量名
        int value;          //全局变量值
        int size;           //所占大小
        bool isConst;       //是否常量
    } * GlobalVar;

    typedef struct GlobalObjectF
    {
        std::string name;   //全局变量名
        float value;        //全局变量值
        int size;           //所占大小
        bool isConst;       //是否常量
    } * GlobalVarF;

    typedef struct GlobalArray
    {
        std::string name;   //全局变量名
        util::Vector<int> values;//全局变量值
        int size;           //所占大小
        bool isConst;       //是否常量
    } * GlobalArr;

    typedef struct GlobalArrayF
    {
        std::string name;   //全局变量名
        util::Vector<float> values;//全局变量值
        int size;           //所占大小
        bool isConst;       //是否常量
    } * GlobalArrF;

    struct Tac
    {
        // TAC操作类型
        typedef enum
        {
            ASSIGN,
            ADD,
            SUB,
            MUL,
            DIV,
            MOD,
            EQU,
            NEQ,
            LES,
            LEQ,
            GTR,
            GEQ,
            NEG,
            LAND,
            LOR,
            LNOT,
            BNOT,
            MARK,
            JUMP,
            JZERO,
            PUSH,
            POP,
            RETURN,
            LOAD_IMM4,
            LOAD_IMM4F,
            LOAD_SYMBOL,
            LOAD,
            STORE,
            MEMO,
            CALL,
            PARAM,
            ALLOC,
            PHI,
        } Kind;

        // 操作数类型
        typedef struct
        {
            Temp var;
            Label label;
            int ival;         // 整数常量
            float fval;       // 浮点常量
            int offset;       // 偏移量
            int size;         // 栈帧大小，数组分配时用
            std::string name; // 符号名
            const char *memo; // memorandum (for Memo tac only)
        } Operand;

        Kind op_code; // 操作类型
        Operand op0;  // 目标地址
        Operand op1;  // 源地址1
        Operand op2;  // 源地址2

        Tac *prev; // 上一条TAC
        Tac *next; // 下一条TAC

        int bb_num;               // 基本块编号，为了数据流分析
        util::Set<Temp> *LiveOut; // 活跃变量分析，为了数据流分析
        int mark;                 // 

        static Tac *Add(Temp dest, Temp op1, Temp op2);
        static Tac *Sub(Temp dest, Temp op1, Temp op2);
        static Tac *Mul(Temp dest, Temp op1, Temp op2);
        static Tac *Div(Temp dest, Temp op1, Temp op2);
        static Tac *Mod(Temp dest, Temp op1, Temp op2);
        static Tac *Equ(Temp dest, Temp op1, Temp op2);
        static Tac *Neq(Temp dest, Temp op1, Temp op2);
        static Tac *Les(Temp dest, Temp op1, Temp op2);
        static Tac *Leq(Temp dest, Temp op1, Temp op2);
        static Tac *Gtr(Temp dest, Temp op1, Temp op2);
        static Tac *Geq(Temp dest, Temp op1, Temp op2);
        static Tac *LAnd(Temp dest, Temp op1, Temp op2);
        static Tac *LOr(Temp dest, Temp op1, Temp op2);
        static Tac *Assign(Temp dest, Temp src);
        static Tac *Neg(Temp dest, Temp src);
        static Tac *LNot(Temp dest, Temp src);
        static Tac *BNot(Temp dest, Temp src);
        static Tac *LoadImm4(Temp dest, int value);
        static Tac *LoadImm4F(Temp dest, float value);
        static Tac *LoadSymbol(Temp dest, std::string label);
        static Tac *Load(Temp dest, Temp src, int offset);
        static Tac *Store(Temp src, Temp base, int offset);
        static Tac *Jump(Label dest);
        static Tac *JZero(Label dest, Temp cond);
        static Tac *Pop(Temp dest);
        static Tac *Push(Temp src);
        static Tac *Return(Temp value);
        static Tac *Mark(Label label);
        static Tac *Memo(const char *);
        static Tac *Call(Temp dest, Label label);
        static Tac *Param(Temp dest);
        static Tac *Alloc(Temp dest, int num);

        //将tac导出到输出流
        void dump(std::ostream &);
    };
    struct Piece
    {
        // kind of this Piece node
        enum
        {
            FUNCTY,
            GLOBAL,
            GLOBALF,
            GLOARR,
            GLOARRF
        } kind;

        // data of this Piece node
        union
        {
            Functy functy;
            GlobalVar globalVar;
            GlobalArr globalArr;
            GlobalVarF globalVarF;
            GlobalArrF globalArrF;
        } as;

        // 下一个块指针
        Piece *next;

        // 导出整个块
        void dump(std::ostream &);
    };
} // namespace tac
}
#endif // __KNPC_TAC__
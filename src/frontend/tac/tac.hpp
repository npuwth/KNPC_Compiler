#ifndef __MIND_TAC__
#define __MIND_TAC__
#include <iostream>
namespace mind{
#define MIND_TAC_DEFINED
namespace tac{
    typedef struct TempVariable
    {
        int id;               // 临时变量的编号
        int size;             // 所占字节数
        bool is_offset_fixed; // 临时变量是否被分配空间
        int offset;           // FP寄存器的偏移量
    } * Temp;

    typedef struct LabelObject
    {
        int id;               // id of a Label
        std::string str_form; // string format of a Label
        bool target;          // whether it is a target (eg. JUMP <Label>)
        Tac *where;           // The TAC which marks this Label (for dataflow analysis)
    } * Label;
}
}
#endif // __MIND_TAC__
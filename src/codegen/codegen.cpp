#include "codegen.h"
void generate(const koopa_raw_program_t &program)
{
    cout << "  .text" << endl;
    cout << "  .global main";
    generate(program.values);
    generate(program.funcs);
}
void generate(const koopa_raw_slice_t &slice)
{
    for (size_t i = 0; i < slice.len; ++i)
    {
        auto ptr = slice.buffer[i];
        switch (slice.kind)
        {
        case KOOPA_RSIK_FUNCTION:
            generate(reinterpret_cast<koopa_raw_function_t>(ptr));
            break;
        case KOOPA_RSIK_BASIC_BLOCK:
            generate(reinterpret_cast<koopa_raw_basic_block_t>(ptr));
            break;
        case KOOPA_RSIK_VALUE:
            generate(reinterpret_cast<koopa_raw_value_t>(ptr));
            break;
        default:
            break;
        }
    }
}
void generate(const koopa_raw_function_t &func)
{
    cout << endl;
    string name = func->name;
    cout << name.substr(1,name.length()) << ":" << endl;
    generate(func->bbs);
}
void generate(const koopa_raw_basic_block_t &block)
{
    generate(block->insts);
}
void generate(const koopa_raw_value_t &value)
{
    const auto &kind = value->kind;
    switch (kind.tag)
    {
    case KOOPA_RVT_RETURN:
        // 访问return指令
        generate(kind.data.ret);
        break;
    case KOOPA_RVT_INTEGER:
        //访问 integer 指令
        generate(kind.data.integer);
        break;
    default:
        break;
    }
}
void generate(const koopa_raw_integer_t &integer)
{
    int32_t int_val = integer.value;
}
void generate(const koopa_raw_return_t &ret)
{
    koopa_raw_value_t ret_value = ret.value;
    int32_t int_val = ret_value->kind.data.integer.value;
    cout << "  li a0, " << int_val << endl;
    cout << "  ret" << endl;
}
void print(const char *str)
{
    koopa_program_t program;
    koopa_error_code_t ret = koopa_parse_from_string(str, &program);
    koopa_raw_program_builder_t builder = koopa_new_raw_program_builder();
    koopa_raw_program_t raw = koopa_build_raw_program(builder, program);
    koopa_delete_program(program);
    generate(raw);
    koopa_delete_raw_program_builder(builder);
}
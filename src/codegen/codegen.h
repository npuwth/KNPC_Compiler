#pragma once

#include "koopa.h"
#include <memory>
#include <iostream>
using namespace std;
void generate(const koopa_raw_program_t &program);
void generate(const koopa_raw_slice_t &slice);
void generate(const koopa_raw_function_t &func);
void generate(const koopa_raw_basic_block_t &block);
void generate(const koopa_raw_value_t &value);
void generate(const koopa_raw_integer_t &integer);
void generate(const koopa_raw_return_t &ret);
void print(const char * str);
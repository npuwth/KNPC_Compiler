# SycCompiler

## 项目环境

1. `Java`: 用于运行 Antlr 软件包 
2. `CMake`: 本项目使用 cmake 进行构建

## 项目构建

语法文件`*.g4`位于`src/frontend/parser`路径，编译器代码文件位于`src/`路径下
（由于第一次编译需要编译 antlr 库，可能会比较耗时）。

```shell
mkdir build && cd build
cmake ..
make
```

在开发过程中你可能想单独更新语法规则文件，在`build`文件夹下运行`make update_antlr`即可。

## 运行

通过`make`，本项目会在build目录下生成一个可执行文件。

在项目的根目录下输入
```shell
./build/SysY testcase.c
```

即可在控制台看到输出的汇编

## 项目结构
```
├── 3rdparty        # 第三方库
│   ├── hash.hpp
│   ├── hash_fun.hpp
│   ├── hash_iterator.hpp
│   ├── hash_map.hpp
│   ├── hash_table.hpp
│   ├── list.hpp
│   ├── map.hpp
│   ├── set.hpp
│   ├── stack.hpp
│   └── vector.hpp
├── backend         # 后端，生成汇编
│   └── asm
│       ├── arm_frame_manager.cpp
│       ├── arm_frame_manager.hpp
│       ├── arm_md.cpp
│       ├── arm_md.hpp
│       ├── mach_desc.hpp
│       ├── offset_counter.cpp
│       └── offset_counter.hpp
├── config.hpp
├── define.hpp
├── error.cpp
├── error.hpp
├── errorbuf.hpp
├── frontend        # 前端，生成三地址码
│   ├── parser      # 基于Antlr词法分析和语法分析
│   │   ├── SysY.g4
│   │   ├── SysY.interp
│   │   ├── SysY.tokens
│   │   ├── SysYBaseVisitor.cpp
│   │   ├── SysYBaseVisitor.h
│   │   ├── SysYLexer.cpp
│   │   ├── SysYLexer.h
│   │   ├── SysYLexer.interp
│   │   ├── SysYLexer.tokens
│   │   ├── SysYParser.cpp
│   │   ├── SysYParser.h
│   │   ├── SysYVisitor.cpp
│   │   └── SysYVisitor.h
│   ├── scope       # 作用域
│   │   ├── func_scope.cpp
│   │   ├── global_scope.cpp
│   │   ├── local_scope.cpp
│   │   ├── scope.cpp
│   │   ├── scope.hpp
│   │   ├── scope_stack.cpp
│   │   └── scope_stack.hpp
│   ├── symb        # 符号表
│   │   ├── arrayvariable.cpp
│   │   ├── function.cpp
│   │   ├── symbol.cpp
│   │   ├── symbol.hpp
│   │   └── variable.cpp
│   ├── tac         # 中间IR——三地址码
│   │   ├── dataflow.cpp
│   │   ├── flow_graph.cpp
│   │   ├── flow_graph.hpp
│   │   ├── tac.cpp
│   │   ├── tac.hpp
│   │   ├── trans_helper.cpp
│   │   └── trans_helper.hpp
│   ├── translation     # 遍历语法分析树生成IR
│   │   ├── generate_ir.cpp
│   │   └── generate_ir.hpp
│   └── type            # 类型
│       ├── array_type.cpp
│       ├── base_type.cpp
│       ├── func_type.cpp
│       ├── type.cpp
│       └── type.hpp
├── location.hpp
├── main.cpp
├── misc.cpp
├── optimizer           #中端优化
│   ├── optimizer.cpp
│   ├── ssa.cpp
│   └── ssa.hpp
├── options.cpp
└── options.hpp
```


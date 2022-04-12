# compiler

A toy compiler is used to translate the SysY language (a subset of C) into ARMv7a assembly instructions.

## 目录

- [进度](#当前进度)
- [文件目录](#文件目录)

### 当前进度

- **2022年4月13日**：完成只有main函数的语句翻译成Koopa IR以及RISCV汇编

### 文件目录

```
compiler
│  .gitignore
│  Makefile
│  README.md
├─build
│  
└─src
    │  ast.h
    │  main.cpp
    │  sysy.l
    │  sysy.y
    │
    ├─codegen
    │      codegen.cpp
    │      codegen.h
    │      koopa.h
    │
    └─irgen
```


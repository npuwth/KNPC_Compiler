# SycCompiler

## 项目环境

1. `Java`: 用于运行 Antlr 软件包 
2. `CMake`: 本项目使用 cmake 进行构建

## 项目构建

语法文件`*.g4`位于`generate/`路径，编译器代码文件位于`src/`路径下
（由于第一次编译需要编译 antlr 库，可能会比较耗时）。

```shell
mkdir build && cd build
cmake ..
make
```

在开发过程中你可能想单独更新语法规则文件，在`build`文件夹下运行`make update_antlr`即可。

## 运行

通过`make`，本项目会在build目录下生成一个可执行文件。

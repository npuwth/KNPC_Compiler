# ANTLR4

wth 2022.4.18

------

### 概述：

清华大学特等奖使用，前端，比Flex&Bison更高级更现代。

官方教程：[antlr4/cpp-target.md at master · antlr/antlr4 (github.com)](https://github.com/antlr/antlr4/blob/master/doc/cpp-target.md)

使用流程：[Ubuntu 20.04桌面版 安装antlr4的C++ runtime library（运行时库）_kfd666的博客-CSDN博客_antlr c++](https://blog.csdn.net/drutgdh/article/details/122816033)

使用流程2：[ANTLR4 & C++ - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/240229064)

注意：不仅需要生成头文件，还需要自己链接runtime library！

### 工作流程：

输入的字符流组织到InputStream中，InputStream放入词法解析器里面，词法解析器提供词素流TokenStream，TokenStream供给Parser生成AST，在Antlr4里面组织的形式为XXContext，这就是Antlr4能为我们提供的一个分析过程的大致流程。

`-visitor`这个选项能生成Visitor类，对于AST的不同节点，无需我们自己去遍历AST来从中抽取对应的属性并进行操作操作，Antlr4为每一种AST节点都提供了一种进入方法接口，针对特定的AST节点进行操作，并可以通过`visit`这个方法从根往下执行。

Antlr实际上做了两件事，一是翻译语法和词法，并生成相应代码，然后就是为翻译出来的语法词法代码提供运行时的支持。

### 访问模式：

Listener模式，Visitor模式

### 内存管理：

Accordingly a parse tree is only valid for the lifetime of its parser. 

The parser, in turn, is only valid for the lifetime of its token stream, and so on back to the original `ANTLRInputStream` (or equivalent). 

To retain a tree across function calls you'll need to create and store all of these and `delete` all but the tree when you no longer need it.

### 优势：

- antlr4的规则文件描述更加简单，更加通俗易懂

- antlr4能生成不同目标语言

- antlr4能为每一个AST节点提供一个专门的进入入口，这样在处理AST节点的时候就很方便

- antlr4的提供的API也非常多 ，功能也非常多

- 在很多IDE上有提供ANTLR的插件，能非常方便的检测我们的规则文件并验证设计的正确性
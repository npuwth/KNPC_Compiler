# Visitor模式

wth 2022.5.5

------

## Visitor设计模式

在语义分析和中间表示生成两个步骤中，我们都需要遍历整个抽象语法树。Visitor 模式的目的，就是对遍历树状结构的过程进行封装，本质就是一个 DFS 遍历。

教程： [通用的ast解析工具 - 苍青浪 - 博客园 (cnblogs.com)](https://www.cnblogs.com/cangqinglang/p/14212146.html)

### 特点

1. visitor需要自己来指定访问特定类型的节点，在使用过程中，只需要对感兴趣的节点实现visit方法即可
2. visitor模式可以自定义返回值
3. visitor模式是对指定节点的访问

### 具体使用

Visitor类：

```
class Visitor {
public:
    virtual void visit(Program *) {}
    virtual void visit(FuncDefn *) {}
    ... ...
};
```

如果要实现一种具体的遍历AST的方法，就去继承Visitor：

```
class SemPass1 : public Visitor {
    void visit(ast::Program* prog) {
        // ...

        // visit global variables and each function
        for (auto it = prog->func_and_globals->begin(); it != prog->func_and_globals->end(); ++it) {
            (*it)->accept(this);
            // ...
        }
        // ...
    }
    void visit(ast::FuncDefn *) {
    ... ...;
    }
    ... ...
}
```

在这个SemPass1的具体的类里面实现了具体的访问策略。

对于每个AST Node来说，都要实现一个简单的accept函数：

```
class FuncDefn : public ASTNode {
public:
    void accept(Visitor *v) override {
        // 仅作示意，实际实现在对应的 .cpp 文件里
        v->visit(this);
    }
};
```

这些AST Node类的accept函数基本是一样的。为了便于实现，我们不使用 getKind 来判断结点类型，而是调用结点自身的一个 accept 函数。调用方法就是：

`(*it)->accept(this);`(上面代码示例)
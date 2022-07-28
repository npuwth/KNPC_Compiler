# 加入浮点Float

wth 2022.7.26

------

比赛树莓派用的是armhf内核（32位支持hard float的内核）

（比赛要求汇编是32位arm V7）

使用hard float会有很大的性能优势，使用硬件FPU去执行。

也就是使用大量的浮点指令！

VFP：Vector Floating Point

### 具体实现

使用软浮点就需要调用一些abi，即the floating point helper functions。

最大的问题：哪些情况下需要考虑隐式类型转换？

比如数组初始化？int和float相加？

修改了Temp的定义，加入了isFloat属性和ctvalf用于存放编译时刻静态值。（需要后端翻译TAC时检测一下Temp的isFloat属性，看看是不是浮点）。

加入了genLoadImm4F用于浮点立即数赋值。LoadImm4F这是一条新的TAC，需要后端支持一下。

对于全局变量，新增加了两种类型（Piece的类型），分别是GLOBALF（全局浮点）和GLOARRF（全局浮点数组）。需要后端对该两种情况进行翻译。

### 参考资料

教程：arm浮点  [arm浮点运算 - 走看看 (zoukankan.com)](http://t.zoukankan.com/-9-8-p-9254964.html)

编译参数： [CMake: (一) arm浮点编译参数 - 采男孩的小蘑菇 - 博客园 (cnblogs.com)](https://www.cnblogs.com/flyinggod/p/13713183.html)


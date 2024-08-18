`algorithm`
`tutorials`
`demos`
`concepts`
`tools`

优先级：
算法
八股
项目
英语

定范围：STL 面向对象 modern C++
# methodology 
`量变引起自变`
`最小必要知识`
`二八原则` 知识点也是不平等的

1. 侯杰视频
   demo法，通过一个简单的例子将C++的知识点串起来
2. Effective C++/STL/Modern 
   条款法，告诉你怎么做大部分情况是对了，当然作为一本书会解释为什么是对的，但个人决定学会使用它比为什么要使用它对初学者来说更有意义，可以猜想这些条款背后可能是某个程序员写了些bug，他花费了很多时间解决了它，不仅如此他还总结了他犯错了原因，给出了下次不范这种错误的原因。
3. C++ prime
   体系法：像一本词汇书
4. quick concept: https://www.youtube.com/channel/UCEOGtxYTB6vo6MQ-WQ9W_nQ
   二八法：抓重点

程序和文章的区别，作家和程序员的区别，程序员按时计费，作家一份时间可以一直copy

tutorials `C++ Primer` 学习单词
instruction `Effective C++` 写作注意事项
how-tos `operation booklet` 需要但没必要死记的部分，社会中的普通人，单词中的concrete words
写程序抛开对代码的理解，还有些熟练度，工程做法等问题，这些问题往往如果长时间不接触，或时间久了，就会忘记。为了避免重复花时间在这些问题上，希望通过`how-tos`来记录。
concepts `design philosophy` 对编程语言的设计的感悟，是以一种`top-down`的视角来看待程序设计，如程序的设计范式
demos -->`practices` 范文怎么写 范文法

1. 系统设计 PER SIT RPM `现实世界的问题是什么，怎么抽象成物理问题，如何感知环境中的目标，如何定位，如何规划路径，这些都是物理问题，驾驶员模型是对人行为的抽象，所以系统设计即是将现实世界转化为物理世界和人的抽象`

2. 软件系统设计 `怎么将真实世界抽象成软件世界，软件世界是最小单元是代码，组织这些代码的是文件，文件里是类，而设计类的关系即需要设计模式，但这些是上层的设计，重要但低频率`如：runnable 中间层怎么与implement结构，UML中sequence diagram中各个对象怎么交互。

3. 数据结构和算法
`需要自定义哪些对象`

`对象里需要哪些函数`
`保证程序健壮性，需要的const,explict,private`
`多态是程序设计的硬需要`
`如果程序的顶层结构确定，设计函数就是在设计算法`

algorithm `leetcode`
tools `tool chains`




## 写程序需要的工具
`editor` -->vscode
`comment` -->doxygen
`document` -->markdown
`unit test` -->gtest pytest
`build system` -->cmake
`version control` -->git

## 写的程序怎么运行的
- 可执行文件的怎么运行在`操作系统` 多线程程序的开发
- 可执行文件之间之间怎么通信`计算机网络`

与程序员打交道的几个instance
语言<--> 程序语言
程序 -
1. 对物理世界的抽象，编程范式(OOP,STL,函数式)
2. 基于计算机硬件体系（内存管理，操作系统，CPU）
   编译器 `编译器会自动申请哪些函数？` `哪些写法是因为编译器可以自动推导`
   操作系统 `进程，线程`
   GPU `CUDA`
   CPU `汇编，指令集x86,arm`


多种实现方法

`封装` `底层，上层`
基础设施 pointer 引用也是对pointer的抽象 上层应用抽象为智能指针 STL抽象为iterator，
基础设施 malloc/free, C++ 抽象为new delete, STL 抽象为alloctor

STL的编程范式 算法传入的是指针，那不是说它又倒退回C的编程方式了吗

编程范式对任何语言来说，它都是支持的：
面向对象
STL
函数式

时间对每个人是公平的，但又是不公平的。对于C++，
目前可行的策略是不要花时间在一些不重要的知识点上：

multiple/virtual inherence
exception
iostream


学习编程与学习English有很多类似之处，你的有些词汇量，但每个单词是不平等的，
你的知道编程里的关键字和语法，但对于每种语法你掌握的并不一定一样。


JAVA与C++

语法：
1. 指针与引用。C++ 类型，值，引用，左值，右值，指针
2. 多重继承
3. 自动内存管理，对象创建， jave用new,C++堆/栈 RAII
4. 操作符重载
5. 预处理 #
6. 类型转换，C++存在隐式转换 RTTI
7. 异常
8. java 纯OO， 不支持全局函数，C++多编程范式
9. 面向对象，C++ 用virtual ,JAVA默认都是virtual, 纯虚函数和接口
10. callback回调的实现，lambada ,bind
11. 字符串，java是定长的
12. boolean C++非0

生态：
1. 平台移植
C++ 平台差异 linux,window ，C++ 中内存大小可能不一样size of ，GCC,CLANG,VC++
java jvm 跨平台

2. 外部库
C++库：C++ QT,STL,boost
JAVA 库：数据库，网络，IO,并发,thread

3. 工具链
C++ vscode visual studio
java IDEA

网络 TCP/HTTP

应用：
`每个语言有自己的优势和生态，做什么应用觉得你使用哪些语言`
操作系统 linux  --> linux
Office --> 轮子哥
编译器 LLVM --> 蓝色
服务器后端 --> 陈硕
游戏开发 -->
web 后端--> java
自动驾驶--> 浦东新村轱天乐https://www.zhihu.com/people/ma-rong-bo-38

C++ primer
https://www.zhihu.com/question/32087709/answer/1664944308

JAVA 是基于C++对于商业化的妥协，商业化需要人的标准化，能在短时间内培养出可用的人才，因此
java的设计者必然会对C++中难掌握，易犯错的点做修改

语言的向后兼容性带来的问题？
目前都在做加法，但做减法就无法兼容历史，而更modern的方法由于大量陈旧的内容在导致开发人员有太多的干扰项


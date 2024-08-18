程序的编译和运行过程（Hello World 是如何运行的）

# Top-Down
`compile time` and `run time`
## Configure  --> CMake 文件组织

## Preprocessing --> #define
- #include 属于编译前的Preprocessing阶段

## 编译器
`编译器` `汇编器` `链接器`  
   ![alt text](resources\compiler.png "Output from ros2")

- 静态链接和动态链接：程序编译成功，但运行时提示无法找到xxx.dll文件，动态链接库是在run time 时才被调用 

## 操作系统
`make install` --> 用来完成"安装"和"操作系统连接"这两步
1. 必须将可执行文件保存到用户事先指定的安装目录，表面上，这一步很简单，就是将可执行文件（连带相关的数据文件）拷贝过去就行了。但是实际上，这一步还必须完成创建目录、保存文件、设置权限等步骤。这整个的保存过程就称为"安装"（Installation）

2. 可执行文件安装后，必须以某种方式通知操作系统，让其知道可以使用这个程序了。比如，我们安装了一个文本阅读程序，往往希望双击txt文件，该程序就会自动运行,这就要求在操作系统中，登记这个程序的元数据：文件名、文件描述、关联后缀名等等。

3. 程序打包
生成安装包如 .exe文件 和.deb文件，ELF文件（Executableand linking format） x86 Linux系统下的一种常用目标文件(objectfile)格式, 提供程序的进程映像，加载到内存执行
https://www.yhspy.com/2020/06/17/Linux%20%E4%B8%8B%E7%9A%84%20ELF%20%E5%AE%8C%E6%95%B4%E7%BB%93%E6%9E%84%E5%88%86%E6%9E%90/

## Target
1. 单元测试 --> enable_testing
target 包含单元测试 

## 程序运行 run time --> link .so file, dynamics binding
动态绑定 多态
动态链接 .so


# Bottom-Up 写程序与各component打交道的地方
## 编写CMake --> 程序的组织结构
1. 确定有哪些.o文件

## 操作系统 
1. 编程语言与操作系统的接口抽象成标准库 `#include<pthread.h>`
2. 直接call system函数

## 预处理器
#include 
#define

## 编译器
explicit 
inline
constexpr 编译期常量
override

## 运行时多态
ref: 
- [编译器的工作过程](http://www.ruanyifeng.com/blog/2014/11/compiler.html)
- [深入理解计算机系统（二）：Hello World 是如何运行的](https://zhuanlan.zhihu.com/p/37479652)
- http://nethack4.org/blog/building-c.html
## correct copy
深拷贝，浅拷贝，资源类
1. custom copy
copy ctor
assignment operator

2. prohibit copy
private copy ctor assignment operator
NoCopyClass
delete



## performance
move directly instead of copy first
move
std::unique_ptr
右值
perfect forward
引入右值引用，就是为了移动语义。移动语义就是为了减少拷贝。std::move就是将左值转为右值引用。这样就可以重载到移动构造函数了，移动构造函数将指针赋值一下就好了，不用深拷贝了，提高性能
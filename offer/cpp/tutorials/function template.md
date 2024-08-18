# C++ template

## 函数模板

##### 知识讲解

[C++ 模板常见特性（函数模板、类模板） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/101898043)

##### 代码实现

```c++
//method.h
#pragma once
template<typename T>
void swap(T& t1,T& t2);

#include "method.inl"
```

```c++
//method.inl
template<typename T>
void swap(T& t1,T& t2)
{
    T temp;
    temp=t1;
    t1=t2;
    t2=temp;
}
```

```c++
//main.cpp
#include <stdio.h>
#include "method.h"

int main()
{
    int n1=1,n2=2;
    swap<int>(a1,a2);
    printf("n1:%d, n2:%d\n", n1, n2);
    return 0;
}
```

##### 代码构建

```cmake
#CMakeLists.txt
cmake_minimum_required(VERSION 2.8)
project(list)
add_executable(list main.cpp)
```

##### 在bash中测试上述代码

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

##### 总结

模板声明，定义，模板实例化（编译器来做）
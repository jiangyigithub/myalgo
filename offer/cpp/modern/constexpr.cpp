#include <iostream>
#include <array>
using namespace std;

/***
 * 
 * constexpr：告诉编译器我可以是编译期间可知的，尽情的优化我吧。
 * const：告诉程序员没人动得了我，放心的把我传出去；或者放心的把变量交给我，我啥也不动就瞅瞅。
 * https://www.zhihu.com/question/35614219
***/

// 默认是inline,constexpr告诉编译器可以优化我 编译器里有优化器
constexpr int foo(int i)
{
    return i + 5;
}

int main()
{
    int i = 10;
    std::array<int, foo(5)> arr; // OK
    
    foo(i); // Call is Ok
    
    // But...
    std::array<int, foo(i)> arr1; // Error
   
}

## 参考资料
1. 侯杰视频
   通过一个简单的例子将C++的知识点串起来
2. Effective C++/STL/ 
   条款法，告诉你怎么做大部分情况是对了，当然作为一本书会解释为什么是对的，但个人决定学会使用它比为什么要使用它对初学者来说更有意义，可以猜想这些条款背后可能是某个程序员写了些bug，他花费了很多时间解决了它，不仅如此他还总结了他犯错了原因，给出了下次不范这种错误的原因。
3. C++ prime
   像一本词汇书，

## 项目一：基于对象编程
`string 类` --> 类的成员变量里有指针
class with pointer memebers 必须有copy ctor 和copy operator=, 默认是浅拷贝，赋值和复制的两个实例，其中一个实例中指针指向的内容被删去，会导致另一个实例中指向的内容消失，导致undefined behavior.

https://hubojing.github.io/2018/12/27/C-%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1%EF%BC%88%E4%BE%AF%E6%8D%B7%EF%BC%89%E7%AC%94%E8%AE%B0/

https://hubojing.github.io/2019/01/22/C-%E7%A8%8B%E5%BA%8F%E8%AE%BE%E8%AE%A1%E4%B9%8B%E5%85%BC%E8%B0%88%E5%AF%B9%E8%B1%A1%E6%A8%A1%E5%9E%8B/#explicit-one-argument-ctor


`complex类`
* 引用，函数参数传递与返回值
* const
  - 参数
  - 函数
* 操作符重载
* 成员函数还是全局函数

## 项目二: xml parser项目
（序列化与反序列化）

## 项目三：web项目
基于Epoll的简易Http服务器https://zhuanlan.zhihu.com/p/503390413

https://www.zhihu.com/question/29637351

https://github.com/linyacool/WebServer
（网络编程）

https://www.cnblogs.com/yrxing/p/14143644.html

https://xiaolincoding.com/os/8_network_system/reactor.html#%E5%85%B3%E6%B3%A8%E4%BD%9C%E8%80%85
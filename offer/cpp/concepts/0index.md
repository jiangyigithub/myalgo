# C++ 程序设计

(写给自己的话，学习编程也有些年份了，学习方法问题一直是我在思考的一个问题，做事情最难的往往在起步，
我期望的做法是，知识点在都包含在代码中，所以knowledge不应该只是知识的理解，应包含代码)
学英语只学词汇，从不同学习的词汇来造句,写程序只学语法，且从不去实践

程序是在做设计，哪些做设计需要考虑哪些内容呢？想想程序的sequence图，sequence图有哪些对象，对象里函数怎么去调用组成
`需要自定义哪些对象`
`对象里需要哪些函数`
`保证程序健壮性，需要的const,explict,private`
`多态是程序设计的硬需要`
`如果程序的顶层结构确定，设计函数就是在设计算法`

- `polymorphism`
  - runtime virtual function（虚函数，纯虚函数，虚表）
  - build time template
- `con/de - structor` 
  - single class
    - copy ctor
    - assignment ctor
    - copy assignment ctor
  - multi class
  - initilization list

`Effective STL 阅读笔记`
https://zhuanlan.zhihu.com/p/458156007

好的语言是否是使用者知道怎么用，但不需要为什么这么用呢？就跟英语一样，curious 发音为`/ˈkjʊəriəs/`,大家都知道用它来表达好奇，但是否需要为什么设计curious表示好奇，发音是什么。语言使用者非语言专家。时间成本和收益，不求甚解。

一个例子最好能包含80%的知识点。


## invoke
`function parameter`

## 
`函数指针` `回调函数` `函数作为参数` `Smart function` `class with operator()` `function object` `std::bind` `std::function` `lambda`
其实理解很简单，举个排序的例子。我们可以先定义两个返回bool的函数more()和less(),分别表示排序规则，大的放前面还是小的放前面。当我们调用sort()函数时，除了向参数列表中丢进去数组或者容器，可以将more或者less的函数指针作为参数一起丢进去。是丢more还是less由情况决定，即在不同的时间使用不同的函数。用函数调用不用函数指针的话，可能就要定义两个sort，moreSort和lessSort，两个函数中调用不同的比较函数，此时他们之间有大量重复代码，效率显然不如函数指针高。当然，实际情况下，sort中用的应该是有状态的仿函数而不是函数指针，这就是另外的事情了。

作者：蓦子骞
链接：https://www.zhihu.com/question/283024782/answer/1112893609
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
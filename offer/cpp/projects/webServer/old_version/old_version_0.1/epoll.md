epoll三个函数

int epoll_create(int size);

    分配一个eventpoll;
    初始化红黑树的根节点epfd。eventpoll与epfd一一对应。

int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

操作红黑树，根据op对红黑树进行增删改

int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);

把就绪队列的数据从内核copy到用户空间。

如果maxevents小于就绪队列大小，比如就绪队列大小为100，maxevents传入50，怎么办呢？

先将就绪队列里面的50个节点copy到用户空间，之后下次epoll_wait再copy 50个节点。

https://www.zhihu.com/question/486578358/answer/2534288200

`epoll使用红黑树和队列，红黑树存放需要检测的节点，队列存放就绪的节点。`
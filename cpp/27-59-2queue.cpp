/*
Leetcode 59：队列的最大值

一、题目描述

请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

*/

#include "head.hpp"

class MaxQueue
{
    queue<int> que;
    deque<int> deq;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (deq.empty())
            return -1;
        return deq.front();
    }

    void push_back(int value)
    {
        while (!deq.empty() && deq.back() < value)
        {
            deq.pop_back();
        }
        deq.push_back(value);
        que.push(value);
    }

    int pop_front()
    {
        if (que.empty())
            return -1;
        int ans = que.front();
        if (ans == deq.front())
        {
            deq.pop_front();
        }
        que.pop();
        return ans;
    }
};

int main()
{
    MaxQueue *maxQueue = new MaxQueue();
    maxQueue->push_back(5);
    maxQueue->push_back(1);
    maxQueue->max_value();
    maxQueue->push_back(3);
    maxQueue->pop_front();
    maxQueue->max_value();
    maxQueue->pop_front();
    return 0;
}

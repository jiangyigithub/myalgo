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

#include "head.hpp"
#include "PrintUtil.hpp"
#include <stack>

// 剑指 Offer 30.  包含 min 函数的栈
class MinStack
{
public:
    void push(int value)
    {
        data_stack.push(value);
        if (min_stack.empty() || value <= min_stack.top())
        {
            min_stack.push(value);
        }
    }

    void pop()
    {
        if (!data_stack.empty())
        {
            int value = data_stack.top();
            data_stack.pop();
            if (value == min_stack.top())
            {
                min_stack.pop();
            }
        }
    }

    int top()
    {
        if (!data_stack.empty())
        {
            return data_stack.top();
        }
        return -1; // 栈为空时返回一个特殊值
    }

    int min()
    {
        if (!min_stack.empty())
        {
            return min_stack.top();
        }
        return -1; // 栈为空时返回一个特殊值
    }

private:
    std::stack<int> data_stack; // 存储数据的主栈
    std::stack<int> min_stack;  // 存储最小值的辅助栈
};

int main()
{
    MinStack *minStack = new MinStack();
    vector<int> res;
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    res.push_back(minStack->min());
    minStack->pop();
    res.push_back(minStack->top());
    res.push_back(minStack->min());
    PrintUtil::printVector(res);
}
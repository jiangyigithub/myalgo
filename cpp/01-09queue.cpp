#include "head.hpp"
#include "PrintUtil.hpp"

// 剑指 Offer 09. 用两个栈实现队列
class CQueue
{
public:
    CQueue()
    {
    }
    stack<int> stack_in, stack_out;

    void appendTail(int value)
    {
        stack_in.push(value);
    }

    int deleteHead()
    {
        // step 1 取stack_out已有部分
        if (!stack_out.empty())
        {
            int temp = stack_out.top();
            stack_out.pop();
            return temp;
        }
        if (stack_in.empty())
            return -1;
        // step 2 把stack_in中的copy 到stack_out
        while (!stack_in.empty())
        {
            int temp = stack_in.top();
            stack_in.pop();
            stack_out.push(temp);
        }
        int temp = stack_out.top();
        stack_out.pop();
        return temp;
    }
};

int main()
{
    // ====== Driver Code ======
    vector<int> res;
    CQueue *cQueue = new CQueue();
    res.push_back(cQueue->deleteHead());
    cQueue->appendTail(5);
    cQueue->appendTail(2);
    res.push_back(cQueue->deleteHead());
    res.push_back(cQueue->deleteHead());
    PrintUtil::printVector(res);

    return 0;
}

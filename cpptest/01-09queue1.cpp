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

    }

    int deleteHead()
    {
        
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

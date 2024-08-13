#include <stack>
#include <string>
#include <iostream>
using namespace std;

class MinStack {
    stack<int> stk;
    stack<int> minstk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(minstk.empty()||val<=minstk.top()){
            minstk.push(val);
        }
    }
    
    void pop() {
        if(!minstk.empty() && stk.top()==minstk.top()) minstk.pop();
        if(!stk.empty()) stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << "Minimum: " << obj->getMin() << endl; // 应输出 -3
    obj->pop();
    cout << "Top: " << obj->top() << endl;       // 应输出 0
    cout << "Minimum: " << obj->getMin() << endl; // 应输出 -2
    delete obj;
    return 0;


    // 测试用例：按照新的测试操作序列和参数
    // ["MinStack","push","push","push","getMin","pop","getMin"]
    // [[],[0],[1],[0],[],[],[]]
    MinStack* obj = new MinStack();
    
    // 按照新的操作序列执行
    obj->push(0);
    obj->push(1);
    obj->push(0);
    
    // 打印 getMin 操作结果
    cout << "Minimum: " << obj->getMin() << endl; // 应输出 0
    
    obj->pop();
    
    // 打印 top 操作结果
    cout << "Top: " << obj->top() << endl;       // 应输出 1
    
    // 打印 getMin 操作结果
    cout << "Minimum: " << obj->getMin() << endl; // 应输出 0
    
    delete obj;
    return 0;
}

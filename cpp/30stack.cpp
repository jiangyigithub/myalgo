#include "head.hpp"
class MinStack{
    public:
    stack<int> A,B;
    MinStack(){}
    void push(int x){
        A.push(x);
        if(B.empty() || B.top()>=x) B.push(x);
    }
    void pop(){
        if(A.top()==B.top())
            B.pop();
        A.pop();
    }
    int top(){
        return A.top();
    }
    int min(){
        return B.top();
    }

};

int main(){
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->min();   
    minStack->pop();
    minStack->top();      
    minStack->min();   
}
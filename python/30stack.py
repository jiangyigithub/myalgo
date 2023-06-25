class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack=[]
        self.stack_min=[]

    def push(self, x: int) -> None:
        self.stack.append(x)
        if self.stack_min==[]:
            self.stack_min.append(x)
        else:
            val=min(x,self.stack_min[-1])
            self.stack_min.append(val)


    def pop(self) -> None:
        self.stack.pop() # pop(-1)
        self.stack_min.pop() # pop(-1)


    def top(self) -> int:
        return self.stack[-1]


    def min(self) -> int:
        return self.stack_min[-1]

if __name__=="__main__":
    minStack=MinStack()
    minStack.push(-2)
    minStack.push(0)
    minStack.push(-3)
    minStack.min()  # --> 返回 -3.
    minStack.pop()
    minStack.top()  #   --> 返回 0.
    minStack.min()  # --> 返回 -2.


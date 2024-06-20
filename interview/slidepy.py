from collections import deque

def minSlidingWindow(nums,k):
    result=[]
    dq=deque()
    for i in range(len(nums)):
        # dq[0]<
        if dq and dq[0]<i-k+1:
            dq.popleft()
        while(dq and nums[i]<nums[dq[-1]]):
            dq.pop()
        dq.append(i)
        if i>=k-1:
            result.append(nums[dq[0]])
    return result


nums = [3,2,1,4,5,6]
k=3
res = minSlidingWindow(nums,k)
print(res)


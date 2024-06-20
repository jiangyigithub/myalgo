from collections import deque

def min_sliding_window(nums, k):
    result = []
    dq = deque()  # 存储的是索引，而不是值
    for i in range(len(nums)):
        # 移除不在窗口内的索引
        if dq and dq[0] < i - k + 1:
            dq.popleft()

        # 移除所有比当前元素大的元素
        while dq and nums[dq[-1]] > nums[i]:
            dq.pop()
        dq.append(i)

        # 当窗口大小达到要求时，记录窗口的最小值
        if i >= k - 1:
            result.append(nums[dq[0]])
    print(len(result),len(nums))
    return result

nums = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3
print(min_sliding_window(nums, k))

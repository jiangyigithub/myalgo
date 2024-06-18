from collections import deque

def min_sliding_window(nums, k):
    if not nums or k == 0:
        return []

    result = []
    dq = deque()  # 存储的是索引，而不是值

    for i in range(len(nums)):
        # 移除不在窗口内的索引
        if dq and dq[0] < i - k + 1:
            dq.popleft()

        # 移除所有比当前元素大的元素
        while dq and nums[dq[-1]] > nums[i]:
            dq.pop()

        # 将当前元素添加到队尾
        dq.append(i)

        # 当窗口大小达到要求时，记录窗口的最小值
        if i >= k - 1:
            result.append(nums[dq[0]])

    return result

# 测试
nums = [1, 3, -1, -3, 5, 3, 6, 7, 9, 11, 3, 2, 8, 5, 4, 6, 8, 2, 4, 5, 7, 6, 10, 11]
k = 3
print(min_sliding_window(nums, k))  # 根据数组和窗口大小，输出每个窗口的最小值

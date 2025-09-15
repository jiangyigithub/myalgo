
# 给你一个整数数组 nums 。nums 的每个元素是 1，2 或 3。在每次操作中，你可以删除 nums 中的一个元素。返回使 nums 成为 非递减 顺序所需操作数的 最小值。

 

# 示例 1：

# 输入：nums = [2,1,3,2,1]
# 输出：3
# 解释：
# 其中一个最优方案是删除 nums[0]，nums[2] 和 nums[3]。
# 示例 2：

# 输入：nums = [1,3,2,1,3,3]
# 输出：2
# 解释：
# 其中一个最优方案是删除 nums[1] 和 nums[2]。
# 示例 3：

# 输入：nums = [2,2,2,2,3,3]
# 输出：0
# 解释：
# nums 已是非递减顺序的。
 

# 提示：

# 1 <= nums.length <= 100
# 1 <= nums[i] <= 3
# 进阶：你可以使用 O(n) 时间复杂度以内的算法解决吗？

# 正难则反，计算最多保留多少个数。这些保留的数必须是非递减的

from typing import List
from bisect import bisect_right
from dataclasses import dataclass

# 原算法
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        g = []
        for x in nums:
            j = bisect_right(g, x)
            if j == len(g):
                g.append(x)
            else:
                g[j] = x
        return len(nums) - len(g)

# 定义测试用例结构体
@dataclass
class TestCase:
    nums: List[int]
    expected: int

# 定义测试用例
test_cases = [
    TestCase(nums=[1,3,3,2,1,3,3], expected=2),
    TestCase(nums=[2,2,2,2,3,3], expected=0),
    TestCase(nums=[2,1,3,2,1], expected=3),
]

# 运行测试
solution = Solution()
for i, case in enumerate(test_cases, 1):
    result = solution.minimumOperations(case.nums)
    passed = result == case.expected
    print(f"Test Case {i}:")
    print(f"  Input: {case.nums}")
    print(f"  Expected: {case.expected}")
    print(f"  Actual: {result}")
    print(f"  Passed: {passed}")
    print("-" * 40)

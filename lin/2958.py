from typing import List
from collections import Counter

# 原始算法
class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = left = 0
        cnt = Counter()
        for right, x in enumerate(nums):
            cnt[x] += 1
            while cnt[x] > k:
                cnt[nums[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)
        return ans

# 测试用例结构体
class TestCase:
    def __init__(self, nums: List[int], k: int, expected: int):
        self.nums = nums  # 输入的 nums
        self.k = k        # 输入的 k
        self.expected = expected  # 预期结果
        self.actual = None  # 实际结果（在运行测试后填充）
        self.passed = False  # 是否通过测试（在运行测试后填充）

    def run_test(self, solution: Solution):
        # 运行实际的算法
        self.actual = solution.maxSubarrayLength(self.nums, self.k)
        # 判断测试是否通过
        self.passed = self.actual == self.expected

    def __str__(self):
        # 返回测试用例的详细信息字符串
        return (f"Input: nums={self.nums}, k={self.k}\n"
                f"Expected: {self.expected}, Actual: {self.actual}\n"
                f"Test Passed: {self.passed}\n")

# 运行所有测试用例
def run_tests(test_cases: List[TestCase]):
    solution = Solution()
    for i, test in enumerate(test_cases):
        test.run_test(solution)
        print(f"Test Case {i + 1}:\n{test}")

# 定义测试用例
test_cases = [
    TestCase([1, 2, 2, 3, 3, 3, 3], 2, 5),  # 最大长度子数组为[2, 2, 3, 3, 3]
    TestCase([1, 2, 3, 1, 2, 3], 1, 2),    # 最大长度子数组为[1, 2]
    TestCase([4, 4, 4, 4, 4], 1, 1),       # 最大长度子数组为[4]
    TestCase([1, 1, 1, 2, 2, 3, 3], 2, 7), # 最大长度子数组为整个数组
    TestCase([], 1, 0),                    # 空数组
]

# 运行测试
run_tests(test_cases)

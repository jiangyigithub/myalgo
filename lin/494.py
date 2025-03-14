from typing import List
from functools import cache
from dataclasses import dataclass

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        s = sum(nums) - abs(target)
        if s < 0 or s % 2:
            return 0
        m = s // 2  # 背包容量

        @cache  # 缓存装饰器，避免重复计算 dfs 的结果（记忆化）
        def dfs(i: int, c: int) -> int:
            if i < 0:
                return 1 if c == 0 else 0
            if c < nums[i]:
                return dfs(i - 1, c)  # 只能不选
            return dfs(i - 1, c) + dfs(i - 1, c - nums[i])  # 不选 + 选
        
        return dfs(len(nums) - 1, m)

@dataclass
class TestCase:
    nums: List[int]
    target: int
    expected: int

def run_tests():
    test_cases = [
        TestCase(nums=[1, 1, 1, 1, 1], target=3, expected=5),
        TestCase(nums=[1], target=1, expected=1),
        TestCase(nums=[1], target=2, expected=0),
        TestCase(nums=[100], target=0, expected=0),
        TestCase(nums=[0, 0, 0, 0, 0], target=0, expected=32),
    ]
    
    solution = Solution()
    
    for i, test in enumerate(test_cases):
        result = solution.findTargetSumWays(test.nums, test.target)
        print(f"Test Case {i+1}:")
        print(f"  Input: nums={test.nums}, target={test.target}")
        print(f"  Expected: {test.expected}")
        print(f"  Actual: {result}")
        print(f"  Passed: {result == test.expected}\n")

# 运行测试
run_tests()
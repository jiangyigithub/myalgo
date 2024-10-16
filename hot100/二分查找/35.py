from typing import List
from dataclasses import dataclass

# 定义结构体存储测试用例
@dataclass
class TestCase:
    nums: List[int]
    target: int
    expected: int

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left = 0
        n = len(nums)
        right = n - 1
        while left <= right:
            mid = left + (right - left) // 2
            if target > nums[mid]:
                left = mid + 1
            else:
                right = mid - 1
        print(f'left:{left},right:{right}')
        return left

# 定义测试函数
def run_tests():
    # 初始化测试用例
    test_cases = [
        TestCase(nums=[1, 3, 5, 6], target=4, expected=2),
        # TestCase(nums=[1, 3, 5, 6], target=2, expected=1),
        # TestCase(nums=[1, 3, 5, 6], target=7, expected=4),
        # TestCase(nums=[1, 3, 5, 6], target=0, expected=0),
    ]
    
    solution = Solution()
    
    # 遍历每个测试用例并输出测试结果
    for i, test in enumerate(test_cases, 1):
        actual = solution.searchInsert(test.nums, test.target)
        passed = actual == test.expected
        print(f"Test Case {i}:")
        print(f"  Input: nums = {test.nums}, target = {test.target}")
        print(f"  Expected: {test.expected}, Actual: {actual}")
        print(f"  Test Passed: {passed}\n")

# 运行测试
run_tests()

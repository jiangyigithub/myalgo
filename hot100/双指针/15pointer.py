from typing import List, Tuple
from dataclasses import dataclass, field

@dataclass
class TestCase:
    nums: List[int]
    expected: List[List[int]]
    actual: List[List[int]] = field(default_factory=list)
    passed: bool = False

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        n = len(nums)
        for i in range(n - 2):
            x = nums[i]
            if i > 0 and x == nums[i - 1]:  # 跳过重复数字
                continue
            if x + nums[i + 1] + nums[i + 2] > 0:  # 优化一，x太大了，直接退出整个循环
                break
            if x + nums[-2] + nums[-1] < 0:  # 优化二，x太小了，退出当前循环，找一下更大的x
                continue
            j = i + 1
            k = n - 1
            while j < k:
                s = x + nums[j] + nums[k]
                if s > 0:
                    k -= 1
                elif s < 0:
                    j += 1
                else:
                    ans.append([x, nums[j], nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j - 1]:  # 跳过重复数字
                        j += 1
                    k -= 1
                    while k > j and nums[k] == nums[k + 1]:  # 跳过重复数字
                        k -= 1
        return ans

# Test cases
test_cases = [
    TestCase(nums=[-1, 0, 1, 2, -1, -4], expected=[[-1, -1, 2], [-1, 0, 1]]),
    TestCase(nums=[0, 1, 1], expected=[]),
    TestCase(nums=[0, 0, 0], expected=[[0, 0, 0]]),
    TestCase(nums=[-2, 0, 1, 1, 2], expected=[[-2, 0, 2], [-2, 1, 1]]),
    TestCase(nums=[], expected=[]),
    TestCase(nums=[1, 2, -2, -1], expected=[])
]

sol = Solution()

# Running test cases
for test in test_cases:
    test.actual = sol.threeSum(test.nums)
    test.passed = sorted(test.actual) == sorted(test.expected)
    print(f"Test case: {test.nums}")
    print(f"Expected: {test.expected}")
    print(f"Actual: {test.actual}")
    print(f"Passed: {test.passed}")
    print()

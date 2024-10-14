from typing import List, NamedTuple

# 定义结构体来存储测试用例
class TestCase(NamedTuple):
    nums: List[int]
    target: int
    expected: int

class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = left = 0
        right = len(nums) - 1
        while left < right:
            if nums[left] + nums[right] < target:
                ans += right - left
                left += 1
            else:
                right -= 1
        return ans

# 测试函数
def run_tests():
    # 定义测试用例
    test_cases =[
        TestCase(nums=[-1,1,2,3,1],target=2,expected=3),
        TestCase(nums=[-6,2,5,-2,-7,-1,3],target=-2,expected=10),
        TestCase(nums=[-1, 1, 2, 3, 4], target=5, expected=5),
        TestCase(nums=[2, 3, 1], target=4, expected=2),
        TestCase(nums=[-2, 0, 1, 3], target=2, expected=3),
        TestCase(nums=[1, 5, 7, 9], target=10, expected=2)
    ]

    solution = Solution()
    
    # 逐个运行测试用例并输出详细信息
    for i, test_case in enumerate(test_cases):
        actual = solution.countPairs(test_case.nums, test_case.target)
        passed = actual == test_case.expected
        print(f"Test Case {i + 1}:")
        print(f"  Input: nums = {test_case.nums}, target = {test_case.target}")
        print(f"  Expected: {test_case.expected}, Actual: {actual}")
        print(f"  Test {'Passed' if passed else 'Failed'}")
        print()

# 运行测试
run_tests()

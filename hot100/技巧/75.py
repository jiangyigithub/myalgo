from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        low, i, high = 0, 0, len(nums) - 1

        while i <= high:
            if nums[i] == 0:
                nums[i], nums[low] = nums[low], nums[i]
                low += 1
                i += 1
            elif nums[i] == 1:
                i += 1
            else:  # nums[i] == 2
                nums[i], nums[high] = nums[high], nums[i]
                high -= 1

# 定义测试用例的结构体
class TestCase:
    def __init__(self, input, expected):
        self.input = input
        self.expected = expected
        self.passed = False

# 测试函数
def runTestCases():
    # 定义测试用例
    testCases = [
        TestCase([2, 0, 2, 1, 1, 0], [0, 0, 1, 1, 2, 2]),
        TestCase([2, 0, 1], [0, 1, 2]),
        TestCase([0], [0]),
        TestCase([1], [1]),
        TestCase([2, 2, 1, 1, 0, 0], [0, 0, 1, 1, 2, 2])
    ]

    solution = Solution()
    for testCase in testCases:
        # 获取输入的副本，以免修改原始数据
        nums = testCase.input[:]
        # 运行算法
        solution.sortColors(nums)
        # 检查实际输出是否等于预期输出
        testCase.passed = (nums == testCase.expected)
        # 打印测试用例的详细信息
        print(f"Input: {testCase.input}")
        print(f"Expected: {testCase.expected}")
        print(f"Actual: {nums}")
        print(f"Passed: {'Yes' if testCase.passed else 'No'}\n")

if __name__ == "__main__":
    runTestCases()

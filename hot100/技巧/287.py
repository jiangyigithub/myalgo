from typing import List

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        def next(i):
            return nums[i]

        slow = fast = 0
        # 第一次相遇
        while True:
            slow = next(slow)
            fast = next(next(fast))
            if slow == fast:
                break

        slow = 0
        # 第二次相遇
        while True:
            slow = next(slow)
            fast = next(fast)
            if slow == fast:
                break

        return slow

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
        TestCase([1, 3, 4, 2, 2], 2),
        TestCase([3, 1, 3, 4, 2], 3),
        TestCase([1, 1], 1),
        TestCase([1, 1, 2], 1)
    ]

    solution = Solution()
    for testCase in testCases:
        # 运行算法并获取实际输出
        actual = solution.findDuplicate(testCase.input)
        # 检查实际输出是否等于预期输出
        testCase.passed = (actual == testCase.expected)
        # 打印测试用例的详细信息
        print(f"Input: {testCase.input}")
        print(f"Expected: {testCase.expected}")
        print(f"Actual: {actual}")
        print(f"Passed: {'Yes' if testCase.passed else 'No'}\n")

if __name__ == "__main__":
    runTestCases()

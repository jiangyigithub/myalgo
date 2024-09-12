from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans = []
        path = []

        def dfs(i, left):
            # 如果剩余值为0，则找到了一个有效组合
            if left == 0:
                ans.append(path.copy())
                return
            # 剪枝，如果超过了范围或当前候选数大于剩余值，则终止递归
            if i == len(candidates) or left < candidates[i]:
                return

            # 不选择当前数字，继续向下搜索
            dfs(i + 1, left)

            # 选择当前数字，并继续搜索
            path.append(candidates[i])
            dfs(i, left - candidates[i])
            path.pop()

        # 从第0个候选数字开始搜索
        dfs(0, target)
        return ans

# 定义测试用例的结构体
class TestCase:
    def __init__(self, candidates, target, expected):
        self.candidates = candidates
        self.target = target
        self.expected = expected
        self.passed = False

# 测试函数
def runTestCases():
    # 定义测试用例
    testCases = [
        TestCase(candidates=[2, 3, 6, 7], target=7, expected=[[2, 2, 3], [7]]),
        TestCase(candidates=[2, 3, 5], target=8, expected=[[2, 2, 2, 2], [2, 3, 3], [3, 5]]),
        TestCase(candidates=[2], target=1, expected=[]),
        TestCase(candidates=[1], target=1, expected=[[1]]),
        TestCase(candidates=[1], target=2, expected=[[1, 1]]),
    ]

    solution = Solution()
    for testCase in testCases:
        # 运行算法并获取实际输出
        actual = solution.combinationSum(testCase.candidates, testCase.target)
        # 检查实际输出是否等于预期输出（排序后比较）
        testCase.passed = sorted(actual) == sorted(testCase.expected)
        # 打印测试用例的详细信息
        print(f"Candidates: {testCase.candidates}")
        print(f"Target: {testCase.target}")
        print(f"Expected: {testCase.expected}")
        print(f"Actual: {actual}")
        print(f"Passed: {'Yes' if testCase.passed else 'No'}\n")

if __name__ == "__main__":
    runTestCases()

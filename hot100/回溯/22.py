from typing import List
from dataclasses import dataclass, field

@dataclass
class TestCase:
    n: int
    expected: List[str]
    actual: List[str] = field(default_factory=list)
    passed: bool = False

def run_test_cases():
    # 定义测试用例
    test_cases = [
        TestCase(n=1, expected=["()"]),
        TestCase(n=2, expected=["(())", "()()"]),
        TestCase(n=3, expected=["((()))", "(()())", "(())()", "()(())", "()()()"]),
    ]

    # 运行测试
    solution = Solution()
    for case in test_cases:
        case.actual = solution.generateParenthesis(case.n)
        case.passed = sorted(case.actual) == sorted(case.expected)  # 比较结果时进行排序

    # 输出测试结果
    for i, case in enumerate(test_cases):
        print(f"Test Case {i + 1}: n = {case.n}")
        print(f"Expected: {case.expected}")
        print(f"Actual: {case.actual}")
        print(f"Passed: {case.passed}")
        print("-" * 30)

# 解决方案类
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        m = 2 * n
        path = [''] * m
        ans = []
        # 二选1，选左括号还是右括号
        def dfs(i, left, right):
            if left == n and right == n:
                ans.append(''.join(path))
                return
            if left < n:
                path[i] = '('
                dfs(i + 1, left + 1, right)
            if right < left:
                path[i] = ')'
                dfs(i + 1, left, right + 1)

        dfs(0, 0, 0)
        return ans

# 执行测试用例
run_test_cases()

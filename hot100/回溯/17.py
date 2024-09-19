from typing import List, NamedTuple

MAPPING = "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        n = len(digits)
        if n == 0:
            return []
        ans = []
        path = [''] * n  # 本题 path 长度固定为 n
        def dfs(i: int) -> None:
            if i == n:
                ans.append(''.join(path))
                return
            for c in MAPPING[int(digits[i])]:
                path[i] = c  # 直接覆盖
                dfs(i + 1)
        dfs(0)
        return ans

# 测试用例结构体
class TestCase(NamedTuple):
    digits: str
    expected: List[str]

# 测试函数
def run_tests():
    # 定义测试用例
    test_cases = [
        TestCase(digits="23", expected=["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]),
        TestCase(digits="", expected=[]),
        TestCase(digits="2", expected=["a", "b", "c"]),
    ]

    # 创建 Solution 实例
    solution = Solution()

    # 遍历每个测试用例
    for idx, case in enumerate(test_cases):
        actual = solution.letterCombinations(case.digits)
        # 输出每个测试用例的详细信息
        print(f"Test Case {idx + 1}:")
        print(f"  Input: {case.digits}")
        print(f"  Expected: {case.expected}")
        print(f"  Actual: {actual}")
        print(f"  Passed: {actual == case.expected}")
        print("-" * 50)

# 运行测试
run_tests()


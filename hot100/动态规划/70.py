from functools import cache
from dataclasses import dataclass
from typing import List

# 解决方案类
class Solution:
    def climbStairs(self, n: int) -> int:
        @cache
        def dfs(i: int) -> int:
            if i <= 1:
                return 1
            return dfs(i - 1) + dfs(i - 2)
        
        return dfs(n)

# 定义测试用例的结构体
@dataclass
class TestCase:
    n: int
    expected: int

# 运行单个测试用例
def run_test_case(test_case: TestCase) -> None:
    solution = Solution()
    actual = solution.climbStairs(test_case.n)
    
    # 比较预期结果和实际结果
    passed = (actual == test_case.expected)
    
    # 输出测试用例的详细信息
    print(f"Test Case:")
    print(f"  Input n: {test_case.n}")
    print(f"  Expected Result: {test_case.expected}")
    print(f"  Actual Result: {actual}")
    print(f"  Status: {'Passed' if passed else 'Failed'}")
    print(f"-----------------------------")

# 主函数
def main():
    # 定义测试用例
    test_cases: List[TestCase] = [
        TestCase(n=2, expected=2),  # 1 + 1, 2
        TestCase(n=3, expected=3),  # 1 + 1 + 1, 1 + 2, 2 + 1
        TestCase(n=4, expected=5),  # 1 + 1 + 1 + 1, 1 + 1 + 2, 1 + 2 + 1, 2 + 1 + 1, 2 + 2
        TestCase(n=5, expected=8),  # 1 + 1 + 1 + 1 + 1, 1 + 1 + 1 + 2, 1 + 1 + 2 + 1, 1 + 2 + 1 + 1, 2 + 1 + 1 + 1, 2 + 2 + 1, 2 + 1 + 2, 1 + 2 + 2
        TestCase(n=6, expected=13)  # 1 + 1 + 1 + 1 + 1 + 1, 1 + 1 + 1 + 1 + 2, 1 + 1 + 1 + 2 + 1, 1 + 1 + 2 + 1 + 1, 1 + 2 + 1 + 1 + 1, 2 + 1 + 1 + 1 + 1, 1 + 1 + 2 + 2, 1 + 2 + 2 + 1, 2 + 1 + 2 + 1, 2 + 2 + 1 + 1, 2 + 2 + 2, 1 + 2 + 1 + 2, 2 + 1 + 2 + 2
    ]

    # 运行测试用例
    for test_case in test_cases:
        run_test_case(test_case)

if __name__ == "__main__":
    main()

from typing import List

class Solution:

    def solveNQueens(self, n: int) -> List[List[str]]:
        ans=[]
        col=[0]*n

        def valid(r,c):
            for R in range(r):
                C=col[R]
                if r+c==R+C or r-c == R-C:
                    return False
            return True
        
        def dfs(r,s):
            if r==n:
                print(col)
                ans.append(['.' * c + 'Q' + '.' * (n - 1 - c) for c in col])
                return
            for c in s:
                if valid(r,c):
                    col[r]=c
                    dfs(r+1,s-{c})
        dfs(0,set(range(n)))
        return ans

# 定义测试用例结构体
class TestCase:
    def __init__(self, n: int, expected: List[List[str]]):
        self.n = n
        self.expected = expected
        self.result = []
        self.passed = False

    def run_test(self, solution: Solution):
        self.result = solution.solveNQueens(self.n)
        # 比较预期结果和实际结果
        self.passed = self.result == self.expected

# 测试用例列表
test_cases = [
    TestCase(4, [
        [".Q..",
         "...Q",
         "Q...",
         "..Q."],
        ["..Q.",
         "Q...",
         "...Q",
         ".Q.."]
    ]),
    TestCase(1, [["Q"]]),
    TestCase(2, []),  # 2皇后无解
    TestCase(3, []),  # 3皇后无解
]

# 运行测试并输出结果
solution = Solution()
for i, test_case in enumerate(test_cases):
    test_case.run_test(solution)
    print(f"Test Case {i+1}:")
    print(f"  Board Size: {test_case.n}")
    print(f"  Expected: {test_case.expected}")
    print(f"  Actual: {test_case.result}")
    print(f"  Passed: {test_case.passed}")
    print("-" * 50)

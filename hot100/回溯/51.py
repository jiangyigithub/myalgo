from typing import List

class Solution:

    def solveNQueens(self, n: int) -> List[List[str]]:
        ans=[]
        path=[0]*n

        def valid(r,c):
            for R in range(r):
                C=path[R]
                if r+c==R+C or r-c == R-C:
                    return False
            return True
        
        def dfs(r,s):
            if r==n:
                ans.append(['.' * c + 'Q' + '.' * (n - 1 - c) for c in path])
                return
            for c in s:
                if valid(r,c):
                    path[r]=c
                    dfs(r+1,s-{c})
        dfs(0,set(range(n)))
        return ans
    
    def solveNQueens2(self, n: int) -> List[List[str]]:
        m = n * 2 - 1
        ans = []
        path = [0] * n
        on_path, diag1, diag2 = [False] * n, [False] * m, [False] * m
        
        def dfs(r: int) -> None:
            if r == n:
                ans.append(['.' * c + 'Q' + '.' * (n - 1 - c) for c in path])
                return
            for c, on in enumerate(on_path):
                if not on and not diag1[r + c] and not diag2[r - c]:
                    path[r] = c
                    on_path[c] = diag1[r + c] = diag2[r - c] = True
                    dfs(r + 1)
                    on_path[c] = diag1[r + c] = diag2[r - c] = False  # 恢复现场
        dfs(0)
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

from typing import List, Tuple
from itertools import permutations
from math import inf

class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        source = []
        target = []
        print(grid)
        for i, row in enumerate(grid):
            for j, cnt in enumerate(row):
                if cnt > 1:
                    source.extend([(i, j)] * (cnt - 1))
                elif cnt == 0:
                    target.append((i, j))

        ans = inf
        for s in permutations(source):
            total = 0
            for (x1, y1), (x2, y2) in zip(s, target):
                total += abs(x1 - x2) + abs(y1 - y2)
            ans = min(ans, total)
        return ans


# 定义测试用例的结构体
class TestCase:
    def __init__(self, grid: List[List[int]], expected: int):
        self.grid = grid
        self.expected = expected
        self.actual = None
        self.passed = False

    def run_test(self, solution: Solution):
        self.actual = solution.minimumMoves(self.grid)
        self.passed = self.actual == self.expected

    def __str__(self):
        return (f"Grid: {self.grid}\n"
                f"Expected: {self.expected}\n"
                f"Actual: {self.actual}\n"
                f"Test Passed: {self.passed}\n")


# 测试用例
test_cases = [
 TestCase([[1, 3, 0], [1, 0, 0], [1, 0, 3]], 4),
 TestCase([[1,1,0],[1,1,1],[1,2,1]],3)
]

# 运行测试用例
solution = Solution()
for idx, test_case in enumerate(test_cases, 1):
    test_case.run_test(solution)
    print(f"Test Case {idx}:")
    print(test_case)

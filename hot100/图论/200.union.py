from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        f = {}

        def find(x):
            f.setdefault(x, x)
            if f[x] != x:
                f[x] = find(f[x])
            return f[x]

        def union(x, y):
            f[find(x)] = find(y)

        if not grid: return 0
        row = len(grid)
        col = len(grid[0])

        for i in range(row):
            for j in range(col):
                if grid[i][j] == "1":
                    for x, y in [[-1, 0], [0, -1]]:
                        tmp_i = i + x
                        tmp_j = j + y
                        if 0 <= tmp_i < row and 0 <= tmp_j < col and grid[tmp_i][tmp_j] == "1":
                            union(tmp_i * col + tmp_j, i * col + j)
        # print(f)
        res = set()
        for i in range(row):
            for j in range(col):
                if grid[i][j] == "1":
                    res.add(find((i * col + j)))
        return len(res)

# Structure to hold test case information
class TestCase:
    def __init__(self, grid: List[List[str]], expected: int):
        self.grid = grid
        self.expected = expected

# Function to run test cases
def runTests():
    # Create test cases
    testCases = [
        TestCase([
            ["1", "1", "0", "0", "0"],
            ["1", "1", "0", "0", "0"],
            ["0", "0", "1", "0", "0"],
            ["0", "0", "0", "1", "1"]
        ], 3),
        
        TestCase([
            ["1", "1", "1", "1", "0"],
            ["1", "1", "0", "1", "0"],
            ["1", "1", "0", "0", "0"],
            ["0", "0", "0", "0", "0"]
        ], 1),
        
        TestCase([
            ["1", "0", "0", "1"],
            ["0", "0", "1", "1"],
            ["0", "1", "1", "0"],
            ["1", "0", "0", "0"]
        ], 3),
        
        TestCase([
            ["0", "0", "0", "0"],
            ["0", "0", "0", "0"],
            ["0", "0", "0", "0"],
            ["0", "0", "0", "0"]
        ], 0),
        
        TestCase([
            ["1"]
        ], 1),
        
        TestCase([
            ["1", "1"],
            ["1", "1"]
        ], 1),
        
        TestCase([
            ["1", "0"],
            ["0", "1"]
        ], 2)
    ]

    sol = Solution()
    for i, testCase in enumerate(testCases):
        # Make a deep copy of the grid to preserve the original grid for each test case
        grid_copy = [row[:] for row in testCase.grid]
        result = sol.numIslands(grid_copy)
        print(f"Test Case {i + 1}:")
        print(f"Grid:")
        for row in testCase.grid:
            print(row)
        print(f"Expected Result: {testCase.expected}")
        print(f"Actual Result: {result}")
        print(f"Test {'Passed' if result == testCase.expected else 'Failed'}\n")

if __name__ == "__main__":
    runTests()
from typing import List
from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # BFS 
        def bfs(grid, i, j):
            queue = deque([[i, j]])
            while queue:
                x, y = queue.popleft()
                if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] == '1':
                    grid[x][y] = '0'  # Mark the land as visited
                    for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                        queue.append([x + dx, y + dy])
        
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':  # 找到一个岛屿的根节点了
                    bfs(grid, i, j)
                    ans += 1  # Increment the island count

        return ans

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
        ], 1)
    ]

    sol = Solution()
    for i, testCase in enumerate(testCases):
        result = sol.numIslands(testCase.grid)
        print(f"Test Case {i + 1}:")
        print(f"Expected Result: {testCase.expected}")
        print(f"Actual Result: {result}")
        print(f"Test {'Passed' if result == testCase.expected else 'Failed'}\n")

if __name__ == "__main__":
    runTests()

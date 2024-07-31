from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(grid, i, j):
            # Check boundary conditions and whether the cell is water ('0')
            if not (0 <= i < len(grid)) or not (0 <= j < len(grid[0])) or grid[i][j] == '0':
                return
            # Mark the cell as visited
            grid[i][j] = '0'
            # Explore all 4 directions
            dfs(grid, i + 1, j)
            dfs(grid, i, j + 1)
            dfs(grid, i - 1, j)
            dfs(grid, i, j - 1)

        count = 0
        # Iterate through each cell in the grid
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                # If we find land ('1'), start a DFS to mark the entire island
                if grid[i][j] == '1':
                    dfs(grid, i, j)
                    count += 1  # Increment island count
        
        return count

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

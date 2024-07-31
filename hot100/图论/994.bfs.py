from typing import List

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        fresh = 0
        q = []

        # Count fresh oranges and initialize queue with rotten oranges
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == 1:
                    fresh += 1  # Count fresh oranges
                elif x == 2:
                    q.append((i, j))  # Initial rotten oranges

        # Initialize the time taken
        ans = -1
        
        # Directions for four possible movements
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        # BFS to rot oranges
        while q:
            ans += 1  # Increase time
            tmp = q
            q = []
            for x, y in tmp:  # Process all rotten oranges
                for dx, dy in directions:  # Explore in four directions
                    i, j = x + dx, y + dy
                    if 0 <= i < m and 0 <= j < n and grid[i][j] == 1:  # Fresh orange found
                        fresh -= 1
                        grid[i][j] = 2  # Mark as rotten
                        q.append((i, j))  # Add to queue

        # If there are still fresh oranges left, return -1
        return -1 if fresh else max(ans, 0)

# Structure to hold test case information
class TestCase:
    def __init__(self, grid: List[List[int]], expected: int):
        self.grid = grid
        self.expected = expected

# Function to run test cases
def runTests():
    # Create test cases
    testCases = [
        TestCase([
            [2, 1, 1, 0],
            [1, 1, 0, 1],
            [0, 0, 1, 2]
        ], 2),
        
        TestCase([
            [2, 1, 1, 2, 1, 1],
            [1, 1, 2, 0, 1, 1],
            [1, 0, 0, 2, 0, 1],
            [2, 0, 1, 0, 1, 1],
            [1, 1, 1, 2, 1, 1]
        ], 3),
        
        TestCase([
            [2, 2, 2],
            [2, 2, 2],
            [2, 2, 2]
        ], 0),
        
        TestCase([
            [1, 1, 1, 1],
            [1, 1, 1, 1],
            [1, 1, 1, 1]
        ], -1),
        
        TestCase([
            [0]
        ], 0),
        
        TestCase([
            [2]
        ], 0)
    ]

    sol = Solution()
    for i, testCase in enumerate(testCases):
        # Make a deep copy of the grid to preserve the original grid for each test case
        grid_copy = [row[:] for row in testCase.grid]
        result = sol.orangesRotting(grid_copy)
        print(f"Test Case {i + 1}:")
        print(f"Grid:")
        for row in testCase.grid:
            print(row)
        print(f"Expected Result: {testCase.expected}")
        print(f"Actual Result: {result}")
        print(f"Test {'Passed' if result == testCase.expected else 'Failed'}\n")

if __name__ == "__main__":
    runTests()

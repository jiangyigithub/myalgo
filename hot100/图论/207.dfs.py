from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        def dfs(i, adjacency, flags):
            if flags[i] == -1:
                return True
            if flags[i] == 1:
                return False
            flags[i] = 1
            for j in adjacency[i]:
                if not dfs(j, adjacency, flags):
                    return False
            flags[i] = -1
            return True

        adjacency = [[] for _ in range(numCourses)]
        flags = [0 for _ in range(numCourses)]

        for cur, pre in prerequisites:
            adjacency[pre].append(cur)

        for i in range(numCourses):
            if not dfs(i, adjacency, flags):
                return False

        return True

# Structure to hold test case information
class TestCase:
    def __init__(self, numCourses: int, prerequisites: List[List[int]], expected: bool):
        self.numCourses = numCourses
        self.prerequisites = prerequisites
        self.expected = expected

# Function to run test cases
def runTests():
    # Create test cases
    testCases = [
        TestCase(2, [[1, 0]], True),
        TestCase(2, [[1, 0], [0, 1]], False),
        TestCase(4, [[1, 0], [2, 1], [3, 2]], True),
        TestCase(3, [[1, 0], [2, 0], [0, 2]], False),
        TestCase(5, [[1, 0], [2, 1], [3, 2], [4, 3]], True),
        TestCase(6, [[1, 0], [2, 1], [3, 2], [1, 4], [5, 4]], True),
        TestCase(6, [[1, 0], [2, 1], [3, 2], [1, 4], [4, 5], [5, 1]], False)
    ]

    sol = Solution()
    for i, testCase in enumerate(testCases):
        result = sol.canFinish(testCase.numCourses, testCase.prerequisites)
        print(f"Test Case {i + 1}:")
        print(f"Expected Result: {testCase.expected}")
        print(f"Actual Result: {result}")
        print(f"Test {'Passed' if result == testCase.expected else 'Failed'}\n")

if __name__ == "__main__":
    runTests()

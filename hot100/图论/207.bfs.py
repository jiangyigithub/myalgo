from collections import deque
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegrees = [0 for _ in range(numCourses)]
        adjacency = [[] for _ in range(numCourses)]
        queue = deque()

        # Get the indegree and adjacency of every course.
        for cur, pre in prerequisites:
            indegrees[cur] += 1
            adjacency[pre].append(cur)

        # Get all the courses with the indegree of 0.
        for i in range(len(indegrees)):
            if not indegrees[i]:
                queue.append(i)

        # BFS TopSort.
        while queue:
            pre = queue.popleft()
            numCourses -= 1
            for cur in adjacency[pre]:
                indegrees[cur] -= 1
                if not indegrees[cur]:
                    queue.append(cur)

        return numCourses == 0

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
        TestCase(5, [[1, 0], [2, 1], [3, 2], [4, 3]], True)
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

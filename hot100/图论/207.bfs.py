from collections import deque
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegrees = [0 for _ in range(numCourses)]
        adjacency = [[] for _ in range(numCourses)]
        que = deque()

        # 统计DAG的节点
        for nxt, cur in prerequisites:
            indegrees[nxt] += 1
            adjacency[cur].append(nxt)

        # 根节点入队，入度为0，即为根
        for i in range(len(indegrees)):
            if not indegrees[i]:
                que.append(i)
        
        top_order = []  # 用于存储拓扑排序的结果
        
        # BFS
        while que:
            cur = que.popleft()
            numCourses -= 1
            top_order.append(cur)
            for nxt in adjacency[cur]:
                indegrees[nxt] -= 1
                if not indegrees[nxt]:
                    que.append(nxt)

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

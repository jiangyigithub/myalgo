from typing import List

class Solution:
    def permute(self,nums):
        n=len(nums)
        ans=[]
        path=[0]*n
        def dfs(i,s):
            if i==n:
                ans.append(path.copy())
                return
            for x in s:
                path[i]=x
                dfs(i+1,s-{x})
        dfs(0,set(nums))
        return ans

    def permute2(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        path = [0] * n  # 所有排列的长度都是一样的 n
        on_path = [False] * n
        def dfs(i: int) -> None:
            if i == n:
                ans.append(path.copy())
                return

            for j, on in enumerate(on_path):
                if not on:
                    path[i] = nums[j]  # 从没有选的数字中选一个
                    on_path[j] = True  # 已选上
                    dfs(i + 1)
                    on_path[j] = False  # 恢复现场
                    # 注意 path 无需恢复现场，因为排列长度固定，直接覆盖就行
        dfs(0)
        return ans
    
class TestCase:
    def __init__(self, nums, expected):
        self.nums = nums
        self.expected = expected
        self.actual = []
        self.passed = False

    def run_test(self, solution):
        # 运行测试用例并更新实际结果和通过状态
        self.actual = solution.permute(self.nums)
        self.passed = sorted(self.actual) == sorted(self.expected)

    def __str__(self):
        # 返回测试用例的详细信息
        return (f"TestCase(nums={self.nums}, expected={self.expected}, "
                f"actual={self.actual}, passed={self.passed})")
    
# 创建测试用例
test_cases = [
    TestCase([1, 2, 3], [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]),
    TestCase([0, 1], [[0, 1], [1, 0]]),
    TestCase([1], [[1]])
]

# 运行所有测试用例
solution = Solution()
for test in test_cases:
    test.run_test(solution)
    print(test)
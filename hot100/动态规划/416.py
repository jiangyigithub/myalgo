from typing import List
from functools import cache

class Solution:
    # 从数组中选数，总和为s//2,每个数只能选一次，即为0-1背包问题
    def canPartition(self, nums: List[int]) -> bool:
        @cache
        # 选i，倒着选
        # 剩余容量j
        def dfs(i,j):
            if i<0:
                return j==0
            if nums[i]>j:
                return dfs(i-1,j)
            return dfs(i-1,j-nums[i]) or dfs(i-1,j)
        s=sum(nums)
        return s%2==0 and dfs(len(nums)-1,s//2)
    
    def canPartition2(self, nums: List[int]) -> bool:
        @cache  # 缓存装饰器，避免重复计算 dfs 的结果（记忆化）
        def dfs(i: int, j: int) -> bool:
            if i < 0:
                return j == 0
            return j >= nums[i] and dfs(i - 1, j - nums[i]) or dfs(i - 1, j)
        s = sum(nums)
        return s % 2 == 0 and dfs(len(nums) - 1, s // 2)

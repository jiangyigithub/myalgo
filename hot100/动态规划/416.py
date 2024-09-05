from typing import List
from functools import cache

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        @cache
        # 选i（0-1背包）
        # 剩余容量j
        def dfs(i,j):
            if i<0:
                return j==0
            return j>=nums[i] and dfs(i-1,j-nums[i]) or dfs(i-1,j)
        s=sum(nums)
        return s%2==0 and dfs(len(nums)-1,s//2)
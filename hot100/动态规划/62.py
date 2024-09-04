from typing import List
from functools import cache
from dataclasses import dataclass
import math

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        @cache
        def dfs(i,j):
            if i==0 or j==0:
                return 1
            return dfs(i-1,j)+dfs(i,j-1)
        return dfs(m-1,n-1)
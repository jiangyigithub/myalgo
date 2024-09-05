from typing import List
from functools import cache

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)

        # 递归函数计算以第 i 个元素结尾的子数组的最大乘积
        # i: 第 i 个元素结尾的子数组
        @cache  # 使用缓存来避免重复计算
        def max_prod(i):
            if i == 0:
                # 基础条件：第一个元素的乘积就是它本身
                return nums[0]
            
            current = nums[i]
            # 获取前一个位置的最大乘积和最小乘积
            prev_max = max_prod(i - 1)
            prev_min = min_prod(i - 1)

            # 计算当前元素结尾的最大乘积，可以是：
            # 1. 当前元素自身
            # 2. 当前元素与前一个位置的最大乘积相乘
            # 3. 当前元素与前一个位置的最小乘积相乘（因为负负得正的可能性）
            return max(current, current * prev_max, current * prev_min)

        # 递归函数计算以第 i 个元素结尾的子数组的最小乘积
        @cache  # 使用缓存来避免重复计算
        def min_prod(i):
            if i == 0:
                # 基础条件：第一个元素的乘积就是它本身
                return nums[0]
            
            current = nums[i]
            # 获取前一个位置的最大乘积和最小乘积
            prev_max = max_prod(i - 1)
            prev_min = min_prod(i - 1)

            # 计算当前元素结尾的最小乘积，可以是：
            # 1. 当前元素自身
            # 2. 当前元素与前一个位置的最大乘积相乘
            # 3. 当前元素与前一个位置的最小乘积相乘
            return min(current, current * prev_max, current * prev_min)

        # 初始化结果为数组的第一个元素
        ans = nums[0]
        # 遍历所有位置，更新全局的最大乘积
        for i in range(n):
            ans = max(ans, max_prod(i))

        return ans
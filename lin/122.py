from typing import List
from functools import cache
from math import inf

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        
        @cache
        def dfs(i: int, hold: bool) -> int:
            if i < 0:
                return -inf if hold else 0
            if hold:
                return max(dfs(i - 1, True), dfs(i - 1, False) - prices[i])
            else:
                return max(dfs(i - 1, False), dfs(i - 1, True) + prices[i])
        
        return dfs(n - 1, False)

# ----------------------
# 测试代码
# ----------------------

def run_tests():
    sol = Solution()
    
    test_cases = [
        ([7, 1, 5, 3, 6, 4], 7),       # 低买高卖多次：1->5, 3->6
        ([1, 2, 3, 4, 5], 4),          # 持续上升：买入1卖出5
        ([7, 6, 4, 3, 1], 0),          # 持续下降：不交易
        ([2, 4, 1], 2),                # 一次交易：2->4
        ([3, 3, 5, 0, 0, 3, 1, 4], 8), # 多次交易机会
    ]
    
    for i, (prices, expected) in enumerate(test_cases, 1):
        result = sol.maxProfit(prices)
        print(f"Test Case {i}: prices = {prices}")
        print(f"  ➤ Expected: {expected}, Got: {result}")
        print(f"  ✅ {'Passed' if result == expected else 'Failed'}\n")

# 运行测试
run_tests()

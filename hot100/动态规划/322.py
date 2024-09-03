from typing import List
from functools import cache
from dataclasses import dataclass

# Define the Solution class with the coinChange method
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        @cache  # 缓存装饰器，避免重复计算 dfs 的结果（记忆化）
        def dfs(i: int, c: int) -> int:
            if i < 0:
                return 0 if c == 0 else float('inf')
            if c < coins[i]:
                return dfs(i - 1, c)#不选
            return min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1)#不选/选
        ans = dfs(len(coins) - 1, amount)
        return ans if ans < float('inf') else -1
    
    def coinChange2(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[float('inf')] * (amount + 1) for _ in range(n + 1)]
        dp[0][0] = 0
        for i, x in enumerate(coins):
            for c in range(amount + 1):
                if c < x:
                    dp[i + 1][c] = dp[i][c]
                else:
                    dp[i + 1][c] = min(dp[i][c], dp[i + 1][c - x] + 1)
        ans = dp[n][amount]
        return ans if ans < float('inf') else -1
    
    def coinChange3(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[float('inf')] * (amount + 1) for _ in range(2)]
        dp[0][0] = 0
        for i, x in enumerate(coins):
            for c in range(amount + 1):
                if c < x:
                    dp[(i + 1) % 2][c] = dp[i % 2][c]
                else:
                    dp[(i + 1) % 2][c] = min(dp[i % 2][c], dp[(i + 1) % 2][c - x] + 1)
        ans = dp[n % 2][amount]
        return ans if ans < float('inf') else -1
    
    def coinChange4(self, coins: List[int], amount: int) -> int:
        dp = [0] + [float('inf')] * amount
        for x in coins:
            for c in range(x, amount + 1):
                dp[c] = min(dp[c], dp[c - x] + 1)
        ans = dp[amount]
        return ans if ans < float('inf') else -1

# Define a dataclass for test cases
@dataclass
class TestCase:
    coins: List[int]
    amount: int
    expected: int

# Function to run tests
def run_tests():
    # Test cases
    test_cases = [
        TestCase(coins=[1, 2, 5], amount=11, expected=3),
        TestCase(coins=[2], amount=3, expected=-1),
        TestCase(coins=[1], amount=0, expected=0),
        TestCase(coins=[1], amount=2, expected=2),
        TestCase(coins=[1, 3, 4, 5], amount=7, expected=2),
    ]

    solution = Solution()

    # Run each test case
    for i, test in enumerate(test_cases):
        actual = solution.coinChange(test.coins, test.amount)
        passed = actual == test.expected
        print(dp"Test Case {i + 1}:")
        print(dp"  Coins: {test.coins}, Amount: {test.amount}")
        print(dp"  Expected: {test.expected}, Actual: {actual}")
        print(dp"  Passed: {'Yes' if passed else 'No'}")
        print("-" * 50)

# Run the test function
run_tests()

#include <vector>
#include <iostream>
#include <algorithm> // for std::min
#include <climits>
using namespace std;
// {{1, 2, 5}, 11, 3},     // Test case 1: 11 can be made with 5 + 5 + 1
// {{2}, 3, -1},           // Test case 2: 3 cannot be made with only coin 2
// {{1, 2, 5}, 0, 0},      // Test case 3: 0 can be made with no coins
// {{1}, 2, 2},            // Test case 4: 2 can be made with two 1 coins
// {{2}, 1, -1},           // Test case 5: 1 cannot be made with only coin 2
// {{1, 2, 5, 10}, 27, 4}  // Test case 6: 27 can be made with 10 + 10 + 5 + 2

class Solution
{

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1)); // -1 表示没有访问过
        auto dfs = [&](auto &&dfs, int i, int c) -> int
        {
            if (i < 0)
            {
                return c == 0 ? 0 : INT_MAX / 2; // 除 2 防止下面 + 1 溢出
            }
            int &res = memo[i][c]; // 注意这里是引用
            if (res != -1)
            { // 之前计算过
                return res;
            }
            if (c < coins[i])
            {
                return res = dfs(dfs, i - 1, c);
            }
            return res = min(dfs(dfs, i - 1, c), dfs(dfs, i, c - coins[i]) + 1);
        };
        int ans = dfs(dfs, n - 1, amount);
        return ans < INT_MAX / 2 ? ans : -1;
    }

    int coinChangeDP(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX / 2)); // 除 2 防止下面 + 1 溢出
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int c = 0; c <= amount; c++)
            {
                if (c < coins[i])
                    dp[i + 1][c] = dp[i][c];
                else
                    dp[i + 1][c] = min(dp[i][c], dp[i + 1][c - coins[i]] + 1);
            }
        }
        int ans = dp[n][amount];
        return ans < INT_MAX / 2 ? ans : -1;
    }

    int coinChangeTwoArray(vector<int> &coins, int amount)
    {
        int n = coins.size();
        // 空间优化：两个数组（滚动数组）
        vector<vector<int>> dp(2, vector<int>(amount + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int c = 0; c <= amount; c++)
            {
                if (c < coins[i])
                    dp[(i + 1) % 2][c] = dp[i % 2][c];
                else
                    dp[(i + 1) % 2][c] = min(dp[i % 2][c], dp[(i + 1) % 2][c - coins[i]] + 1);
            }
        }
        int ans = dp[n % 2][amount];
        return ans < INT_MAX / 2 ? ans : -1;
    }

    int coinChangeOneArray(vector<int> &coins, int amount)
    {
        // 空间优化：一个数组
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;
        for (int x : coins)
        {
            for (int c = x; c <= amount; c++)
            {
                dp[c] = min(dp[c], dp[c - x] + 1);
            }
        }
        return dp[amount] == amount +1 ? -1:dp[amount];
    }
};

struct TestCase
{
    vector<int> coins;
    int amount;
    int expected;
};

int main()
{
    TestCase testCases[] = {
        {{1, 2, 5}, 11, 3},     // Test case 1: 11 can be made with 5 + 5 + 1
        {{2}, 3, -1},           // Test case 2: 3 cannot be made with only coin 2
        {{1, 2, 5}, 0, 0},      // Test case 3: 0 can be made with no coins
        {{1}, 2, 2},            // Test case 4: 2 can be made with two 1 coins
        {{2}, 1, -1},           // Test case 5: 1 cannot be made with only coin 2
        {{1, 2, 5, 10}, 27, 4}, // Test case 6: 27 can be made with 10 + 10 + 5 + 2
        {{5, 4, 3}, 20, 4}};

    for (size_t i = 0; i < sizeof(testCases) / sizeof(TestCase); ++i)
    {
        const TestCase &testCase = testCases[i];
        vector<int> temp = testCase.coins;
        // int result = Solution().coinChange(temp, testCase.amount);
        // int result = Solution().coinChangeDP(temp, testCase.amount);
        // int result = Solution().coinChangeTwoArray(temp, testCase.amount);
        int result = Solution().coinChangeOneArray(temp, testCase.amount);
        // int result = Solution().coinChangeDP2(temp, testCase.amount);
        cout << "Test case " << i + 1 << ": expected = " << testCase.expected << ", got = " << result;
        if (result == testCase.expected)
        {
            cout << " [PASSED]" << endl;
        }
        else
        {
            cout << " [FAILED]" << endl;
        }
    }

    return 0;
}

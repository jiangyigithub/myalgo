#include <vector>
#include <iostream>
#include <algorithm> // for std::min
using namespace std;
// {{1, 2, 5}, 11, 3},     // Test case 1: 11 can be made with 5 + 5 + 1
// {{2}, 3, -1},           // Test case 2: 3 cannot be made with only coin 2
// {{1, 2, 5}, 0, 0},      // Test case 3: 0 can be made with no coins
// {{1}, 2, 2},            // Test case 4: 2 can be made with two 1 coins
// {{2}, 1, -1},           // Test case 5: 1 cannot be made with only coin 2
// {{1, 2, 5, 10}, 27, 4}  // Test case 6: 27 can be made with 10 + 10 + 5 + 2

int coinChange(const vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0; // 凑成0金额所需硬币数量为0

    for (int i = 1; i <= amount; ++i)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

/* 零钱兑换：动态规划 */
int coinChangeDP2(vector<int> &coins, int amount)
{
    int n = coins.size();
    // 使用整型 int 的最大值来代替。而这又会导致大数越界：状态转移方程中的+1操作可能发生溢出
    int MAX = amount + 1;
    // 初始化 dp 表
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    // 状态转移：首行首列
    for (int a = 1; a <= amount; a++)
    {
        dp[0][a] = MAX;
    }
    // 状态转移：其余行和列
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amount; a++)
        {
            if (coins[i - 1] > a)
            {
                // 若超过目标金额，则不选硬币 i
                dp[i][a] = dp[i - 1][a];
            }
            else
            {
                // 不选和选硬币 i 这两种方案的较小值
                dp[i][a] = min(dp[i - 1][a], dp[i][a - coins[i - 1]] + 1);
            }
        }
    }
    return dp[n][amount] != MAX ? dp[n][amount] : -1;
}

struct TestCase
{
    vector<int> coins;
    int amount;
    int expected;
};

int main()
{
    TestCase testCases[] = {
        {{5, 4, 3}, 20, 4},
        {{1, 2, 5}, 11, 3},    // Test case 1: 11 can be made with 5 + 5 + 1
        {{2}, 3, -1},          // Test case 2: 3 cannot be made with only coin 2
        {{1, 2, 5}, 0, 0},     // Test case 3: 0 can be made with no coins
        {{1}, 2, 2},           // Test case 4: 2 can be made with two 1 coins
        {{2}, 1, -1},          // Test case 5: 1 cannot be made with only coin 2
        {{1, 2, 5, 10}, 27, 4} // Test case 6: 27 can be made with 10 + 10 + 5 + 2
    };

    for (size_t i = 0; i < 6; ++i)
    {
        const TestCase &testCase = testCases[i];
        vector<int> temp = testCase.coins;
        int result = coinChange(temp, testCase.amount);
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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 左边 或上面
                if (i == 0 && j > 0)
                {
                    dp[0][j] = dp[0][j - 1] + grid[0][j];
                }
                else if (j == 0 && i > 0)
                {
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                }
                else if (i > 0 && j > 0)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
 int minPathSum2(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; ++i) {
            dp[i][0] += dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] += dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

struct TestCase
{
    vector<vector<int>> grid;
    int expected;
};

void runTest(TestCase &test, Solution &solution)
{
    int actual = solution.minPathSum(test.grid);
    cout << "Test Case:" << endl;
    for (const auto &row : test.grid)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "Expected: " << test.expected << endl;
    cout << "Actual: " << actual << endl;
    cout << (actual == test.expected ? "Test Passed" : "Test Failed") << endl
         << endl;
}

int main()
{
    vector<TestCase> testCases = {
        {{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 7},
        {{{1, 2, 3}, {4, 5, 6}}, 12}};

    Solution solution;
    for (auto &test : testCases)
    {
        runTest(test, solution);
    }

    return 0;
}
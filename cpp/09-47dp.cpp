#include "head.hpp"
/***
剑指 Offer 47. 礼物的最大价值
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 

示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
 

提示：

0 < grid.length <= 200
0 < grid[0].length <= 200
***/


// https://www.hello-algo.com/chapter_dynamic_programming/dp_solution_pipeline/#1335
class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                    grid[i][j] += grid[i][j - 1];
                else if (j == 0)
                    grid[i][j] += grid[i - 1][j];
                else
                    grid[i][j] += max(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[m - 1][n - 1];
    }

    /* 最小路径和：状态压缩后的动态规划 */
    int maxPathSumDPComp(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        // 初始化 dp 表
        vector<int> dp(m);
        // 状态转移：首行
        dp[0] = grid[0][0];
        for (int j = 1; j < m; j++)
        {
            dp[j] = dp[j - 1] + grid[0][j];
        }
        // 状态转移：其余行
        for (int i = 1; i < n; i++)
        {
            // 状态转移：首列
            dp[0] = dp[0] + grid[i][0];
            // 状态转移：其余列
            for (int j = 1; j < m; j++)
            {
                dp[j] = max(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[m - 1];
    }
};

int main()
{
    // [[1,3,1],[1,5,1],[4,2,1]]
    vector<vector<int>> m_grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    
    int result2 = Solution().maxPathSumDPComp(m_grid);
    int result = Solution().maxValue(m_grid);
    
    cout << result2 << endl;
    cout << result << endl;
}
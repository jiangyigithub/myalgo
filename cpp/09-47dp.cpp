#include "head.hpp"

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
};

int main()
{
    // [[1,3,1],[1,5,1],[4,2,1]]
    vector<vector<int>> m_grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int result = Solution().maxValue(m_grid);
    cout << result << endl;
}
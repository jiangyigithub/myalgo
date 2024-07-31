#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 别玩了return返回，比较是字符而不是字符串'0' '1'

//  if (grid.empty())
//         return 0;
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        if (i < 0 || i >= nr || j < 0 || j >= nc || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;
        int ans = 0;
        int nr = grid.size();
        int nc = grid[0].size();
        for (int i = 0; i < nr; ++i)
        {
            for (int j = 0; j < nc; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};

int main()
{
    // 测试用例
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    vector<vector<char>> grid2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    Solution solution;

    cout << "Number of islands in grid1: " << solution.numIslands(grid1) << endl;
    cout << "Number of islands in grid2: " << solution.numIslands(grid2) << endl;

    return 0;
}

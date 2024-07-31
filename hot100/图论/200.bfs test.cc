#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    void bfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();
        queue<pair<int, int>> que;
        que.push({r, c});
        grid[r][c] = '0'; // 将当前格子标记为已访问

        // 定义四个方向的偏移量
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!que.empty()) {
            auto [row, col] = que.front();
            que.pop();
       
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;
                if (newRow >= 0 && newRow < nr && newCol >= 0 && newCol < nc && grid[newRow][newCol] == '1') {
                    que.push({newRow, newCol});
                    grid[newRow][newCol] = '0'; // 将新找到的陆地格子标记为已访问
                }
            }
        }
    }


    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;
        int ans = 0;
        int nr = grid.size();
        int nl = grid[0].size();
        for (int i = 0; i < nr; ++i)
        {
            for (int j = 0; j < nl; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    bfs(grid, i, j);
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

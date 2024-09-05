#include <vector>
using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> memo(m, vector<int>(n, -1)); // -1 表示没有访问过
    auto dfs = [&](auto &&dfs, int i, int j)
    {
        if(i == 0 || j == 0) return 1;
        int &res = memo[i][j]; // 注意这里是引用
        if (res != -1)
        { // 之前计算过
            return res;
        }
        // 这是个杨辉三角形，每个位置的路径 = 该位置左边的路径 + 该位置上边的路径
        return res = dfs(dfs, i - 1, j) + dfs(dfs, i, j - 1);
    };
    return dfs(dfs, m - 1, n - 1);
}
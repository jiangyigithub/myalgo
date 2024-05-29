#include "head.hpp"
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        // 创建一个二维的访问标记数组
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // 记录可以到达的格子的数量
        int res = 0;
        // 使用队列来实现广度优先搜索
        queue<vector<int>> que;
        // 初始时将起点 (0, 0) 和其数位和 (0, 0) 入队
        que.push({0, 0, 0, 0});

        // 开始 BFS 循环
        while (!que.empty())
        {
            // 取出队首元素
            vector<int> x = que.front();
            que.pop();
            int i = x[0], j = x[1], si = x[2], sj = x[3];

            // 判断是否越界，是否数位和大于 k 或者是否已经访问过
            if (i >= m || j >= n || k < si + sj || visited[i][j])
                continue;

            // 标记当前格子已访问
            visited[i][j] = true;
            // 计数
            res++;

            // 将右边的格子入队
            que.push({i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj});
            // 将下边的格子入队
            que.push({i, j + 1, si, (j + 1) % 10 != 0 ? sj + 1 : sj - 8});
        }
        return res;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

/*
m=4 n=4 k=2
[0,0] [0,1] [0,2] [0,3]
[1,0] [1,1] [1,2] [1,3]
[2,0] [2,1] [2,2] [2,3]
[3,0] [3,1] [3,2] [3,3]
*/

int main()
{
    string line;

    int m = 4;
    int n = 4;
    int k = 3;

    int ret = Solution().movingCount(m, n, k);

    string out = to_string(ret);
    cout << out << endl;

    return 0;
}
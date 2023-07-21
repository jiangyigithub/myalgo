#include "head.hpp"
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        int res = 0;
        queue<vector<int>> que;
        que.push({0, 0, 0, 0});
        while (que.size() > 0)
        {
            vector<int> x = que.front();
            que.pop();
            int i = x[0], j = x[1], si = x[2], sj = x[3];
            if (i >= m || j >= n || k < si + sj || visited[i][j])
                continue;
            visited[i][j] = true;
            res++;
            que.push({i + 1, j, (i + 1) % 10 != 0 ? si + 1 : si - 8, sj});
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
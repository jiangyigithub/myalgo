#include "head.hpp"

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        vector<int> res;
        while (true)
        {
            for (int i = l; i <= r; i++)
                res.push_back(matrix[t][i]); // left to right
            t++;
            if (t > b)
                break;
            for (int i = t; i <= b; i++)
                res.push_back(matrix[i][r]); // top to bottom
            r--;
            if (l > r)
                break;
            for (int i = r; i >= l; i--)
                res.push_back(matrix[b][i]); // right to left
            b--;
            if (t > b)
                break;
            for (int i = b; i >= t; i--)
                res.push_back(matrix[i][l]); // bottom to top
            l++;
            if (l > r)
                break;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = Solution().spiralOrder(matrix);
    for (auto each : result)
    {
        cout << each << endl;
    }
}
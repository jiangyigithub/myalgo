#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        // 完全背包
        vector<vector<bool>> f(n + 1, vector<bool>(target + 1));
        f[0][0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                f[i + 1][j] = f[i][j] || j >= candidates[i] && f[i + 1][j - candidates[i]];
            }
        }

        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int)> dfs = [&](int i, int left) {
            if (left == 0) {
                // 找到一个合法组合
                ans.push_back(path);
                return;
            }

            // 无法用下标在 [0, i] 中的数字组合出 left
            if (left < 0 || !f[i + 1][left]) {
                return;
            }

            // 不选
            dfs(i - 1, left);

            // 选
            path.push_back(candidates[i]);
            dfs(i, left - candidates[i]);
            path.pop_back();
        };

        // 倒着递归，这样参数符合 f 数组的定义
        dfs(n - 1, target);
        return ans;
    }
};
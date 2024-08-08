#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int)> dfs = [&](int i, int left) {
            if (left == 0) {
                // 找到一个合法组合
                ans.push_back(path);
                return;
            }

            if (left < candidates[i]) {
                return;
            }

            // 枚举选哪个
            for (int j = i; j < candidates.size(); j++) {
                path.push_back(candidates[j]);
                dfs(j, left - candidates[j]);
                path.pop_back(); // 恢复现场
            }
        };

        dfs(0, target);
        return ans;
    }
};
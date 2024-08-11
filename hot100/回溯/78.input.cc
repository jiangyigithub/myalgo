#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        auto dfs = [&](auto&& dfs, int i) -> void {
            if (i == n) { // 子集构造完毕
                ans.emplace_back(path);
                return;
            }
            
            // 不选 nums[i]，直接进入下一层
            dfs(dfs, i + 1);
            
            // 选 nums[i]，再进入下一层
            path.push_back(nums[i]);
            dfs(dfs, i + 1);
            path.pop_back(); // 恢复现场
        };
        dfs(dfs, 0);
        return ans;
    }
};


void printSubsets(const vector<vector<int>>& subsets) {
    for (const auto& subset : subsets) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
}

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = solution.subsets(nums1);
    cout << "Subsets of {1, 2, 3}:\n";
    printSubsets(result1);
    
    // Test case 2
    vector<int> nums2 = {0};
    vector<vector<int>> result2 = solution.subsets(nums2);
    cout << "Subsets of {0}:\n";
    printSubsets(result2);
    
    // Test case 3
    vector<int> nums3 = {};
    vector<vector<int>> result3 = solution.subsets(nums3);
    cout << "Subsets of {}:\n";
    printSubsets(result3);

    // Additional test case 4
    vector<int> nums4 = {4, 5, 6, 7};
    vector<vector<int>> result4 = solution.subsets(nums4);
    cout << "Subsets of {4, 5, 6, 7}:\n";
    printSubsets(result4);
    
    return 0;
}


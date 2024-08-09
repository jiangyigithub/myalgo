#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> ans;
        int counter = 0;  // Counter to track recursive calls

        
        // Lambda function for DFS
        auto dfs = [&](auto&& dfs, int i) -> void {
            ++counter;  // Increment counter on each call
            ans.push_back(path);
            for (int j = i; j < n; ++j) {
                path.push_back(nums[j]);
                dfs(dfs, j + 1);
                path.pop_back();
            }
        };
        
        // Initial call to DFS
        dfs(dfs, 0);
        cout << "Number of recursive calls: " << counter << endl;  // Output the counter value
        
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
    
    // // Test case 2
    // vector<int> nums2 = {0};
    // vector<vector<int>> result2 = solution.subsets(nums2);
    // cout << "Subsets of {0}:\n";
    // printSubsets(result2);
    
    // // Test case 3
    // vector<int> nums3 = {};
    // vector<vector<int>> result3 = solution.subsets(nums3);
    // cout << "Subsets of {}:\n";
    // printSubsets(result3);

    // // Additional test case 4
    // vector<int> nums4 = {4, 5, 6, 7};
    // vector<vector<int>> result4 = solution.subsets(nums4);
    // cout << "Subsets of {4, 5, 6, 7}:\n";
    // printSubsets(result4);
    
    return 0;
}

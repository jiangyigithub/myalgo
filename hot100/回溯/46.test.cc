#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution
{

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> visited(n,0);
        vector<int> path(n);
        function<void(int)> dfs=[&](int i){
            if(i==n){
                ans.push_back(path);
                return;
            }
            for(int j=0;j<n;j++){
                if(visited[j]==0){
                    path[i]=nums[j];
                    visited[j]=1;
                    dfs(i+1);
                    visited[j]=0;
                }
                
            }
        };
        dfs(0);
        return ans;
    }
};

void printResult(const vector<vector<int>> &result)
{
    for (const auto &vec : result)
    {
        for (int num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {0, 1};
    vector<int> nums3 = {1};

    cout << "Permutations of {1, 2, 3}:" << endl;
    vector<vector<int>> result1 = sol.permute(nums1);
    printResult(result1);

    // cout << "Permutations of {0, 1}:" << endl;
    // vector<vector<int>> result2 = sol.permute(nums2);
    // printResult(result2);

    // cout << "Permutations of {1}:" << endl;
    // vector<vector<int>> result3 = sol.permute(nums3);
    // printResult(result3);

    return 0;
}

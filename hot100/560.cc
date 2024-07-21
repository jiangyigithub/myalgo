#include <iostream>
#include <vector>
using namespace std;
/*
初始化一个二维 DP 数组 dp，其中 dp[i][j] 表示数组从索引 i 到索引 j 的子数组的和。
*/
// Function to count the number of subarrays with sum equal to k using DP
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    
    // Initialize a 2D DP array
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Fill the DP array
    for (int i = 0; i < n; ++i) {
        dp[i][i] = nums[i];
        if (dp[i][i] == k) {
            count++;
        }
        for (int j = i + 1; j < n; ++j) {
            dp[i][j] = dp[i][j-1] + nums[j];
            if (dp[i][j] == k) {
                count++;
            }
        }
    }
    
    return count;
}

// Structure to store test cases
struct TestCase {
    vector<int> nums;
    int k;
    int expected;
};

int main() {
    // Define test cases
    vector<TestCase> testCases = {
        {{1, 1, 1}, 2, 2},
        {{1, 2, 3}, 3, 2},
        {{1, -1, 0}, 0, 3},
        {{3, 4, 7, 2, -3, 1, 4, 2}, 7, 4}
    };
    
    // Run test cases
    for (auto& testCase : testCases) {
        int result = subarraySum(testCase.nums, testCase.k);
        cout << "Array: [";
        for (size_t i = 0; i < testCase.nums.size(); ++i) {
            cout << testCase.nums[i];
            if (i != testCase.nums.size() - 1) cout << ", ";
        }
        cout << "], k: " << testCase.k << endl;
        cout << "Expected result: " << testCase.expected << ", Actual result: " << result << endl;
        cout << (result == testCase.expected ? "Test passed" : "Test failed") << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}

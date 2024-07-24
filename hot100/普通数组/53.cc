#include <iostream>
#include <vector>
#include <algorithm> // for std::max
using namespace std;

// https://leetcode.cn/problems/maximum-subarray/solutions/9058/dong-tai-gui-hua-fen-zhi-fa-python-dai-ma-java-dai/?envType=study-plan-v2&envId=top-100-liked



int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sum = nums[0];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = nums[i];
        sum = max(sum, dp[i][i]);
        for (int j = i + 1; j < n; ++j)
        {
            dp[i][j] = dp[i][j - 1] + nums[j];
            sum = max(sum, dp[i][j]);
        }
    }
    return sum;
}

// Function to find the maximum sum of a contiguous subarray using DP
// dp[i]：表示以 nums[i] 结尾 的 连续 子数组的最大和。
int maxSubArray2(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0)
        return 0; // Handle edge case for empty array

    // Initialize the DP array
    vector<int> dp(n);
    dp[0] = nums[0];        // Base case: the max sum of subarray ending at index 0 is nums[0]
    int max_global = dp[0]; // Initialize the global max sum

    // Fill the DP array using the state transition equation
    for (int i = 1; i < n; ++i)
    {   
        dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        max_global = max(max_global, dp[i]);
    }

    return max_global; // Return the global maximum sum
}

// Function to find the maximum sum of a contiguous subarray
/// 优化空间的代码会丢失可读性，不好理解和向他人阐述。
int maxSubArray3(vector<int> &nums)
{
    // Initialize the current and global maximums
    int max_current = nums[0];
    int max_global = nums[0];

    // Traverse the array starting from the second element
    for (size_t i = 1; i < nums.size(); ++i)
    {
        // Update max_current to be the maximum of the current element or current element + max_current
        max_current = max(nums[i], max_current + nums[i]);

        // Update max_global to be the maximum of max_global or max_current
        if (max_current > max_global)
        {
            max_global = max_current;
        }
    }

    return max_global; // Return the global maximum
}

// Structure to store test cases
struct TestCase
{
    vector<int> nums; // Input array
    int expected;     // Expected result
};

int main()
{
    // Define test cases
    vector<TestCase> testCases = {
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
        {{1}, 1},
        {{5, 4, -1, 7, 8}, 23},
        {{-1, -2, -3, -4}, -1},
        {{1, 2, 3, 4, 5}, 15}};

    // Run test cases
    for (auto &testCase : testCases)
    {
        int result = maxSubArray(testCase.nums);
        cout << "Array: [";
        for (size_t i = 0; i < testCase.nums.size(); ++i)
        {
            cout << testCase.nums[i];
            if (i != testCase.nums.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
        cout << "Expected result: " << testCase.expected << ", Actual result: " << result << endl;
        cout << (result == testCase.expected ? "Test passed" : "Test failed") << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}

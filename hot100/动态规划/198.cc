#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n, -1); // -1 表示没有计算过

        // dfs(i) 表示从 nums[0] 到 nums[i] 最多能偷多少
        auto dfs = [&](auto &&dfs, int i) -> int
        {
            if (i < 0)
                return 0; // 递归边界（没有房子）
            if (memo[i] != -1)
                return memo[i]; // 之前计算过
            memo[i] = max(dfs(dfs, i - 1), dfs(dfs, i - 2) + nums[i]);
            return memo[i];
        };

        return dfs(dfs, n - 1); // 从最后一个房子开始思考
    }
};

struct TestCase
{
    vector<int> nums;
    int expected;
};

void runTestCase(const TestCase &testCase)
{
    Solution solution;
    int result = solution.rob(testCase.nums);
    string status = (result == testCase.expected) ? "Passed" : "Failed";

    cout << "Test Case:" << endl;
    cout << "  Input: ";
    for (int num : testCase.nums)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "  Expected Result: " << testCase.expected << endl;
    cout << "  Actual Result: " << result << endl;
    cout << "  Status: " << status << endl;
    cout << "-----------------------------" << endl;
}

int main()
{
    vector<TestCase> testCases = {
        {{1, 2, 3, 1}, 4},
        {{2, 7, 9, 3, 1}, 12},
        {{2, 1, 1, 2}, 4},
        {{5, 3, 4, 11, 2}, 16},
        {{0, 0, 0, 0}, 0},
        {{100}, 100},
        {{}, 0},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 30}};

    for (const auto &testCase : testCases)
    {
        runTestCase(testCase);
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n, -1);
        function<int(int)> dfs = [&](int i)
        {
            if (i < 0)
                return 0;
            if (memo[i] != -1)
                return memo[i]; // 避免重复计算
            memo[i] = max(dfs(i - 1), dfs(i - 2) + nums[i]); // 金额作为返回值还是递归参数
            // 不选第i个元素 dfs(i - 1)
            // 选第i个元素 dfs(i - 2) + nums[i]
            return memo[i];
        };
        return dfs(n - 1);
    }

    int rob2(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n,0);
        for(int i=0;i<n;i++)
        {
            memo[i+2] = max(memo[i+1],memo[i]+nums[i]);
        }
        return memo[n+1];
    }

    int rob3(vector<int> &nums)
    {
        int n = nums.size();
        int f1=0,f0=0;
        for(int i=0;i<n;i++){
            int new_f = max(f1,f0+nums[i]);
            f0=f1;
            f1=new_f;
        }
        return f1;
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

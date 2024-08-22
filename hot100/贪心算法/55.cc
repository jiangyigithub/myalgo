#include <iostream>
#include <vector>
using namespace std;

struct TestCase
{
    vector<int> input; // 输入数组
    bool expected;     // 预期结果
    bool actual;       // 实际结果
    bool passed;       // 测试是否通过
};

class Solution
{
public:
    // i + nums[i]
    bool canJump(vector<int> &nums)
    {
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // 无法到达 i
            if (i > mx) // mx表示上个周期的mx值
            {
                return false;
            }
            mx = max(mx, i + nums[i]); // 从 i 最右可以跳到 i + nums[i]
        }
        return true;
    }
};

void runTests(vector<TestCase> &testCases, Solution &sol)
{
    for (auto &testCase : testCases)
    {
        testCase.actual = sol.canJump(testCase.input);
        testCase.passed = (testCase.actual == testCase.expected);

        // 输出测试用例的详细信息
        cout << "Test Case: ";
        for (int n : testCase.input)
        {
            cout << n << " ";
        }
        cout << "\nExpected: " << (testCase.expected ? "true" : "false")
             << "\nActual: " << (testCase.actual ? "true" : "false")
             << "\nTest " << (testCase.passed ? "Passed" : "Failed") << "\n\n";
    }
}

int main()
{
    Solution sol;

    // 初始化测试用例
    vector<TestCase> testCases = {
        {{2, 3, 1, 1, 4}, true, false, false},  // 预期：true
        {{3, 2, 1, 0, 4}, false, false, false}, // 预期：false
        {{0}, true, false, false},              // 预期：true
        {{2, 0}, true, false, false},           // 预期：true
        {{1, 1, 1, 1, 1}, true, false, false},  // 预期：true
    };

    // 运行测试
    runTests(testCases, sol);

    return 0;
}

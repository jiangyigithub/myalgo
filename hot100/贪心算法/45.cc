#include <iostream>
#include <vector>
using namespace std;

// 定义结构体存储测试用例
struct TestCase
{
    vector<int> input; // 输入数组
    int expected;      // 预期结果
    int actual;        // 实际结果
    bool passed;       // 测试是否通过
};

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int step = 0;
        int current_end = 0;
        int farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // 更新当前能够跳到的最远位置
            farthest = max(farthest, i + nums[i]);

            // 如果到达了当前跳跃的末端，需要跳跃一次
            if (i == current_end)
            {
                step++;
                current_end = farthest;
            }
        }
        return step;
    }
};

// 测试函数
void runTests(vector<TestCase> &testCases, Solution &sol)
{
    for (auto &testCase : testCases)
    {
        // 计算实际结果
        testCase.actual = sol.jump(testCase.input);
        // 判断测试是否通过
        testCase.passed = (testCase.actual == testCase.expected);

        // 输出测试用例的详细信息
        cout << "Test Case: ";
        for (int n : testCase.input)
        {
            cout << n << " ";
        }
        cout << "\nExpected: " << testCase.expected
             << "\nActual: " << testCase.actual
             << "\nTest " << (testCase.passed ? "Passed" : "Failed") << "\n\n";
    }
}

int main()
{
    Solution sol;

    // 初始化测试用例
    vector<TestCase> testCases = {
        {{2, 3, 1, 1, 4}, 2, 0, false}, // 预期：2
        {{2, 3, 0, 1, 4}, 2, 0, false}, // 预期：2
        {{1, 2, 3}, 2, 0, false},       // 预期：2
        {{2, 1, 1, 1, 1}, 3, 0, false}, // 预期：3
        {{0}, 0, 0, false},             // 预期：0（只有一个元素）
    };

    // 运行测试
    runTests(testCases, sol);

    return 0;
}

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
        int far = 0;
        int cend = 0; //更新当前落地
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            far = max(far,nums[i]+i);
            // 起点是在变化，一开始的起点为0
            if(i==cend)
            {
                step++;
                cend=far;
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

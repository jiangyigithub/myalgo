#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    // {{30, 40, 50, 60}, {1, 1, 1, 0}},

    // 遍历整个数组，如果栈不空，且当前数字大于栈顶元素，那么如果直接入栈的话就不是 递减栈 ，
    // 所以需要取出栈顶元素，由于当前数字大于栈顶元素的数字，而且一定是第一个大于栈顶元素的数，直接求出下标差就是二者的距离。

    // 继续看新的栈顶元素，直到当前数字小于等于栈顶元素停止，
    // 然后将数字入栈，这样就可以一直保持递减栈，且每个数字和第一个大于它的数的距离也可以算出来。

    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            int t = temperatures[i];
            while (!stk.empty() && t > temperatures[stk.top()])
            {
                int j = stk.top();
                stk.pop();
                ans[j] = i - j; // i 是第一個大於j的元素
            }
            stk.push(i);
        }
        return ans;
    }

    vector<int> dailyTemperaturesWithRight(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--)
        {
            int t = temperatures[i];
            while (!stk.empty() && t >= temperatures[stk.top()])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return ans;
    }
};

// 定义结构体来存储测试用例
struct TestCase
{
    vector<int> temperatures;
    vector<int> expected;
    vector<int> result;
    bool passed;
};

// 测试函数
void runTestCase(Solution &solution, TestCase &testCase)
{
    // testCase.result = solution.dailyTemperatures(testCase.temperatures);
    testCase.result = solution.dailyTemperaturesWithRight(testCase.temperatures);
    testCase.passed = (testCase.result == testCase.expected);
}

// 打印测试用例详情
void printTestCaseDetails(const TestCase &testCase, int index)
{
    cout << "Test Case " << index + 1 << ":\n";
    cout << "Temperatures: ";
    for (int temp : testCase.temperatures)
    {
        cout << temp << " ";
    }
    cout << "\nExpected: ";
    for (int exp : testCase.expected)
    {
        cout << exp << " ";
    }
    cout << "\nResult: ";
    for (int res : testCase.result)
    {
        cout << res << " ";
    }
    cout << "\nTest " << (testCase.passed ? "Passed" : "Failed") << "\n\n";
}

int main()
{
    Solution solution;

    // 定义测试用例
    vector<TestCase> testCases = {
        {{73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0}},
        {{30, 40, 50, 60}, {1, 1, 1, 0}},
        {{30, 60, 90}, {1, 1, 0}},
        {{90, 60, 30}, {0, 0, 0}}};

    // 运行并输出每个测试用例的详细信息
    for (int i = 0; i < testCases.size(); i++)
    {
        runTestCase(solution, testCases[i]);
        printTestCaseDetails(testCases[i], i);
    }

    return 0;
}

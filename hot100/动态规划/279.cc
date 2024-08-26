#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring> // for memset
using namespace std;

// 初始化 memo 数组
int memo[101][10001];
auto init = []
{
    memset(memo, -1, sizeof(memo)); // -1 表示没有计算过
    return 0;
}();

// 定义 dfs 函数
int dfs(int i, int j)
{
    if (i == 0)
    {
        return j == 0 ? 0 : INT_MAX;
    }

    int &res = memo[i][j]; // 注意这里是引用

    // 之前计算过
    if (res != -1)
    {
        return res;
    }

    if (j < i * i)
    {
        res = dfs(i - 1, j); // 只能不选
    }
    else
    {
        res = min(dfs(i - 1, j), dfs(i, j - i * i) + 1); // 不选 vs 选
    }

    return res;
}

class Solution
{
public:
    int numSquares(int n)
    {
        return dfs(sqrt(n), n);
    }
};

// 结构体定义，存储测试用例
struct TestCase
{
    int n;
    int expected;
};

// 运行单个测试用例
void runTestCase(const TestCase &testCase)
{
    Solution solution;
    int actual = solution.numSquares(testCase.n);

    // 比较预期结果和实际结果
    bool passed = (actual == testCase.expected);

    // 输出测试用例的详细信息
    cout << "Test Case:" << endl;
    cout << "  Input n: " << testCase.n << endl;
    cout << "  Expected Result: " << testCase.expected << endl;
    cout << "  Actual Result: " << actual << endl;
    cout << "  Status: " << (passed ? "Passed" : "Failed") << endl;
    cout << "-----------------------------" << endl;
}

int main()
{
    // 定义测试用例
    vector<TestCase> testCases = {
        {12, 3}, // 12 = 4 + 4 + 4
        {13, 2}, // 13 = 4 + 9
        {1, 1},  // 1 = 1
        {7, 4},  // 7 = 1 + 1 + 1 + 4
        {16, 1}, // 16 = 16
    };

    // 运行测试用例
    for (const auto &testCase : testCases)
    {
        runTestCase(testCase);
    }

    return 0;
}

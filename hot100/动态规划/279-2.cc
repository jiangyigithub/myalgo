#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring> // for memset
using namespace std;

const int N = 10000;

int f[101][N + 1];

auto init = []
{
    ranges::fill(f[0], INT_MAX);

    f[0][0] = 0;

    for (int i = 1; i * i <= N; i++)
    {

        for (int j = 0; j <= N; j++)
        {

            if (j < i * i)
            {

                f[i][j] = f[i - 1][j]; // 只能不选
            }
            else
            {

                f[i][j] = min(f[i - 1][j], f[i][j - i * i] + 1); // 不选 vs 选
            }
        }
    }

    return 0;
}();

class Solution
{

public:
    int numSquares(int n)
    {

        return f[(int)sqrt(n)][n]; // 也可以写 f[100][n]
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

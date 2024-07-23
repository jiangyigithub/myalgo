#include <iostream>
#include <vector>

using namespace std;

// 定义测试用例的结构体
struct TestCase
{
    vector<vector<int>> matrix;
    int target;
    bool expected;
};

// 螺旋顺序搜索函数
class Solution
{
public:
    //{{1, 4, 7, 11},
    // {2, 5, 8, 12},
    // {3, 6, 9, 16},
    // {10, 13, 14, 17}},
    //     5,
    //     true
    bool searchMatrix(const vector<vector<int>> &matrix, int target)
    {

        if (matrix.empty())
        {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        cout << "matrix.size()" << m;
        cout << "matrix[0].size()" << n;

        int left = m - 1;
        int right = 0;

        while (left >= 0 && right < n)
        {
            int temp = matrix[left][right];
            if (target == temp)
            {
                return true;
            }
            else if (target > temp)
            {
                right++;
            }
            else
            {
                left--;
            }
        }
        return false;
    }
};

// 比较结果函数
bool checkResult(bool expected, bool actual)
{
    return expected == actual;
}

// 打印矩阵
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

// 打印测试结果
void printTestCase(TestCase &testCase, Solution &solution)
{
    bool result = solution.searchMatrix(testCase.matrix, testCase.target);
    bool passed = checkResult(testCase.expected, result);

    // 打印测试用例的详细信息
    cout << "Input Matrix:" << endl;
    printMatrix(testCase.matrix);
    cout << "Target: " << testCase.target << endl;
    cout << "Expected Result: " << (testCase.expected ? "Found" : "Not Found") << endl;
    cout << "Actual Result: " << (result ? "Found" : "Not Found") << endl;
    cout << "Test " << (passed ? "Passed" : "Failed") << endl;
    cout << "----------------------------------------" << endl;
}

int main()
{
    Solution solution;

    // 定义测试用例
    vector<TestCase> testCases = {
        {{{1, 4, 7, 11}, {2, 5, 8, 12}, {3, 6, 9, 16}, {10, 13, 14, 17}},
         5,
         true},
        {{{1, 4, 7, 11}, {2, 5, 8, 12}, {3, 6, 9, 16}, {10, 13, 14, 17}},
         20,
         false},
        {{{1, 2, 3}, {4, 5, 6}},
         5,
         true},
        {{{1}},
         1,
         true},
        {{},
         1,
         false}};

    // 执行测试
    for (auto &testCase : testCases)
    {
        printTestCase(testCase, solution);
    }

    return 0;
}

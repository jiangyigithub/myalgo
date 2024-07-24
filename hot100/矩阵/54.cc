#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

// 定义测试用例的结构体
struct TestCase
{
    vector<vector<int>> matrix;
    vector<int> expected;
};

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

// 打印 vector
void printVector(const vector<int> &vec)
{
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
}

// 螺旋顺序函数
/// 你的边界，我来更新

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    if (matrix.empty())
        return {};
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0;
    int right = n - 1;
    int left = 0;
    int bottom = m - 1;
    vector<int> res;
    while (true)
    {
        for (int i = left; i <= right; i++)
            res.push_back(matrix[top][i]); // left to right
        if (++top > bottom)
            break;
        for (int i = top; i <= bottom; i++)
            res.push_back(matrix[i][right]); // top to bottom
        if (left > --right)
            break;
        for (int i = right; i >= left; i--)
            res.push_back(matrix[bottom][i]); // right to left
        if (top > --bottom)
            break;
        for (int i = bottom; i >= top; i--)
            res.push_back(matrix[i][left]); // bottom to top
        if (++left > right)
            break;
    }
    return res;
}

vector<int> spiralOrder2(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0;
    int right = n - 1;
    int left = 0;
    int bottom = m - 1;
    vector<int> ret;
    while (true)
    {
        // 从左到右，更新top边界
        for (int j = left; j <= right; j++)
        {
            ret.push_back(matrix[top][j]);
        }
        top++;
        if (top > bottom)
            break;

        // 从上到下，更新right边界
        for (int i = top; i <= bottom; i++)
        {
            ret.push_back(matrix[i][right]);
        }
        right--;
        if (right < left)
            break;

        // 从右到左，更新bottom 边界
        for (int j = right; j >= left; j--)
        {
            ret.push_back(matrix[bottom][j]);
        }
        bottom--;
        if (top > bottom)
            break;

        // 从下到上，更新left边界
        for (int i = bottom; i >= top; i--)
        {
            ret.push_back(matrix[i][left]);
        }
        left++;
        if (right < left)
            break;
    }
    return ret;
}

// 比较结果函数
bool checkResult(const vector<int> &expected, const vector<int> &actual)
{
    if (expected.size() != actual.size())
    {
        return false;
    }
    for (size_t i = 0; i < expected.size(); ++i)
    {
        if (expected[i] != actual[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    // 定义测试用例
    vector<TestCase> testCases = {
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
         {1, 2, 3, 6, 9, 8, 7, 4, 5}},
        {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
         {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}},
        {{{1, 2, 3}, {4, 5, 6}},
         {1, 2, 3, 6, 5, 4}},
        {{{1}},
         {1}},
        {{},
         {}}};

    for (const auto &testCase : testCases)
    {
        // 获取实际结果
        vector<int> result = spiralOrder(testCase.matrix);

        // 检查结果
        bool passed = checkResult(testCase.expected, result);

        // 打印测试用例的详细信息
        cout << "Input Matrix:" << endl;
        printMatrix(testCase.matrix);
        cout << "Expected Result: ";
        printVector(testCase.expected);
        cout << "Actual Result: ";
        printVector(result);
        cout << "Test " << (passed ? "Passed" : "Failed") << endl;
        cout << "----------------------------------------" << endl;
    }

    return 0;
}

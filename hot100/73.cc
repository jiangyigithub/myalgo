#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
看懂题目

*/
// 定义结构体来存储测试用例
struct TestCase
{
    std::vector<std::vector<int>> input;
    std::vector<std::vector<int>> expected;
};

// Solution类包含将矩阵置零的方法
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++)
        {
            if (!matrix[i][0])
            {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (!matrix[0][j])
            {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][j])
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (!matrix[i][0] || !matrix[0][j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (flag_col0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }

    void setZeroes2(std::vector<std::vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        bool flag_col0 = false, flag_row0 = false;

        // 检查第一列是否有零，只标记不置0，不破坏标记
        // 空间复杂度为O(1)，只能在数组内操作，直接检查会导致标记被破坏，导致额外的行和列被置0
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                flag_col0 = true;
                break;
            }
        }

        // 检查第一行是否有零，只标记不置0
        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
            {
                flag_row0 = true;
                break;
            }
        }

        // 借用第一行和第一列作为标记，第一行和第一列没有被破坏
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;//第i行应被置0
                    matrix[0][j] = 0;//第j行应被置0
                }
            }
        }

        // 根据标记将相应的行和列置零
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // 如果需要，将第一列置零
        if (flag_col0)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }

        // 如果需要，将第一行置零
        if (flag_row0)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
    }
};

// 打印矩阵
void printMatrix(const std::vector<std::vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// 比较两个矩阵是否相等
bool matricesEqual(const std::vector<std::vector<int>> &mat1, const std::vector<std::vector<int>> &mat2)
{
    if (mat1.size() != mat2.size())
        return false;
    for (size_t i = 0; i < mat1.size(); i++)
    {
        if (mat1[i] != mat2[i])
            return false;
    }
    return true;
}

// 运行测试用例
void runTestCases(const std::vector<TestCase> &testCases)
{
    Solution solution;
    for (size_t i = 0; i < testCases.size(); i++)
    {
        std::vector<std::vector<int>> input = testCases[i].input;
        std::vector<std::vector<int>> expected = testCases[i].expected;

        solution.setZeroes(input);

        std::cout << "Test Case " << i + 1 << ":\n";
        std::cout << "Input:\n";
        printMatrix(testCases[i].input);
        std::cout << "Expected Output:\n";
        printMatrix(testCases[i].expected);
        std::cout << "Actual Output:\n";
        printMatrix(input);

        if (matricesEqual(input, expected))
        {
            std::cout << "Test Passed\n";
        }
        else
        {
            std::cout << "Test Failed\n";
        }
        std::cout << "-------------------------\n";
    }
}

int main()
{
    std::vector<TestCase> testCases = {
        {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
         {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}},
        {{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
         {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}}}};

    runTestCases(testCases);

    return 0;
}

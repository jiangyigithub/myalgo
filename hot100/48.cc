#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

// Function to print the matrix
void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Rotate the matrix 90 degrees clockwise
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[7,4,1],[8,5,2],[9,6,3]]

// 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// Rotate the matrix 90 degrees clockwise
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    print_matrix(matrix);
    // 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
    // 输出：[[7,4,1],[8,5,2],[9,6,3]]
    // Step 1: Transpose the matrix

    /// 对角旋转，只交接一半元素
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    print_matrix(matrix);
    // Step 2: Reverse each row
    for (int i = 0; i < n; ++i)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    print_matrix(matrix);
}

void rotate2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // 深拷贝 matrix -> tmp
    vector<vector<int>> tmp = matrix;
    // 根据元素旋转公式，遍历修改原矩阵 matrix 的各元素
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[j][n - 1 - i] = tmp[i][j];
        }
    }
}



// Structure to store test case details
struct TestCase
{
    vector<vector<int>> input_matrix;
    vector<vector<int>> expected_output;
    vector<vector<int>> actual_output;
    bool passed;

    TestCase(const vector<vector<int>> &input, const vector<vector<int>> &expected)
        : input_matrix(input), expected_output(expected), passed(false) {}

    void run_test()
    {
        actual_output = input_matrix; // Copy input to actual_output for modification
        rotate(actual_output);
        passed = (actual_output == expected_output);
    }

    void print_result()
    {
        cout << "Input Matrix: " << endl;
        print_matrix(input_matrix);
        cout << "Expected Output: " << endl;
        print_matrix(expected_output);
        cout << "Actual Output: " << endl;
        print_matrix(actual_output);
        cout << "Test Passed: " << (passed ? "True" : "False") << endl;
    }

    void print_matrix(const vector<vector<int>> &matrix)
    {
        for (const auto &row : matrix)
        {
            for (int val : row)
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // List of test cases
    vector<TestCase> test_cases = {
        TestCase({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}),
        TestCase({{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}}, {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}),
        TestCase({{1}}, {{1}}),
        TestCase({{1, 2}, {3, 4}}, {{3, 1}, {4, 2}})};

    // Run and print test cases
    for (auto &test : test_cases)
    {
        test.run_test();
        test.print_result();
        cout << "--------------------------" << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> c(numRows);
        for (int i = 0; i < numRows; i++) {
            c[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) 
            {
                // 左上方的数 + 正上方的数 (加法原理)
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
        return c;
    }
};

// 结构体定义，存储测试用例
struct TestCase {
    int numRows;
    vector<vector<int>> expected;
};

void runTestCase(const TestCase& testCase) {
    Solution solution;
    vector<vector<int>> result = solution.generate(testCase.numRows);
    
    // 比较预期结果和实际结果
    bool passed = (result == testCase.expected);
    
    // 输出测试用例的详细信息
    cout << "Test Case:" << endl;
    cout << "  Input numRows: " << testCase.numRows << endl;
    
    cout << "  Expected Result: [";
    for (const auto& row : testCase.expected) {
        cout << "[";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;
    
    cout << "  Actual Result: [";
    for (const auto& row : result) {
        cout << "[";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "] ";
    }
    cout << "]" << endl;
    
    cout << "  Status: " << (passed ? "Passed" : "Failed") << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    // 定义测试用例
    vector<TestCase> testCases = {
        {5, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}},
        {1, {{1}}},
        {3, {{1}, {1, 1}, {1, 2, 1}}},
        {4, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}}}
    };

    // 运行测试用例
    for (const auto& testCase : testCases) {
        runTestCase(testCase);
    }

    return 0;
}

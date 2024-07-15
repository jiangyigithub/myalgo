#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 结构体定义测试用例
struct TestCase {
    string input;
    int numRows;
    string expected;
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; // 特殊情况处理

        vector<string> rows(min(numRows, int(s.size())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }

        string result;
        for (string& row : rows) {
            result += row;
        }
        return result;
    }

    // 输出 Z 字形可视化
    void visualize(string s, int numRows) {
        if (numRows == 1) {
            cout << s << endl;
            return;
        }

        vector<string> rows(min(numRows, int(s.size())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            currentRow += goingDown ? 1 : -1;
        }

        for (const string& row : rows) {
            cout << row << endl;
        }
    }
};

void runTests(const vector<TestCase>& testCases, Solution& solution) {
    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        string result = solution.convert(testCase.input, testCase.numRows);
        cout << "Test case " << i + 1 << ": input = \"" << testCase.input 
             << "\", numRows = " << testCase.numRows 
             << ", expected = \"" << testCase.expected 
             << "\", got = \"" << result << "\"";

        if (result == testCase.expected) {
            cout << " [PASSED]" << endl;
        } else {
            cout << " [FAILED]" << endl;
        }

        // 输出 Z 字形可视化
        cout << "Zigzag visualization:" << endl;
        solution.visualize(testCase.input, testCase.numRows);
        cout << endl;
    }
}

int main() {
    Solution solution;
    vector<TestCase> testCases = {
        {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
        {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
        {"AB", 1, "AB"},
        {"A", 1, "A"}
    };

    runTests(testCases, solution);

    return 0;
}

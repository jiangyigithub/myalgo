#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            ans ^= x;
        }
        return ans;
    }
};

// 定义测试用例的结构体
struct TestCase {
    vector<int> input;    // 测试输入
    int expected;         // 预期输出
    bool passed;          // 测试是否通过
};

// 测试函数
void runTestCases() {
    // 定义测试用例
    vector<TestCase> testCases = {
        {{2, 2, 1}, 1, false},
        {{4, 1, 2, 1, 2}, 4, false},
        {{1}, 1, false}
    };

    Solution solution;
    for (auto& testCase : testCases) {
        // 运行算法并获取实际输出
        int actual = solution.singleNumber(testCase.input);
        // 检查实际输出是否等于预期输出
        testCase.passed = (actual == testCase.expected);
        // 打印测试用例的详细信息
        cout << "Input: ";
        for (int num : testCase.input) {
            cout << num << " ";
        }
        cout << "\nExpected: " << testCase.expected
             << "\nActual: " << actual
             << "\nPassed: " << (testCase.passed ? "Yes" : "No") << "\n" << endl;
    }
}

int main() {
    runTestCases();
    return 0;
}

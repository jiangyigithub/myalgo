#include <iostream>
#include <limits.h> // For INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        /// 判断条件是
        while (x != 0) {
            int unitsDigit = x % 10; // 提取个位数字
            
            // 检查加入unitsDigit后是否会溢出，再拼接最终结果前，判断溢出
            /// 规律是 2 4 8 6，4次一循环
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && unitsDigit > 7)) return 0;
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && unitsDigit < -8)) return 0;
            
            reversed = reversed * 10 + unitsDigit; // 将unitsDigit加入reversed中
            x /= 10; // 移除个位数字
        }
        return reversed;//x=0 输出结果
    }
};

struct TestCase {
    int input;
    int expected;
};

void runTests(const TestCase testCases[], size_t numCases, Solution& solution) {
    for (size_t i = 0; i < numCases; ++i) {
        const TestCase& testCase = testCases[i];
        int result = solution.reverse(testCase.input);
        cout << "Test case " << i + 1 << ": input = " << testCase.input 
             << ", expected = " << testCase.expected 
             << ", got = " << result;
        if (result == testCase.expected) {
            cout << " [PASSED]" << endl;
        } else {
            cout << " [FAILED]" << endl;
        }
    }
}

int main() {
    Solution solution;
    TestCase testCases[] = {
        {123, 321},
        {-123, -321},
        {120, 21},
        {0, 0},
        {1534236469, 0}, // Example of overflow, should return 0
        {-2147483648, 0} // Example of negative overflow, should return 0
    };

    size_t numCases = sizeof(testCases) / sizeof(TestCase);
    runTests(testCases, numCases, solution);

    return 0;
}

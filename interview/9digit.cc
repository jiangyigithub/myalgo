#include <iostream>
#include <vector>

// 定义结构体存储测试用例
struct TestCase {
    int input;
    bool expectedOutput;
};

// 判断是否是回文数的函数
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    int cur = 0;
    int num = x;

    while (num != 0) {
        cur = cur * 10 + num % 10;
        num /= 10;
    }

    return cur == x;
}

int main() {
    // 定义测试用例
    std::vector<TestCase> testCases = {
        {121, true},
        {-121, false},
        {10, false},
        {12321, true},
        {0, true},
        {1, true},
        {1221, true},
        {123, false}
    };

    // 输出测试用例结果
    std::cout << std::boolalpha; // 打印布尔值为 true/false 而不是 1/0
    for (const auto& testCase : testCases) {
        bool actualOutput = isPalindrome(testCase.input);
        bool testPassed = (actualOutput == testCase.expectedOutput);
        std::cout << "Input: " << testCase.input 
                  << ", Expected Output: " << testCase.expectedOutput 
                  << ", Actual Output: " << actualOutput 
                  << ", Test Passed: " << testPassed 
                  << std::endl;
    }

    return 0;
}

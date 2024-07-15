#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX and INT_MIN

using namespace std;
// 定义结构体存储测试用例
struct TestCase
{
    int input;
    bool expected;
};

// 判断是否是回文数的函数
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int reversed = 0;
    int num = x;
    while (num != 0)
    {
        int unitsDigit = num % 10;
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && unitsDigit > 7))
            return false;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && unitsDigit < -8))
            return false;
        reversed = 10 * reversed + unitsDigit;
        num /= 10;
    }
    return reversed == x;
}

int main()
{
    // 定义测试用例
    std::vector<TestCase> testCases = {
        {121, true},
        {-121, false},
        {10, false},
        {12321, true},
        {0, true},
        {1, true},
        {1221, true},
        {123, false},
        {1234567899, false}};

    // 输出测试用例结果
    for (size_t i = 0; i < 9; ++i)
    {
        const TestCase &testCase = testCases[i];
        bool result = isPalindrome(testCase.input);
        cout << "Test case:" << i + 1 << "Input: \"" << testCase.input << ": expected = " << testCase.expected << ", got = " << result;
        if (result == testCase.expected)
        {
            cout << " [PASSED]" << endl;
        }
        else
        {
            cout << " [FAILED]" << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <string>
#include <climits>
#include <vector>

struct TestCase {
    std::string input;
    int expected_output;
};

class Solution {
public:
    int myAtoi(std::string s) {
        int n = s.size();
        int i = 0;

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            ++i;
        }

        // Step 2: Check the sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        // Step 3: Convert digits to integer
        long result = 0;
        while (i < n && std::isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow and underflow
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            ++i;
        }

        return static_cast<int>(result * sign);
    }
};

void runTest(const TestCase& testCase) {
    Solution solution;
    int actual_output = solution.myAtoi(testCase.input);

    std::cout << "Input: \"" << testCase.input << "\"" << std::endl;
    std::cout << "Expected Output: " << testCase.expected_output << std::endl;
    std::cout << "Actual Output: " << actual_output << std::endl;

    if (actual_output == testCase.expected_output) {
        std::cout << "Test Result: Passed" << std::endl;
    } else {
        std::cout << "Test Result: Failed" << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    // Define test cases
    std::vector<TestCase> testCases = {
        {"42", 42},
        {"   -42", -42},
        {"4193 with words", 4193},
        {"words and 987", 0},
        {"-91283472332", -2147483648}
    };

    // Run each test case
    for (const auto& testCase : testCases) {
        runTest(testCase);
    }

    return 0;
}

#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Automaton
{
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};
    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution
{
public:
    int myAtoi(string str)
    {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};

struct TestCase {
    std::string input;
    int expected_output;
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

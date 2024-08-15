#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {

        
        return result;
    }
};

struct TestCase {
    string input;
    string expected;
    string actual;
    bool passed;
};

int main() {
    Solution solution;
    vector<TestCase> testCases = {
        {"3[a]2[bc]", "aaabcbc"},
        {"3[a2[c]]", "accaccacc"},
        {"2[abc]3[cd]ef", "abcabccdcdcdef"},
        {"abc3[cd]xyz", "abccdcdcdxyz"}
    };

    for (auto& testCase : testCases) {
        testCase.actual = solution.decodeString(testCase.input);
        testCase.passed = (testCase.actual == testCase.expected);
    }

    for (const auto& testCase : testCases) {
        cout << "Input: " << testCase.input << endl;
        cout << "Expected: " << testCase.expected << endl;
        cout << "Actual: " << testCase.actual << endl;
        cout << "Passed: " << (testCase.passed ? "Yes" : "No") << endl;
        cout << "---------------------------" << endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); ++i) {
            int len1 = expandAroundCenter(s, i, i);   // Odd length palindrome
            int len2 = expandAroundCenter(s, i, i + 1); // Even length palindrome
            int len = max(len1, len2);
            
            if (len > maxLen) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }

        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

// 结构体定义测试用例
struct TestCase {
    string input;
    string expected;
};

void runTests(const vector<TestCase>& testCases, Solution& solution) {
    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        string result = solution.longestPalindrome(testCase.input);
        cout << "Test case " << i + 1 << ": input = \"" << testCase.input 
             << "\", expected = \"" << testCase.expected 
             << "\", got = \"" << result << "\"";

        if (result == testCase.expected) {
            cout << " [PASSED]" << endl;
        } else {
            cout << " [FAILED]" << endl;
        }
    }
}

int main() {
    Solution solution;
    vector<TestCase> testCases = {
        {"babad", "bab"},  // "aba" is also a valid answer
        {"cbbd", "bb"},
        {"a", "a"},
        {"ac", "a"},
        {"racecar", "racecar"},
        {"", ""}
    };

    runTests(testCases, solution);

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        // dp[i][j] 表示 s[i..j] 是否为回文子串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;

        // 单字符都是回文
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // 判断长度为2的子串是否为回文
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // 长度大于2的子串判断
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(start, maxLen);
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

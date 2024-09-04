#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome2(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";
        // 用于记忆化存储，初始化为 -1，表示未计算
        vector<vector<int>> memo(n, vector<int>(n, -1));
        int start = 0, maxLen = 1;
        // 递归函数，判断 s[i..j] 是否为回文子串
        auto dfs = [&](auto &&dfs, int i, int j) -> bool
        {
            int &ans = memo[i][j]; // 注意这里是引用
            // 如果已经计算过，直接返回结果
            if (ans != -1)
            {
                return memo[i][j];
            }
            // 单字符和空串是回文
            if (i >= j)
            {
                memo[i][j] = 1;
                return true;
            }
            // 两端字符相同，且内部子串也是回文
            if (s[i] == s[j] && dfs(dfs, i + 1, j - 1))
            {
                memo[i][j] = 1;
                return true;
            }
            // 否则不是回文
            memo[i][j] = 0;
            return false;
        };

        // 遍历所有可能的子串，找出最长的回文子串
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                if (dfs(dfs, i, j) && j - i + 1 > maxLen)
                {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }

    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";

        // dp[i][j] 表示 s[i..j] 是否为回文子串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;

        // 单字符都是回文
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
        }

        // 判断长度为2的子串是否为回文
        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // 长度大于2的子串判断
        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    start = i;
                    maxLen = len;
                }
            }
        }

        // 打印 dp 数组
        cout << "DP Table:" << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return s.substr(start, maxLen);
    }
};

// 结构体定义测试用例
struct TestCase
{
    string input;
    string expected;
};

void runTests(const vector<TestCase> &testCases, Solution &solution)
{
    for (size_t i = 0; i < testCases.size(); ++i)
    {
        const TestCase &testCase = testCases[i];
        string result = solution.longestPalindrome2(testCase.input);
        cout << "Test case " << i + 1 << ": input = \"" << testCase.input
             << "\", expected = \"" << testCase.expected
             << "\", got = \"" << result << "\"";

        if (result == testCase.expected)
        {
            cout << " [PASSED]" << endl;
        }
        else
        {
            cout << " [FAILED]" << endl;
        }
    }
}

int main()
{
    Solution solution;
    vector<TestCase> testCases = {
        {"babad", "bab"}, // "aba" is also a valid answer
        {"cbbd", "bb"},
        {"a", "a"},
        {"ac", "a"},
        {"racecar", "racecar"},
        {"", ""}};

    runTests(testCases, solution);

    return 0;
}

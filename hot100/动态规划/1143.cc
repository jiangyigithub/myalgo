#include <vector>
#include <iostream>
#include <algorithm> // for std::max
#include <climits>
#include <string>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<int>> memo(m, vector<int>(n, -1)); // -1 表示没有计算过
        auto dfs = [&](auto &&dfs, int i, int j) -> int
        {
            if (i < 0 || j < 0)
                return 0;
            int &res = memo[i][j]; // 注意这里是引用
            if (res != -1)
                return res; // 之前计算过
            if (s[i] == t[j])
                return res = dfs(dfs, i - 1, j - 1) + 1;
            return res = max(dfs(dfs, i - 1, j), dfs(dfs, i, j - 1));
        };
        return dfs(dfs, m - 1, n - 1);
    }

    int longestCommonSubsequence2(string s, string t)
    {
        int n = t.size();
        vector<int> dp(n + 1);
        for (char ch : s)
        {
            for (int j = 0, pre = 0; j < n; j++)
            {
                int temp = dp[j + 1];
                dp[j + 1] = ch == t[j] ? pre + 1 : max(dp[j + 1], dp[j]);
                pre = temp;
            }
        }
        return dp[n];
    }
};

// Structure to hold test case data
struct TestCase
{
    string s;
    string t;
    int expected;
};

// Function to run tests and print detailed results
void runTests()
{
    Solution solution;
    vector<TestCase> testCases = {
        {"abcde", "ace", 3},
        {"abc", "def", 0},
        {"", "", 0},
        {"abc", "", 0},
        {"abcdef", "abcdef", 6},
        {"abcabcaa", "acbacba", 5}};

    for (int i = 0; i < testCases.size(); ++i)
    {
        int actual = solution.longestCommonSubsequence(testCases[i].s, testCases[i].t);
        bool passed = actual == testCases[i].expected;

        // Print detailed information
        cout << "Test Case " << i + 1 << ":" << endl;
        cout << "  String s: \"" << testCases[i].s << "\"" << endl;
        cout << "  String t: \"" << testCases[i].t << "\"" << endl;
        cout << "  Expected: " << testCases[i].expected << endl;
        cout << "  Actual: " << actual << endl;
        cout << "  Result: " << (passed ? "PASS" : "FAIL") << endl;
        cout << "---------------------------------------" << endl;
    }
}

int main()
{
    runTests();
    return 0;
}

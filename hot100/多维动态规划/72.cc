#include <vector>
#include <iostream>
#include <algorithm> // for std::min, std::iota
#include <climits>
#include <string>
#include <numeric> // for std::iota

using namespace std;

class Solution
{
public:
    int minDistanceDFS(string s, string t)
    {
        int m = s.size(), n = t.size();
        vector<vector<int>> memo(m, vector<int>(n, -1)); // -1 表示还没有计算过
        auto dfs = [&](auto &&dfs, int i, int j) -> int
        {
            if (i < 0)
            {
                return j + 1; // If s is exhausted, return the remaining length of t (need to insert remaining characters of t into s)
            }
            if (j < 0)
            {
                return i + 1; // If t is exhausted, return the remaining length of s (need to delete remaining characters of s)
            }
            int &res = memo[i][j]; // 注意这里是引用
            if (res != -1)
            {
                return res; // 之前算过了
            }
            if (s[i] == t[j])
            {
                return res = dfs(dfs, i - 1, j - 1);
            }
            // 对于二维DP,单数组空间优化部分，由于当前状态与左、上、左上三个状态有关，与背包问题只与两个状态有关不同，
            // 所以不能简单地正序或逆序循环，而是将左上状态保存下来即可转换为正序循环单数组。
            /*
            输入：word1 = "intention", word2 = "execution"
            输出：5
            解释：
            intention -> inention (删除 't') --> dfs(dfs, i - 1, j) +1 ,   // Delete s[i]  i子问题规模都降低
            inention -> enention (将 'i' 替换为 'e') --> dfs(dfs, i - 1, j - 1) +1    // Replace s[i] with t[j]
            enention -> exention (将 'n' 替换为 'x')
            exention -> exection (将 'n' 替换为 'c') 
            exection -> execution (插入 'u') --> dfs(dfs, i, j - 1)    // Insert t[j]
            */
            return res = min(min(dfs(dfs, i - 1, j), dfs(dfs, i, j - 1)), dfs(dfs, i - 1, j - 1)) + 1;
        };
        return dfs(dfs, m - 1, n - 1);
    }

    int minDistance(string s, string t)
    {
        int n = t.size();
        vector<int> dp(n + 1);
        iota(dp.begin(), dp.end(), 0); // Initialize dp with 0, 1, 2, ..., n
        for (char x : s)
        {
            int pre = dp[0];
            dp[0]++;
            for (int j = 0; j < n; j++)
            {
                int tmp = dp[j + 1];
                dp[j + 1] = x == t[j] ? pre : min(min(dp[j + 1], dp[j]), pre) + 1;
                pre = tmp;
            }
        }
        return dp[n];
    }
};

// Structure to hold test case data
struct TestCase
{
    string s;     // Input string s
    string t;     // Input string t
    int expected; // Expected result
};

// Function to run tests and print detailed results
void runTests()
{
    Solution solution;
    vector<TestCase> testCases = {
        {"horse", "ros", 3},           // Expected result: 3
        {"intention", "execution", 5}, // Expected result: 5
        {"", "", 0},                   // Both strings are empty, expected result: 0
        {"a", "", 1},                  // One string is empty, expected result: 1
        {"", "b", 1},                  // One string is empty, expected result: 1
        {"abc", "abc", 0},             // Both strings are the same, expected result: 0
        {"kitten", "sitting", 3}       // Expected result: 3
    };

    for (int i = 0; i < testCases.size(); ++i)
    {
        int actual = solution.minDistance(testCases[i].s, testCases[i].t);
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

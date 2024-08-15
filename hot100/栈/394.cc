#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    // "3[a2[c]]", "accaccacc"
    // 先进后出
    string decodeString(string s)
    {
        stack<pair<string, int>> st;
        string ans = "";
        int mul = 0;
        for (auto c : s)
        {
            if (c == '[')
            {
                st.emplace(ans, mul);
                ans = "";
                mul = 0;
            }
            else if (c == ']')
            {
                auto [last_res, cur_mul] = st.top();
                st.pop();
                string tmp = last_res;
                for (int i = 0; i < cur_mul; i++)
                    tmp += ans;
                ans = tmp;
            }
            else if ('0' <= c && c <= '9')
            {
                mul = mul * 10 + (c - '0');
            }
            else
            {
                ans += c;
            }
        }
        return ans ;
    }
};

struct TestCase
{
    string input;
    string expected;
    string actual;
    bool passed;
};

int main()
{
    Solution solution;
    vector<TestCase> testCases = {
        {"3[a]2[bc]", "aaabcbc"},
        {"3[a2[c]]", "accaccacc"},
        {"2[abc]3[cd]ef", "abcabccdcdcdef"},
        {"abc3[cd]xyz", "abccdcdcdxyz"}};

    for (auto &testCase : testCases)
    {
        testCase.actual = solution.decodeString(testCase.input);
        testCase.passed = (testCase.actual == testCase.expected);
    }

    for (const auto &testCase : testCases)
    {
        cout << "Input: " << testCase.input << endl;
        cout << "Expected: " << testCase.expected << endl;
        cout << "Actual: " << testCase.actual << endl;
        cout << "Passed: " << (testCase.passed ? "Yes" : "No") << endl;
        cout << "---------------------------" << endl;
    }

    return 0;
}

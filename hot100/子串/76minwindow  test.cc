#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

string minWindow2(string S, string T)
{
    vector<int> chars(128, 0);
    vector<bool> flag(128, false);
    // 先统计T中的字符情况
    for (int i = 0; i < T.size(); ++i)
    {
        flag[T[i]] = true;
        ++chars[T[i]];
    }
    // 移动滑动窗口，不断更改统计数据
    int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
    for (int r = 0; r < S.size(); ++r)
    {
        if (flag[S[r]])
        {
            if (--chars[S[r]] >= 0)
            {
                ++cnt;
            }
            // 若目前滑动窗口已包含T中全部字符，
            // 则尝试将l右移，在不影响结果的情况下获得最短子字符串
            while (cnt == T.size())
            {
                if (r - l + 1 < min_size)
                {
                    min_l = l;
                    min_size = r - l + 1;
                }
                if (flag[S[l]] && ++chars[S[l]] > 0)
                {
                    --cnt;
                }
                ++l;
            }
        }
    }
    return min_size > S.size() ? "" : S.substr(min_l, min_size);
}

// 测试用例结构体
struct TestCase
{
    string S;
    string T;
    string expected;
};

void runTestCases()
{
    vector<TestCase> testCases = {
        {"ADOBECODEBANC", "ABC", "BANC"},
        {"a", "a", "a"},
        {"a", "aa", ""},
        {"", "a", ""},
        {"a", "", ""},
        {"aa", "aa", "aa"},
        {"abcdefgh", "hgfedcba", "abcdefgh"},
        {"ADOBECODEBANCCODE", "ABC", "BANC"}};

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        const TestCase &testCase = testCases[i];
        string result = minWindow2(testCase.S, testCase.T);
        cout << "Test case " << i + 1 << ": expected = \"" << testCase.expected << "\", got = \"" << result << "\"";
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
    runTestCases();
    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // 如果 T 为空串，则直接返回空串
        if (t.empty()) return "";
        int n = s.size(), tot = 0;
        vector<int> c1(60), c2(60);
        for (char x : t)
        {
            if (++c1[getIdx(x)] == 1)
                tot++;
        }
        string ans = "";
        for (int  left = 0, right = 0; right < n; right++)
        {
            int idx1 = getIdx(s[right]);
            if (++c2[idx1] == c1[idx1])
                tot--;
            while (left < right)
            {
                int idx2 = getIdx(s[left]);
                if (c2[idx2] > c1[idx2] && --c2[idx2] >= 0)
                    left++; // 左移
                else
                    break;
            }
            if (tot == 0 && (ans.empty() || ans.size() > right - left + 1)) //找到代码
                ans = s.substr(left, right - left + 1);
        }
        return ans;
    }
    int getIdx(char x)
    {
        return x >= 'A' && x <= 'Z' ? x - 'A' + 26 : x - 'a';
    }
};

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
        string result = Solution().minWindow(testCase.S, testCase.T);
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


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    bool is_covered(int cnt_s[], int cnt_t[]) {
        for (int i = 'A'; i <= 'Z'; i++) {
            if (cnt_s[i] < cnt_t[i]) {
                return false;
            }
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (cnt_s[i] < cnt_t[i]) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        // 如果 T 为空串，则直接返回空串
        if (t.empty()) return "";
        int m = s.length();
        int ans_left = -1, ans_right = m, left = 0;
        int cnt_s[128]{}, cnt_t[128]{};
        for (char c : t) {
            cnt_t[c]++;
        }
        for (int right = 0; right < m; right++) { // 移动子串右端点
            cnt_s[s[right]]++; // 右端点字母移入子串
            while (is_covered(cnt_s, cnt_t)) { // 涵盖
                if (right - left < ans_right - ans_left) { // 找到更短的子串
                    ans_left = left; // 记录此时的左右端点
                    ans_right = right;
                }
                cnt_s[s[left++]]--; // 左端点字母移出子串
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }

     string minWindow2(string s, string t) {
        int m = s.length();
        int ans_left = -1, ans_right = m, left = 0, less = 0;
        int cnt_s[128]{}, cnt_t[128]{};
        for (char c : t) {
            less += cnt_t[c]++ == 0; // 有 less 种字母的出现次数 < t 中的字母出现次数
        }
        for (int right = 0; right < m; right++) { // 移动子串右端点
            char c = s[right]; // 右端点字母（移入子串）
            less -= ++cnt_s[c] == cnt_t[c]; // c 的出现次数从 < 变成 >=
            while (less == 0) { // 涵盖：所有字母的出现次数都是 >=
                if (right - left < ans_right - ans_left) { // 找到更短的子串
                    ans_left = left; // 记录此时的左右端点
                    ans_right = right;
                }
                char x = s[left++]; // 左端点字母（移出子串）
                less += cnt_s[x]-- == cnt_t[x]; // x 的出现次数从 >= 变成 <
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
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

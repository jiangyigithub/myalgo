#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
struct TestCase
{
    std::string s;
    std::string p;
    std::vector<int> expected;
    std::vector<int> actual;
    bool passed;

    TestCase(std::string s, std::string p, std::vector<int> expected)
        : s(s), p(p), expected(expected), passed(false) {}
};

#include <vector>
#include <string>
using namespace std;

bool check(const vector<int> &c1, const vector<int> &c2)
{
    for (int i = 0; i < 26; i++)
    {
        if (c1[i] != c2[i])
            return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;
    int n = s.size(), m = p.size();
    if (n < m)
        return ans;

    vector<int> c1(26, 0), c2(26, 0);
    for (int i = 0; i < m; ++i)
        c2[p[i] - 'a']++;

    int left = 0;
    for (int right = 0; right < n; right++)
    {
        c1[s[right] - 'a']++;
        if (right - left + 1 > m)
            c1[s[left++] - 'a']--;
        if (check(c1, c2))
            ans.push_back(left);
    }

    return ans;
}

// 使用变量 a 统计 p 中不同字符的数量，
// 使用变量 b 统计滑动窗口（子串）内有多少个字符词频与 p 相等。
vector<int> findAnagrams2(string s, string p)
{
    vector<int> ans;
    int n = s.size(), m = p.size();
    if (n < m)
        return ans;

    vector<int> cnt(26, 0);
    for (int i = 0; i < m; i++)
        cnt[p[i] - 'a']++;

    int a = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
            a++;
    }

    /// 滑动窗口左移，右移只更新b
    for (int left = 0, right = 0, b = 0; right < n; right++)
    {
        if (--cnt[s[right] - 'a'] == 0)
            b++;
        if (right - left + 1 > m && ++cnt[s[left++] - 'a'] == 1)
            b--;
        if (b == a)
            ans.push_back(left);
    }

    return ans;
}

vector<int> findAnagrams3(string s, string p)
{
    int n = s.size();
    int len = p.size();
    vector<int> res;
    if (n < len)
        return res;

    vector<int> p_cnt(26, 0);
    vector<int> s_cnt(26, 0);

    // 计算 p 的字符计数
    for (int i = 0; i < len; i++)
    {
        p_cnt[p[i] - 'a']++;
    }

    int left = 0;
    for (int right = 0; right < n; right++)
    {
        int cur_right = s[right] - 'a';
        s_cnt[cur_right]++;

        while (s_cnt[cur_right] > p_cnt[cur_right])
        {
            int cur_left = s[left] - 'a';
            s_cnt[cur_left]--;
            left++;
        }

        if (right - left + 1 == len)
        {
            res.push_back(left);
        }
    }

    return res;
}

vector<int> findAnagrams4(string s, string p)
{
    vector<int> ans;
    // 初始化一个数组来统计字符串 p 中每个字符的出现次数
    vector<int> cnt(26, 0);
    for (int i = 0; i < p.size(); i++)
    {
        cnt[p[i] - 'a']++;
    }
    // left 和 right 分别表示滑动窗口的左右边界
    int left = 0;
    for (int right = 0; right < s.size(); right++)
    {
        // 更新当前窗口中字符的计数数组
        cnt[s[right] - 'a']--;
        // 从左侧收缩窗口，直到当前字符的计数在限定范围内
        while (cnt[s[right] - 'a'] < 0)
        {
            cout<<"while "<<s.substr(left,right-left+1)<<endl;
            cnt[s[left] - 'a']++;
            left++;
        }
        // 检查当前窗口大小是否等于字符串 p 的大小
        if (right - left + 1 == p.size())
        {
            ans.push_back(left);
        }
    }
    return ans;
}



void runTestCases()
{
    std::vector<TestCase> testCases = {
        TestCase("cbaebabacd", "abc", {0, 6}),
        // TestCase("abab", "ab", {0, 1, 2}),
        // TestCase("af", "be", {}),
        // TestCase("a", "a", {0}),
        // TestCase("aaaaaaaaaa", "aaaaa", {0, 1, 2, 3, 4, 5})
        };

    for (auto &testCase : testCases)
    {
        testCase.actual = findAnagrams4(testCase.s, testCase.p);
        testCase.passed = (testCase.actual == testCase.expected);

        std::cout << "Test case - s: \"" << testCase.s << "\", p: \"" << testCase.p << "\"\n";
        std::cout << "Expected: [ ";
        for (int index : testCase.expected)
        {
            std::cout << index << " ";
        }
        std::cout << "], Actual: [ ";
        for (int index : testCase.actual)
        {
            std::cout << index << " ";
        }
        std::cout << "], Result: " << (testCase.passed ? "Passed" : "Failed") << "\n\n";
    }
}

int main()
{
    runTestCases();
    return 0;
}

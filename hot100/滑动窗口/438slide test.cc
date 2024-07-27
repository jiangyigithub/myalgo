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

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    int len = p.size();
    int n = s.size();
    if (n < len)
    {
        return res;
    }
    vector<int> pCount(26, 0);
    vector<int> sCount(26, 0);
    for (auto ch : p)
    {
        int temp = ch - 'a';
        pCount[temp]++;
    }
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        int temp = s[right] - 'a';
        sCount[temp]++;

        /// 保证不多，条件中要先将right存入，再判断，且第一个周期不会执行
        while (sCount[temp] > pCount[temp])
        {
            int l_digit = s[left] - 'a';
            // cout<<"while (sCount[temp] > pCount[temp])"<<s.substr(left,right-left+1)<<endl;
            sCount[l_digit]--;
            left++;
        }
        cout<<"左边"<<s.substr(left,right-left+1)<<endl;
        ///保证不少
        if (right - left + 1 == len)
        {
            res.push_back(left);
        }
    }

    return res;
}

/// @brief 438 和 76 两道题是完全一样的
/// @param s 
/// @param p 
/// @return 
vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> s_cnt(128), p_cnt(128);
        int gap = 0;

        for (auto c : p) {
            p_cnt[c]++;
            if (p_cnt[c] == 1)
                gap++;
        }

        int left = 0;
        vector<int> ans;
        for (int right = 0; right < n; ++right) {
            char c = s[right];
            s_cnt[c]++;
            if (s_cnt[c] == p_cnt[c])
                gap--;
            while (gap == 0) {
                if (right - left + 1 == m)
                    ans.push_back(left);

                char x = s[left];
                s_cnt[x]--;
                if (s_cnt[x] < p_cnt[x])
                    gap++;
                left++;
            }
        }
        return ans;
    }

void runTestCases()
{
    std::vector<TestCase> testCases = {
        TestCase("cbaebabacd", "abc", {0, 6})
        // ,
        // TestCase("abab", "ab", {0, 1, 2}),
        // TestCase("af", "be", {}),
        // TestCase("a", "a", {0}),
        // TestCase("aaaaaaaaaa", "aaaaa", {0, 1, 2, 3, 4, 5})
        };

    for (auto &testCase : testCases)
    {
        testCase.actual = findAnagrams(testCase.s, testCase.p);
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

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
struct TestCase {
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



    bool check(const vector<int>& c1, const vector<int>& c2) {
        for (int i = 0; i < 26; i++) {
            if (c1[i] != c2[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        if (n < m) return ans;

        vector<int> c1(26, 0), c2(26, 0);
        for (int i = 0; i < m; ++i) c2[p[i] - 'a']++;
        
        int l = 0;
        for (int r = 0; r < n; r++) {
            c1[s[r] - 'a']++;
            if (r - l + 1 > m) c1[s[l++] - 'a']--;
            if (check(c1, c2)) ans.push_back(l);
        }

        return ans;
    }

// 使用变量 a 统计 p 中不同字符的数量，
// 使用变量 b 统计滑动窗口（子串）内有多少个字符词频与 p 相等。
 vector<int> findAnagrams2(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        if (n < m) return ans;

        vector<int> cnt(26, 0);
        for (int i = 0; i < m; i++) cnt[p[i] - 'a']++;

        int a = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) a++;
        }
        
        /// 滑动窗口左移，右移只更新b
        for (int l = 0, r = 0, b = 0; r < n; r++) {
            if (--cnt[s[r] - 'a'] == 0) b++;
            if (r - l + 1 > m && ++cnt[s[l++] - 'a'] == 1) b--;
            if (b == a) ans.push_back(l);
        }

        return ans;
    }

vector<int> findAnagrams3(string s, string p) {
        int n = s.size();
        int len = p.size();
        vector<int> res;
        if (n < len) return res;

        vector<int> p_cnt(26, 0);
        vector<int> s_cnt(26, 0);

        // 计算 p 的字符计数
        for (int i = 0; i < len; i++) {
            p_cnt[p[i] - 'a']++;
        }

        int left = 0;
        for (int right = 0; right < n; right++) {
            int cur_right = s[right] - 'a';
            s_cnt[cur_right]++;
            
            while (s_cnt[cur_right] > p_cnt[cur_right]) {
                int cur_left = s[left] - 'a';
                s_cnt[cur_left]--;
                left++;
            }
            
            if (right - left + 1 == len) {
                res.push_back(left);
            }
        }

        return res;
    }

void runTestCases() {
    std::vector<TestCase> testCases = {
        TestCase("cbaebabacd", "abc", {0, 6}),
        TestCase("abab", "ab", {0, 1, 2}),
        TestCase("af", "be", {}),
        TestCase("a", "a", {0}),
        TestCase("aaaaaaaaaa", "aaaaa", {0, 1, 2, 3, 4, 5})
    };

    for (auto& testCase : testCases) {
        testCase.actual = findAnagrams2(testCase.s, testCase.p);
        testCase.passed = (testCase.actual == testCase.expected);

        std::cout << "Test case - s: \"" << testCase.s << "\", p: \"" << testCase.p << "\"\n";
        std::cout << "Expected: [ ";
        for (int index : testCase.expected) {
            std::cout << index << " ";
        }
        std::cout << "], Actual: [ ";
        for (int index : testCase.actual) {
            std::cout << index << " ";
        }
        std::cout << "], Result: " << (testCase.passed ? "Passed" : "Failed") << "\n\n";
    }
}

int main() {
    runTestCases();
    return 0;
}

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

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int s_len = s.size();
    int p_len = p.size();
    
    if (p_len > s_len) return result;

    unordered_map<char, int> p_count, s_count;

    // 初始化 p 的字符计数器
    for (char c : p) {
        p_count[c]++;
    }

    // 初始化 s 的前 p_len - 1 个字符的计数器
    for (int i = 0; i < p_len - 1; i++) {
        s_count[s[i]]++;
    }

    // 滑动窗口遍历 s
    for (int i = p_len - 1; i < s_len; i++) {
        // 增加当前字符到窗口计数器
        s_count[s[i]]++;
        
        // 检查当前窗口是否为异位词
        if (s_count == p_count) {
            result.push_back(i - p_len + 1);
        }
        
        // 移除窗口左端字符
        s_count[s[i - p_len + 1]]--;
        // 如果计数为 0，删除该字符
        if (s_count[s[i - p_len + 1]] == 0) {
            s_count.erase(s[i - p_len + 1]);
        }
    }

    return result;
}

vector<int> findAnagrams2(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> res;
        if (n < m) return res;

        vector<int> p_cnt(26, 0);
        vector<int> s_cnt(26, 0);

        // 计算 p 的字符计数
        for (int i = 0; i < m; i++) {
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
            
            if (right - left + 1 == m) {
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

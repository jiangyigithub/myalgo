#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 如果输入字符串为空，直接返回空字符串
        if (s.empty()) return "";
        
        // 初始化起始位置和最大长度
        int start = 0, maxLen = 1;

        // 遍历字符串中的每个字符
        for (int i = 0; i < s.size(); ++i) {
            // 查找以单个字符为中心的奇数长度的回文
            int len1 = expandAroundCenter(s, i, i);
            
            // 查找以两个字符为中心的偶数长度的回文
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // 选择较长的回文长度
            int len = max(len1, len2);
            
            // 如果找到的回文长度大于当前最大长度
            if (len > maxLen) {
                // 更新起始位置和最大长度
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }

        // 返回最长回文子串
        return s.substr(start, maxLen);
    }

private:
    // 辅助函数：以中心为起点向外扩展寻找回文
    int expandAroundCenter(const string &s, int left, int right) {
        // 当左右字符相等且在字符串范围内时，继续扩展
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;  // 左边界左移
            right++; // 右边界右移
        }
        // 返回回文长度
        return right - left - 1;
    }
};

// 结构体定义测试用例
struct TestCase {
    string input;
    string expected;
};

void runTests(const vector<TestCase>& testCases, Solution& solution) {
    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        string result = solution.longestPalindrome(testCase.input);
        cout << "Test case " << i + 1 << ": input = \"" << testCase.input 
             << "\", expected = \"" << testCase.expected 
             << "\", got = \"" << result << "\"";

        if (result == testCase.expected) {
            cout << " [PASSED]" << endl;
        } else {
            cout << " [FAILED]" << endl;
        }
    }
}

int main() {
    Solution solution;
    vector<TestCase> testCases = {
        {"babad", "bab"},  // "aba" is also a valid answer
        {"cbbd", "bb"},
        {"a", "a"},
        {"ac", "a"},
        {"racecar", "racecar"},
        {"", ""}
    };

    runTests(testCases, solution);

    return 0;
}

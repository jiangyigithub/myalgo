#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 函数：计算字符串中不含重复字符的最长子串的长度
int lengthOfLongestSubstring(string s) {
    int n = s.length(); // 获取字符串长度
    unordered_set<char> charSet; // 用于存储当前窗口内的字符
    int start = 0, maxLength = 0; // 初始化窗口起始位置和最长子串长度

    for (int end = 0; end < n; ++end) {
        // 如果当前字符在集合中，说明有重复字符，需要调整窗口
        while (charSet.find(s[end]) != charSet.end()) {
            charSet.erase(s[start]); // 从集合中移除窗口起始位置的字符
            ++start; // 将窗口起始位置右移
        }
        charSet.insert(s[end]); // 将当前字符添加到集合中
        maxLength = max(maxLength, end - start + 1); // 更新最长子串长度
    }

    return maxLength; // 返回最长子串长度
}

/// @brief  两种方法更新左边界的方法不同，一个通过unordered set更新左边界，一个通过ordered map更新左边界
/// @param s 
/// @return 
int lengthOfLongestSubstring2(string s) {
    unordered_map<char, int> dic;
    int i = -1, res = 0, len = s.size();
    for(int j = 0; j < len; j++) {
        if (dic.find(s[j]) != dic.end())
            i = max(i, dic.find(s[j])->second); // 更新左指针
        dic[s[j]] = j; // 哈希表记录
        res = max(res, j - i); // 更新结果
    }
    return res;
}

// Define the TestCase struct
struct TestCase
{
    string input;
    int expected;
};

int main()
{
    // Initialize the test cases
    TestCase testCases[] = {
        {"abcabcbb", 3}, // Test case 1: "abcabcbb" has longest substring "abc" with length 3
        {"bbbbb", 1},    // Test case 2: "bbbbb" has longest substring "b" with length 1
        {"pwwkew", 3},   // Test case 3: "pwwkew" has longest substring "wke" with length 3
        {"", 0},         // Test case 4: empty string has longest substring of length 0
        {" ", 1},        // Test case 5: " " has longest substring " " with length 1
        {"au", 2},       // Test case 6: "au" has longest substring "au" with length 2
        {"dvdf", 3}      // Test case 7: "dvdf" has longest substring "vdf" with length 3
    };

    // Run each test case
    for (size_t i = 0; i < 7; ++i)
    {
        const TestCase &testCase = testCases[i];
        int result = lengthOfLongestSubstring(testCase.input);
        cout << "Test case " << i + 1 << ": expected = " << testCase.expected << ", got = " << result;
        if (result == testCase.expected)
        {
            cout << " [PASSED]" << endl;
        }
        else
        {
            cout << " [FAILED]" << endl;
        }
    }

    return 0;
}

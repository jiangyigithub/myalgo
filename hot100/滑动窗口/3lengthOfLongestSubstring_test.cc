#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
维护unordered set保证不重复
*/
// 函数：计算字符串中不含重复字符的最长子串的长度(128类似)
/*
右边界每次移动1，左边界根据具体条件来移动，hashSet作为该条件的辅助数据结构
*/
/*
滑动窗口+无重复(hashSet)
*/
int lengthOfLongestSubstring(string s)
{
    int res = 0;
    unordered_set<char> mySet;
    int start = 0;
    for (int end = 0; end < s.size(); ++end)
    {
        /// 更新左边界
        while (mySet.find(s[end]) != mySet.end())
        {
            mySet.erase(s[start]);
            start++;
        }
        mySet.insert(s[end]);
        res = max(res, end - start + 1);
    }
    return res; // 返回最长子串长度
}

/// @brief  两种方法更新左边界的方法不同，一个通过unordered set更新左边界，一个通过ordered map更新左边界
/// @param s
/// @return
int lengthOfLongestSubstring2(string s)
{
    unordered_map<char, int> dic;
    int i = -1, res = 0, len = s.size();
    for (int j = 0; j < len; j++)
    {
        if (dic.find(s[j]) != dic.end())
            i = max(i, dic.find(s[j])->second); // 更新左指针
        dic[s[j]] = j;                          // 哈希表记录
        res = max(res, j - i);                  // 更新结果
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

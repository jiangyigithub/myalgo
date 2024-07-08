#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
维护unordered set保证不重复
*/
// 函数：计算字符串中不含重复字符的最长子串的长度
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

int main()
{
    // 测试用例
    string s1 = "abcabcbb";
    cout << lengthOfLongestSubstring(s1) << endl; // 输出：3，最长子串为 "abc"

    string s2 = "bbbbb";
    cout << lengthOfLongestSubstring(s2) << endl; // 输出：1，最长子串为 "b"

    string s3 = "pwwkew";
    cout << lengthOfLongestSubstring(s3) << endl; // 输出：3，最长子串为 "wke"

    string s4 = "";
    cout << lengthOfLongestSubstring(s4) << endl; // 输出：0，最长子串为空

    string s5 = " ";
    cout << lengthOfLongestSubstring(s5) << endl; // 输出：1，最长子串为 " "

    string s6 = "au";
    cout << lengthOfLongestSubstring(s6) << endl; // 输出：2，最长子串为 "au"

    string s7 = "dvdf";
    cout << lengthOfLongestSubstring(s7) << endl; // 输出：3，最长子串为 "vdf"

    return 0;
}

/*
剑指 Offer 48. 最长不含重复字符的子字符串
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

 

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

提示：

s.length <= 40000
*/

#include "head.hpp"
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> dic;
        int i = -1, res = 0, len = s.size();
        for (int j = 0; j < len; j++)
        {   
            // 判断元素是否在哈希表中
            if (dic.find(s[j]) != dic.end())
                i = max(i, dic[s[j]]);              // 元素在哈希表中上一时刻的位置
            dic[s[j]] = j;                          // 元素在哈希表中当前时刻的位置
            // j-i 为不含重复字符串的首尾指针
            res = max(res, j - i);                  // 更新结果
        }
        return res;
    }
};

int main()
{
    string line = "abcabcbb";

    int ret = Solution().lengthOfLongestSubstring(line);

    string out = to_string(ret);
    cout << out << endl;

    return 0;
}
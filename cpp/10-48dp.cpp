#include "head.hpp"
/// unordered_map 的使用方法： find ,判断元素在不在hash_map中
/// 空间复杂度的优化
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
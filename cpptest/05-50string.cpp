#include "head.hpp"

// ===== Solution Code =====
// 剑指 Offer 50. 第一个只出现一次的字符
class Solution
{
public:
    char firstUniqChar(string s)
    {
        unordered_map<char, bool> dic;
        for (char c : s)
        {
            dic[c] = dic.find(c) == dic.end(); // 第一个出现,marked as "true"
        }
        for (char c : s)
        {
            if (dic[c])
                return c;
        }
    }
};

int main()
{
    // ======= Test Case =======
    string s = "abaccdeff";
    // ====== Driver Code ======
    Solution *slt = new Solution();
    char res = slt->firstUniqChar(s);
    cout << res << endl;

    return 0;
}

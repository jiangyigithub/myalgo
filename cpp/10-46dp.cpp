/*
剑指 Offer 46. 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 

提示：

0 <= num < 231
*/

#include "head.hpp"

// ===== Solution Code =====
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int a = 1, b = 1, len = s.size();
        for(int i = len - 2; i > -1; i--) {
            string tmp = s.substr(i, 2);
            int c = tmp.compare("10") >= 0 && tmp.compare("25") <= 0 ? a + b : a;
            b = a;
            a = c;
        }
        return a;
    }
};

int main() {
    // ======= Test Case =======
    int num = 12258;
    // ====== Driver Code ======
    Solution* slt = new Solution();
    int res = slt->translateNum(num);
    cout << res << endl;
    
    return 0;
}

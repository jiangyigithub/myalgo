/*
剑指 Offer 65. 不用加减乘除做加法
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

示例:

输入: a = 1, b = 1
输出: 2

*/

#include "include.hpp"

// ===== Solution Code =====
// https://iq.opengenus.org/addition-using-bitwise-operations/
class Solution {
public:
    int add(int a, int b) {
        while(b != 0)
        {
            int c = (unsigned int)(a & b) << 1;  // bitwise left shift
            a ^= b;                              // bitwise Xor
            b = c;
        }
        return a;
    }
};

int main() {
    // ======= Test Case =======
    int a = 1;
    int b = 1;
    // ====== Driver Code ======
    Solution* slt = new Solution();
    int res = slt->add(a, b);
    cout << res << endl;
    
    return 0;
}

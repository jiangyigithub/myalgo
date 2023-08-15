/*
剑指 Offer 64. 求 1 + 2 + … + n
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

 

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45
 

限制：

1 <= n <= 10000
*/

#include "head.hpp"

// ===== Solution Code =====
class Solution {
public:
    int sumNums(int n) {
        n > 1 && (n += sumNums(n - 1));
        return n;
    }
};

int main() {
    // ======= Test Case =======
    int n = 3;
    // ====== Driver Code ======
    Solution* slt = new Solution();
    int res = slt->sumNums(n);
    cout << res << endl;
    
    return 0;
}

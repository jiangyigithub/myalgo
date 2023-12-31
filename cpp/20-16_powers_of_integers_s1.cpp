/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

 

示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
 

提示：

-100.0 < x < 100.0
-231 <= n <= 231-1
n 是一个整数
要么 x 不为零，要么 n > 0 。
-104 <= xn <= 104

*/

#include "include.hpp"

// ===== Solution Code =====
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0.0f) return 0.0;
        long b = n;
        double res = 1.0;
        if(b < 0) {
            x = 1 / x;
            b = -b;
        }
        while(b > 0) {
            if((b & 1) == 1) res *= x; // --> "治"
            x *= x;
            b >>= 1;//右移一位 (same as /2) -->"分"
        }
        return res;
    }
    
    // https://leetcode.cn/leetbook/read/illustration-of-algorithm/9h1gyt/
    int sumNums(int n) {
        int res = 0;
        for(int i = 1; i <= n; i++)
            res += i;
        return res;
    }
};

int main() {
    // ======= Test Case =======
    double x = 2.0;
    int n = 10;
    // ====== Driver Code ======
    Solution* slt = new Solution();
    double res = slt->myPow(x, n);
    cout << res << endl;
    
    return 0;
}

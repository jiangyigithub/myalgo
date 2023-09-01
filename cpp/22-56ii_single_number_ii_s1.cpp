/*
剑指 Offer 56 - II. 数组中数字出现的次数 II
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

 

示例 1：

输入：nums = [3,4,3,3]
输出：4
示例 2：

输入：nums = [9,1,7,9,7,9,7]
输出：1

*/

#include "include.hpp"
// ===== Solution Code =====
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int num : nums){
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};

int main() {
    // ======= Test Case =======
    vector<int> nums = { 3, 4, 3, 3 };
    // ====== Driver Code ======
    Solution* slt = new Solution();
    int res = slt->singleNumber(nums);
    cout << res << endl;
    
    return 0;
}

/*
剑指 Offer 61. 扑克牌中的顺子
从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

 

示例 1:

输入: [1,2,3,4,5]
输出: True
 

示例 2:

输入: [0,0,1,2,5]
输出: True
 

限制：

数组长度为 5 

数组的数取值为 [0, 13] .
*/

#include "head.hpp"

// ===== Solution Code =====
class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        unordered_set<int> repeat;
        int max = 0, min = 14;
        for (int num : nums)
        {
            if (num == 0)
                continue;             // 跳过大小王
            max = std::max(max, num); // 最大牌
            min = std::min(min, num); // 最小牌
            if (repeat.find(num) != repeat.end())
                return false;   // 若有重复，提前返回 false
            repeat.insert(num); // 添加此牌至 Set
        }
        return max - min < 5; // 最大牌 - 最小牌 < 5 则可构成顺子
    }
};

int main()
{
    // ======= Test Case =======
    vector<int> nums = {0, 0, 1, 2, 5};
    // ====== Driver Code ======
    Solution *slt = new Solution();
    bool res = slt->isStraight(nums);
    std::cout << res << std::endl;

    return 0;
}

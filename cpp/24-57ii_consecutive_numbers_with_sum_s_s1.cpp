/*
剑指 Offer 57 - II. 和为 s 的连续正数序列
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]

*/

#include "include.hpp"

// ===== Solution Code =====
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1;
        double j = 2.0;
        vector<vector<int>> res;
        while(i < j) {
            j = (-1 + sqrt(1 + 4 * (2 * target + (long) i * i - i))) / 2;
            if(i < j && j == (int)j) {
                vector<int> ans;
                for(int k = i; k <= (int)j; k++)
                    ans.push_back(k);
                res.push_back(ans);
            }
            i++;
        }
        return res;
    }
};

int main() {
    // ======= Test Case =======
    int target = 9;
    // ====== Driver Code ======
    Solution* slt = new Solution();
    vector<vector<int>> res = slt->findContinuousSequence(target);
    PrintUtil::printVectorMatrix(res);
    
    return 0;
}

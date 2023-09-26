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
class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        int i = 1, j = 2, s = 3;
        vector<vector<int>> res;
        while (i < j)
        {
            if (s == target)
            {
                vector<int> ans;
                for (int k = i; k <= j; k++)
                    ans.push_back(k);
                res.push_back(ans);
            }
            // 窗口左边界右移
            if (s >= target)
            {
                s -= i;
                i++;
            }
            else
            {
                j++;
                s += j;
            }
        }
        return res;
    }

    vector<vector<int>> findContinuousSequence2(int target)
    {
        vector<vector<int>> result;
        int left = 1;  // 滑动窗口的左边界
        int right = 2; // 滑动窗口的右边界
        int sum = 3;   // 滑动窗口中数字的和，初始为1+2=3

        while (left < right)
        {
            if (sum == target)
            {
                vector<int> sequence;
                for (int i = left; i <= right; ++i)
                {
                    sequence.push_back(i);
                }
                result.push_back(sequence);
                // 窗口左边界右移
                sum -= left;
                left++;
            }
            else if (sum < target)
            {
                // 窗口右边界右移
                right++;
                sum += right;
            }
            else
            {
                // 窗口左边界右移
                sum -= left;
                left++;
            }
        }

        return result;
    }
};

int main()
{
    // ======= Test Case =======
    int target = 15;
    // ====== Driver Code ======
    Solution *slt = new Solution();
    vector<vector<int>> res = slt->findContinuousSequence2(target);
    PrintUtil::printVectorMatrix(res);

    return 0;
}

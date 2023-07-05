#include "head.hpp"

// ===== Solution Code =====
// 剑指 Offer 53 - II. 0～n-1 中缺失的数字
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int m = (i + j) / 2;
            if (nums[m] == m)
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};

int main()
{
    // ======= Test Case =======
    vector<int> nums = {0, 1, 2, 4, 5};
    // ====== Driver Code ======
    Solution *slt = new Solution();
    int res = slt->missingNumber(nums);
    cout << res << endl;
    return 0;
}

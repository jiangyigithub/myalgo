// 我觉得可以用高数的极值定理思想类比理解162题，题目要找的是区间极大值，由于极值点的导数为0，而极大值左升右降，左侧导数大于0，右侧导数小于0；
// 与右侧值比较大小的过程类似于求导，导数大于0就向右侧，在右侧找，导数小于0就向左找。汇合点就是满足左升右降的极大值。

class Solution
{

public:
    int findPeakElement(vector<int> &nums)
    {

        int left = -1, right = nums.size() - 1; // 开区间 (-1, n-1)

        while (left + 1 < right)
        { // 开区间不为空

            int mid = left + (right - left) / 2;

            if (nums[mid + 1]-nums[mid]<0) // 导数小于0，mid 应减小
            {

                right = mid;
            }
            else // 导数大于0，mid 应增加
            {

                left = mid;
            }
        }

        return right;
    }
};

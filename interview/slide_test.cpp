#include <vector>
#include <deque>
#include <iostream>

std::vector<int> minSlidingWindow(std::vector<int> &nums, int k)
{
    std::vector<int> result;
    std::deque<int> dq;
    for (int i = 0; i < nums.size(); i++)
    {
        /// 如果deque不会空，不满足 i-k+1 < dq.front()<i
        if (!dq.empty() && dq.front() < (i - k + 1))
        {
            dq.pop_front();
        }

        /// 满足nums[i]<nums[dq.back()]
        while (!dq.empty() && nums[i] < nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        /// 最值为nums[dq.front()]
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

int main()
{
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::vector<int> result = minSlidingWindow(nums, k);

    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}
#include <vector>
#include <deque>
#include <iostream>

/*
关键词：双端队列,单调队列，存储索引
 */
std::vector<int> minSlidingWindow2(std::vector<int> &nums)
{
    std::vector<int> result;
    std::deque<int> dq; // 存储的是索引，而不是值

    for (int i = 0; i < nums.size(); ++i)
    {
        while (!dq.empty() && nums[dq.back()] > nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        result.push_back(nums[dq.front()]);
    }
    return result;
}

std::vector<int> minSlidingWindow(std::vector<int> &nums, int k)
{
    std::vector<int> result;
    std::deque<int> dq;
    for (int i = 0; i < nums.size(); ++i)
    {
        /// 由于窗口的滑动，更新最值
        if (!dq.empty() && dq.front() < i - k + 1)
        {
            dq.pop_front();
        }

        /// 由于窗口的滑动，将新增的index正确加入到单调队列中
        while (!dq.empty() && nums[dq.back()] > nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        /// 当i滑到k-1位置开始记录结果，双端队列的front元素加到result的
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

// 测试
int main()
{
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    // std::vector<int> result = minSlidingWindow(nums, k);
    std::vector<int> result = minSlidingWindow2(nums);

    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}

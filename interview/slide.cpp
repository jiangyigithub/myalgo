#include <vector>
#include <deque>
#include <iostream>

/*
关键词：双端队列,单调队列，存储索引
 */
std::vector<int> minSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::deque<int> dq;  // 存储的是索引，而不是值

    for (int i = 0; i < nums.size(); ++i) {
        // 移除不在窗口内的索引
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // 移除所有比当前元素大的元素，因为队列的front要为当前窗口的最小值
        while (!dq.empty() && nums[dq.back()] > nums[i]) {
            dq.pop_back();
        }

        // 将当前元素添加到队尾
        dq.push_back(i);
        
        /// 窗口对应的数据结构为双端队列,且为单调队列,队列的front为当前窗口的最小值
        // 当窗口大小达到要求时，记录窗口的最小值
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

// 测试
int main() {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::vector<int> result = minSlidingWindow(nums, k);
    
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}

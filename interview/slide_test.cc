#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// Function to compute minimum sliding window
std::vector<int> minSlidingWindow(std::vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i)
    {
        // Remove elements from the front of deque if they are out of the window
        if (!dq.empty() && (i - k + 1 > dq.front()))
        {
            dq.pop_front();
        }

        // Maintain deque in decreasing order of elements
        while (!dq.empty() && (nums[i] < nums[dq.back()]))
        {
            dq.pop_back();
        }

        // Add current element index to deque
        dq.push_back(i);

        // Once we have processed at least k elements, start adding results
        if (i >= k - 1)
        {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main()
{
    // Define test cases in a compact array format
    vector<int> testCases[] = {
        {1, 3, -1, -3, 5, 3, 6, 7}, // nums1: Mixed positive and negative numbers
        {1, 2, 3, 4, 5},            // nums2: Consecutive increasing numbers
        {5, 4, 3, 2, 1}             // nums3: Consecutive decreasing numbers
    };

    int ks[] = {3, 2, 3}; // Corresponding k values

    for (int i = 0; i < 3; ++i)
    {
        std::vector<int> result = minSlidingWindow(testCases[i], ks[i]);

        std::cout << "Result for nums" << i + 1 << " with k" << i + 1 << " = " << ks[i] << ": ";
        for (int val : result)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

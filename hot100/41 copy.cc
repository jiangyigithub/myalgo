#include <iostream>
#include <vector>
#include <algorithm>
/// 对数组中的元素，从1开始排序，
/*
方法：原地哈希

如果数组中包含 x∈[1,N]，那么恢复后，数组的第 x−1 个元素为 x。

在恢复后，数组应当有 [1, 2, ..., N] 的形式，但其中有若干个位置上的数是错误的，每一个错误的位置就代表了一个缺失的正数。

以题目中的示例二 [3, 4, -1, 1] 为例，恢复后的数组应当为 [1, -1, 3, 4]，我们就可以知道缺失的数为 2。

那么我们如何将数组进行恢复呢？我们可以对数组进行一次遍历，对于遍历到的数 x=nums[i]，如果 x∈[1,N]，我们就知道 x 应当出现在数组中的 x−1 的位置，因此交换 nums[i] 和 nums[x−1]，这样 x 就出现在了正确的位置。在完成交换后，新的 nums[i] 可能还在 [1,N] 的范围内，我们需要继续进行交换操作，直到 x∈/[1,N]。

注意到上面的方法可能会陷入死循环。如果 nums[i] 恰好与 nums[x−1] 相等，那么就会无限交换下去。此时我们有 nums[i]=x=nums[x−1]，说明 x 已经出现在了正确的位置。因此我们可以跳出循环，开始遍历下一个数。

由于每次的交换操作都会使得某一个数交换到正确的位置，因此交换的次数最多为 N，整个方法的时间复杂度为 O(N)。

作者：力扣官方题解
链接：https://leetcode.cn/problems/first-missing-positive/solutions/304743/que-shi-de-di-yi-ge-zheng-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
https://leetcode.cn/problems/first-missing-positive/solutions/7703/tong-pai-xu-python-dai-ma-by-liweiwei1419/?envType=study-plan-v2&envId=top-100-liked
*/

// 哈希函数
int hashFunc(int num) {
    return num - 1;
}

// Function to find the first missing positive integer
int firstMissingPositive(std::vector<int> &nums)
{
    int n = nums.size();

    // 1. Place each number in its correct index
    for (int i = 0; i < n; ++i)
    {   

        /// nums[i] = i+1 
        /// --> nums[i]-1 == i
        /// 为满足交换,必须为 nums[x]和nums[y]交换， nums[nums[i]-1] == nums[i]
        while (nums[i] >= 1 && nums[i] <= n && nums[i]!= nums[nums[i]-1] )
        {
            // Swap nums[i] and nums[nums[i] - 1]
            // 数值为 i 的数映射到下标为 i - 1 的位置
            /// 排序后 nums[i] 应当在 i-1的位置
            std::swap(nums[i], nums[nums[i] - 1]); // 哈希函数为：f(nums[i]) = nums[i] - 1 -->
        }
    }

    // 2. Find the first index where the number does not match the index + 1
    for (int i = 0; i < n; ++i)
    {
        // {{3, 4, -1, 1}, 2},
        // 1 -1 3 4
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }

    // 3. If all numbers from 1 to n are in the array, then the smallest missing positive is n + 1
    return n + 1;
}

// Struct to hold a test case
struct TestCase
{
    std::vector<int> nums; // Input array
    int expected;          // Expected result
};

// Function to run a test case and output the result
void runTestCase(const TestCase &testCase)
{
    std::vector<int> nums = testCase.nums;
    int expected = testCase.expected;
    int result = firstMissingPositive(nums);

    std::cout << "Test case:\n";
    std::cout << "Input: ";
    for (int num : testCase.nums)
    {
        std::cout << num << " ";
    }
    std::cout << "\nExpected result: " << expected << "\n";
    std::cout << "Actual result: " << result << "\n";
    std::cout << "Test " << (result == expected ? "Passed" : "Failed") << "\n";
    std::cout << "----------------------------------\n";
}

int main()
{
    // Define test cases
    std::vector<TestCase> testCases = {
        {{3, 4, -1, 1}, 2},
        {{1, 2, 0}, 3},
        {{7, 8, 9, 11, 12}, 1},
        {{1, 1, 0, -1, -2}, 2},
        {{5, 6, 7, 8, 9, 10, 11, 12}, 1},
        {{1}, 2},
        {{}, 1}};

    // Run each test case
    for (const auto &testCase : testCases)
    {
        runTestCase(testCase);
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
使用前缀和（Prefix Sum）与哈希表来高效地统计和为 k 的子数组的个数。

    前缀和的定义：
        前缀和表示从数组的开始位置到当前位置的所有元素的和。
        用 prefix_sum 表示前缀和，prefix_sum[i]表示从数组开始到索引 i 的元素和。

    子数组和的表示：
        一个子数组从索引 i 到索引 j 的和可以表示为 prefix_sum[j]−prefix_sum[i−1]
        如果这个和等于 k，即 prefix_sum[j]−prefix_sum[i−1]=k，可以转化为 prefix_sum[j]=k+prefix_sum[i−1]

    使用哈希表记录前缀和：
        我们用一个哈希表 prefix_sums 来记录每一个前缀和出现的次数。
        当我们遍历数组时，通过查找 prefix_sums[prefix_sum - k] 来快速找到符合条件的子数组的数量。

    具体步骤：
        初始化一个哈希表 prefix_sums，并在其中放入一对键值 (0, 1)，表示前缀和为0的情况。
        遍历数组，更新当前的前缀和 prefix_sum。
        检查 prefix_sum - k 是否在哈希表中，如果存在，则说明从某个之前的索引到当前索引的子数组的和为 kk，累加其出现的次数。
        将当前的前缀和 prefix_sum 的出现次数记录到哈希表中。
*/
// Function to count the number of subarrays with sum equal to k
int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size(), sum = 0, ans = 0;
    unordered_map<int, int> cnt;
    cnt[0]=1;
    for (int i = 0; i < n; ++i)
    {
        sum += nums[i]; // 前缀和
        ans+=cnt.count(sum-k)>0?cnt[sum-k]:0;
        // if (cnt.count(sum - k) > 0)
        // {
        //     ans += cnt[sum - k];
        // }
        cnt[sum]++;
    }
    return ans;
}

// Structure to store test cases
struct TestCase
{
    vector<int> nums; // Input array
    int k;            // Target sum
    int expected;     // Expected result
};

int main()
{
    // Define test cases
    vector<TestCase> testCases = {
        {{1, 1, 1}, 2, 2},
        {{1, 2, 3}, 3, 2},
        {{1, -1, 0}, 0, 3},
        {{-1, -1, 1}, 0, 1},
        {{3, 4, 7, 2, -3, 1, 4, 2}, 7, 4}};

    // Run test cases
    for (auto &testCase : testCases)
    {
        int result = subarraySum(testCase.nums, testCase.k);
        cout << "Array: [";
        for (size_t i = 0; i < testCase.nums.size(); ++i)
        {
            cout << testCase.nums[i];
            if (i != testCase.nums.size() - 1)
                cout << ", ";
        }
        cout << "], k: " << testCase.k << endl;
        cout << "Expected result: " << testCase.expected << ", Actual result: " << result << endl;
        cout << (result == testCase.expected ? "Test passed" : "Test failed") << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}

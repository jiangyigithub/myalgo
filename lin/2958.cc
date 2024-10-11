#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 定义 Solution 类
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, left = 0;
        unordered_map<int, int> cnt;
        for (int right = 0; right < nums.size(); right++) {
            cnt[nums[right]]++;
            while (cnt[nums[right]] > k) {
                cnt[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1); 
        }
        return ans;
    }
};

// 定义 TestCase 结构体
struct TestCase {
    vector<int> nums;  // 输入的数组
    int k;             // 输入的 k 值
    int expected;      // 预期的结果
    int actual;        // 实际的结果
    bool passed;       // 是否通过测试

    // 构造函数
    TestCase(vector<int> n, int k_val, int exp) : nums(n), k(k_val), expected(exp), actual(0), passed(false) {}

    // 运行测试
    void runTest(Solution& solution) {
        actual = solution.maxSubarrayLength(nums, k);
        passed = (actual == expected);
    }

    // 打印测试用例的详细信息
    void print() {
        cout << "Input: nums = [";
        for (size_t i = 0; i < nums.size(); i++) {
            cout << nums[i] << (i < nums.size() - 1 ? ", " : "");
        }
        cout << "], k = " << k << endl;
        cout << "Expected: " << expected << ", Actual: " << actual << endl;
        cout << "Test Passed: " << (passed ? "True" : "False") << endl;
        cout << "------------------------------------------" << endl;
    }
};

// 运行所有测试用例
void runTests(vector<TestCase>& testCases) {
    Solution solution;
    for (size_t i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":" << endl;
        testCases[i].runTest(solution);
        testCases[i].print();
    }
}

// 主函数
int main() {
    // 定义测试用例
    vector<TestCase> testCases = {
        TestCase({1, 2, 2, 3, 3, 3, 3}, 2, 5),  // 最大长度子数组为 [2, 2, 3, 3, 3]
        TestCase({1, 2, 3, 1, 2, 3}, 1, 2),     // 最大长度子数组为 [1, 2]
        TestCase({4, 4, 4, 4, 4}, 1, 1),        // 最大长度子数组为 [4]
        TestCase({1, 1, 1, 2, 2, 3, 3}, 2, 7),  // 最大长度子数组为整个数组
        TestCase({}, 1, 0)                      // 空数组
    };

    // 运行所有测试用例
    runTests(testCases);

    return 0;
}

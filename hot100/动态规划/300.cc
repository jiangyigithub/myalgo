#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 解决方案类
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> memo(n, 0); // 初始化为0，表示没有计算过

        // 递归函数定义,有两个思路，1.选/不选？ 2.枚举选哪个？
        auto dfs = [&](auto &&dfs, int i) -> int {
            int &res = memo[i]; // 引用，方便修改
            if (res > 0) { // 如果之前计算过，直接返回
                return res;
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    res = max(res, dfs(dfs, j)); // 递归查找子问题的解
                }
            }
            return ++res; // 最少的LIS长度为1
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(dfs, i)); // 遍历所有元素求解
        }
        return ans;
    }
};

// 测试用例结构体
struct TestCase {
    vector<int> nums;
    int expected;
};

// 测试函数
void runTests() {
    Solution sol;
    vector<TestCase> testCases = {
        {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
        {{0, 1, 0, 3, 2, 3}, 4},
        {{7, 7, 7, 7, 7, 7, 7}, 1},
        {{1, 3, 6, 7, 9, 4, 10, 5, 6}, 6}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        int result = sol.lengthOfLIS(testCases[i].nums);
        bool passed = result == testCases[i].expected;
        
        // 输出测试用例的详细信息
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Input: ";
        for (int num : testCases[i].nums) {
            cout << num << " ";
        }
        cout << "\nExpected Result: " << testCases[i].expected;
        cout << "\nActual Result: " << result;
        cout << "\nTest " << (passed ? "PASSED" : "FAILED") << "\n\n";
    }
}

int main() {
    runTests();
    return 0;
}

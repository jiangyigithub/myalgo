#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            
            // 判断 mid 和 target 是否在相同的段中
            if ((nums[mid] > nums[n - 1] && (target > nums[n - 1] && nums[mid] >= target)) ||
                (nums[mid] <= nums[n - 1] && (target > nums[n - 1] || nums[mid] >= target))) {
                // target 在 nums[mid] 的左边
                right = mid - 1;
            } else {
                // target 在 nums[mid] 的右边
                left = mid + 1;
            }
        }
        
        return -1;  // 如果没有找到
    }
};

struct TestCase {
    vector<int> nums;
    int target;
    int expected;
};

void runTestCase( TestCase& testCase, Solution& solution) {
    int result = solution.search(testCase.nums, testCase.target);
    bool passed = result == testCase.expected;

    cout << "Test case: [";
    for (size_t i = 0; i < testCase.nums.size(); ++i) {
        cout << testCase.nums[i];
        if (i < testCase.nums.size() - 1) cout << ", ";
    }
    cout << "], Target: " << testCase.target << ", Expected: " << testCase.expected << ", Result: " << result << ", Passed: " << (passed ? "Yes" : "No") << endl;
}

int main() {
    Solution solution;
    vector<TestCase> testCases = {
        {{4, 5, 6, 7, 0, 1, 2}, 0, 4},
        {{4, 5, 6, 7, 0, 1, 2}, 3, -1},
        {{1}, 0, -1},
        {{1, 3}, 3, 1},
        {{5, 1, 3}, 5, 0},
    };

    for ( auto& testCase : testCases) {
        runTestCase(testCase, solution);
    }

    return 0;
}

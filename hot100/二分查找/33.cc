#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    /// 找最小值，找target
    int search(vector<int>& nums, int target) {
        

        /// x , end , target 三个 metric
        auto is_blue = [&](int i) -> bool {

            int x = nums[i];

            int end = nums.back();

            if (x > end) {

                return target > end && x >= target; // 都在第一段，且在target右侧

            }

            return target > end || x >= target;

        };

        int left = -1, right = nums.size() - 1; // 开区间 (-1, n-1)

        while (left + 1 < right) { // 开区间不为空

            int mid = left + (right - left) / 2;

            if (is_blue(mid)) {

                right = mid; // mid左移

            } else {

                left = mid; // mid右移

            }

        }

        return nums[right] == target ? right : -1;

    }

};


struct TestCase {
    vector<int> nums;
    int target;
    int expected;
};

void runTestCase(TestCase& testCase, Solution& solution) {
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

    for (auto& testCase : testCases) {
        runTestCase(testCase, solution);
    }

    return 0;
}

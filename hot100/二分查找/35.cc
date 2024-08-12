#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        cout<<"left"<<left<<endl;
        cout<<"right"<<right<<endl;
        return left;
    }
};

struct TestCase {
    vector<int> nums;
    int target;
    int expected;
};

void runTestCase(TestCase& testCase, Solution& solution) {
    int result = solution.searchInsert(testCase.nums, testCase.target);
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
        {{1, 3, 5, 6}, 5, 2},
        {{1, 3, 5, 6}, 2, 1},
        {{1, 3, 5, 6}, 7, 4},
        {{1, 3, 5, 6}, 0, 0},
        {{}, 5, 0},
        {{1}, 0, 0},
        {{1, 3, 5, 6}, 3, 1},
    };

    for (auto& testCase : testCases) {
        runTestCase(testCase, solution);
    }

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        
        int firstIdx = findFirstOccurrence(nums, target);
        if (firstIdx != -1) {
            int lastIdx = findLastOccurrence(nums, target);
            result = {firstIdx, lastIdx};
        }
        
        return result;
    }

private:
/// 找到了怎么确定是最左边的，如果不是，区间怎么更新
    int findFirstOccurrence(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                // Check if it's the first occurrence
                if (mid == 0 || nums[mid - 1] != target) {
                    return mid;
                } else {
                    right = mid - 1;  // Continue searching in the left half
                }
            } else if (nums[mid] < target) {
                left = mid + 1;  // Continue searching in the right half
            } else {
                right = mid - 1;  // Continue searching in the left half
            }
        }
        return -1;  // Target not found
    }
    
    int findLastOccurrence(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                // Check if it's the last occurrence
                if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                    return mid;
                } else {
                    left = mid + 1;  // Continue searching in the right half
                }
            } else if (nums[mid] < target) {
                left = mid + 1;  // Continue searching in the right half
            } else {
                right = mid - 1;  // Continue searching in the left half
            }
        }
        return -1;  // Target not found
    }
};

void printResult(vector<int>& result, vector<int>& expected, size_t testCaseIndex) {
    cout << "Test case " << testCaseIndex + 1 << ": ";
    cout << "expected = " << expected[0] << ", " << expected[1];
    cout << ", got = " << result[0] << ", " << result[1];

    if (result == expected) {
        cout << " [PASSED]" << endl;
    } else {
        cout << " [FAILED]" << endl;
    }
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> result1 = sol.searchRange(nums1, target1);
    vector<int> expected1 = {3, 4};
    printResult(result1, expected1, 0);

    // Test Case 2
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    int target2 = 6;
    vector<int> result2 = sol.searchRange(nums2, target2);
    vector<int> expected2 = {-1, -1};
    printResult(result2, expected2, 1);

    // Test Case 3
    vector<int> nums3 = {1, 2, 2, 2, 3};
    int target3 = 2;
    vector<int> result3 = sol.searchRange(nums3, target3);
    vector<int> expected3 = {1, 3};
    printResult(result3, expected3, 2);

    // Test Case 4
    vector<int> nums4 = {1};
    int target4 = 1;
    vector<int> result4 = sol.searchRange(nums4, target4);
    vector<int> expected4 = {0, 0};
    printResult(result4, expected4, 3);

    // Test Case 5
    vector<int> nums5 = {1, 2, 3, 4, 5};
    int target5 = 6;
    vector<int> result5 = sol.searchRange(nums5, target5);
    vector<int> expected5 = {-1, -1};
    printResult(result5, expected5, 4);

    return 0;
}

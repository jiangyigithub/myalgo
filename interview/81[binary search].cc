#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct TestCase {
    vector<int> nums;
    int target;
    bool expected;
};

bool searchInRotatedSortedArray(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return true;
        }
        
        // Handling duplicates
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
        } 
        // Left half is sorted
        else if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        // Right half is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return false;
}

void runTestCases(const vector<TestCase>& testCases) {
    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        bool actual = searchInRotatedSortedArray(const_cast<vector<int>&>(testCase.nums), testCase.target);
        bool passed = (actual == testCase.expected);
        
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Array: ";
        for (int num : testCase.nums) {
            cout << num << " ";
        }
        cout << "\nTarget: " << testCase.target << "\n";
        cout << "Expected: " << (testCase.expected ? "true" : "false") << "\n";
        cout << "Actual: " << (actual ? "true" : "false") << "\n";
        cout << "Test " << (passed ? "PASSED" : "FAILED") << "\n\n";
    }
}

int main() {
    vector<TestCase> testCases = {
        {{2, 5, 6, 0, 0, 1, 2}, 0, true},
        {{2, 5, 6, 0, 0, 1, 2}, 3, false},
        {{1, 1, 1, 1, 1, 1, 3, 1}, 3, true},
        {{1, 3, 1, 1, 1}, 3, true},
        {{1, 3, 5}, 3, true},
        {{5, 1, 3}, 3, true}
    };
    
    runTestCases(testCases);

    return 0;
}

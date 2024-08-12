#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int findMin(vector<int>& nums){
        int n=nums.size();
        int left =0,right=n-2;
        int end = nums[n-1];
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]>end) left = mid+1; // 右移
            else right = mid-1; // 左移
        }
        return left;
    }

    int binaraySearch(vector<int>& nums, int target,int left ,int right){
        while(left<=right){
            int mid = left + (right-left)/2;
            if(target>nums[mid]) left = mid+1;
            else right = mid-1;
        }
        return nums[left]==target? left:-1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int end = nums[n-1];
        int gap = findMin(nums);
        if(target>end) return binaraySearch(nums,target,0,gap-1);
        return binaraySearch(nums,target,gap,n-1);
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

#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct TestCase {
    vector<int> nums;
    int target;
    vector<int> expected;
    vector<int> actual;
    bool passed;
};

class Solution {
    int search(vector<int>& nums, int target){
        int n=nums.size();
        int left =0,right =n-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(target>nums[mid]) left=mid+1;
            else right=mid-1;
        }
        return left; // 以left ,左边都小于target , 右边都大于等于target
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = search(nums,target);
        if(low==nums.size()||nums[low]!=target) return{-1,-1};
        int up = search(nums,target+1)-1;
        return {low,up};
    }
};

void runTestCases() {
    Solution solution;
    vector<TestCase> testCases = {
        {{5, 7, 7, 8, 8, 10}, 8, {3, 4}, {}, false},
        {{5, 7, 7, 8, 8, 10}, 6, {-1, -1}, {}, false},
        {{}, 0, {-1, -1}, {}, false},
        {{1}, 1, {0, 0}, {}, false}
    };

    for (auto& testCase : testCases) {
        testCase.actual = solution.searchRange(testCase.nums, testCase.target);
        testCase.passed = (testCase.actual == testCase.expected);

        // 输出每个测试用例的详细信息
        cout << "Test case: nums = [";
        for (size_t i = 0; i < testCase.nums.size(); ++i) {
            cout << testCase.nums[i];
            if (i < testCase.nums.size() - 1) {
                cout << ", ";
            }
        }
        cout << "], target = " << testCase.target << "\n";
        cout << "Expected result: [" << testCase.expected[0] << ", " << testCase.expected[1] << "]\n";
        cout << "Actual result: [" << testCase.actual[0] << ", " << testCase.actual[1] << "]\n";
        cout << "Test " << (testCase.passed ? "PASSED" : "FAILED") << "\n\n";
    }
}

int main() {
    runTestCases();
    return 0;
}

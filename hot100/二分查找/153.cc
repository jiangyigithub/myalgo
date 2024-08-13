#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left =0,right=n-2;
        while(left<=right){
            int mid = left+(right-left)/2;            
            if(nums[mid]>nums[n-1]){
                left = mid+1; // mid右移
            }
            else{
                right = mid-1; // mid左移
            }
        }
        return nums[left];
    }
};

// 测试用例
struct TestCase {
    vector<int> nums;
    int expected;
    int actual;
    bool passed;
};

void runTestCases() {
    Solution solution;
    vector<TestCase> testCases = {
        {{3, 4, 5, 1, 2}, 1, 0, false},
        {{4, 5, 6, 7, 0, 1, 2}, 0, 0, false},
        {{11, 13, 15, 17}, 11, 0, false},
        {{2, 2, 2, 0, 1}, 0, 0, false},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 1, 0, false}
    };

    for (auto& testCase : testCases) {
        testCase.actual = solution.findMin(testCase.nums);
        testCase.passed = (testCase.actual == testCase.expected);

        // 输出每个测试用例的详细信息
        cout << "Test case: nums = [";
        for (size_t i = 0; i < testCase.nums.size(); ++i) {
            cout << testCase.nums[i];
            if (i < testCase.nums.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
        cout << "Expected result: " << testCase.expected << "\n";
        cout << "Actual result: " << testCase.actual << "\n";
        cout << "Test " << (testCase.passed ? "PASSED" : "FAILED") << "\n\n";
    }
}

int main() {
    runTestCases();
    return 0;
}
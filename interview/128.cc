#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    int longest_streak = 0;



    return longest_streak;
}

// 测试结构体
struct TestCase {
    vector<int> nums;
    int expected;
    string description;
};

// 运行测试用例并打印结果
void runTestCases() {
    vector<TestCase> testCases = {
        {{100, 4, 200, 1, 3, 2}, 4, "Basic test case"},
        {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9, "Test with duplicates and larger sequence"},
        {{1, 2, 0, 1}, 3, "Test with small sequence and duplicates"},
        {{9, 1, -3, 7, 5, 0, -1, 2, -2, 1}, 4, "Test with negative and positive numbers"},
        {{}, 0, "Test with empty array"}
    };

    for (auto& testCase : testCases) {
        int result = longestConsecutive(testCase.nums);
        cout << "Test Case: " << testCase.description << endl;
        cout << "Input: ";
        for (const int& num : testCase.nums) {
            cout << num << " ";
        }
        cout << endl;
        cout << "Expected: " << testCase.expected << ", Actual: " << result << endl;
        cout << "Test Passed: " << (result == testCase.expected ? "Yes" : "No") << endl;
        cout << "--------------------------------------------" << endl;
    }
}

int main() {
    runTestCases();
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0, r = numbers.size() - 1, sum;
    while (l < r) {
        sum = numbers[l] + numbers[r];
        if (sum == target)
            break;
        if (sum < target)
            ++l;
        else
            --r;
    }
    return vector<int>{l + 1, r + 1}; // 返回的下标从1开始
}

struct TestCase {
    vector<int> numbers;
    int target;
    vector<int> expected;
};

void runTestCase(const TestCase& testCase) {
    vector<int> result = twoSum(const_cast<vector<int>&>(testCase.numbers), testCase.target);
    if (result == testCase.expected) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
        cout << "Expected: [" << testCase.expected[0] << ", " << testCase.expected[1] << "], ";
        cout << "Got: [" << result[0] << ", " << result[1] << "]" << endl;
    }
}

void testTwoSum() {
    vector<TestCase> testCases = {
        // 测试用例 1
        // 数组： [2, 7, 11, 15]
        // 目标值： 9
        // 期望输出： [1, 2]（下标从1开始，nums[0] + nums[1] = 2 + 7 = 9）
        {{2, 7, 11, 15}, 9, {1, 2}},
        
        // 测试用例 2
        // 数组： [2, 3, 4]
        // 目标值： 6
        // 期望输出： [1, 3]（下标从1开始，nums[0] + nums[2] = 2 + 4 = 6）
        {{2, 3, 4}, 6, {1, 3}},
        
        // 测试用例 3
        // 数组： [-1, 0]
        // 目标值： -1
        // 期望输出： [1, 2]（下标从1开始，nums[0] + nums[1] = -1 + 0 = -1）
        {{-1, 0}, -1, {1, 2}},
        
        // 测试用例 4
        // 数组： [1, 2, 3, 4, 4, 9, 56, 90]
        // 目标值： 8
        // 期望输出： [4, 5]（下标从1开始，nums[3] + nums[4] = 4 + 4 = 8）
        {{1, 2, 3, 4, 4, 9, 56, 90}, 8, {4, 5}},
        
        // 测试用例 5
        // 数组： [5, 25, 75]
        // 目标值： 100
        // 期望输出： [2, 3]（下标从1开始，nums[1] + nums[2] = 25 + 75 = 100）
        {{5, 25, 75}, 100, {2, 3}}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test case " << i + 1 << ": ";
        runTestCase(testCases[i]);
    }
}

int main() {
    testTwoSum();
    return 0;
}

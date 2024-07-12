#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> num_to_index;

    for (int i = 0; i < nums.size(); ++i)
    {

        int complement = target - nums[i];
        if (num_to_index.find(complement) != num_to_index.end())
        {
            return {num_to_index[complement], i};
        }
        num_to_index[nums[i]] = i; // 不会自我匹配
    }

    return {};
}

struct TestCase
{
    vector<int> nums;
    int target;
    vector<int> expected;
};

void runTestCase(const TestCase &testCase)
{
    vector<int> result = twoSum(const_cast<vector<int> &>(testCase.nums), testCase.target);
    if (result == testCase.expected)
    {
        cout << "Expected: [" << testCase.expected[0] << ", " << testCase.expected[1] << "], ";
        cout << "Got: [" << result[0] << ", " << result[1] << "]";
        cout << " Passed" << endl;
    }
    else
    {
        cout << "Expected: [" << testCase.expected[0] << ", " << testCase.expected[1] << "], ";
        cout << "Got: [" << result[0] << ", " << result[1] << "]";
        cout << " Failed" << endl;
    }
}

void testTwoSum()
{
    vector<TestCase> testCases = {
        {{2, 7, 11, 15}, 9, {0, 1}},
        {{3, 2, 4}, 6, {1, 2}},
        {{3, 3}, 6, {0, 1}},
        {{1, 2, 3, 4, 5}, 9, {3, 4}},
        {{10, 20, 30, 40, 50}, 90, {3, 4}}};

    for (int i = 0; i < testCases.size(); ++i)
    {
        cout << "Test case " << i + 1 << ": ";
        runTestCase(testCases[i]);
    }
}

int main()
{
    testTwoSum();
    return 0;
}

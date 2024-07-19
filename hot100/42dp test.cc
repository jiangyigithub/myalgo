#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 结构体用于存储测试用例的输入和期望输出
struct TestCase
{
    vector<int> heights;
    int expected;

    TestCase(vector<int> h, int exp) : heights(h), expected(exp) {}
};

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        if (height.size() < 2)
        {
            return 0;
        }
        for (int i = 1; i < height.size() - 1; ++i)
        {
            int leftMax = 0;
            int rightMax = 0;
            for (int m = i; m >= 0; m--)
            {
                leftMax = max(height[m], leftMax);
            }
            for (int n = i; n < height.size(); n++)
            {
                rightMax = max(height[n], rightMax);
            }
            res += (min(leftMax, rightMax) - height[i]);
        }

        return res;
    }

    int trap2(vector<int> &height)
    {
        int res = 0;
        if (height.size() < 2)
        {
            return 0;
        }
        int n = height.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);
        leftMax[0] = height[0];
        rightMax[0] = height[n];
        for (int i = 1; i < height.size(); ++i){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        for (int i = n-1; i >=0; --i){
            rightMax[i]=max(rightMax[i+1],height[i]);
        }
        for (int i = 1; i < height.size() - 1; ++i)
        {
   
            res += (min(leftMax[i], rightMax[i]) - height[i]);
        }

        return res;
    }

    // 运行单个测试用例并输出结果
    void runTest(const TestCase &testCase)
    {
        vector<int> heights = testCase.heights;
        int expected = testCase.expected;

        int result = trap2(heights);

        // 输出测试用例的输入数组
        cout << "Input: [";
        for (size_t i = 0; i < heights.size(); ++i)
        {
            cout << heights[i];
            if (i < heights.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;

        // 输出预期结果和实际结果
        cout << "Expected: " << expected << endl;
        cout << "Actual: " << result << endl;

        // 判断测试是否通过
        if (result == expected)
        {
            cout << "Test Passed!" << endl;
        }
        else
        {
            cout << "Test Failed!" << endl;
        }

        cout << "----------------------" << endl;
    }

    // 可视化函数，用于输出柱状图表示的柱子高度
    void visualize(vector<int> &heights)
    {
        int maxHeight = *max_element(heights.begin(), heights.end());

        for (int h = maxHeight; h > 0; --h)
        {
            for (int i = 0; i < heights.size(); ++i)
            {
                if (heights[i] >= h)
                {
                    cout << "|";
                }
                else
                {
                    cout << " ";
                }
                cout << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < heights.size(); ++i)
        {
            cout << "==";
        }
        cout << endl;

        for (int i = 0; i < heights.size(); ++i)
        {
            cout << heights[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution solution;

    // 测试用例
    vector<TestCase> testCases = {
        // 正常情况
        {{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6},
        {{4, 2, 0, 3, 2, 5}, 9},
        {{3, 1, 2, 4, 0, 1, 3, 2, 1, 2, 1}, 12},

        // 边界情况：没有柱子或只有一个柱子
        {{}, 0},
        {{1}, 0},
        {{5}, 0},

        // 全部递减的情况
        {{5, 4, 3, 2, 1}, 0},

        // 全部递增的情况
        {{1, 2, 3, 4, 5}, 0},

        // 部分递减、递增混合的情况
        {{3, 1, 2, 0, 4, 1}, 6},

        // 大量连续相等的柱子
        {{2, 2, 2, 2, 2, 2, 2, 2}, 0},

        // 大量相等且有不同高度的柱子
        {{3, 3, 1, 2, 2, 1, 3, 3}, 6}};

    // 遍历每个测试用例，运行并输出结果
    for (auto &testCase : testCases)
    {
        // solution.visualize(testCase.heights);  // 可视化柱子高度
        solution.runTest(testCase); // 运行测试用例
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // for std::max

using namespace std;

// 定义 Solution 类及其函数
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        vector<int> right(n, n);
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};

// 定义测试用例结构体
struct TestCase {
    vector<int> input;
    int expected;
    TestCase(vector<int> i, int e) : input(i), expected(e) {}
};

int main() {
    Solution solution;

    // 初始化测试用例
    vector<TestCase> testCases = {
        TestCase({2, 1, 5, 6, 2, 3}, 10),
        TestCase({2, 4}, 4),
        TestCase({1, 2, 3, 4, 5}, 9),
        TestCase({5, 4, 1, 2}, 8),
        TestCase({1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 10)
    };

    // 运行测试用例
    for (int i = 0; i < testCases.size(); ++i) {
        int result = solution.largestRectangleArea(testCases[i].input);
        bool passed = (result == testCases[i].expected);
        cout << "Test Case " << i + 1 << ":" << endl;
        cout << "Input: ";
        for (int num : testCases[i].input) {
            cout << num << " ";
        }
        cout << endl;
        cout << "Expected: " << testCases[i].expected << endl;
        cout << "Actual: " << result << endl;
        cout << "Passed: " << (passed ? "Yes" : "No") << endl << endl;
    }

    return 0;
}

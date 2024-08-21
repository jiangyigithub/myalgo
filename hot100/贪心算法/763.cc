#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 定义结构体存储测试用例
struct TestCase {
    string input;               // 输入字符串
    vector<int> expected;       // 预期输出
    vector<int> actual;         // 实际输出
    bool passed;                // 测试是否通过
};

// Solution类中包含partitionLabels方法
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int last[26];
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i; // 每个字母最后出现的下标
        }

        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) 
        {
            end = max(end, last[s[i] - 'a']); // 更新当前区间右端点的最大值
            if (end == i) { // 当前区间合并完毕
                ans.push_back(end - start + 1); // 区间长度加入答案
                start = i + 1; // 下一个区间的左端点
            }
        }
        return ans;
    }
};

// 测试函数
void runTests(vector<TestCase>& testCases, Solution& sol) {
    for (auto& testCase : testCases) {
        // 计算实际结果
        testCase.actual = sol.partitionLabels(testCase.input);
        // 判断测试是否通过
        testCase.passed = (testCase.actual == testCase.expected);

        // 输出测试用例的详细信息
        cout << "Test Case: \"" << testCase.input << "\"\n";
        cout << "Expected: ";
        for (int len : testCase.expected) {
            cout << len << " ";
        }
        cout << "\nActual:   ";
        for (int len : testCase.actual) {
            cout << len << " ";
        }
        cout << "\nTest " << (testCase.passed ? "Passed" : "Failed") << "\n\n";
    }
}

int main() {
    // 初始化测试用例
    vector<TestCase> testCases = {
        {"ababcbacadefegdehijhklij", {9, 7, 8}, {}, false}, // 预期划分是 {9, 7, 8}
        {"eccbbbbdec", {10}, {}, false},                  // 预期划分是 {10}
        {"abac", {2, 2}, {}, false},                      // 预期划分是 {2, 2}
        {"caedbdedda", {1, 9}, {}, false}                 // 预期划分是 {1, 9}
    };

    // 创建Solution实例
    Solution sol;

    // 运行测试
    runTests(testCases, sol);

    return 0;
}

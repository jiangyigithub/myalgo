#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 定义结构体存储测试用例
struct TestCase
{
    string input;         // 输入字符串
    vector<int> expected; // 预期输出
    vector<int> actual;   // 实际输出
    bool passed;          // 测试是否通过
};

// Solution类中包含partitionLabels方法
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();
        int last[26];
        for (int i = 0; i < n; i++)
        {
            last[s[i] - 'a'] = i; // 每个字母最后出现的下标
        }

        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {   
            // 第一个片段 "ababcbaca" 
            // 第二个片段 "defegde" 
            // 第三个片段 "hijhklij"
            end = max(end, last[s[i] - 'a']); // 更新当前区间右端点的最大值
            if (end == i) // 确定区间终点
            {                                  
                ans.push_back(end - start + 1); // 区间长度加入答案
                start = i + 1;                  // 下一个区间的左端点，合并区间，且区间之间是相邻的
            }
        }
        return ans;
    }

    vector<int> partitionLabelsForMerge(string s)
    {
        int n = s.size();
        vector<pair<int, int>> intervals; // 存储所有区间

        // 记录每个字母的最早和最晚出现位置
        vector<int> first(26, n); // 初始化为最大值
        vector<int> last(26, -1); // 初始化为最小值

        for (int i = 0; i < n; i++)
        {
            if (first[s[i] - 'a'] == n)
            {
                first[s[i] - 'a'] = i; //等价为 first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            }
            last[s[i] - 'a'] = i; //等价为 last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }

        // 收集所有区间
        for (int i = 0; i < 26; i++)
        {
            if (last[i] != -1)
            {
                intervals.push_back({first[i], last[i]});
            }
        }

        // 对区间进行排序，按照开始位置排序
        sort(intervals.begin(), intervals.end());

        // 合并区间
        vector<int> ans;
        int start = intervals[0].first, end = intervals[0].second;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].first > end)
            {
                // 当前区间与前一个区间不重叠
                ans.push_back(end - start + 1);
                start = intervals[i].first;
                end = intervals[i].second;
            }
            else
            {
                // 当前区间与前一个区间重叠，合并它们
                end = max(end, intervals[i].second);
            }
        }

        // 最后一个区间
        ans.push_back(end - start + 1);

        return ans;
    }
};

// 测试函数
void runTests(vector<TestCase> &testCases, Solution &sol)
{
    for (auto &testCase : testCases)
    {
        // 计算实际结果
        // testCase.actual = sol.partitionLabels(testCase.input);
        testCase.actual = sol.partitionLabelsForMerge(testCase.input);
        // 判断测试是否通过
        testCase.passed = (testCase.actual == testCase.expected);

        // 输出测试用例的详细信息
        cout << "Test Case: \"" << testCase.input << "\"\n";
        cout << "Expected: ";
        for (int len : testCase.expected)
        {
            cout << len << " ";
        }
        cout << "\nActual:   ";
        for (int len : testCase.actual)
        {
            cout << len << " ";
        }
        cout << "\nTest " << (testCase.passed ? "Passed" : "Failed") << "\n\n";
    }
}

int main()
{
    // 初始化测试用例
    vector<TestCase> testCases = {
        {"ababcbacadefegdehijhklij", {9, 7, 8}, {}, false}, // 预期划分是 {9, 7, 8}
        {"eccbbbbdec", {10}, {}, false},                    // 预期划分是 {10}
        {"abac", {3, 1}, {}, false},                        // 预期划分是 {2, 2}
        {"caedbdedda", {1, 9}, {}, false}                   // 预期划分是 {1, 9}
    };

    // 创建Solution实例
    Solution sol;

    // 运行测试
    runTests(testCases, sol);

    return 0;
}

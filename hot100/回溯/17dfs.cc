#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    // 数字到字母的映射关系
    string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // 存储结果组合
    vector<string> ans;

    // 存储当前路径的字母组合
    string path;

public:
    // 主函数，接收数字字符串并返回所有可能的字母组合
    vector<string> letterCombinations(string digits) {
        int n = digits.size(); // 获取输入字符串的长度
        if (n == 0) return {}; // 如果输入为空，直接返回空向量
        path.resize(n); // 初始化路径长度为输入字符串的长度
        dfs(digits, 0, n); // 开始深度优先搜索
        return ans; // 返回结果
    }

private:
    // 深度优先搜索函数
    void dfs(const string& digits, int i, int n) {
        if (i == n) { // 如果当前索引等于字符串长度，说明已经构建了一个完整的组合
            ans.push_back(path); // 将当前路径添加到结果中
            return;
        }
        // 遍历当前数字对应的所有可能字母
        for (char c : MAPPING[digits[i] - '0']) {
            path[i] = c; // 将当前字母添加到路径中
            dfs(digits, i + 1, n); // 递归处理下一个数字
        }
    }
};

int main() {
    Solution solution;
    // 测试用例，包括输入和预期输出
    vector<pair<string, vector<string>>> testCases = {
        {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
        // {"", {}},
        // {"2", {"a", "b", "c"}},
        // {"7", {"p", "q", "r", "s"}},
        // {"78", {"pt", "pu", "pv", "qt", "qu", "qv", "rt", "ru", "rv", "st", "su", "sv"}}
    };
    
    for (const auto& testCase : testCases) {
        string digits = testCase.first; // 输入数字字符串
        vector<string> expected = testCase.second; // 预期输出
        vector<string> result = solution.letterCombinations(digits); // 实际输出
        
        // 输出输入数字字符串
        cout << "Input: " << digits << endl;

        // 输出预期结果
        cout << "Expected: ";
        for (const string& s : expected) {
            cout << s << " ";
        }
        cout << endl;

        // 输出实际结果
        cout << "Result: ";
        for (const string& s : result) {
            cout << s << " ";
        }
        cout << endl;

        // 判断测试是否通过
        cout << (result == expected ? "Pass" : "Fail") << endl;
        cout << "-------------------------" << endl;
    }
    
    return 0;
}

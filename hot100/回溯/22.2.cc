#include <iostream>
#include <vector>
#include <string>

/// 方法二：枚举下一个左括号的位置
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; // 用于存储结果的向量，包含所有合法的括号组合
        vector<int> path; // 用于记录左括号的位置

        // balance = 左括号个数 - 右括号个数
        
        auto dfs = [&](auto&& dfs, int i, int balance) {
            if (path.size() == n) { // 如果左括号数量达到 n
                string s(n * 2, ')'); // 初始化长度为 2*n 的字符串，全是右括号
                for (int j : path) {
                    s[j] = '('; // 将 path 中记录的位置设置为左括号
                }
                ans.emplace_back(s); // 将生成的合法组合加入结果
                return; // 回溯
            }

            // 可以填 0 到 balance 个右括号
            for (int close = 0; close <= balance; close++) { // 填 close 个右括号
                path.push_back(i + close); // 在当前位置填 1 个左括号
                dfs(dfs, i + close + 1, balance - close + 1); // 递归处理下一个位置
                path.pop_back(); // 回溯
            }
        };

        dfs(dfs, 0, 0); // 从初始位置 0 和 0 个平衡值开始深度优先搜索

        return ans; // 返回包含所有合法组合的结果
    }
};

// 测试代码
int main() {
    Solution solution;

    // 测试案例
    vector<int> testCases = {1, 2, 3, 4}; // 可根据需要添加更多测试案例

    for (int n : testCases) {
        cout << "n = " << n << " 时的括号组合：" << endl;
        vector<string> result = solution.generateParenthesis(n);
        for (const string& s : result) {
            cout << s << endl;
        }
        cout << endl;
    }

    return 0;
}

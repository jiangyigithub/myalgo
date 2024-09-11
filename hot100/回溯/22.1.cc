#include <iostream>
#include <vector>
#include <string>
/*
 /// 方法一：枚举填左括号还是右括号
在递归生成过程中，我们遵循以下规则：

只要左括号的数量 left 小于 n，我们就可以添加一个左括号。
只要右括号的数量 right 小于左括号的数量 left，我们就可以添加一个右括号。
*/

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int m = n * 2; // 括号字符串的总长度将是 2*n
        vector<string> ans; // 用于存储结果的向量，包含所有合法的括号组合
        string path(m, 0); // 用于构建每个括号组合的字符串，初始化为长度 m

        // 使用 lambda 函数定义深度优先搜索（dfs）函数
        // i：当前填充的位置
        // open：已使用的左括号数量
       
        auto dfs = [&](auto&& dfs, int i, int open) {
            if (i == m) { // 如果当前路径长度等于 m
                ans.emplace_back(path); // 将当前合法组合加入结果中
                return; // 回溯
            }

            if (open < n) { // 如果已使用的左括号数量小于 n
                path[i] = '('; // 在当前位置放置一个左括号 '('
                dfs(dfs, i + 1, open + 1); // 递归处理下一个位置，并增加一个左括号的数量
            }

            if (i - open < open) { // 如果已使用的右括号数量小于已使用的左括号数量
                path[i] = ')'; // 在当前位置放置一个右括号 ')'
                dfs(dfs, i + 1, open); // 递归处理下一个位置，左括号数量保持不变
            }
        };

        dfs(dfs, 0, 0); // 从初始值开始深度优先搜索：位置 0 和 0 个左括号

        return ans; // 返回包含所有合法组合的结果
    }

    vector<string> generateParenthesis2(int n) {
        int m = n * 2; // 括号字符串的总长度将是 2*n
        vector<string> ans; // 用于存储结果的向量，包含所有合法的括号组合
        string path(m, 0); // 用于构建每个括号组合的字符串，初始化为长度 m

        auto dfs = [&](auto&& dfs,int k, int i, int j) {
            if (i == n && j== n) { // 如果当前路径长度等于 m
                ans.push_back(path); // 将当前合法组合加入结果中
                return; // 回溯
            }

            if (i < n) { // 如果已使用的左括号数量小于 n
                path[k] = '('; // 在当前位置放置一个左括号 '('
                dfs(dfs,k+1, i + 1, j); // 递归处理下一个位置，并增加一个左括号的数量
            }

            if (j<i) { // 如果已使用的右括号数量小于已使用的左括号数量
                path[k] = ')'; // 在当前位置放置一个右括号 ')'
                dfs(dfs,k+1,i,j+1); // 递归处理下一个位置，左括号数量保持不变
            }
        };

        dfs(dfs, 0, 0, 0); // 从初始值开始深度优先搜索：位置 0 和 0 个左括号

        return ans; // 返回包含所有合法组合的结果
    }
};

// 测试代码
int main() {
    Solution solution;
    int n;

    // 测试案例
    vector<int> testCases = {1, 2, 3, 4}; // 可根据需要添加更多测试案例

    for (int n : testCases) {
        cout << "n = " << n << " 时的括号组合：" << endl;
        // vector<string> result = solution.generateParenthesis(n);
        vector<string> result = solution.generateParenthesis2(n);
        for (const string& s : result) {
            cout << s << endl;
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <functional>

/// 方法一：枚举填左括号还是右括号
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans; // 用于存储结果的向量，包含所有合法的括号组合 
        int m=2*n;
        string path(m,0);
        function<void(int,int)> dfs=[&](int i,int leftcnt){
            if(i==m){
                ans.push_back(path);
                return;
            }
            if(leftcnt<n){
                path[i]='(';
                dfs(i+1,leftcnt+1);
            }
            if(i-leftcnt<leftcnt){
                path[i]=')';
                dfs(i+1,leftcnt);
            }
        };
        dfs(0,0);
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
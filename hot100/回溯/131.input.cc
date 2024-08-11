#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.length();

        // start 表示当前这段回文子串的开始位置
        function<void(int, int)> dfs = [&](int i, int start) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }

            // 不选 i 和 i+1 之间的逗号（i=n-1 时一定要选）
            if (i < n - 1) {
                dfs(i + 1, start);
            }

            // 选 i 和 i+1 之间的逗号（把 s[i] 作为子串的最后一个字符）
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, i + 1); // 下一个子串从 i+1 开始
                path.pop_back(); // 恢复现场
            }
        };
        dfs(0, 0);
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    vector<vector<string>> result = sol.partition(s);

    for (const auto& partition : result) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}

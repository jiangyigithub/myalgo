#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution
{

    string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits)
    {
        int n = digits.size();
        if (n == 0)
            return {};
        vector<string> ans;
        string path(n, 0); // 本题 path 长度固定为 n
        function<void(int)> dfs = [&](int i)
        {
            if (i == n)
            {
                ans.push_back(path);
                return;
            }
            for (char c : MAPPING[digits[i] - '0'])
            {
                path[i] = c; // 直接覆盖
                cout<<"dfs path"<<path[i]<<endl;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<pair<string, vector<string>>> testCases = {
        {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
        // {"", {}},
        // {"2", {"a", "b", "c"}},
        // {"7", {"p", "q", "r", "s"}},
        // {"78", {"pt", "pu", "pv", "qt", "qu", "qv", "rt", "ru", "rv", "st", "su", "sv"}}
        };

    for (const auto &testCase : testCases)
    {
        string digits = testCase.first;
        vector<string> expected = testCase.second;
        vector<string> result = solution.letterCombinations(digits);

        cout << "Input: " << digits << endl;
        cout << "Expected: ";
        for (const string &s : expected)
        {
            cout << s << " ";
        }
        cout << endl;
        cout << "Result: ";
        for (const string &s : result)
        {
            cout << s << " ";
        }
        cout << endl;
        cout << (result == expected ? "Pass" : "Fail") << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}

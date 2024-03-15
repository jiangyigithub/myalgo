#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    vector<string> res;

    void dfs(string &s, int left, int right)
    {
        if (left == right)
        {
            res.push_back(s);
            return;
        }
        set<char> st;
        for (int i = left; i <= right; i++)
        {
            if (st.find(s[i]) != st.end())
                continue;
            st.insert(s[i]);

            std::swap(s[i], s[left]);
            dfs(s, left + 1, right);
            std::swap(s[i], s[left]);
        }
    }
};

int main()
{
    Solution sol;
    string str = "abcdef";
    sol.dfs(str, 0, str.size() - 1);

    for (const string &permutation : sol.res)
    {
        cout << permutation << endl;
    }

    return 0;
}

#include "head.hpp"
#include <set>

class Solution
{
public:
    vector<string> permutation(string s)
    {
        dfs(s, 0);
        return res;
    }

private:
    vector<string> res;
    void dfs(string s, int x)
    {
        if (x == s.size() - 1)
        {
            res.push_back(s); // 添加排列方案
            return;
        }
        set<int> st;
        for (int i = x; i < s.size(); i++)
        {
            if (st.find(s[i]) != st.end()) // 重复，因此剪枝
                continue;
            st.insert(s[i]);
            swap(s[i], s[x]); // 降低空间复杂度
            dfs(s, x + 1);
            swap(s[i], s[x]); // 回溯/撤销
        }
    }
};

int main(){
    string s="abcd";
    vector<string> out = Solution().permutation(s);
    for(auto elem:out){
         cout << elem << endl;
    }
    return 0;
}
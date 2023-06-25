#include "head.hpp"

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &a)
    {
        int len = a.size();
        if (len == 0)
            return {};
        vector<int> L(len, 0);
        vector<int> R(len, 0);
        vector<int> res(len);
        L[0] = 1;
        for (int i = 1; i < len; i++)
        {
            L[i] = L[i - 1] * a[i - 1];
        }

        R[len - 1] = 1;
        for (int i = len - 2; i >= 0; i--)
        {
            R[i] = R[i + 1] * a[i + 1];
        }

        for (int i = 0; i < len; i++)
        {
            res[i] = L[i] * R[i];
        }
        return res;
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 4, 5};
    vector<int> res = Solution().productExceptSelf(input);
    for (auto e : res)
    {
        cout << e << ", ";
    }
}
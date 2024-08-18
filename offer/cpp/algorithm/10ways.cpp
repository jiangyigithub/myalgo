#include "head.hpp"
int numWays(int n)
{
    int pre = 1, cur = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = (cur + pre) % 1000000007;
        pre = cur;
        cur = sum;
    }
    return pre;
}

int main()
{
    int result = numWays(5);
    cout << "numWays(5): " << result << endl;
}
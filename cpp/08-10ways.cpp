#include "head.hpp"
// 剑指 Offer 10- II. 青蛙跳台阶问题

int numWays2(int n)
{
    int ret[2] = {1, 1};
    if (n < 2)
        return ret[n];
    int pre = 1, cur = 1;
    int sum = 0;
    // loop start at index 2
    for (int i = 2; i <= n; i++)
    {
        sum = cur + pre;
        pre = cur;
        cur = sum;
    }
    return sum;
}

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
   
    int n = 6;
    for (int i = 0; i <= n; i++)
    {
        cout << "optimize space    --> F(" << i << ")= " << numWays2(i) << endl;
        cout << "optimize space2   --> F(" << i << ")= " << numWays(i) << endl;
    }
}
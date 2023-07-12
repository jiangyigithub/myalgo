// 1 brute force recur approach
// 2 with pruning
// 3 convert top-down to down-top
// 4 space complexity optimize

/// 重叠子问题的消除方法
// 1. 存在巨量冗余的递归树

#include "head.hpp"
int helper(int *memo, int n);
// brute forch recur
int fib(int n)
{
    // static int t = 0;
    // t++;
    // cout << "n =" << n << "; time = " << t << endl;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

/// recur with pruning
int fib2(int n)
{
    int memo[n + 1] = {0};
    return helper(memo, n);
}

int helper(int *memo, int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    // 已经计算过，不用再计算了
    if (memo[n] != 0)
        return memo[n];
    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    return memo[n];
}

/// convert recur to loop
//  DP table
int fib3(int n)
{
    if (n == 0)
        return 0;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

/// space optimize
// DP table 的大小从 n 缩小到 2
int fib4(int n)
{
    int ret[2] = {0, 1};
    if (n < 2)
        return ret[n];
    int pre = 0, cur = 1;
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

int fib5(int n)
{
    int pre = 0, cur = 1, sum;
    // loop start at index 0
    for (int i = 0; i < n; i++)
    {
        sum = (pre + cur) % 1000000007;
        pre = cur;
        cur = sum;
    }
    return pre; // not return sum
}

int main()
{
    int result = fib2(3);
    int n = 6;
    for (int i = 0; i <= n; i++)
    {
        cout << "brute force recur --> F(" << i << ")= " << fib(i) << endl;
        cout << "store memory      --> F(" << i << ")= " << fib2(i) << endl;
        cout << "DP table for loop --> F(" << i << ")= " << fib3(i) << endl;
        cout << "optimize space    --> F(" << i << ")= " << fib4(i) << endl;
    }
}

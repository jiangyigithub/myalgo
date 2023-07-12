#include "head.hpp"

// 剑指 Offer 63. 股票的最大利润
class Solution
{
public:
    /// @brief Brute Force, time complexity is N^2
    /// @param prices
    /// @return
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (prices[i] > prices[j])
                {
                    profit = max(profit, prices[i] - prices[j]);
                }
            }
        }
        return profit;
    }

    /// @brief DP table
    /// @param prices
    /// @return
    int maxProfit2(vector<int> &prices)
    {
        int cost = INT_MAX, profit = 0;
        int len = prices.size() - 1;
        int dp[len + 1] = {0};
        for (int i = 1; i <= len; i++)
        {
            cost = min(cost, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - min(cost, prices[i]));
        }
        return dp[len];
    }

    /// @brief optimize space complexity
    /// @param prices
    /// @return
    int maxProfit3(vector<int> &prices)
    {
        int cost = INT_MAX, profit = 0;
        for (int price : prices)
        {
            cost = min(cost, price);
            profit = max(profit, price - cost);
        }
        return profit;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                       { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                        { return !isspace(ch); })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

int main()
{
    string line = "[7,1,5,3,6,4]";
    vector<int> prices = stringToIntegerVector(line);
    int ret = Solution().maxProfit(prices);
    int ret2 = Solution().maxProfit2(prices);
    int ret3 = Solution().maxProfit3(prices);
    cout << "brute force               --> "<<ret << endl;
    cout << "DP table                  --> "<<ret2 << endl;
    cout << "optimize space complexity --> "<<ret3 << endl;

    return 0;
}
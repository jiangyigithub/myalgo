#include "head.hpp"

// 剑指 Offer 63. 股票的最大利润
// https://medium.com/@ganeshprasad227/best-time-to-buy-and-sell-stock-1-only-one-stock-allowed-python-cpp-coding-interview-b2a8856b1fc4
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
            dp[i] = max(dp[i - 1], prices[i] - cost);
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
            cost = min(cost, price); //if the current price is the lowest
            profit = max(profit, price - cost); //if the gap between the lowest and current price is maximum seen so far
        }
        return profit;
    }
    
    /// @brief do use system function
    // The algorithm for best time to buy and sell stock:

    // 1.Iterate through the prices in the list.
    // 2.see if the current price is the lowest seen so far, if yes then remember it.
    // 3.Otherwise check if the gap between the lowest and current price is maximum seen so far, if yes then remember the gap.
    // 4.The maximum gap is the maximum profit we can make with a single transaction.
    /// @param prices 
    /// @return 
    int maxProfit4(const vector<int> &prices)
    {
        // variable  to hold the maximum profit
        int maximum_profit = 0;

        // variable to hold the minimum price seen so far
        int minimum_price = prices[0];

        // traverse the prices list to find the maximum profit
        for (auto price : prices)
        {
            /* This is the greedy part, choose the minimum seen so
            far as well as look for the maximum profit
            */
            // if the current prices is minimum seen so far
            if (minimum_price > price)
            {
                // update price
                minimum_price = price;
            }
            else if ((price - minimum_price) > maximum_profit)
            {
                maximum_profit = (price - minimum_price);
            }
        }

        // return the maximum profit seen so far
        return maximum_profit;
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
    cout << "brute force               --> " << ret << endl;
    cout << "DP table                  --> " << ret2 << endl;
    cout << "optimize space complexity --> " << ret3 << endl;

    return 0;
}
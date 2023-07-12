#include "head.hpp"

// 剑指 Offer 63. 股票的最大利润
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int cost = INT_MAX, profit = 0;
        for (int price : prices)
        {
            // p[i]=max(dp[i−1],prices[i]−min(cost,prices[i])
            cost = min(cost, price);
            profit = max(profit, price - cost);
        }
        return profit;
    }
    
    /// Brute Force, time complexity is N^2
    int maxProfit2(vector<int> &prices)
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

    string out = to_string(ret);
    cout << out << endl;

    return 0;
}
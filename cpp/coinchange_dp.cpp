#include "head.hpp"
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        return recur(coins, amount);
    }

private:
    int recur(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;

        int res = INT_MAX;
        for (auto coin : coins)
        {
            int sub = recur(coins, amount - coin);
            if (sub == -1)
                continue;
            res = res < (sub + 1) ? res : (sub + 1);
        }

        return res == INT_MAX ? -1 : res;
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

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line = "[1,2,5]";

    vector<int> coins = stringToIntegerVector(line);
    line = "11";
    int amount = stringToInteger(line);

    int ret = Solution().coinChange(coins, amount);

    string out = to_string(ret);
    cout << out << endl;

    return 0;
}
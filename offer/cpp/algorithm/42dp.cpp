#include "head.hpp"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > 0)
                nums[i] += nums[i - 1];
            if (nums[i] > res)
                res = nums[i];
        }
        return res;
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
    string line = "[-2,1,-3,4,-1,2,1,-5,4]";

    vector<int> nums = stringToIntegerVector(line);

    int ret = Solution().maxSubArray(nums);

    string out = to_string(ret);
    cout << out << endl;

    return 0;
}
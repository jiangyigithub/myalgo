#include "head.hpp"

// 剑指 Offer 11. 旋转数组的最小数字
class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right)
        {   
            int mid = (left + right) / 2;
            if (numbers[mid] > numbers[right])
                left = mid + 1;
            else if (numbers[mid] < numbers[right])
                right = mid;
            else
                right--;
        }
        return numbers[left];
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
    string line = "[3,4,5,1,2]";
    vector<int> numbers = stringToIntegerVector(line);

    int ret = Solution().minArray(numbers);

    string out = to_string(ret);
    cout << out << endl;

    return 0;
}
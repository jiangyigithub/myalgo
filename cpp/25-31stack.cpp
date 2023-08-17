#include "head.hpp"

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> stk;
        int i = 0;
        for (auto e : pushed)
        {
            stk.push(e);
            while (!stk.empty() && stk.top() == popped[i])
            {
                stk.pop();
                i++;
            }
        }
        return stk.empty();
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

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
        string line = "[1,2,3,4,5]";
        vector<int> pushed = stringToIntegerVector(line);
        line = "[4,5,3,2,1]";
        vector<int> popped = stringToIntegerVector(line);

        bool ret = Solution().validateStackSequences(pushed, popped);

        string out = boolToString(ret);
        cout << out << endl;

    return 0;
}
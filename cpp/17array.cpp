#include "head.hpp"

class Solution
{
private:
    vector<string> res;
    void DFS(int n, int count, string record)
    {
        if (count == n)
        {
            if (record.front() != '0')
                res.push_back(record);
            return;
        }
        for (int index = 0; index <= 9; index++)
        {
            if (record.size() && record.front() == '0')
            {
                DFS(n, count + 1, to_string(index));
            }
            else
            {
                DFS(n, count + 1, record + to_string(index));
            }
        }
    }

public:
    vector<int> printNumbers(int n)
    {
        DFS(n, 0, "");
        vector<int> intRes;
        for (vector<string>::iterator iter = res.begin(); iter != res.end(); iter++)
        {
            intRes.push_back(stoi(*iter));
        }
        return intRes;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line = "2";

    int n = stringToInteger(line);

    vector<int> ret = Solution().printNumbers(n);

    string out = integerVectorToString(ret);
    cout << out << endl;

    return 0;
}
#include "head.hpp"

class Solution
{
public:
    bool verifyPostorder(vector<int> &postorder)
    {
        return recur(postorder, 0, postorder.size() - 1);
    }

private:
    bool recur(vector<int> &postorder, int i, int j)
    {   
        // recur end
        if (i >= j)
            return true;
        int p = i;
        // find the first element larger than the root element
        // the m element is the first element of right subtree of binary search tree
        while (postorder[p] < postorder[j])
            p++;
        int m = p;
        // the rest elements of right side of the binary search tree should large than the root element 
        while (postorder[p] > postorder[j])
            p++;
        // left subtree range i,m-1
        // right subtree range m,j-1
        // the root of the tree j
        return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
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
    string line = "[1,3,2,6,5]";

    vector<int> postorder = stringToIntegerVector(line);

    bool ret = Solution().verifyPostorder(postorder);

    string out = boolToString(ret);
    cout << out << endl;

    return 0;
}
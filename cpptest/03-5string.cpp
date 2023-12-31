#include "head.hpp"

// 剑指 Offer 05. 替换空格
class Solution
{
public:
    string replaceSpace(string s)
    {
        // 1. statics the number of space
        int len=s.size();
        int count =0;
        for(auto elem:s){
            if(elem ==' '){
                count ++;
            }
        }
        // 2. resize the string
        s.resize(len+2*count);

        // 3. reserve insert
        for(int i=len-1,j=s.size()-1;i<j;i--,j--){
            if(s[i]!=' '){
                s[j]=s[i];
            }
            else{
                s[j-2]='%';
                s[j-1]='2';
                s[j]='0';
                // 4. forward 2 step
                j-=2;
            }
        }
        return s;
    }

};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string s = "We are happy.";
    string ret = Solution().replaceSpace(s);
    string out = (ret);
    cout << out << endl;

    return 0;
}
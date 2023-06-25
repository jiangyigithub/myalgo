#include "head.hpp"

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len=s.size();
        reverseString(s,0,len-1);
        reverseString(s,0,len-n-1);
        reverseString(s,len-n,len-1);
        return s;
    }

    string reverseLeftWords(string s, int n,string method="stl") {
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.end()-n);
        reverse(s.end()-n,s.end());
        return s;
    }

private:
 void reverseString(string& s,int lo,int hi){
     while(lo<hi) {
         swap(s[lo],s[hi]);
         lo++;
         hi--;
 }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        string ret = Solution().reverseLeftWords(s, n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
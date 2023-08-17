#include "head.hpp"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n!=0){
            res+=n&1;
            n>>=1;
        }
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line = "123";
   
    int n = stringToInteger(line);
    
    int ret = Solution().hammingWeight(n);

    string out = to_string(ret);
    cout << out << endl;
    
    return 0;
}
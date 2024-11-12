#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n=s.size();
        int left =0;
        int same =0;
        for(int right=1;right<n;right++){
            if(s[right]==s[right-1]){
                same++;
     
            if(same>1){
                left++
            }
            }

        }
        
    }
};
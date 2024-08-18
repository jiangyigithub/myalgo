#include "head.hpp"
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,bool> map;
        for(int num:nums){
            if(map[num]) {
                return num;
            }
            map[num] = true;
        }
        return -1;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    line = "[1,2,3,4,2,3]";
    vector<int> nums = stringToIntegerVector(line);
    
    int ret = Solution().findRepeatNumber(nums);

    string out = to_string(ret);
    cout << out << endl;
    return 0;
}
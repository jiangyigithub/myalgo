#include "head.hpp"
class Solution {
private:
vector<vector<int>> res;

void backtrack(vector<int>& nums, vector<int>& paths){
	/// recur end contion, while the length of path is meet
    if(paths.size()==nums.size()){
        res.push_back(paths);
        return;
    }
    
    for(std::size_t i=0;i!=nums.size();i++){
        //pruning
        if(std::find(paths.begin(), paths.end(), nums[i]) != paths.end()) 
            continue;
        paths.push_back(nums[i]);
        backtrack(nums,paths);
        //backtrack
        paths.pop_back();
    }
}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> paths;
        backtrack(nums,paths);
        return res;
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line = "[1,2,3]";
    vector<int> nums = stringToIntegerVector(line);
    vector<vector<int>> rets = Solution().permute(nums);
    for(auto ret:rets)
    {
    string out = integerVectorToString(ret);
    cout << out << endl;
    }
    return 0;
}



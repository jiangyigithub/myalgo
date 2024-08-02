#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> phoneMap = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        vector<string> combinations;
        string currentCombination;
        backtrack(combinations, phoneMap, digits, 0, currentCombination);
        return combinations;
    }
    
private:
    void backtrack(vector<string>& combinations, const vector<string>& phoneMap, const string& digits, int index, string& currentCombination) {
        if (index == digits.length()) {
            combinations.push_back(currentCombination);
            return;
        }
        
        string possibleLetters = phoneMap[digits[index] - '0'];
        for (char letter : possibleLetters) {
            currentCombination.push_back(letter);
            backtrack(combinations, phoneMap, digits, index + 1, currentCombination);
            currentCombination.pop_back();
        }
    }
};

int main() {
    Solution solution;
    vector<pair<string, vector<string>>> testCases = {
        {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
        {"", {}},
        {"2", {"a", "b", "c"}},
        {"7", {"p", "q", "r", "s"}},
        {"78", {"pt", "pu", "pv", "qt", "qu", "qv", "rt", "ru", "rv", "st", "su", "sv"}}
    };
    
    for (const auto& testCase : testCases) {
        string digits = testCase.first;
        vector<string> expected = testCase.second;
        vector<string> result = solution.letterCombinations(digits);
        
        cout << "Input: " << digits << endl;
        cout << "Expected: ";
        for (const string& s : expected) {
            cout << s << " ";
        }
        cout << endl;
        cout << "Result: ";
        for (const string& s : result) {
            cout << s << " ";
        }
        cout << endl;
        cout << (result == expected ? "Pass" : "Fail") << endl;
        cout << "-------------------------" << endl;
    }
    
    return 0;
}

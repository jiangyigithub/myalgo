#include "head.hpp"
class Solution {
public:
    bool isNumber(string s) {
        vector<unordered_map<char, int>> states = {
            {{' ', 0}, {'s', 1}, {'d', 2}, {'.', 4}}, // 0.
            {{'d', 2}, {'.', 4}},                    // 1.
            {{'d', 2}, {'.', 3}, {'e', 5}, {' ', 8}}, // 2.
            {{'d', 3}, {'e', 5}, {' ', 8}},           // 3.
            {{'d', 3}},                              // 4.
            {{'s', 6}, {'d', 7}},                    // 5.
            {{'d', 7}},                              // 6.
            {{'d', 7}, {' ', 8}},                    // 7.
            {{' ', 8}}                               // 8.
        };
        int p = 0;
        char t;
        for(char c : s) {
            if(c >= '0' && c <= '9') t = 'd';
            else if(c == '+' || c == '-') t = 's';
            else if(c == 'e' || c == 'E') t = 'e';
            else if(c == '.' || c == ' ') t = c;
            else t = '?';
            if(states[p].count(t) == 0) return false;
            p = states[p][t];
        }
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    std::cout << std::boolalpha; // To print 'true' and 'false' instead of 1 and 0
    
    std::cout << solution.isNumber("0") << std::endl;          // true
    std::cout << solution.isNumber(" 0.1 ") << std::endl;      // true
    std::cout << solution.isNumber("abc") << std::endl;        // false
    std::cout << solution.isNumber("1 a") << std::endl;        // false
    std::cout << solution.isNumber("2e10") << std::endl;       // true
    std::cout << solution.isNumber(" -90e3   ") << std::endl; // true
    std::cout << solution.isNumber(" 1e") << std::endl;        // false
    std::cout << solution.isNumber("e3") << std::endl;         // false
    std::cout << solution.isNumber(" 6e-1") << std::endl;     // true
    std::cout << solution.isNumber(" 99e2.5 ") << std::endl;  // false
    std::cout << solution.isNumber("53.5e93") << std::endl;   // true
    std::cout << solution.isNumber(" --6 ") << std::endl;     // false
    
    return 0;
}
/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：

若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
 

示例 1：

输入：s = "0"
输出：true
示例 2：

输入：s = "e"
输出：false
示例 3：

输入：s = "."
输出：false
示例 4：

输入：s = "    .1  "
输出：true

*/
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
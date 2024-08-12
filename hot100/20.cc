#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 如果字符串长度不是偶数，直接返回 false
        if (s.length() % 2 != 0) {
            return false;
        }
        
        // 使用栈来存储待匹配的右括号
        stack<char> st;
        
        // 遍历字符串中的每个字符
        for (char c : s) {
            // 如果当前字符是左括号，入栈对应的右括号
            if (c == '(') {
                st.push(')'); 
            } else if (c == '[') {
                st.push(']');
            } else if (c == '{') {
                st.push('}');
            // 如果当前字符是右括号
            } else { 
                // 如果栈为空或栈顶元素不是当前右括号，返回 false
                if (st.empty() || st.top() != c) {
                    return false;
                }
                // 栈顶元素匹配，弹出栈顶元素
                st.pop();
            }
        }
        
        // 如果栈为空，所有左括号都匹配完毕，返回 true；否则返回 false
        return st.empty();
    }
};

// 测试代码
int main() {
    Solution solution;
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";

    cout << "Test 1 - Expected: true, Result: " << (solution.isValid(test1) ? "true" : "false") << endl;
    cout << "Test 2 - Expected: true, Result: " << (solution.isValid(test2) ? "true" : "false") << endl;
    cout << "Test 3 - Expected: false, Result: " << (solution.isValid(test3) ? "true" : "false") << endl;
    cout << "Test 4 - Expected: false, Result: " << (solution.isValid(test4) ? "true" : "false") << endl;
    cout << "Test 5 - Expected: true, Result: " << (solution.isValid(test5) ? "true" : "false") << endl;

    return 0;
}

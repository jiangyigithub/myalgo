#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans = ""; // 用于存储当前解码后的字符串
        stack<int> nums; // 用于存储遇到的数字，表示字符串需要重复的次数
        stack<string> strs; // 用于存储遇到的中间字符串
        int num = 0; // 用于记录当前遇到的数字
        int n = s.size(); // 输入字符串的长度
        
        for(int i = 0; i < n; ++i) {
            // 如果当前字符是数字，构建完整的数字
            if(s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
            }
            // 如果当前字符是字母，直接添加到结果字符串中
            else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                ans = ans + s[i];
            }
            // 如果遇到左括号 '['，表示开始一个新的重复段
            else if(s[i] == '[') {
                nums.push(num); // 将数字压入数字栈
                num = 0; // 重置数字变量
                strs.push(ans); // 将当前结果字符串压入字符串栈
                ans = ""; // 重置结果字符串
            }
            // 如果遇到右括号 ']'，表示结束一个重复段
            else {
                int times = nums.top(); // 获取需要重复的次数
                nums.pop(); // 从栈中移除这个次数
                // 将当前结果字符串重复相应次数并添加到栈顶字符串
                for(int j = 0; j < times; ++j)
                    strs.top() += ans;
                ans = strs.top(); // 将栈顶字符串作为新的结果字符串
                strs.pop(); // 从栈中移除这个字符串
            }
        }
        return ans; // 返回最终解码后的字符串
    }
};

// 定义测试用例结构体
struct TestCase {
    string input;
    string expected;
    TestCase(string i, string e) : input(i), expected(e) {}
};

int main() {
    Solution solution;
    
    // 初始化测试用例
    vector<TestCase> testCases = {
        TestCase("3[a]2[bc]", "aaabcbc"),
        TestCase("3[a2[c]]", "accaccacc"),
        TestCase("2[abc]3[cd]ef", "abcabccdcdcdef"),
        TestCase("abc3[cd]xyz", "abccdcdcdxyz"),
        TestCase("10[a]", "aaaaaaaaaa")
    };

    // 运行测试用例
    for (int i = 0; i < testCases.size(); ++i) {
        string result = solution.decodeString(testCases[i].input);
        bool passed = (result == testCases[i].expected);
        cout << "Test Case " << i + 1 << ":" << endl;
        cout << "Input: " << testCases[i].input << endl;
        cout << "Expected: " << testCases[i].expected << endl;
        cout << "Actual: " << result << endl;
        cout << "Passed: " << (passed ? "Yes" : "No") << endl << endl;
    }

    return 0;
}

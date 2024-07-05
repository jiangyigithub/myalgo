#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 函数：计算字符串中不含重复字符的最长子串的长度
int lengthOfLongestSubstring(string s) {
    int n = s.length(); // 获取字符串长度
    unordered_set<char> charSet; // 用于存储当前窗口内的字符
    int start = 0, maxLength = 0; // 初始化窗口起始位置和最长子串长度

    for (int end = 0; end < n; ++end) {
        // 如果当前字符在集合中，说明有重复字符，需要调整窗口
        while (charSet.find(s[end]) != charSet.end()) {
            charSet.erase(s[start]); // 从集合中移除窗口起始位置的字符
            ++start; // 将窗口起始位置右移
        }
        charSet.insert(s[end]); // 将当前字符添加到集合中
        maxLength = max(maxLength, end - start + 1); // 更新最长子串长度
    }

    return maxLength; // 返回最长子串长度
}


int lengthOfLongestSubstring2(string s) {
    unordered_map<char, int> dic;
    int i = -1, res = 0, len = s.size();
    for(int j = 0; j < len; j++) {
        if (dic.find(s[j]) != dic.end())
            i = max(i, dic.find(s[j])->second); // 更新左指针
        dic[s[j]] = j; // 哈希表记录
        res = max(res, j - i); // 更新结果
    }
    return res;
}



int main() {
    // 测试用例
    string s1 = "abcabcbb";
    cout << lengthOfLongestSubstring(s1) << endl; // 输出：3，最长子串为 "abc"

    string s2 = "bbbbb";
    cout << lengthOfLongestSubstring(s2) << endl; // 输出：1，最长子串为 "b"

    string s3 = "pwwkew";
    cout << lengthOfLongestSubstring(s3) << endl; // 输出：3，最长子串为 "wke"

    string s4 = "";
    cout << lengthOfLongestSubstring(s4) << endl; // 输出：0，最长子串为空

    string s5 = " ";
    cout << lengthOfLongestSubstring(s5) << endl; // 输出：1，最长子串为 " "

    string s6 = "au";
    cout << lengthOfLongestSubstring(s6) << endl; // 输出：2，最长子串为 "au"

    string s7 = "dvdf";
    cout << lengthOfLongestSubstring(s7) << endl; // 输出：3，最长子串为 "vdf"

    return 0;
}

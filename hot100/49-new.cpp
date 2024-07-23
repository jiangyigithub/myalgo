#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 判断两个字符串是否是字母异位词
bool isMatch(string& temp, string& temp2) {
    if (temp.size() != temp2.size()) return false;
    
    unordered_map<char, int> hashMap;
    for (auto c : temp) {
        hashMap[c]++;
    }
    for (auto c : temp2) {
        if (hashMap.find(c) == hashMap.end() || hashMap[c] == 0) {
            return false;
        }
        hashMap[c]--;
    }
    return true;
}

// 递归地将字母异位词分组
vector<vector<string>> group(vector<string>& strs) {
    if (strs.size() < 2) {
        return {strs};
    }
    
    vector<vector<string>> result;
    string comp = strs[0];
    vector<string> group1 = {comp};
    vector<string> remaining;
    
    for (int i = 1; i < strs.size(); ++i) {
        if (isMatch(strs[i], comp)) {
            group1.push_back(strs[i]);
        } else {
            remaining.push_back(strs[i]);
        }
    }
    
    result.push_back(group1);
    
    if (!remaining.empty()) {
        vector<vector<string>> remainingGroups = group(remaining);
        result.insert(result.end(), remainingGroups.begin(), remainingGroups.end());
    }
    
    return result;
}

// 主函数，用于将字母异位词分组
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ret = group(strs);
    return ret;
}

// 结构体用于存储测试用例
struct TestCase {
    vector<string> input;
    vector<vector<string>> expected;
    string description;
};

// 函数用于比较两个二维vector是否相等
bool compareResult(const vector<vector<string>>& result, const vector<vector<string>>& expected) {
    if (result.size() != expected.size()) return false;
    for (const auto& group : result) {
        bool found = false;
        for (const auto& exp_group : expected) {
            if (group == exp_group) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

// 输出测试结果
void printTestResult(const TestCase& testCase, const vector<vector<string>>& result) {
    cout << "Test Case: " << testCase.description << endl;
    cout << "Input: ";
    for (const string& str : testCase.input) {
        cout << str << " ";
    }
    cout << endl;

    cout << "Expected: " << endl;
    for (const auto& group : testCase.expected) {
        cout << "[ ";
        for (const string& str : group) {
            cout << str << " ";
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Actual: " << endl;
    for (const auto& group : result) {
        cout << "[ ";
        for (const string& str : group) {
            cout << str << " ";
        }
        cout << "] ";
    }
    cout << endl;

    cout << "Test Passed: " << (compareResult(result, testCase.expected) ? "Yes" : "No") << endl;
    cout << "--------------------------------------------" << endl;
}

int main() {
    // 定义测试用例
    vector<TestCase> testCases = {
        {{"eat", "tea", "tan", "ate", "nat", "bat"}, {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}}, "Basic test case"},
        {{"abc", "cba", "bca", "abcd", "dcba"}, {{"abc", "cba", "bca"}, {"abcd", "dcba"}}, "Test with different lengths"},
        {{"", ""}, {{"", ""}}, "Test with empty strings"},
        {{"a"}, {{"a"}}, "Test with single character string"}
    };

    // 运行测试用例
    for (TestCase& testCase : testCases) {
        vector<vector<string>> result = groupAnagrams(testCase.input);
        printTestResult(testCase, result);
    }

    return 0;
}

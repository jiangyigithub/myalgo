#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
// {{"eat", "tea", "tan", "ate", "nat", "bat"}, {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}}, "Basic test case"},

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ret;
    unordered_map<string,vector<string>> hashMap;
    for(auto str:strs){
        string key=str;
        sort(key.begin(),key.end());
        hashMap[key].push_back(str);
    }

    for (const auto& pair : hashMap) {
        ret.push_back(pair.second);
    }

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

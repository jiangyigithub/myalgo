#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

string minWindowSubstring(string S, string T)
{
    // 如果 T 为空串，则直接返回空串
    if (T.empty())
        return "";
    // 统计 T 中每个字符的出现次数
    unordered_map<char, int> tFreq;
    // 当前窗口中各字符的出现次数统计
    unordered_map<char, int> windowCounts;
    for (char c : T)
    {
        tFreq[c]++;
    }
    // T 中不同字符的总数
    int required = tFreq.size();
    // 已经在当前窗口中满足要求的字符数目,formed == required表示
    int formed = 0;

    // 滑动窗口的左右边界及最小子串的起始位置和长度
    int left = 0, right = 0;
    int minLength = INT_MAX;
    int start = -1, end = -1;

    // 右边界向右移动，直到遍历完整个字符串 S
    for (right = 0; right < S.size(); ++right)
    {
        char c = S[right];
        windowCounts[c]++; // 增加当前字符在窗口中的计数

        // 如果当前字符是 T 中的字符，并且窗口中该字符的计数达到了 T 中该字符的要求
        if (tFreq.find(c) != tFreq.end() && windowCounts[c] == tFreq[c])
        {
            formed++; // 已满足要求的字符数加一
        }

        /// step 3：滑动窗口收缩和更新最小子串
        while (left <= right && formed == required)
        {
            c = S[left];

            // 更新最小子串的起始位置和长度
            if (right - left + 1 < minLength)
            {
                minLength = right - left + 1;
                start = left;
                end = right;
            }

            windowCounts[c]--; // 移动左边界，减少左边界字符在窗口中的计数

            // 如果移除的是 T 中的字符，并且窗口中该字符的计数小于 T 中该字符的要求，则不再满足要求
            if (tFreq.find(c) != tFreq.end() && windowCounts[c] < tFreq[c])
            {
                formed--; // 已满足要求的字符数减一
            }

            left++; // 缩小窗口，移动左边界
        }
    }

    // 如果 minLength 没有被更新过，说明没有找到符合要求的子串，返回空串；否则返回最小子串
    if (minLength == INT_MAX)
    {
        return "";
    }
    else
    {
        return S.substr(start, minLength);
    }
}

// 其中chars 表示目前每个字符缺少的数量，flag 表示每个字符是否在T 中存在
string minWindow(string S, string T)
{
    vector<int> chars(128, 0);
    vector<bool> flag(128, false);
    // 先统计T中的字符情况
    for (int i = 0; i < T.size(); ++i)
    {
        flag[T[i]] = true;
        ++chars[T[i]];
    }
    // 移动滑动窗口，不断更改统计数据
    int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
    for (int r = 0; r < S.size(); ++r)
    {
        if (flag[S[r]])
        {
            if (--chars[S[r]] >= 0)
            {
                ++cnt;
            }
            // 若目前滑动窗口已包含T中全部字符，
            // 则尝试将l右移，在不影响结果的情况下获得最短子字符串
            while (cnt == T.size())
            {
                if (r - l + 1 < min_size)
                {
                    min_l = l;
                    min_size = r - l + 1;
                }
                if (flag[S[l]] && ++chars[S[l]] > 0)
                {
                    --cnt;
                }
                ++l;
            }
        }
    }
    return min_size > S.size() ? "" : S.substr(min_l, min_size);
}

string minWindow2(string S, string T)
{
    unordered_map<char, int> chars;
    unordered_map<char, bool> flag;

    // 先统计T中的字符情况
    for (char c : T)
    {
        flag[c] = true;
        ++chars[c];
    }

    // 移动滑动窗口，不断更改统计数据
    int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;

    for (int r = 0; r < S.size(); ++r)
    {
        if (flag[S[r]])
        {
            if (--chars[S[r]] >= 0)
            {
                ++cnt;
            }

            // 若目前滑动窗口已包含T中全部字符，
            // 则尝试将l右移，在不影响结果的情况下获得最短子字符串
            while (cnt == T.size())
            {
                if (r - l + 1 < min_size)
                {
                    min_l = l;
                    min_size = r - l + 1;
                }
                if (flag[S[l]] && ++chars[S[l]] > 0)
                {
                    --cnt;
                }
                ++l;
            }
        }
    }

    return min_size > S.size() ? "" : S.substr(min_l, min_size);
}

// 测试用例结构体
struct TestCase
{
    string S;
    string T;
    string expected;
};

void runTestCases()
{
    vector<TestCase> testCases = {
        {"ADOBECODEBANC", "ABC", "BANC"},
        {"a", "a", "a"},
        {"a", "aa", ""},
        {"", "a", ""},
        {"a", "", ""},
        {"aa", "aa", "aa"},
        {"abcdefgh", "hgfedcba", "abcdefgh"},
        {"ADOBECODEBANCCODE", "ABC", "BANC"}};

    for (size_t i = 0; i < testCases.size(); ++i)
    {
        const TestCase &testCase = testCases[i];
        string result = minWindowSubstring(testCase.S, testCase.T);
        cout << "Test case " << i + 1 << ": expected = \"" << testCase.expected << "\", got = \"" << result << "\"";
        if (result == testCase.expected)
        {
            cout << " [PASSED]" << endl;
        }
        else
        {
            cout << " [FAILED]" << endl;
        }
    }
}

int main()
{
    runTestCases();
    return 0;
}

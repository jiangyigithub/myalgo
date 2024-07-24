#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<string> findSubstrings(string S, string T)
{
    vector<string> substrings; // 用于存储所有包含 T 的子串

    if (T.size() > S.size())
        return substrings; // 如果 T 的长度大于 S 的长度，直接返回空结果

    unordered_map<char, int> tFreq;
    for (char c : T)
    {
        tFreq[c]++;
    }

    int required = tFreq.size();
    unordered_map<char, int> windowCounts;

    int left = 0, right = 0;
    int formed = 0;

    for (right = 0; right < S.size(); ++right)
    {
        char c = S[right];
        windowCounts[c]++;

        if (tFreq.find(c) != tFreq.end() && windowCounts[c] == tFreq[c])
        {
            formed++;
        }

        while (left <= right && formed == required)
        {
            // 当窗口中已经包含了所有 T 中的字符时，找到一个包含 T 的子串
            if (right - left + 1 >= T.size())
            { // 确保子串长度至少为 T 的长度
                substrings.push_back(S.substr(left, right - left + 1));
            }

            c = S[left];
            windowCounts[c]--;

            if (tFreq.find(c) != tFreq.end() && windowCounts[c] < tFreq[c])
            {
                formed--;
            }

            left++;
        }
    }

    return substrings;
}

int main()
{
    string S = "ADOBECODEBANC";
    string T = "ABC";

    vector<string> result = findSubstrings(S, T);
    cout << "Substrings containing T:" << endl;
    int minLen = INT_MAX;
    for (const auto &substr : result)
    {
        cout << substr << endl;
        // if(substr.length()<minLen){
        //     minLen = substr.length();
        // }
        minLen = min(static_cast<int>(substr.length()), minLen);

    }
    cout<<minLen<<endl;

    return 0;
}
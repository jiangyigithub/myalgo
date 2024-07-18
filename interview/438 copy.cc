#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
struct TestCase
{
    std::string s;
    std::string p;
    std::vector<int> expected;
    std::vector<int> actual;
    bool passed;

    TestCase(std::string s, std::string p, std::vector<int> expected)
        : s(s), p(p), expected(expected), passed(false) {}
};

vector<int> findAnagrams2(string s, string p)
{
    vector<int> res;
    int len = p.size();
    int n = s.size();
    vector<int> pCount(26, 0);
    vector<int> sCount(26, 0);
    for (auto ch : p)
    {
        int temp = ch - 'a';
        pCount[temp]++;
    }
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        int temp = s[right] - 'a';
        while (sCount[temp] > pCount[temp])
        {
            int l_digit = s[left] - 'a';
            sCount[left]--;
            left++;
        }

        sCount[temp]++;
        if (right - left + 1 == len)
        {
            res.push_back(left);
        }
    }

    return res;
}

void runTestCases()
{
    std::vector<TestCase> testCases = {
        TestCase("cbaebabacd", "abc", {0, 6}),
        TestCase("abab", "ab", {0, 1, 2}),
        TestCase("af", "be", {}),
        TestCase("a", "a", {0}),
        TestCase("aaaaaaaaaa", "aaaaa", {0, 1, 2, 3, 4, 5})};

    for (auto &testCase : testCases)
    {
        testCase.actual = findAnagrams2(testCase.s, testCase.p);
        testCase.passed = (testCase.actual == testCase.expected);

        std::cout << "Test case - s: \"" << testCase.s << "\", p: \"" << testCase.p << "\"\n";
        std::cout << "Expected: [ ";
        for (int index : testCase.expected)
        {
            std::cout << index << " ";
        }
        std::cout << "], Actual: [ ";
        for (int index : testCase.actual)
        {
            std::cout << index << " ";
        }
        std::cout << "], Result: " << (testCase.passed ? "Passed" : "Failed") << "\n\n";
    }
}

int main()
{
    runTestCases();
    return 0;
}

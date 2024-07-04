#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TestCase {
    vector<vector<int>> input;
    vector<vector<int>> expected;
};

vector<vector<int>> mergeSegments(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    if(intervals.empty()){
        return result;
    }
    // Step 1: Sort intervals based on the start time
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});

    result.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); ++i){
        bool isOverlap = (intervals[i][0] <= result.back()[1]);
        if(isOverlap){
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}

int main()
{
    TestCase testCases[] = {
        // Test Case 1: Merging intervals with multiple overlaps.
        {{{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}},
        // Test Case 2: No overlaps.
        {{{1, 2}, {3, 4}, {5, 6}}, {{1, 2}, {3, 4}, {5, 6}}},
        // Test Case 3: All intervals overlap.
        {{{1, 4}, {2, 5}, {3, 6}}, {{1, 6}}},
        // Test Case 4: Single interval.
        {{{1, 4}}, {{1, 4}}},
        // Test Case 5: Intervals with one containing another.
        {{{1, 10}, {2, 3}, {4, 8}}, {{1, 10}}}
    };

    for (int i = 0; i < sizeof(testCases) / sizeof(TestCase); ++i)
    {
        vector<vector<int>> result = mergeSegments(testCases[i].input);
        cout << "Test case " << i + 1 << ": expected = ";
        for (const auto &seg : testCases[i].expected)
        {
            cout << "[" << seg[0] << ", " << seg[1] << "] ";
        }
        cout << ", got = ";
        for (const auto &seg : result)
        {
            cout << "[" << seg[0] << ", " << seg[1] << "] ";
        }
        
        if (result == testCases[i].expected) {
            cout << " [PASSED]" << endl;
        } else {
            cout << " [FAILED]" << endl;
        }
    }

    return 0;
}

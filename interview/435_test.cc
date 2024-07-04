#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Greedy strategy: prioritize keeping intervals that end earlier and do not overlap.
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return 0;
    }
    
    // Step 1: Sort intervals by ending time
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    vector<int> prev = intervals[0];
    int removed = 0;

    for (int i = 1; i < intervals.size(); ++i) {
        // Check for overlap
        if (intervals[i][0] < prev[1]) {
            removed++;
        } else {
            prev = intervals[i];
        }
    }
    
    return removed;
}

struct TestCase {
    vector<vector<int>> intervals;
    int expected;
};

int main() {
    TestCase testCases[] = {
        {{{1, 2}, {3, 4}, {5, 6}}, 0},                   // Test case 1: No intervals overlap
        {{{1, 3}, {1, 3}, {1, 3}}, 2},                   // Test case 2: All intervals completely overlap
        {{{1, 2}, {2, 3}, {3, 4}, {1, 3}}, 1},           // Test case 3: Partial overlap with one interval
        {{{1, 2}, {1, 3}, {2, 4}, {3, 5}, {2, 3}}, 2},   // Test case 4: Mixed overlap
        {{{1, 10}}, 0}                                 // Test case 5: Single interval
    };

    for (size_t i = 0; i < sizeof(testCases) / sizeof(TestCase); ++i) {
        int result = eraseOverlapIntervals(testCases[i].intervals);
        
        cout << "Test case " << i + 1 << ": expected = " << testCases[i].expected << ", got = " << result;
        
        if (result == testCases[i].expected) {
            cout << " [PASSED]" << endl;
        } else {
            cout << " [FAILED]" << endl;
        }
    }

    return 0;
}

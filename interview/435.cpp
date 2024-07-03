#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Greedy strategy: prioritize keeping intervals that end earlier and do not overlap.
int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    // If there are no intervals, there's nothing to remove
    if (intervals.empty())
    {
        return 0;
    }

    // Sort intervals by their end time
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    });

    int removed = 0;                // Count of removed intervals
    vector<int> prev = intervals[0]; // Track the last interval that was kept

    // Iterate through the intervals starting from the second one
    for (int i = 1; i < intervals.size(); ++i)
    {
        // If the current interval starts before the previous one ends, it overlaps
        if (intervals[i][0] < prev[1])
        {
            ++removed; // Increment the count of removed intervals
        }
        else
        {
            // Update prev to the current interval as it does not overlap
            prev = intervals[i];
        }
    }

    return removed;
}

int main() {
  vector<vector<int>> testCases[] = {
        {{1, 2}, {3, 4}, {5, 6}},                // Test case 1: No intervals overlap
        {{1, 3}, {1, 3}, {1, 3}},                // Test case 2: All intervals completely overlap
        {{1, 2}, {2, 3}, {3, 4}, {1, 3}},        // Test case 3: Partial overlap with one interval
        {{1, 2}, {1, 3}, {2, 4}, {3, 5}, {2, 3}},// Test case 4: Mixed overlap
        {{1, 10}}                                // Test case 5: Single interval
    };

    for (int i = 0; i < 5; ++i) {
        cout << "Test case " << i + 1 << ": " << eraseOverlapIntervals(testCases[i]) << endl;
    }

    return 0;
}

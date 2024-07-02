#include <vector>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    if (intervals.empty())
    {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
        { return a[1] < b[1]; });
    int removed = 0, prev = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i][0] < prev)
        {
            ++removed;
        }
        else
        {
            prev = intervals[i][1];
        }
    }
    return removed;
}
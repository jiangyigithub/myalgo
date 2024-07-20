#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeSegments(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    if (intervals.empty())
    {
        return result; // 区间集合为空直接返回
    }

    // 按照区间的左边界进行排序
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    result.push_back(intervals[0]); // 第一个区间可以直接放入结果集中
    int removed = 0;
    for (size_t i = 1; i < intervals.size(); ++i)
    {
        if (result.back()[1] >= intervals[i][0])
        { // 发现重叠区间
            // 合并区间,只需要更新结果集最后一个区间的右边界,因为根据排序,左边界已经是最小的
            result.back()[1] = max(result.back()[1], intervals[i][1]);
            removed++;
        }
        else
        {
            result.push_back(intervals[i]); // 区间不重叠
        }
    }
    cout << "remove = " << removed <<endl;
    return result;
}

int main()
{

    vector<vector<int>> testCases[] = {
        // Test Case 1: Merging intervals with multiple overlaps.
        {{1, 3}, {2, 6}, {8, 10}, {15, 18}},
        // Test Case 2: Intervals that touch but do not overlap.
        {{1, 4}, {4, 5}},
        // Test Case 3: One interval completely within another.
        {{1, 4}, {2, 3}},
        // Test Case 4: Overlapping and non-overlapping mixed intervals.
        {{1, 5}, {2, 3}, {4, 6}},
        // Test Case 5: No intervals overlap.
        {{1, 2}, {3, 4}, {5, 6}},
        // Test Case 6: Mixed overlap and non-overlap scenarios.
        {{1, 10}, {2, 6}, {8, 10}, {15, 18}}};
    for (int i = 0; i < 6; ++i)
    {
        vector<vector<int>> merged = mergeSegments(testCases[i]);
        cout << "Test case " << i + 1 << ": " << "拼接后的线段：";
        for (const auto &seg : merged)
        {
            cout << "[" << seg[0] << ", " << seg[1] << "] ";
        }
        cout << endl;
    }

    return 0;
}

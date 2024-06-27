#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeSegments(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    if (intervals.empty()) {
        return result;  // 区间集合为空直接返回
    }

    // 按照区间的左边界进行排序
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    result.push_back(intervals[0]);  // 第一个区间可以直接放入结果集中

    for (size_t i = 1; i < intervals.size(); ++i) {
        if (result.back()[1] >= intervals[i][0]) {  // 发现重叠区间
            // 合并区间，只需要更新结果集最后一个区间的右边界，因为根据排序，左边界已经是最小的
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } else {
            result.push_back(intervals[i]);  // 区间不重叠
        }
    }

    return result;
}

int main() {
    vector<vector<int>> segments = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = mergeSegments(segments);

    cout << "拼接后的线段：";
    for (const auto& seg : merged) {
        cout << "[" << seg[0] << ", " << seg[1] << "] ";
    }
    cout << endl;

    return 0;
}

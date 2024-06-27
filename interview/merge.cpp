#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> mergeSegments(vector<pair<int, int>>& segments) {
    sort(segments.begin(), segments.end());

    vector<pair<int, int>> mergedSegments;
    int start = segments[0].first;
    int end = segments[0].second;

    // 遍历所有线段，检查相邻的线段是否可以合并
    for (size_t i = 1; i < segments.size(); ++i) {
        int seg_start = segments[i].first;
        int seg_end = segments[i].second;

        // 如果当前线段的起始点在前一个线段的终点之后，则不能合并，将前一个线段添加到结果中
        if (seg_start > end) {
            mergedSegments.push_back({start, end});
            start = seg_start;
            end = seg_end;
        } else {
            // 如果可以合并，则更新合并后的终点
            end = max(end, seg_end);
        }
    }

    // 添加最后一个合并后的线段
    mergedSegments.push_back({start, end});

    return mergedSegments;
}

int main() {
    vector<pair<int, int>> segments = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<pair<int, int>> merged = mergeSegments(segments);

    cout << "拼接后的线段：";
    for (const auto& seg : merged) {
        cout << "(" << seg.first << ", " << seg.second << ") ";
    }
    cout << endl;

    return 0;
}

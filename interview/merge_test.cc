#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeSegments(vector<vector<int>> &intervals)
{
    vector<vector<int>> result;
    if(intervals.empty()){
        return result;
    }
    ///step 1 sort 
    sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){return a[0]<b[0];});

    result.push_back(intervals[0]);
    for(int i=1;i<intervals.size();++i){
        bool isOverlap = (intervals[i][0]<result.back()[1]);
        if(isOverlap){
            result.back()[1] = max(result.back()[1],intervals[i][1]);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}

int main()
{

    vector<vector<int>> testCases[] = {
        // Test Case 1: Merging intervals with multiple overlaps.
        {{1, 3}, {2, 6}, {8, 10}, {15, 18}}};
    for (int i = 0; i < 1; ++i)
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

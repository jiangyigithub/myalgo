#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Greedy strategy: prioritize keeping intervals that end earlier and do not overlap.
int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
 if(intervals.empty()){
    return 0;
 }
/// step 1. sort by right boundry 0 1 2 3
sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){return a[1]<b[1];});
 vector<int> prev = intervals[0];
 int removed = 0;

 for(int i=1;i<intervals.size();++i){
    /// check overlap
    if(intervals[i][0] < prev[1]){
        removed++;
    }
    /// update prev
    else{
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

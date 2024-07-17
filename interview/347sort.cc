#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>


using namespace std;

// Struct to store a test case
struct TestCase {
    vector<int> nums;
    int k;
    vector<int> expected;
};

// Function to find top k frequent elements
vector<int> topKFrequent(const vector<int>& nums, int k) {
    // Step 1: Count frequency of each element
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }
    
    // Step 2: Use a min heap to maintain top k frequent elements
    auto compare = [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second; // Min heap based on frequency
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);
    
    for (auto& entry : freqMap) {
        minHeap.push(entry);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    // Step 3: Extract elements from heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }


    
    // Reverse the result because we want descending order of frequency
    reverse(result.begin(), result.end());
    
    return result;
}

// Function to run test cases and print results
void runTests(const vector<TestCase>& testCases) {
    int passed = 0;
    for (int i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        vector<int> result = topKFrequent(testCase.nums, testCase.k);
        
        bool pass = (result == testCase.expected);
        
        cout << "Test Case " << i + 1 << ":" << endl;
        cout << "Input: nums = [";
        for (int j = 0; j < testCase.nums.size(); ++j) {
            cout << testCase.nums[j];
            if (j < testCase.nums.size() - 1) {
                cout << ", ";
            }
        }
        cout << "], k = " << testCase.k << endl;
        
        cout << "Expected: [";
        for (int j = 0; j < testCase.expected.size(); ++j) {
            cout << testCase.expected[j];
            if (j < testCase.expected.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
        
        cout << "Actual: [";
        for (int j = 0; j < result.size(); ++j) {
            cout << result[j];
            if (j < result.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
        
        cout << "Pass: " << (pass ? "Yes" : "No") << endl;
        cout << endl;
        
        if (pass) {
            passed++;
        }
    }
    
    cout << "Passed " << passed << " out of " << testCases.size() << " test cases." << endl;
}

int main() {
    // Define test cases
    vector<TestCase> testCases = {
        {{1, 1, 1, 2, 2, 3}, 2, {1, 2}},
        {{1}, 1, {1}},
        {{4, 4, 4, 4, 2, 2, 3, 3, 1}, 3, {4, 2, 3}}
    };
    
    // Run tests
    runTests(testCases);
    
    return 0;
}

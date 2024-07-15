#include <iostream>
#include <queue>
#include <vector>
#include <cmath> // for fabs function to compare floating-point numbers

using namespace std;

class MedianFinder {
public:
    // Max-heap to store the smaller half of the numbers
    priority_queue<int> maxHeap;
    // Min-heap to store the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Adds a number into the data structure.
    void addNum(int num) {
        maxHeap.push(num);
        
        if (!maxHeap.empty() && !minHeap.empty() && (maxHeap.top() > minHeap.top())) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    MedianFinder medianFinder;
    
    for (int num : nums1) {
        medianFinder.addNum(num);
    }
    for (int num : nums2) {
        medianFinder.addNum(num);
    }
    
    return medianFinder.findMedian();
}

// Structure to store test cases
struct TestCase {
    vector<int> nums1;
    vector<int> nums2;
    double expected;
};

void runTestCases(vector<TestCase>& testCases) {
    for (const auto& testCase : testCases) {
        double result = findMedianSortedArrays(testCase.nums1, testCase.nums2);
        bool passed = fabs(result - testCase.expected) < 1e-6; // Using a small tolerance for floating-point comparison
        cout << "Test case: nums1 = [";
        for (size_t i = 0; i < testCase.nums1.size(); ++i) {
            cout << testCase.nums1[i];
            if (i != testCase.nums1.size() - 1) cout << ", ";
        }
        cout << "], nums2 = [";
        for (size_t i = 0; i < testCase.nums2.size(); ++i) {
            cout << testCase.nums2[i];
            if (i != testCase.nums2.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
        cout << "Expected: " << testCase.expected << ", Actual: " << result << ", Passed: " << (passed ? "Yes" : "No") << endl << endl;
    }
}

int main() {
    // Define test cases
    vector<TestCase> testCases = {
        {{1, 3}, {2}, 2.0},
        {{1, 2}, {3, 4}, 2.5},
        {{0, 0}, {0, 0}, 0.0},
        {{}, {1}, 1.0},
        {{2}, {}, 2.0}
    };

    // Run test cases
    runTestCases(testCases);

    return 0;
}

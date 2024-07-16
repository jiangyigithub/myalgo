#include <iostream>
#include <queue>
#include <vector>
#include <cmath> // for fabs function to compare floating-point numbers

using namespace std;
/*
 maxHeap        minHeap
+---------+    +---------+
|    3    |    |    4    |
|    2    |    |    5    |
|    1    |    |    6    |
+---------+    +---------+
*/

void printMaxHeap(priority_queue<int> maxHeap)
{
    cout << "MaxHeap: ";
    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
}

// Helper function to print a min-heap (priority_queue with greater<int>)
void printMinHeap(priority_queue<int, vector<int>, greater<int>> minHeap)
{
    cout << "MinHeap: ";
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}


class MedianFinder {
public:
    // Max-heap to store the smaller half of the numbers
    priority_queue<int> maxHeap;
    // Min-heap to store the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Adds a number into the data structure.
    void addNum(int num) {
        // Always push the new number into maxHeap first
        maxHeap.push(num);
        
        // Ensure the largest number in maxHeap is not greater than the smallest in minHeap
        if (!maxHeap.empty() && !minHeap.empty() && (maxHeap.top() > minHeap.top())) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        // Balance the sizes of the two heaps if necessary
        if (maxHeap.size() > minHeap.size() + 1) {
            // Move the top of maxHeap to minHeap to balance the sizes
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            // Move the top of minHeap to maxHeap to balance the sizes
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        // If maxHeap has more elements, the median is the top of maxHeap
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            // If both heaps are balanced, the median is the average of both tops
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};

// Function to find the median of two sorted arrays using MedianFinder class
double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
    MedianFinder medianFinder;
    
    // Add all elements from the first array to the median finder
    for (int num : nums1) {
        medianFinder.addNum(num);
    }
    // Add all elements from the second array to the median finder
    for (int num : nums2) {
        medianFinder.addNum(num);
    }
    
    printMaxHeap(medianFinder.maxHeap);
    printMinHeap(medianFinder.minHeap);
    // Return the median of the combined arrays
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

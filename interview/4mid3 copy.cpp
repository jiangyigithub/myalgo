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

// Helper function to print a max-heap (priority_queue)
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

class MedianFinder
{
public:
    priority_queue<int> maxNums;
    priority_queue<int, vector<int>, greater<int>> minNums;
    void add(int num)
    {
        maxNums.push(num);
        if (!maxNums.empty() && !minNums.empty() && (maxNums.top() > minNums.top()))
        {
            minNums.push(maxNums.top());
            maxNums.pop();
        }

        if (maxNums.size() - 1 > minNums.size())
        {
            minNums.push(maxNums.top());
            maxNums.pop();
        }
        else if (minNums.size() > maxNums.size())
        {
            maxNums.push(minNums.top());
            minNums.pop();
        }
    }
    double medium()
    {
        if (maxNums.size() > minNums.size())
        {
            return maxNums.top();
        }
        else
        {
            return (maxNums.top() + minNums.top()) / 2.0;
        }
    }
};

// Function to find the median of two sorted arrays using MedianFinder class
double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2)
{
    MedianFinder temp;
    for (int num : nums1)
    {
        temp.add(num);
    }
    for (int num : nums2)
    {
        temp.add(num);
    }

    printMaxHeap(temp.maxNums);
    printMinHeap(temp.minNums);
    return temp.medium();
}

// Structure to store test cases
struct TestCase
{
    vector<int> nums1;
    vector<int> nums2;
    double expected;
};

void runTestCases(vector<TestCase> &testCases)
{
    for (const auto &testCase : testCases)
    {
        double result = findMedianSortedArrays(testCase.nums1, testCase.nums2);
        bool passed = fabs(result - testCase.expected) < 1e-6; // Using a small tolerance for floating-point comparison
        cout << "Test case: nums1 = [";
        for (size_t i = 0; i < testCase.nums1.size(); ++i)
        {
            cout << testCase.nums1[i];
            if (i != testCase.nums1.size() - 1)
                cout << ", ";
        }
        cout << "], nums2 = [";
        for (size_t i = 0; i < testCase.nums2.size(); ++i)
        {
            cout << testCase.nums2[i];
            if (i != testCase.nums2.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
        cout << "Expected: " << testCase.expected << ", Actual: " << result << ", Passed: " << (passed ? "Yes" : "No") << endl
             << endl;
    }
}

int main()
{
    // Define test cases
    vector<TestCase> testCases = {
        {{1, 3}, {2}, 2.0},
        {{1, 2}, {3, 4}, 2.5},
        {{0, 0}, {0, 0}, 0.0},
        {{}, {1}, 1.0},
        {{2}, {}, 2.0}};

    // Run test cases
    runTestCases(testCases);

    return 0;
}

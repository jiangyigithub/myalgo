#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse
using namespace std;

// Function to reverse a portion of the array
void reverse(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

// Function to rotate the array to the right by k positions
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // Handle cases where k >= n
    if (k == 0) return; // No rotation needed

    // Step 1: Reverse the entire array
    reverse(nums, 0, n - 1);

    // Step 2: Reverse the first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse the remaining n - k elements
    reverse(nums, k, n - 1);
}

// Function to print the array
void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Define test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 4, 5, 6, 7},
        {-1, -100, 3, 99},
        {1, 2, 3}
    };
    vector<int> kValues = {3, 2, 4}; // Corresponding k values for each test case

    // Run test cases
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i];
        int k = kValues[i];
        rotate(nums, k);
        cout << "Input: ";
        printArray(testCases[i]);
        cout << "k = " << k << endl;
        cout << "Output: ";
        printArray(nums);
        cout << "-----------------------------" << endl;
    }

    return 0;
}

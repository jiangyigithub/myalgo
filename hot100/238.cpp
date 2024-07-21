#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ret;
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);
    leftMax[0] = 1;
    rightMax[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = leftMax[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = rightMax[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; ++i)
    {
        int temp = leftMax[i] * rightMax[i];
        ret.push_back(temp);
    }
    return ret;
}

// Function to calculate the product of all elements except the current one
vector<int> productExceptSelf2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> left_products(n, 1);  // Array to store left products
    vector<int> right_products(n, 1); // Array to store right products
    vector<int> answer(n);            // Result array

    // Calculate left products
    for (int i = 1; i < n; ++i)
    {
        left_products[i] = left_products[i - 1] * nums[i - 1];
    }

    // Calculate right products and populate the answer array
    int right_product = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        answer[i] = left_products[i] * right_product;
        right_product *= nums[i];
    }

    return answer;
}

// Function to print the array
void printArray(const vector<int> &arr)
{
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    // Define test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 4},
        {-1, 1, 0, -3},
        {5, 6, 7, 8, 9}};

    // Run test cases
    for (const auto &nums : testCases)
    {
        vector<int> result = productExceptSelf(nums);
        cout << "Input: ";
        printArray(nums);
        cout << "Output: ";
        printArray(result);
        cout << "-----------------------------" << endl;
    }

    return 0;
}

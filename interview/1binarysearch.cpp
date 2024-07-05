#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    // Example test cases
    std::vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target1 = 12;
    int target2 = 7;

    // Test case 1: Target value exists in the array
    int index1 = binary_search(arr, target1);
    if (index1 != -1) {
        std::cout << "Target value " << target1 << " found at index " << index1 << std::endl;
    } else {
        std::cout << "Target value " << target1 << " not found in the array" << std::endl;
    }

    // Test case 2: Target value does not exist in the array
    int index2 = binary_search(arr, target2);
    if (index2 != -1) {
        std::cout << "Target value " << target2 << " found at index " << index2 << std::endl;
    } else {
        std::cout << "Target value " << target2 << " not found in the array" << std::endl;
    }

    return 0;
}

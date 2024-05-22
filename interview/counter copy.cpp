#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Comparator function to sort pairs based on second value (frequency)
bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 2, 1, 4, 1, 1};
    std::unordered_map<int, int> frequencyMap;

    // Count occurrences of each element
    for (int num : nums) {
        frequencyMap[num]++;
    }

    // Move data to a vector of pairs to sort
    std::vector<std::pair<int, int>> frequencyVector;
    for (const auto& pair : frequencyMap) {
        frequencyVector.push_back(pair);
    }

    // Sort vector based on frequency
    std::sort(frequencyVector.begin(), frequencyVector.end(), compare);

    // Print sorted elements
    std::cout << "Element\tFrequency" << std::endl;
    for (const auto& elem : frequencyVector) {
        std::cout << elem.first << "\t" << elem.second << std::endl;
    }

    return 0;
}

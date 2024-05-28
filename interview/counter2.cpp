#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 2, 1, 4, 1, 1};
    std::unordered_map<int, int> frequencyMap;

    // Count occurrences of each element
    for (int num : numbers) {
        frequencyMap[num]++;
    }

    // Move data to a vector of pairs to sort
    std::vector<std::pair<int, int>> frequencyVector(frequencyMap.begin(), frequencyMap.end());

    // Sort vector based on frequency using lambda expression
    std::sort(frequencyVector.begin(), frequencyVector.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    });

    // Print sorted elements
    std::cout << "Element\tFrequency" << std::endl;
    for (const auto& elem : frequencyVector) {
        std::cout << elem.first << "\t" << elem.second << std::endl;
    }

    return 0;
}

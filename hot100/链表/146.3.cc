#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <string>
#include <utility> // for std::pair

// LRUCache class definition
class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> cache; // Stores key-value pairs
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map; // Maps key to list iterator

    // Move a key-value pair to the end of the list (mark as recently used)
    void moveToEnd(std::list<std::pair<int, int>>::iterator it) {
        cache.splice(cache.end(), cache, it);
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1; // Key not found
        }
        // Move the accessed key-value pair to the end
        moveToEnd(it->second);
        return it->second->second; // Return the value
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            // Key already exists, update the value and move it to the end
            it->second->second = value;
            moveToEnd(it->second);
        } else {
            // Key does not exist, insert the new key-value pair
            if (cache.size() >= capacity) {
                // Remove the least recently used element (front of the list)
                auto old = cache.front().first;
                cache.pop_front();
                map.erase(old);
            }
            cache.emplace_back(key, value);
            map[key] = --cache.end(); // Update the map with the new key-value pair
        }
    }
};

// TestCase structure definition
struct TestCase {
    std::vector<std::string> operations;
    std::vector<std::pair<int, int>> values; // Pair of (key, value) for put operations and (key, 0) for get operations
    std::vector<int> expected; // Expected results for get operations
};

// Function to run test case and print results
void run_test_case(const TestCase& test_case) {
    LRUCache cache(test_case.values[0].first); // Initialize cache with capacity

    std::vector<int> results;
    
    for (size_t i = 1; i < test_case.operations.size(); ++i) {
        const std::string& op = test_case.operations[i];
        const std::pair<int, int>& val = test_case.values[i];

        if (op == "put") {
            cache.put(val.first, val.second);
            results.push_back(-1); // put operations don't have results
        } else if (op == "get") {
            int result = cache.get(val.first);
            results.push_back(result);
        }
    }

    // Output detailed test information
    for (size_t i = 0; i < results.size(); ++i) {
        const std::string& op = test_case.operations[i + 1];
        const std::pair<int, int>& val = test_case.values[i + 1];
        int expected = test_case.expected[i];
        int actual = results[i];
        
        bool pass = (actual == expected);
        std::cout << "Test case step " << i + 1 << ": "
                  << "Operation = " << op << ", "
                  << "Value = (" << val.first << ", " << (op == "put" ? val.second : 0) << "), "
                  << "Expected = " << expected << ", "
                  << "Actual = " << actual << ", "
                  << "Status = " << (pass ? "PASS" : "FAIL") << std::endl;
    }
}

int main() {
    // Define test cases
    std::vector<TestCase> test_cases = {
        {
            {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"},
            {{2, 0}, {1, 1}, {2, 2}, {1, 0}, {3, 3}, {2, 0}, {4, 4}, {1, 0}, {3, 0}, {4, 0}},
            {0, -1, 1, -1, 3, 4}
        },
        {
            {"LRUCache", "put", "put", "get", "put", "put", "get", "get", "get"},
            {{2, 0}, {2, 1}, {3, 2}, {2, 0}, {4, 3}, {5, 4}, {2, 0}, {3, 0}, {4, 0}},
            {0, 1, -1, -1, 3, 4}
        },
        {
            {"LRUCache", "put", "get", "put", "get", "get"},
            {{1, 0}, {2, 1}, {2, 0}, {3, 2}, {2, 0}, {3, 0}},
            {0, 1, -1, 2}
        }
    };
    
    // Run all test cases
    for (size_t i = 0; i < test_cases.size(); ++i) {
        std::cout << "Running Test Case " << i + 1 << std::endl;
        run_test_case(test_cases[i]);
        std::cout << std::endl;
    }

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <string>
#include <utility> // for std::pair
using namespace std;
// LRUCache class definition

class Node
{
public:
    int key, value;
    Node *prev, *next;

    Node(int k = 0, int v = 0) : key(k), value(v) {}
};

class LRUCache
{
private:
    int capacity;
    Node *dummy; // 哨兵节点
    unordered_map<int, Node *> hashMap;

    // 删除一个节点（抽出一本书）
    void remove(Node *x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    // 在链表头添加一个节点（把一本书放在最上面）
    void push_front(Node *x)
    {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    /// @brief get_node 操作不会影响hashMap，通过key怎么找到节点
    /// @param key 
    /// @return 
    Node *get_node(int key)
    {
        if (hashMap.find(key) != hashMap.end())
        {
            auto node = hashMap[key]; // 有这本书
            // 更新双端队列
            remove(node);             // 把这本书抽出来
            push_front(node);         // 放在最上面
            return node;
        }
        return nullptr;
    }

public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node())
    {
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key)
    {
        auto node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value)
    {
        auto node = get_node(key);
        // 1. 有这本书更新值
        if (node)
        {                        // 有这本书
            node->value = value; // 更新 value
            return;
        }
        // 2. 没有这本书新建节点
        hashMap[key] = node = new Node(key, value); // 新书
        push_front(node); // 放在最上面
        // 3. 书太多了，删除老节点                         
        if (hashMap.size() > capacity)
        { 
            auto back_node = dummy->prev;
            hashMap.erase(back_node->key);
            remove(back_node); // 去掉最后一本书
            delete back_node;  // 释放内存
        }
    }
};

// class LRUCache {
// public:
//     LRUCache(int capacity) : cap(capacity) {
//     }

//     int get(int key) {
//         if (map.find(key) == map.end()) return -1;
//         auto key_value = *map[key];
//         cache.erase(map[key]);
//         cache.push_front(key_value);
//         map[key] = cache.begin();
//         return key_value.second;
//     }

//     void put(int key, int value) {
//         if (map.find(key) == map.end()) {
//             if (cache.size() == cap) {
//                 map.erase(cache.back().first);
//                 cache.pop_back();
//             }
//         }
//         else {
//             cache.erase(map[key]);
//         }
//         cache.push_front({key, value});
//         map[key] = cache.begin();
//     }
// private:
//     int cap;
//     list<pair<int, int>> cache;
//     unordered_map<int, list<pair<int, int>>::iterator> map;
// };


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

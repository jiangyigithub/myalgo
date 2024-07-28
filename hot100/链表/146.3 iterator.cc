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
    int key, val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v) {};
};
class LRUCache
{
private:
    Node *dummy;
    unordered_map<int, Node *> hashMap;
    int capacity;

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

    /// @brief 根据key找对应的node*,找到返回node*,找不到返回nullptr。该操作， 只更新双端队列的元素，hashMap不会有变化
    /// @param key 
    /// @return 
    Node *find_node(int key)
    {
        if (hashMap.find(key) != hashMap.end())
        {
            Node *node = hashMap[key];
            remove(node);
            push_front(node);
            return node;
        }
        return nullptr;
    }

public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node(0, 0))
    {
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key)
    {
        Node *node = find_node(key);
        if (node) 
            return node->val;
        return -1;
    }

    void put(int key, int value)
    {
        //
        Node *node = find_node(key);
        if (node)
        {
            node->val = value;
            return;
        }

        node = new Node(key, value);
        hashMap.insert({key, node}); // 哈希表
        push_front(node); //更新 双端队列
        if (hashMap.size() > capacity)
        {
            Node *end = dummy->prev;
            remove(end);
            hashMap.erase(end->key); //哈希表，根据键值删掉对应的node
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
struct TestCase
{
    std::vector<std::string> operations;
    std::vector<std::pair<int, int>> values; // Pair of (key, value) for put operations and (key, 0) for get operations
    std::vector<int> expected;               // Expected results for get operations
};

// Function to run test case and print results
void run_test_case(const TestCase &test_case)
{
    LRUCache cache(test_case.values[0].first); // Initialize cache with capacity

    std::vector<int> results;

    for (size_t i = 1; i < test_case.operations.size(); ++i)
    {
        const std::string &op = test_case.operations[i];
        const std::pair<int, int> &val = test_case.values[i];

        if (op == "put")
        {
            cache.put(val.first, val.second);
            results.push_back(-1); // put operations don't have results
        }
        else if (op == "get")
        {
            int result = cache.get(val.first);
            results.push_back(result);
        }
    }

    // Output detailed test information
    for (size_t i = 0; i < results.size(); ++i)
    {
        const std::string &op = test_case.operations[i + 1];
        const std::pair<int, int> &val = test_case.values[i + 1];
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

int main()
{
    // Define test cases
    std::vector<TestCase> test_cases = {
        {{"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"},
         {{2, 0}, {1, 1}, {2, 2}, {1, 0}, {3, 3}, {2, 0}, {4, 4}, {1, 0}, {3, 0}, {4, 0}},
         {0, -1, 1, -1, 3, 4}},
        {{"LRUCache", "put", "put", "get", "put", "put", "get", "get", "get"},
         {{2, 0}, {2, 1}, {3, 2}, {2, 0}, {4, 3}, {5, 4}, {2, 0}, {3, 0}, {4, 0}},
         {0, 1, -1, -1, 3, 4}},
        {{"LRUCache", "put", "get", "put", "get", "get"},
         {{1, 0}, {2, 1}, {2, 0}, {3, 2}, {2, 0}, {3, 0}},
         {0, 1, -1, 2}}};

    // Run all test cases
    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        std::cout << "Running Test Case " << i + 1 << std::endl;
        run_test_case(test_cases[i]);
        std::cout << std::endl;
    }

    return 0;
}

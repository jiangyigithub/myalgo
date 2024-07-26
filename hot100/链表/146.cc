#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <string>
#include <utility> // for std::pair

using namespace std;

class Node
{
public:
    int key, value;
    Node *prev, *next;

    Node(int k = 0, int v = 0) : key(k), value(v) {}
};
namespace ling
{
    class LRUCache;
}
class ling::LRUCache
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

    Node *get_node(int key)
    {
        if (hashMap.find(key) != hashMap.end())
        {
            auto node = hashMap[key]; // 有这本书
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
            // 1. Key already exists, update the value and move it to the end
            it->second->second = value;
            moveToEnd(it->second);
        } else {
            // 2. Key does not exist, insert the new key-value pair
            /// 3. 插入前判满
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
struct TestCase
{
    std::vector<std::string> operations;
    std::vector<std::pair<int, int>> values; // Pair of (key, value) for put operations and (key) for get operations
    std::vector<int> expected;               // Expected results for get operations
};

// Function to run test case and print results
void run_test_case(const TestCase &test_case)
{
    // LRUCache cache(test_case.values[0].first); // Initialize cache with capacity
    ling::LRUCache cache(test_case.values[0].first); // Initialize cache with capacity

    std::vector<int> results;
    size_t op_idx = 0;

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
    // Define test case
    TestCase test_case = {
        {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"},
        {{2, 0}, {1, 1}, {2, 2}, {1, 0}, {3, 3}, {2, 0}, {4, 4}, {1, 0}, {3, 0}, {4, 0}},
        {0, -1, 1, -1, 3, 4}};

    // Run test case
    run_test_case(test_case);

    return 0;
}

#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include <utility>
#include <unordered_map>
#include <list>

using namespace std;

// LRUCache 类定义
class LRUCache
{
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        auto it = cache.find(key);
        if (it == cache.end())
        {
            return -1; // key 不存在
        }
        else
        {
            // key 存在，将该节点移到链表头部（表示最近使用）
            data.splice(data.begin(), data, it->second);
            return it->second->second;
        }
    }

    void put(int key, int value)
    {
        auto it = cache.find(key);
        if (it != cache.end())
        {
            // key 存在，更新值并将节点移到链表头部
            it->second->second = value;
            data.splice(data.begin(), data, it->second);
        }
        else
        {
            // key 不存在，检查容量是否已满
            if (data.size() == capacity)
            {
                // 容量已满，移除链表尾部的节点（最久未使用）
                auto del = data.back();
                cache.erase(del.first);
                data.pop_back();
            }
            // 插入新的节点到链表头部
            data.emplace_front(key, value);
            cache[key] = data.begin();
        }
    }

private:
    int capacity;
    std::list<std::pair<int, int>> data;                                     // 存储缓存的键值对
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache; // 键到链表节点的映射
};

// 定义一个参数类型，可以是 `std::pair<int, int>` 或 `int`
using OperationParam = std::variant<std::pair<int, int>, int>;

// 测试用例结构体
struct TestCase
{
    std::string description;
    std::vector<std::pair<std::string, OperationParam>> operations; // 操作序列
    std::vector<int> expectedResults;                               // 预期结果
    std::vector<int> actualResults;                                 // 实际结果
    bool passed;                                                    // 测试是否通过

    TestCase(std::string desc, std::vector<std::pair<std::string, OperationParam>> ops, std::vector<int> expected)
        : description(desc), operations(ops), expectedResults(expected), passed(false) {}
};

// 辅助函数：执行测试用例
void runTestCase(LRUCache &lruCache, TestCase &testCase)
{
    testCase.actualResults.clear();
    for (const auto &op : testCase.operations)
    {
        if (op.first == "put")
        {
            auto param = std::get<std::pair<int, int>>(op.second);
            lruCache.put(param.first, param.second);
            testCase.actualResults.push_back(-1); // put 操作无返回值，用 -1 表示
        }
        else if (op.first == "get")
        {
            auto param = std::get<int>(op.second);
            int result = lruCache.get(param);
            testCase.actualResults.push_back(result);
        }
    }
    testCase.passed = (testCase.actualResults == testCase.expectedResults);
}

// 函数，用于运行并验证测试用例
void printTest(const TestCase &testCase)
{
    std::cout << "Description: " << testCase.description << std::endl;
    std::cout << "Operations:" << std::endl;

    for (const auto &operation : testCase.operations)
    {
        std::cout << "  " << operation.first << " (";
        if (std::holds_alternative<std::pair<int, int>>(operation.second))
        {
            auto param = std::get<std::pair<int, int>>(operation.second);
            std::cout << param.first << ", " << param.second;
        }
        else
        {
            auto param = std::get<int>(operation.second);
            std::cout << param;
        }
        std::cout << ")" << std::endl;
    }

    std::cout << "Expected Results:" << std::endl;
    for (const auto &result : testCase.expectedResults)
    {
        std::cout << "  " << result << std::endl;
    }

    // 模拟操作结果，并将结果存储在 actualResults 中
    for (const auto &operation : testCase.operations)
    {
        if (operation.first == "put")
        {
            auto param = std::get<std::pair<int, int>>(operation.second);
            std::cout << "Put (" << param.first << ", " << param.second << ")" << std::endl;
        }
        else if (operation.first == "get")
        {
            auto param = std::get<int>(operation.second);
            std::cout << "Get (" << param << ")" << std::endl;
            int simulatedResult = param; // 示例：直接将获取的值作为结果
            // testCase.actualResults.push_back(simulatedResult);
        }
    }

    // 检查实际结果是否与预期结果匹配
    bool passed = (testCase.actualResults == testCase.expectedResults);

    std::cout << "Actual Results:" << std::endl;
    for (const auto &result : testCase.actualResults)
    {
        std::cout << "  " << result << std::endl;
    }

    std::cout << "Test Passed: " << (passed ? "Yes" : "No") << std::endl;
}

int main()
{
    // 创建并运行临时的 TestCase 对象
    // 测试用例
    std::vector<TestCase> testCases = {
        TestCase(
            "Test Case 2",
            {{"put", std::make_pair(1, 1)}, {"put", std::make_pair(2, 2)}, {"put", std::make_pair(3, 3)}, {"get", 1}, {"put", std::make_pair(4, 4)}, {"get", 2}, {"get", 3}, {"get", 4}},
            {-1, -1, -1, -1, -1, -1, 3, 4})

    };

    for (auto &testCase : testCases)
    {
        LRUCache lruCache(2);
        runTestCase(lruCache, testCase);
    }

    printTest(TestCase(
        "Test Case 2",
        {{"put", std::make_pair(1, 1)}, {"put", std::make_pair(2, 2)}, {"put", std::make_pair(3, 3)}, {"get", 1}, {"put", std::make_pair(4, 4)}, {"get", 2}, {"get", 3}, {"get", 4}},
        {-1, -1, -1, -1, -1, -1, 3, 4}));

    return 0;
}

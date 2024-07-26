#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility> // for std::pair

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

// Solution class definition
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        // Create a hash map to store the mapping from original nodes to their copies
        std::unordered_map<Node *, Node *> map;
        Node *cur = head;

        // First pass: Create all new nodes and store them in the hash map
        // 1. 复制各节点，并建立 “原节点 -> 新节点” 的 Map 映射
        while (cur)
        {
            map[cur] = new Node(cur->val); // 复制值
            cur = cur->next;
        }

        // Second pass: Assign next and random pointers for the copied nodes
        // 2. 构建新链表的 next 和 random 指向
        cur = head;
        while (cur)
        {
            // {key,value} value->next = value 说明value是链表
            // randow 指针和next指针本质没有区别
            map[cur]->next = map[cur->next]; //复制next连接
            map[cur]->random = map[cur->random];//复制random连接
            cur = cur->next;
        }

        // Return the head of the copied list
        // 3. 返回新链表的头节点
        return map[head];
    }

    Node *copyRandomList2(Node *head)
    {
        if (!head)
            return nullptr;

        // Step 1: Insert copied nodes in between original nodes
        // 1. 复制各节点，并构建拼接链表
        Node *cur = head;
        while (cur)
        {
            Node *temp = new Node(cur->val);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }

        // Step 2: Assign random pointers for copied nodes
        cur = head;
        while (cur)
        {
            Node *copy = cur->next;
            copy->random = (cur->random) ? cur->random->next : nullptr;
            cur = copy->next;
        }

        // Step 3: Separate the original list from the copied list
        Node *newHead = head->next;
        Node *copyCurrent = newHead;
        cur = head;
        while (cur)
        {
            cur->next = copyCurrent->next;
            cur = cur->next;
            if (cur)
                copyCurrent->next = cur->next;
            copyCurrent = copyCurrent->next;
        }

        return newHead;
    }
};

// Structure to represent a test case
struct TestCase
{
    Node *head;                                       // Head of the original linked list
    std::vector<std::pair<int, int>> expected_values; // Expected values in the form (node value, random value)
};

// Helper function to print the list
void printList(Node *node)
{
    while (node)
    {
        std::cout << "Node(val: " << node->val;
        if (node->random)
        {
            std::cout << ", random: " << node->random->val << ")";
        }
        else
        {
            std::cout << ", random: NULL)";
        }
        std::cout << std::endl;
        node = node->next;
    }
}

// Helper function to convert a list to a vector of values
std::vector<std::pair<int, int>> convertListToVector(Node *node)
{
    std::vector<std::pair<int, int>> result;
    while (node)
    {
        result.emplace_back(node->val, node->random ? node->random->val : -1);
        node = node->next;
    }
    return result;
}

// Function to compare two vectors
bool compareVectors(const std::vector<std::pair<int, int>> &actual, const std::vector<std::pair<int, int>> &expected)
{
    if (actual.size() != expected.size())
        return false;
    for (size_t i = 0; i < actual.size(); ++i)
    {
        if (actual[i] != expected[i])
            return false;
    }
    return true;
}

// Function to run a test case and print results
void run_test_case(const TestCase &test_case, Solution &solution)
{
    // Copy the linked list
    Node *copiedList = solution.copyRandomList(test_case.head);

    // Convert the copied list to a vector of values
    std::vector<std::pair<int, int>> actual = convertListToVector(copiedList);

    // Print the actual copied list
    std::cout << "Copied list:" << std::endl;
    printList(copiedList);

    // Check if the result matches the expected values
    bool pass = compareVectors(actual, test_case.expected_values);

    // Print the detailed results
    std::cout << "Expected values:" << std::endl;
    for (const auto &p : test_case.expected_values)
    {
        std::cout << "(val: " << p.first << ", random: " << (p.second == -1 ? "NULL" : std::to_string(p.second)) << ")" << std::endl;
    }

    std::cout << "Actual values:" << std::endl;
    for (const auto &p : actual)
    {
        std::cout << "(val: " << p.first << ", random: " << (p.second == -1 ? "NULL" : std::to_string(p.second)) << ")" << std::endl;
    }

    std::cout << "Test case " << (pass ? "PASSED" : "FAILED") << std::endl;
}

int main()
{
    // Test case 1: Empty list
    TestCase test_case1 = {nullptr, {}};

    // Test case 2: Single node with no random pointer
    Node *head2 = new Node(1);
    TestCase test_case2 = {head2, {{1, -1}}};

    // Test case 3: Single node with a random pointer to itself
    Node *head3 = new Node(2);
    head3->random = head3;
    TestCase test_case3 = {head3, {{2, 2}}};

    // Test case 4: Multiple nodes with no random pointers
    Node *head4 = new Node(3);
    head4->next = new Node(4);
    head4->next->next = new Node(5);
    TestCase test_case4 = {head4, {{3, -1}, {4, -1}, {5, -1}}};

    // Test case 5: Multiple nodes with random pointers
    Node *head5 = new Node(6);
    head5->next = new Node(7);
    head5->next->next = new Node(8);
    head5->next->next->next = new Node(9);
    head5->random = head5->next->next;
    head5->next->random = head5;
    head5->next->next->random = head5->next->next->next;
    head5->next->next->next->random = head5->next;
    TestCase test_case5 = {
        head5,
        {{6, 8}, {7, 6}, {8, 9}, {9, 7}}};

    // Initialize Solution object
    Solution sol;

    // Run all test cases
    std::vector<TestCase> test_cases = {test_case1, test_case2, test_case3, test_case4, test_case5};
    for (size_t i = 0; i < test_cases.size(); ++i)
    {
        std::cout << "Running Test Case " << i + 1 << std::endl;
        run_test_case(test_cases[i], sol);
        std::cout << std::endl;
    }

    // Free allocated memory (not shown here for simplicity)
    return 0;
}

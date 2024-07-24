

#include <iostream>
#include <unordered_set>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class with the findCycleStart method
class Solution
{
public:
    ListNode *findCycleStart2(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                while (slow != head)
                {
                    slow = slow->next;
                    head = head->next;
                }
                return slow;
            }
        }
        return nullptr;
    }

    ListNode *findCycleStart(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        // Detect if there is a cycle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                // Cycle detected, find the start of the cycle
                ListNode *start = head;
                while (start != slow)
                {
                    start = start->next;
                    slow = slow->next;
                }
                return start; // Start of the cycle
            }
        }
        return nullptr; // No cycle
    }
};

// Helper function to create a cycle in the linked list
void createCycle(ListNode *head, int pos)
{
    if (pos == -1)
        return; // No cycle
    ListNode *cycleNode = nullptr, *tail = head;
    int index = 0;
    while (tail->next)
    {
        if (index == pos)
            cycleNode = tail;
        tail = tail->next;
        index++;
    }
    tail->next = cycleNode; // Create cycle
}

// Function to delete a linked list (to avoid memory leaks)
void deleteList(ListNode *head)
{
    std::unordered_set<ListNode *> nodes;
    while (head && nodes.find(head) == nodes.end())
    {
        nodes.insert(head);
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

// Structure to hold test cases
struct TestCase
{
    ListNode *head;     // Head of the linked list
    ListNode *expected; // Expected result for findCycleStart
};

// Function to print test case results
void printTestCase(const TestCase &testCase)
{
    Solution solution;
    ListNode *result = solution.findCycleStart(testCase.head);
    bool pass = (result == testCase.expected);

    std::cout << "Expected: " << (testCase.expected ? std::to_string(testCase.expected->val) : "null")
              << ", Actual: " << (result ? std::to_string(result->val) : "null")
              << ", Test " << (pass ? "Passed" : "Failed")
              << std::endl;
}

// Main function to run all test cases
int main()
{
    // Define test cases
    TestCase testCases[] = {
        // Test case 1: No cycle
        {
            new ListNode(1),
            nullptr},
        // Test case 2: Cycle starting at position 1
        {
            new ListNode(1),
            nullptr},
        // Test case 3: Cycle starting at position 0
        {
            new ListNode(1),
            nullptr},
        // Test case 4: Single node, no cycle
        {
            new ListNode(1),
            nullptr},
        // Test case 5: Single node, cycle
        {
            new ListNode(1),
            nullptr}};

    // Manually setup each test case
    // Test case 1
    testCases[0].head->next = new ListNode(2);
    // Test case 2
    testCases[1].head->next = new ListNode(2);
    testCases[1].head->next->next = new ListNode(3);
    createCycle(testCases[1].head, 1);
    testCases[1].expected = testCases[1].head->next; // Node with value 2
    // Test case 3
    testCases[2].head->next = new ListNode(2);
    createCycle(testCases[2].head, 0);
    testCases[2].expected = testCases[2].head; // Node with value 1
    // Test case 4
    // Already set up correctly
    // Test case 5
    createCycle(testCases[4].head, 0);
    testCases[4].expected = testCases[4].head; // Node with value 1

    // Print results for all test cases
    for (const auto &testCase : testCases)
    {
        printTestCase(testCase);
        deleteList(testCase.head); // Clean up memory
    }

    return 0;
}

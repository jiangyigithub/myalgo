#include <iostream>
#include <unordered_set>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class with the hasCycle method
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head; // Initialize slow and fast pointers
        while (fast && fast->next) {
            slow = slow->next; // Move slow pointer by one step
            fast = fast->next->next; // Move fast pointer by two steps
            if (fast == slow) // Cycle detected
                return true;
        }
        return false; // No cycle
    }
};

// Helper function to create a cycle in the linked list
void createCycle(ListNode *head, int pos) {
    if (pos == -1) return; // No cycle
    ListNode *cycleNode = nullptr, *tail = head;
    int index = 0;
    while (tail->next) {
        if (index == pos) cycleNode = tail;
        tail = tail->next;
        index++;
    }
    tail->next = cycleNode; // Create cycle
}

// Function to delete a linked list (to avoid memory leaks)
void deleteList(ListNode* head) {
    std::unordered_set<ListNode*> nodes;
    while (head && nodes.find(head) == nodes.end()) {
        nodes.insert(head);
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Structure to hold test cases
struct TestCase {
    ListNode* head; // Head of the linked list
    bool expected;  // Expected result for hasCycle
};

// Function to print test case results
void printTestCase(const TestCase& testCase) {
    Solution solution;
    bool result = solution.hasCycle(testCase.head);
    std::cout << "Expected: " << (testCase.expected ? "true" : "false") 
              << ", Actual: " << (result ? "true" : "false") 
              << ", Test " << (result == testCase.expected ? "Passed" : "Failed") 
              << std::endl;
}

// Main function to run all test cases
int main() {
    // Define test cases
    TestCase testCases[] = {
        // Test case 1: No cycle
        { 
            new ListNode(3),
            false
        },
        // Test case 2: Cycle at position 1
        { 
            new ListNode(3),
            true
        },
        // Test case 3: Cycle at position 0
        { 
            new ListNode(1),
            true
        },
        // Test case 4: Single node, no cycle
        { 
            new ListNode(1),
            false
        },
        // Test case 5: Single node, cycle
        { 
            new ListNode(1),
            true
        }
    };

    // Manually setup each test case
    // Test case 1
    testCases[0].head->next = new ListNode(2);
    testCases[0].head->next->next = new ListNode(0);
    testCases[0].head->next->next->next = new ListNode(-4);
    // Test case 2
    testCases[1].head->next = new ListNode(2);
    testCases[1].head->next->next = new ListNode(0);
    testCases[1].head->next->next->next = new ListNode(-4);
    createCycle(testCases[1].head, 1);
    // Test case 3
    testCases[2].head->next = new ListNode(2);
    createCycle(testCases[2].head, 0);
    // Test case 4
    // Already set up correctly
    // Test case 5
    createCycle(testCases[4].head, 0);

    // Print results for all test cases
    for (const auto& testCase : testCases) {
        printTestCase(testCase);
        deleteList(testCase.head); // Clean up memory
    }

    return 0;
}

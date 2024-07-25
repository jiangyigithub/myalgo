#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode dummy;
    ListNode* current = &dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy.next;
}

// Function to convert a linked list to a vector
std::vector<int> linkedListToVector(ListNode* head) {
    std::vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Definition of the Solution class
class Solution {
public:
    // Static variable to keep track of the number of times sortList is called
    static int callCount;

    ListNode* sortList(ListNode* head) {
        callCount++;  // Increment the count each time sortList is called
        if (!head || !head->next) return head; // termination.

        // Cut the LinkedList at the mid index
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr; // Save and cut

        // Recursive sorting
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Merge left and right linked list and return it
        ListNode dummy;
        ListNode* h = &dummy;
        while (left && right) {
            if (left->val < right->val) {
                h->next = left;
                left = left->next;
            } else {
                h->next = right;
                right = right->next;
            }
            h = h->next;
        }
        h->next = left ? left : right;

        return dummy.next;
    }

    // Static method to get the call count
    // 增加一个符合函数记录 函数被递归调用几次
    static int getSortListCallCount() {
        return callCount;
    }
};

// Initialize the static variable
int Solution::callCount = 0;

// Structure to store test cases
struct TestCase {
    std::vector<int> input;
    std::vector<int> expected;
    std::vector<int> actual;
    bool passed;
};

// Function to run test cases
void runTestCases() {
    Solution solution;
    std::vector<TestCase> testCases = {
        {{4, 2, 1, 3}, {1, 2, 3, 4}}
        // ,
        // {{-1, 5, 3, 4, 0}, {-1, 0, 3, 4, 5}},
        // {{}, {}},
        // {{1}, {1}}
    };

    for (auto& testCase : testCases) {
        ListNode* inputList = createLinkedList(testCase.input);
        ListNode* result = solution.sortList(inputList);
        testCase.actual = linkedListToVector(result);
        testCase.passed = (testCase.actual == testCase.expected);
    }

    // Print test results
    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& testCase = testCases[i];
        std::cout << "Test Case " << (i + 1) << ":\n";
        std::cout << "Input: ";
        for (int val : testCase.input) std::cout << val << " ";
        std::cout << "\nExpected: ";
        for (int val : testCase.expected) std::cout << val << " ";
        std::cout << "\nActual: ";
        for (int val : testCase.actual) std::cout << val << " ";
        std::cout << "\nPassed: " << (testCase.passed ? "Yes" : "No") << "\n\n";
    }

    // Print the number of times sortList was called
    std::cout << "Number of times sortList was called: " << Solution::getSortListCallCount() << std::endl;
}

int main() {
    runTestCases();
    return 0;
}

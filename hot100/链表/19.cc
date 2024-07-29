#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
/*
快慢指针，一个先走，一个后走
n  len
0  len-n,还剩n步

删除节点用dummy
*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize two pointers
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move the first pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }
        
        // Move both pointers until the first pointer reaches the end
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // Delete the nth node from the end
        ListNode* nodeToDelete = second->next;
        second->next = nodeToDelete->next;  //等价为 second->next = second->next->next;
      
        delete nodeToDelete;
        
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* node) {
    while (node) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "nullptr" << endl;
}

// Helper function to convert a linked list to a vector
vector<int> linkedListToVector(ListNode* node) {
    vector<int> result;
    while (node) {
        result.push_back(node->val);
        node = node->next;
    }
    return result;
}

// Structure to store test cases
struct TestCase {
    vector<int> input;
    int n;
    vector<int> expectedOutput;
};

int main() {
    Solution solution;
    
    // Test cases
    vector<TestCase> testCases = {
        {{1, 2, 3, 4, 5}, 2, {1, 2, 3, 5}},
        {{1}, 1, {}},
        {{1, 2}, 1, {1}},
        {{1, 2}, 2, {2}},
        {{1, 2, 3, 4, 5}, 5, {2, 3, 4, 5}}
    };
    
    for (size_t i = 0; i < testCases.size(); ++i) {
        // Convert input vector to linked list
        ListNode* inputList = createLinkedList(testCases[i].input);
        
        // Get the actual output from the solution
        ListNode* updatedList = solution.removeNthFromEnd(inputList, testCases[i].n);
        vector<int> actualOutput = linkedListToVector(updatedList);
        
        // Check if the test passed
        bool passed = (actualOutput == testCases[i].expectedOutput);
        
        // Output the test case details
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Input: [";
        for (size_t j = 0; j < testCases[i].input.size(); ++j) {
            cout << testCases[i].input[j] << (j == testCases[i].input.size() - 1 ? "" : ", ");
        }
        cout << "] with n = " << testCases[i].n << "\nExpected Output: [";
        for (size_t j = 0; j < testCases[i].expectedOutput.size(); ++j) {
            cout << testCases[i].expectedOutput[j] << (j == testCases[i].expectedOutput.size() - 1 ? "" : ", ");
        }
        cout << "]\nActual Output: [";
        for (size_t j = 0; j < actualOutput.size(); ++j) {
            cout << actualOutput[j] << (j == actualOutput.size() - 1 ? "" : ", ");
        }
        cout << "]\nTest " << (passed ? "PASSED" : "FAILED") << "\n\n";
    }

    return 0;
}

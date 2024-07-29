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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* node1 = head;
        ListNode* node2 = head->next;
        ListNode* node3 = node2->next;
        
        node1->next = swapPairs(node3);
        node2->next = node1;
   
        
        return node2 ;
    }
    ListNode* swapPairs2(ListNode* head) {
        // Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize pointers
        ListNode* prev = dummy;
        ListNode* current = head;
        
        while (current != nullptr && current->next != nullptr) {
            // Identify the two nodes to be swapped
            ListNode* first = current;
            ListNode* second = current->next;
            
            // Swap the nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move the pointers forward
            prev = first;
            current = first->next;
        }
        
        return dummy->next;
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
    vector<int> expectedOutput;
};

int main() {
    Solution solution;
    
    // Test cases
    vector<TestCase> testCases = {
        {{1, 2, 3, 4}, {2, 1, 4, 3}},
        {{}, {}},
        {{1}, {1}},
        {{1, 2, 3}, {2, 1, 3}},
        {{1, 2, 3, 4, 5}, {2, 1, 4, 3, 5}}
    };
    
    for (size_t i = 0; i < testCases.size(); ++i) {
        // Convert input vector to linked list
        ListNode* inputList = createLinkedList(testCases[i].input);
        
        // Get the actual output from the solution
        ListNode* swappedList = solution.swapPairs(inputList);
        vector<int> actualOutput = linkedListToVector(swappedList);
        
        // Check if the test passed
        bool passed = (actualOutput == testCases[i].expectedOutput);
        
        // Output the test case details
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Input: [";
        for (size_t j = 0; j < testCases[i].input.size(); ++j) {
            cout << testCases[i].input[j] << (j == testCases[i].input.size() - 1 ? "" : ", ");
        }
        cout << "]\nExpected Output: [";
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

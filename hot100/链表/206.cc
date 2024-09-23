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
// 1->2->3->4->5

    ListNode* reverseList(ListNode* head) {
        ListNode* pre=nullptr,*cur=head;
        while(cur!=nullptr){
            ListNode * nxt = cur->next;
            cur->next = pre;
            pre=cur;
            cur=nxt;
        }
        return pre;
    }
};

// Structure to hold test cases
struct TestCase {
    ListNode *input;
    ListNode *expected;
};

// Function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int val : values) {
        ListNode *newNode = new ListNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to compare two lists
bool compareLists(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val != l2->val) {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
}

// Function to print a list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

// Function to run test cases
void runTests() {
    Solution solution;
    vector<TestCase> testCases;
    
    // Define test cases
    testCases.push_back({createList({1, 2, 3, 4, 5}), createList({5, 4, 3, 2, 1})});
    testCases.push_back({createList({1, 2}), createList({2, 1})});
    testCases.push_back({createList({}), createList({})});
    testCases.push_back({createList({1}), createList({1})});
    
    // Run tests and print results
    for (size_t i = 0; i < testCases.size(); ++i) {
        ListNode* result = solution.reverseList(testCases[i].input);
        cout << "Test case " << i + 1 << ":" << endl;
        cout << "Input list: ";
        printList(testCases[i].input);
        cout << "Expected reversed list: ";
        printList(testCases[i].expected);
        cout << "Actual reversed list: ";
        printList(result);
        bool passed = compareLists(result, testCases[i].expected);
        cout << (passed ? "Test Passed" : "Test Failed") << endl;
        cout << endl;
    }
}

int main() {
    runTests();
    return 0;
}

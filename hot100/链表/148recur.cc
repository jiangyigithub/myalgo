#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for test case
struct TestCase {
    ListNode* head;
    vector<int> expected; // Expected sorted values in a vector
};

// Function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to convert vector to linked list
ListNode* vectorToList(const vector<int>& vec) {
    if (vec.empty()) return nullptr;
    ListNode* head = new ListNode(vec[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vec.size(); ++i) {
        current->next = new ListNode(vec[i]);
        current = current->next;
    }
    return head;
}

// Function to convert linked list to vector
vector<int> listToVector(ListNode* head) {
    vector<int> vec;
    while (head) {
        vec.push_back(head->val);
        head = head->next;
    }
    return vec;
}

// Function to sort the linked list using Merge Sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) return head;
        ListNode* mid = getMiddle(head); // 中间靠左的为mid
        ListNode* left = head;
        ListNode* right = mid->next; //第二个链表的头节点
        mid->next = nullptr; //cut 第一个链表,第一个链表结尾指向nullptr

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }

private:
    // 找到链表的中间节点（慢指针到达的位置）
    ListNode* getMiddle(ListNode* head) {
        if (head==nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1) ? l1 : l2;
        return dummy->next;
    }
};

// Function to check if the linked list matches the expected result
bool checkResult(ListNode* head, const vector<int>& expected) {
    vector<int> result = listToVector(head);
    if (result.size() != expected.size()) return false;
    for (size_t i = 0; i < expected.size(); ++i) {
        if (result[i] != expected[i]) return false;
    }
    return true;
}

// Main function to run test cases
int main() {
    Solution sol;
    
    vector<TestCase> testCases = {
        { vectorToList({4, 2, 1, 3}), {1, 2, 3, 4} }
        // ,
        // { vectorToList({1, 2, 3, 4}), {1, 2, 3, 4} },
        // { vectorToList({4, 3, 2, 1}), {1, 2, 3, 4} },
        // { vectorToList({}), {} }  // Edge case: empty list
    };

    for (const auto& testCase : testCases) {
        ListNode* sortedList = sol.sortList(testCase.head);
        bool result = checkResult(sortedList, testCase.expected);
        
        cout << "Expected: ";
        for (int val : testCase.expected) cout << val << " ";
        cout << "\nActual:   ";
        printList(sortedList);
        cout << "Test " << (result ? "Passed" : "Failed") << endl;
        cout << "-----------------" << endl;
        
        // Free the allocated memory for sortedList
        while (sortedList) {
            ListNode* temp = sortedList;
            sortedList = sortedList->next;
            delete temp;
        }
    }
    
    return 0;
}

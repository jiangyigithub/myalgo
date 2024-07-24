#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
/*
有相交在交点相遇
无相交，等长都为nullptr,非等长，走完AB，都为nullptr
*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        ListNode *pA = headA;
        ListNode *pB = headB;

        // Traverse through the lists
        while (pA != pB)
        {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};

// Structure to hold test cases
struct TestCase
{
    ListNode *headA;
    ListNode *headB;
    ListNode *expected;
};

// Function to create a linked list from a vector and optionally return a specific node
ListNode *createList(const vector<int> &values, int intersectVal = -1, ListNode **intersectNode = nullptr)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int val : values)
    {
        ListNode *newNode = new ListNode(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        if (val == intersectVal)
        {
            *intersectNode = newNode;
        }
    }
    return head;
}

// Function to print a list
void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val;
        if (curr->next)
            cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

// Function to run test cases
void runTests()
{
    Solution solution;
    vector<TestCase> testCases;

    // Test case 1: intersecting lists
    ListNode *intersectNode = nullptr;
    ListNode *list1 = createList({4, 1}, 8, &intersectNode);
    ListNode *list2 = createList({5, 0, 1});
    ListNode *list3 = createList({8, 4, 5});
    if (intersectNode)
    {
        intersectNode->next = list3;
    }
    ListNode *temp = list2;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = list3;
    testCases.push_back({list1, list2, intersectNode});

    // Test case 2: non-intersecting lists
    list1 = createList({2, 6, 4});
    list2 = createList({1, 5});
    testCases.push_back({list1, list2, nullptr});

    // Run tests and print results
    for (size_t i = 0; i < testCases.size(); ++i)
    {
        ListNode *result = solution.getIntersectionNode(testCases[i].headA, testCases[i].headB);
        cout << "Test case " << i + 1 << ":" << endl;
        cout << "List A: ";
        printList(testCases[i].headA);
        cout << "List B: ";
        printList(testCases[i].headB);
        cout << "Expected intersection at node with value: " << (testCases[i].expected ? to_string(testCases[i].expected->val) : "None") << endl;
        cout << "Actual intersection at node with value: " << (result ? to_string(result->val) : "None") << endl;
        cout << (result == testCases[i].expected ? "Test Passed" : "Test Failed") << endl;
        cout << endl;
    }
}

int main()
{
    runTests();
    return 0;
}

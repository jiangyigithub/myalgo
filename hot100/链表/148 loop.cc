#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for test case
struct TestCase
{
    ListNode *head;
    vector<int> expected; // Expected sorted values in a vector
};

// Function to print linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to convert vector to linked list
ListNode *vectorToList(const vector<int> &vec)
{
    if (vec.empty())
        return nullptr;
    ListNode *head = new ListNode(vec[0]);
    ListNode *current = head;
    for (size_t i = 1; i < vec.size(); ++i)
    {
        current->next = new ListNode(vec[i]);
        current = current->next;
    }
    return head;
}

// Function to convert linked list to vector
vector<int> listToVector(ListNode *head)
{
    vector<int> vec;
    while (head)
    {
        vec.push_back(head->val);
        head = head->next;
    }
    return vec;
}

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        int length = getLength(head);
        ListNode dummy(-1);
        dummy.next = head;

        for (int step = 1; step < length; step *= 2)
        {
            ListNode *pre = &dummy;
            ListNode *cur = dummy.next;
            while (cur)
            {
                ListNode *h1 = cur;             // First part head
                ListNode *h2 = split(h1, step); // Second part head
                cur = split(h2, step);          // Remaining part head
                ListNode *temp = merge(h1, h2); // Merge sorted parts
                pre->next = temp;               // Connect sorted parts
                while (pre->next)
                {
                    pre = pre->next; // Move pre pointer to the end of sorted part
                }
            }
        }
        return dummy.next;
    }

private:
    int getLength(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *split(ListNode *head, int step)
    {
        if (!head)
            return nullptr;
        ListNode *cur = head;
        for (int i = 1; i < step && cur->next; ++i)
        {
            cur = cur->next;
        }
        ListNode *right = cur->next;
        cur->next = nullptr; // Cut the link
        return right;
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
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
bool checkResult(ListNode *head, const vector<int> &expected)
{
    vector<int> result = listToVector(head);
    if (result.size() != expected.size())
        return false;
    for (size_t i = 0; i < expected.size(); ++i)
    {
        if (result[i] != expected[i])
            return false;
    }
    return true;
}

// Main function to run test cases
int main()
{
    Solution sol;

    vector<TestCase> testCases = {
        {vectorToList({4, 2, 1, 3}), {1, 2, 3, 4}},
        {vectorToList({1, 2, 3, 4}), {1, 2, 3, 4}},
        {vectorToList({4, 3, 2, 1}), {1, 2, 3, 4}},
        {vectorToList({}), {}} // Edge case: empty list
    };

    for (const auto &testCase : testCases)
    {
        ListNode *sortedList = sol.sortList(testCase.head);
        bool result = checkResult(sortedList, testCase.expected);

        cout << "Expected: ";
        for (int val : testCase.expected)
            cout << val << " ";
        cout << "\nActual:   ";
        printList(sortedList);
        cout << "Test " << (result ? "Passed" : "Failed") << endl;
        cout << "-----------------" << endl;

        // Free the allocated memory for sortedList
        while (sortedList)
        {
            ListNode *temp = sortedList;
            sortedList = sortedList->next;
            delete temp;
        }
    }

    return 0;
}

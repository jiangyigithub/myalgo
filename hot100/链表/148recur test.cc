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

// Function to sort the linked list using Merge Sort
class Solution
{
public:
   ListNode *sortList(ListNode *head) {
        // 基本情况：如果链表为空或只有一个节点，直接返回
        if (head == nullptr || head->next == nullptr)
            return head;

        // 使用快慢指针找到链表的中间节点
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
         
        // 将链表分为两部分
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // 递归对两部分分别排序
        ListNode* left = sortList(head);// 函数参数
        ListNode* right = sortList(mid);// 

        // 合并两部分
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }

        // 连接剩余的节点
        cur->next = left? left:right;

        return dummy.next;
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
        {vectorToList({4, 2, 1, 3}), {1, 2, 3, 4}}
        // ,
        // { vectorToList({1, 2, 3, 4}), {1, 2, 3, 4} },
        // { vectorToList({4, 3, 2, 1}), {1, 2, 3, 4} },
        // { vectorToList({}), {} }  // Edge case: empty list
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

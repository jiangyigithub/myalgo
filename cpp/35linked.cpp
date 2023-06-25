#include "head.hpp"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    ListNode *cur = head;
    while (cur)
    {
        std::cout << cur->val;
        cur = cur->next;
    }
    std::cout << endl;

    cur = head;
    while (cur)
    {
        ListNode *temp = new ListNode(cur->val);
        temp->next = cur->next;
        cur->next = temp;
        cur = temp->next;
    }
    
    cur=head;
    while (cur)
    {
        std::cout << cur->val;
        cur = cur->next;
    }
    std::cout << endl;

    return 0;
}
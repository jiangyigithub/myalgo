#include "head.hpp"
#include "ListNode.hpp"

// ===== Solution Code =====
class Solution
{
public:
    // 求链表的交点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode* p1 = headA;
        ListNode* p2= headB;
        while(p1!=p2){
            if(p1==nullptr){
                p1=headB;
            }
            else{
                p1=p1->next;
            }
            if(p2==nullptr){
                p2=headA;
            }
            else{
                p2=p2->next;
            }
        }
        return p1;

    }
};

int main()
{
    // ======= Test Case =======
    // Build two linked lists with intersection of 8
    // headA = 4 -> 1 -> 8 -> 4 -> 5
    //                   ↑
    // headB = 5 -> 0 -> 1
    ListNode *headA = vectorToLinkedList(vector<int>{4, 1, 8, 4, 5});
    ListNode *headB = vectorToLinkedList(vector<int>{5, 0, 1, 8, 4, 5});
    ListNode *intersectA = getListNode(headA, 8);
    ListNode *intersectB = getListNode(headB, 1);
    intersectB->next = intersectA; // Concatenate the two lists
    // ====== Driver Code ======
    Solution *slt = new Solution();
    ListNode *res = slt->getIntersectionNode(headA, headB);
    cout << res->val << endl;

    return 0;
}
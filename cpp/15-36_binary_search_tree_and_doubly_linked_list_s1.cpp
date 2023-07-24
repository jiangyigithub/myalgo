/*
剑指 Offer 36. 二叉搜索树与双向链表
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

 
为了让您更好地理解问题，以下面的二叉搜索树为例：
      4
     / \
    2   5
   /  \
  1    3
 
我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。
1 <--> 2<--> 3 <--> 4 <--> 5
 

注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

注意：此题对比原题有改动。
*/

#include "head.hpp"
#include "PrintUtil.hpp"

/**
 * Definition for a linked list node.
 */
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ===== Solution Code =====
class Solution
{
public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
/*
      4
     / \
    2   5
   /  \
  1    3

1 <--> 2<--> 3 <--> 4 <--> 5
*/

private:
    Node *pre, *head;

private:
    void dfs(Node *cur)
    {
        if (cur == nullptr)
            return;
        dfs(cur->left);
        if (pre != nullptr)
            pre->right = cur;
        else
            head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};

int main()
{
    // ======= Test Case =======
    vector<Node *> nodeList = {
        new Node(1),
        new Node(2),
        new Node(3),
        new Node(4),
        new Node(5)};
    nodeList[3]->left = nodeList[1];
    nodeList[3]->right = nodeList[4];
    nodeList[1]->left = nodeList[0];
    nodeList[1]->right = nodeList[2];
    Node *root = nodeList[3];

    // ====== Driver Code ======
    Solution *slt = new Solution();
    Node *res = slt->treeToDoublyList(root);
    // Print the Doubly circular linked list
    vector<int> nodesVal;
    for (int i = 0; i <= nodeList.size(); i++)
    {
        nodesVal.push_back(res->val);
        res = res->right;
    }
    cout << PrintUtil::strJoin(" <-> ", nodesVal) << endl;

    return 0;
}

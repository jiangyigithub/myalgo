/*
 * File: sfo_27_mirror_of_a_binary_tree_s2.cpp
 * Created Time: 2021-12-09
 * Author: Krahets (krahets@163.com)
 */

#include "head.hpp"
#include "TreeNode.hpp"
#include "PrintUtil.hpp"

// ===== Solution Code =====

class Solution
{
public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode *> que; // FIFO
        que.push(root);
        while (!que.empty())
        {
            TreeNode *node =que.front();
            que.pop();
            // swap nodes
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);

        }
        return root;
    }
};

int main()
{
    // ======= Test Case =======
    TreeNode *root = vectorToTree(vector<int>{4, 2, 7, 1, 3, 6, 9, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    PrintUtil::printTree(root);
    // ====== Driver Code ======
    Solution *slt = new Solution();
    TreeNode *res = slt->mirrorTree(root);
    PrintUtil::printTree(res);

    return 0;
}

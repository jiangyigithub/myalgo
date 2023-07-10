/*
 * File: sfo_28_symmetric_binary_tree_s1.cpp
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
    bool isSymmetric(TreeNode *root)
    {
        return root == nullptr || recur(root->left, root->right);
    }

private:
    // (node1.val == node2.val) && isMirror(node1.left, node2.right) && isMirror(node1.right, node2.left);
    bool recur(TreeNode *L, TreeNode *R)
    {
        if (L == nullptr && R == nullptr)
            return true;
        if (L == nullptr || R == nullptr)
            return false;
        if(L->val != R->val)
            return false;
        return recur(L->left, R->right) && recur(L->right, R->left);
    }
};

int main()
{
    // ======= Test Case =======
    TreeNode *root = vectorToTree(vector<int>{1, 2, 2, 3, 4, 4, 3, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX});
    // ====== Driver Code ======
    Solution *slt = new Solution();
    bool res = slt->isSymmetric(root);
    cout << boolalpha << res << endl;

    return 0;
}

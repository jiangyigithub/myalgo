#include <vector>
#include <algorithm> // For std::find
#include <iostream> // For std::cout

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// **offer 07 重建二叉树**

// - 中序+先序/后序可重建，必须包含中序

// - 重建二叉树关键在于怎么计算递归参数，本题中有3个递归参数:root,left,right

// - 在preorder list中确定root的位置，通过root新建二叉树节点-->参数root

// - 在inorder list确定左/右子树元素的数量-->参数left,right

// - inorder 和 preorder里元素都是相同，重建二叉树需要同时参考这两个列表，两者关联点在于元素，所以把元素作为hashmap的key

// - 右子树的根节点索引：根节点索引 + 左子树长度 + 1

// - i和1在代码中分开,用index=id

//   ```markdown
//   先序遍历用来确定根的位置；
//   中序遍历用来确定左右子树的数量；
//   在递归体中，root表示根的位置in preorder；
//   left和right表示左右子树的边界in inorder;
//   用到了三次recur，其中参数分别表示：
  
//   recur(0,0,len(inorder)-1):本句为建立整棵二叉树，pre[0]为根元素，在inorder中左边界和 右边界分别是整个数组的左右边界
  
//   node.left = recur(root+1,left,i-1)：本句为建立左子树，左子树的根在整棵树根的下一个位置（在preorder中找位置）即root+1；左子树的左边界仍为原树的左边界；左子树的右边界在inorder中位于根元素位置的左侧一个，即i-1
  
//   node.right = recur(i-left+root+1,i+1,right):本句为建立右子树，右子树的根的位置需要在原树根位置root的基础上加上左子树的元素个数i-left的下一位置（在preorder中找位置）,即root+(i-left)+1；右子树的右边界仍为原树的右边界；右子树的左边界在inorder中位于根元素位置的右侧一个，即i+1
//   ```
// Solution class with the buildTree method
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // If preorder list is empty, there are no nodes to construct the tree
        if (preorder.empty()) {
            return nullptr;
        }

        // The first element in the preorder list is the root of the tree
        int root_val = preorder[0];
        // Find the root element in the inorder list to determine the left and right subtrees
        int left_size = find(inorder.begin(), inorder.end(), root_val) - inorder.begin();

        // Elements in the preorder list for the left subtree
        vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        // Elements in the preorder list for the right subtree
        vector<int> pre2(preorder.begin() + 1 + left_size, preorder.end());

        // Elements in the inorder list for the left subtree
        vector<int> in1(inorder.begin(), inorder.begin() + left_size);
        // Elements in the inorder list for the right subtree
        vector<int> in2(inorder.begin() + 1 + left_size, inorder.end());

        // Recursively build the left and right subtrees
        TreeNode *left = buildTree(pre1, in1);
        TreeNode *right = buildTree(pre2, in2);

        // Create the root node with the left and right subtrees
        return new TreeNode(root_val, left, right);
    }
};

// Function to print the tree in inorder traversal (for testing)
void printInorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Function to print the tree in preorder traversal (for testing)
void printPreorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    // Test case
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Create an instance of the Solution class
    Solution sol;
    // Build the tree
    TreeNode *root = sol.buildTree(preorder, inorder);

    // Print the tree in inorder to verify correctness
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    // Print the tree in preorder to verify correctness
    cout << "Preorder traversal of the constructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}


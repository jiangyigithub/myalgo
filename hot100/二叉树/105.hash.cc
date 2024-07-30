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

// Solution class with the buildTree method
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> dfs = [&](int pre_l, int pre_r, int in_l, int in_r) -> TreeNode* {
            if (pre_l == pre_r) { // 空节点
                return nullptr;
            }
            int left_size = index[preorder[pre_l]] - in_l; // 左子树的大小
            TreeNode *left = dfs(pre_l + 1, pre_l + 1 + left_size, in_l, in_l + left_size);
            TreeNode *right = dfs(pre_l + 1 + left_size, pre_r, in_l + 1 + left_size, in_r);
            return new TreeNode(preorder[pre_l], left, right);
        };
        return dfs(0, n, 0, n); // 左闭右开区间
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


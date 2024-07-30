#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* dfs(vector<int>& preorder, int m, int n, vector<int>& inorder,
                  int p, int q, unordered_map<int, int>& hashMap) {
        if (m == n)
            return nullptr;
        int x = preorder[m];//递归里不要轻易写常量
        int x_index = hashMap[x];
        int leftsize = x_index - p;//左子树的长度
        // 已经根的位置，和其左右区间，则可求左、右子树所在区间
        TreeNode* left = dfs(preorder, m + 1, m + 1 + leftsize, inorder, p,
                             p + leftsize, hashMap);
        TreeNode* right = dfs(preorder, m + 1 + leftsize, n, inorder,
                              p + leftsize + 1, q, hashMap);
        return new TreeNode(x, left, right);
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < inorder.size(); ++i) {
            hashMap[inorder[i]] = i;
        }
        int n = preorder.size();
        return dfs(preorder, 0, n, inorder, 0, n, hashMap);
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

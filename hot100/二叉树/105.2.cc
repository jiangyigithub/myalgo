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


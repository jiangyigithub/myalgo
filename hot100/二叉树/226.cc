#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Helper function to print the tree (in-order traversal)
void printTree(TreeNode* root) {
    if (root == nullptr) return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

// Main function to run test cases
int main() {
    Solution solution;

    // Test case 1: Empty tree
    TreeNode* root1 = nullptr;
    TreeNode* invertedRoot1 = solution.invertTree(root1);
    cout << "Test case 1 - Expected: (empty), Got: ";
    printTree(invertedRoot1);
    cout << endl;

    // Test case 2: Single node tree
    TreeNode* root2 = newNode(1);
    TreeNode* invertedRoot2 = solution.invertTree(root2);
    cout << "Test case 2 - Expected: 1, Got: ";
    printTree(invertedRoot2);
    cout << endl;

    // Test case 3: Tree with multiple levels
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root3 = newNode(1);
    root3->left = newNode(2);
    root3->right = newNode(3);
    root3->left->left = newNode(4);
    root3->left->right = newNode(5);
    TreeNode* invertedRoot3 = solution.invertTree(root3);
    // Expected inverted tree:
    //       1
    //      / \
    //     3   2
    //        / \
    //       5   4
    cout << "Test case 3 - Expected: 1 3 2 5 4, Got: ";
    printTree(invertedRoot3);
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
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
/*
交换操作，函数嵌套
temp = A
A = B
B = temp
*/
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

// Helper function to print the tree (level-order traversal)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "(empty)" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current) {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

// Main function to run test cases
int main() {
    Solution solution;

    // Test case 1: Empty tree
    TreeNode* root1 = nullptr;
    TreeNode* invertedRoot1 = solution.invertTree(root1);
    cout << "Test case 1 - Expected: (empty), Got: ";
    printTree(invertedRoot1);

    // Test case 2: Single node tree
    TreeNode* root2 = newNode(1);
    TreeNode* invertedRoot2 = solution.invertTree(root2);
    cout << "Test case 2 - Expected: 1, Got: ";
    printTree(invertedRoot2);

    // Test case 3: Tree with multiple levels
    // Original tree:
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
    cout << "Test case 3 - Expected: 1 3 2 null null 5 4, Got: ";
    printTree(invertedRoot3);

    // Test case 4: Tree with unbalanced depths
    // Original tree:
    //       1
    //      / 
    //     2   
    //    / 
    //   3   
    TreeNode* root4 = newNode(1);
    root4->left = newNode(2);
    root4->left->left = newNode(3);
    TreeNode* invertedRoot4 = solution.invertTree(root4);
    // Expected inverted tree:
    //       1
    //        \
    //         2
    //          \
    //           3
    cout << "Test case 4 - Expected: 1 null 2 null 3, Got: ";
    printTree(invertedRoot4);

    return 0;
}

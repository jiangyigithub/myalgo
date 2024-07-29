#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root ==nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right)+1;

    }
};

// Helper function to create a new TreeNode
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

// Main function to run test cases
int main() {
    Solution solution;

    // Test case 1: Empty tree
    TreeNode* root1 = nullptr;
    cout << "Test case 1 - Expected: 0, Got: " << solution.maxDepth(root1) << endl;

    // Test case 2: Single node tree
    TreeNode* root2 = newNode(1);
    cout << "Test case 2 - Expected: 1, Got: " << solution.maxDepth(root2) << endl;

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
    cout << "Test case 3 - Expected: 3, Got: " << solution.maxDepth(root3) << endl;

    // Test case 4: Tree with unbalanced depths
    //       1
    //      / 
    //     2   
    //    / 
    //   3   
    TreeNode* root4 = newNode(1);
    root4->left = newNode(2);
    root4->left->left = newNode(3);
    cout << "Test case 4 - Expected: 3, Got: " << solution.maxDepth(root4) << endl;

    return 0;
}
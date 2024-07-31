#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    bool dfs(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) return p == q;
        return p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return dfs(root->left, root->right);
    }
};

// Structure to hold test case information
struct TestCase {
    TreeNode* root;
    bool expected;

    TestCase(TreeNode* root, bool expected) : root(root), expected(expected) {}
};

// Function to run test cases
void runTests() {
    // Create test cases
    std::vector<TestCase> testCases;

    // Test case 1: Symmetric tree
    //      1
    //     / \
    //    2   2
    //   / \ / \
    //  3  4 4  3
    testCases.emplace_back(new TreeNode(1, 
                                        new TreeNode(2, new TreeNode(3), new TreeNode(4)), 
                                        new TreeNode(2, new TreeNode(4), new TreeNode(3))), true);

    // Test case 2: Not symmetric tree
    //      1
    //     / \
    //    2   2
    //     \   \
    //     3    3
    testCases.emplace_back(new TreeNode(1, 
                                        new TreeNode(2, nullptr, new TreeNode(3)), 
                                        new TreeNode(2, nullptr, new TreeNode(3))), false);

    // Test case 3: Single node tree
    //      1
    testCases.emplace_back(new TreeNode(1), true);

    Solution sol;
    for (size_t i = 0; i < testCases.size(); ++i) {
        bool result = sol.isSymmetric(testCases[i].root);
        std::cout << "Test Case " << i + 1 << ":\n";
        std::cout << "Expected Result: " << (testCases[i].expected ? "true" : "false") << "\n";
        std::cout << "Actual Result: " << (result ? "true" : "false") << "\n";
        std::cout << "Test " << (result == testCases[i].expected ? "Passed" : "Failed") << "\n\n";
    }

    // Clean up
    for (auto& testCase : testCases) {
        // Function to delete the tree to prevent memory leaks
        std::function<void(TreeNode*)> deleteTree = [&](TreeNode* node) {
            if (node) {
                deleteTree(node->left);
                deleteTree(node->right);
                delete node;
            }
        };
        deleteTree(testCase.root);
    }
}

int main() {
    runTests();
    return 0;
}

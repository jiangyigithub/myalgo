#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans = INT_MIN;

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        int s = left + right + node->val;
        ans = std::max(ans, s);
        return std::max(0, std::max(left, right) + node->val);
    }

public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;  // Reset ans for each new test case
        dfs(root);
        return ans;
    }
};

// Structure to hold test case information
struct TestCase {
    TreeNode* root;
    int expected;

    TestCase(TreeNode* root, int expected) : root(root), expected(expected) {}
};

// Function to run test cases
void runTests() {
    // Create test cases
    std::vector<TestCase> testCases;

    // Test case 1:
    //      1
    //     / \
    //    2   3
    testCases.emplace_back(new TreeNode(1, new TreeNode(2), new TreeNode(3)), 6);

    // Test case 2:
    //      -10
    //      /  \
    //     9   20
    //         / \
    //        15  7
    testCases.emplace_back(new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))), 42);

    // Test case 3:
    //      2
    //     / \
    //    -1  3
    testCases.emplace_back(new TreeNode(2, new TreeNode(-1), new TreeNode(3)), 5);

    Solution sol;
    for (size_t i = 0; i < testCases.size(); ++i) {
        int result = sol.maxPathSum(testCases[i].root);
        std::cout << "Test Case " << i + 1 << ":\n";
        std::cout << "Expected Result: " << testCases[i].expected << "\n";
        std::cout << "Actual Result: " << result << "\n";
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

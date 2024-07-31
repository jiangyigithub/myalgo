#include <iostream>
#include <vector>
#include <functional>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    int ak;
    int ans;

    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        dfs(node->left);
        if (--ak == 0) ans = node->val;
        dfs(node->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        ak = k;
        dfs(root);
        return ans;
    }
};

// Structure to hold test case information
struct TestCase {
    TreeNode* root;
    int k;
    int expected;

    TestCase(TreeNode* root, int k, int expected) : root(root), k(k), expected(expected) {}
};

// Function to run test cases
void runTests() {
    // Create test cases
    std::vector<TestCase> testCases;

    // Test case 1:
    //      3
    //     / \
    //    1   4
    //     \
    //      2
    testCases.emplace_back(new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4)), 1, 1);
    testCases.emplace_back(new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4)), 2, 2);
    testCases.emplace_back(new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4)), 3, 3);
    testCases.emplace_back(new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)), new TreeNode(4)), 4, 4);

    // Test case 2:
    //          5
    //         / \
    //        3   6
    //       / \
    //      2   4
    //     /
    //    1
    testCases.emplace_back(new TreeNode(5, 
                                        new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), 
                                        new TreeNode(6)), 1, 1);
    testCases.emplace_back(new TreeNode(5, 
                                        new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), 
                                        new TreeNode(6)), 2, 2);
    testCases.emplace_back(new TreeNode(5, 
                                        new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), 
                                        new TreeNode(6)), 3, 3);
    testCases.emplace_back(new TreeNode(5, 
                                        new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), 
                                        new TreeNode(6)), 4, 4);
    testCases.emplace_back(new TreeNode(5, 
                                        new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), 
                                        new TreeNode(6)), 5, 5);
    testCases.emplace_back(new TreeNode(5, 
                                        new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr), new TreeNode(4)), 
                                        new TreeNode(6)), 6, 6);

    // Test case 3:
    // Single node tree
    testCases.emplace_back(new TreeNode(1), 1, 1);

    // Test case 4:
    // Larger tree
    //         10
    //        /  \
    //       5   15
    //      / \    \
    //     3   7    18
    testCases.emplace_back(new TreeNode(10, 
                                        new TreeNode(5, new TreeNode(3), new TreeNode(7)), 
                                        new TreeNode(15, nullptr, new TreeNode(18))), 1, 3);
    testCases.emplace_back(new TreeNode(10, 
                                        new TreeNode(5, new TreeNode(3), new TreeNode(7)), 
                                        new TreeNode(15, nullptr, new TreeNode(18))), 2, 5);
    testCases.emplace_back(new TreeNode(10, 
                                        new TreeNode(5, new TreeNode(3), new TreeNode(7)), 
                                        new TreeNode(15, nullptr, new TreeNode(18))), 3, 7);
    testCases.emplace_back(new TreeNode(10, 
                                        new TreeNode(5, new TreeNode(3), new TreeNode(7)), 
                                        new TreeNode(15, nullptr, new TreeNode(18))), 4, 10);
    testCases.emplace_back(new TreeNode(10, 
                                        new TreeNode(5, new TreeNode(3), new TreeNode(7)), 
                                        new TreeNode(15, nullptr, new TreeNode(18))), 5, 15);
    testCases.emplace_back(new TreeNode(10, 
                                        new TreeNode(5, new TreeNode(3), new TreeNode(7)), 
                                        new TreeNode(15, nullptr, new TreeNode(18))), 6, 18);

    Solution sol;
    for (size_t i = 0; i < testCases.size(); ++i) {
        int result = sol.kthSmallest(testCases[i].root, testCases[i].k);
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

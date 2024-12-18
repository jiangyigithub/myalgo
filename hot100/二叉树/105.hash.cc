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

class Solution {
public:
    // pre 根-左-右  inorder 左-根-右
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        
        // 哈希表用于快速查找中序遍历中每个节点的位置
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        
        // 调用辅助函数构建树，初始调用时覆盖整个数组范围
        return dfs(preorder, inorder, index, 0, n, 0, n); // 左闭右开区间
    }

private:
    // 辅助递归函数，用于构建树
    TreeNode* dfs(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &index, int pre_l, int pre_r, int in_l, int in_r) {
        if (pre_l == pre_r) { // 如果前序区间为空，返回空节点
            return nullptr;
        }
        
        // 根节点值为当前前序区间的第一个元素
        int root_val = preorder[pre_l];
        // 在中序区间中找到根节点的位置，以此划分左右子树
        int left_size = index[root_val] - in_l; // 左子树的大小
        
        // 递归构建左子树
        TreeNode *left = dfs(preorder, inorder, index, pre_l + 1, pre_l + 1 + left_size, in_l, in_l + left_size);
        // 递归构建右子树
        TreeNode *right = dfs(preorder, inorder, index, pre_l + 1 + left_size, pre_r, in_l + 1 + left_size, in_r);
        
        // 创建当前的根节点，并连接左右子树
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


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
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        
        // 哈希表用于快速查找中序遍历中每个节点的位置
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        
        return dfs(preorder, 0, n, inorder, 0, n, index); // 左闭右开区间
    }

private:
// int pre_l：前序遍历数组中当前子数组的左边界（包含）。
// int pre_r：前序遍历数组中当前子数组的右边界（不包含）。
// int in_l：中序遍历数组中当前子数组的左边界（包含）。
// int in_r：中序遍历数组中当前子数组的右边界（不包含）。


    TreeNode* dfs(vector<int> &preorder, int pre_l, int pre_r, vector<int> &inorder, int in_l, int in_r, unordered_map<int, int> &index) {
        if (pre_l == pre_r) { // 如果前序区间为空，返回空节点
            return nullptr;
        }
        
        // 根节点值为当前前序区间的第一个元素
        int root_val = preorder[pre_l];
        // 在中序区间中找到根节点的位置，以此划分左右子树
        int left_size = index[root_val] - in_l; // 左子树的大小
        
        // 对于 pre_order left,根,right
        // root pre_l 
        // left  起点,终点,pre_l+1,pre_l+1+size
        // right 起点,终点,pre_l+1+size ,pre_r
        
        // 对于in_order left,根,right
        // left  起点,终点,inl,inl+size
        // root  inl+size
        // right 起点,终点,inl+size+1,inr
        
        //pre_order 和 in_order大小相同
        TreeNode *left = dfs(preorder, pre_l + 1, pre_l + 1 + left_size, inorder, in_l, in_l + left_size, index);
        TreeNode *right = dfs(preorder, pre_l + 1 + left_size, pre_r, inorder, in_l + 1 + left_size, in_r, index);
        
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

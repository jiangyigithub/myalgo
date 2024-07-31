#include <iostream>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        TreeNode* cur=root;
        root->left=nullptr;
        root->right=left;
        while(cur->right){
            cur=cur->right;
        }
        ///遍历root,cur->right 为nullptr,再把右半部分链接到cur上
        cur->right=right;
    }
};

// 二叉树结构:
//        1
//       / \
//      2   5
//     / \   \
//    3   4   6
// 辅助函数：打印展开后的链表
void printFlattenedTree(TreeNode* root) {
    while (root) {
        std::cout << root->val << " ";
        root = root->right;
    }
    std::cout << std::endl;
}

// 测试用例
void testFlatten() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution().flatten(root);
    printFlattenedTree(root); // 预期输出: 1 2 3 4 5 6
}

int main() {
    testFlatten();
    return 0;
}

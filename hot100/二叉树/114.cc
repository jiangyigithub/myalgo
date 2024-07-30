#include <iostream>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        flatten(root->left);
        flatten(root->right);
        /// 下面都是拼接链表的操作
        TreeNode* p = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        // left, right 和链表中的next没有区别
        root->left = nullptr;
        root->right = left;
        // 怎么到达一个链表的尾部，right就是next
        while (p->right) {
            p = p->right;
        }
        p->right = right;
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

#include <iostream>
#include <unordered_map>
using namespace std;

// 定义二叉树的节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long long, int> cnt{{0, 1}}; // 使用前缀和计数
        dfs(root, targetSum, 0, cnt, ans);
        return ans;
    }

private:
    void dfs(TreeNode* node, int targetSum, long long s, unordered_map<long long, int>& cnt, int& ans) {
        if (node == nullptr) {
            return;
        }

        s += node->val; // 更新当前路径和

        // 计算当前路径和减去目标和，检查是否存在这样的前缀和
        ans += cnt.count(s - targetSum) > 0 ? cnt[s - targetSum] : 0;

        cnt[s]++; // 增加当前路径和的计数

        dfs(node->left, targetSum, s, cnt, ans);  // 递归到左子树
        dfs(node->right, targetSum, s, cnt, ans); // 递归到右子树

        cnt[s]--; // 恢复现场，回溯时减去当前路径和的计数
    }
};

// 测试代码
int main() {
    Solution sol;

    // 创建一个测试二叉树
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int targetSum = 8;
    int result = sol.pathSum(root, targetSum);
    cout << "Number of paths with sum " << targetSum << " is: " << result << endl;

    // 释放动态分配的内存
    delete root->left->right->right;
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

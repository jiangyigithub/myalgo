#include <iostream>
#include <functional>
using namespace std;

// 定义二叉树的节点结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;

        // 使用lambda表达式定义dfs函数
        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int
        {
            if (node == nullptr)
                return -1; // 下面 +1 后，对于叶子节点就刚好是 0

            int l_len = dfs(node->left);  // 左子树最大链长， 边的个数
            int r_len = dfs(node->right); // 右子树最大链长
            
            //拐弯，必在叶子节点上
            ans = max(ans, l_len + r_len + 2); // 直径，两条链拼成路径+2

            return max(l_len, r_len) + 1; // 当前子树最大链长+1
        };

        dfs(root);
        return ans;
    }
    
    // 一个是高度，一个是边的个数
    int maxDepth(TreeNode* root) {
        if(root ==nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right)+1;

    }

    int diameterOfBinaryTree2(TreeNode *root)
    {
        int ans = 0;

        // 使用lambda表达式定义dfs函数
        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int
        {
            if (node == nullptr)
                return -1; // 下面 +1 后，对于叶子节点就刚好是 0

            int l_len = dfs(node->left) + 1;  // 左子树最大链长+1
            int r_len = dfs(node->right) + 1; // 右子树最大链长+1

            ans = max(ans, l_len + r_len); // 两条链拼成路径

            return max(l_len, r_len); // 当前子树最大链长
        };

        dfs(root);
        return ans;
    }
};

// 测试代码
int main()
{
    Solution sol;

    // 创建一个测试二叉树
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree is: " << diameter << endl;

    // 释放动态分配的内存
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

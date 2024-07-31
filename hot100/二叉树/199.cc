#include <iostream>
#include <vector>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    vector<int> ans;

    void dfs(TreeNode* root,int depth){
        if root==nullptr return;
        // 第一次深度满足条件
        if(depth==ans.size()){
            ans.push_back(root->val);
        }
        // 先右后左
        dfs(root->right,depth+1);
        dfs(root->left,depth+1);

    }

public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};
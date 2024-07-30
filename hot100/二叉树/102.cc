#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<TreeNode *> que;
    // 循环次数为当前层节点数（即队列queue长度）
    que.push(root);
    while (!que.empty())
    {
        vector<int> ret;
        /// que.size只在init时被用到，循环内操作会改变容器的大小
        for (int i = que.size(); i>0; --i)
        {
            TreeNode *temp = que.front();
            que.pop();
            ret.push_back(temp->val);
            if (temp->left)
                que.push(temp->left); //que size在改变
            if (temp->right)
                que.push(temp->right);
        }
        ans.push_back(ret);
    }
}


// Helper function to create a binary tree node
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Creating a binary tree for testing:
    //      3
    //     / \
    //    9  20
    //       / \
    //      15  7
    TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
    
    
    vector<vector<int>> result = levelOrder(root);
    
    // Print the result
    cout << "Level order traversal: " << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
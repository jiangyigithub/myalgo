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

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode *root, vector<int>& ans)// 传入引用
    {
        if (root == nullptr)
            return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
};

// Helper function to create a binary tree node
TreeNode *createNode(int val)
{
    return new TreeNode(val);
}

int main()
{
    // Creating a binary tree for testing:
    //      1
    //       \
    //        2
    //       /
    //      3
    TreeNode *root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    cout << "Recursive In-order Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;


    cout << "Iterative In-order Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
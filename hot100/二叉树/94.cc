
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
        if(root==nullptr) return {};
        vector<int> ans = inorderTraversal(root->left);
        ans.push_back(root->val)
        auto temp = inorderTraversal(root->right);
        ans.insert(ans.end(),temp.begin(),temp.end());
        return ans;
    }
};

// Helper function to create a binary tree node
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Creating a binary tree for testing:
    //      1
    //       \
    //        2
    //       /
    //      3
    TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);
    
    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    cout << "Recursive In-order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    SolutionIterative solutionIterative;
    result = solutionIterative.inorderTraversal(root);
    cout << "Iterative In-order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// 定义二叉树的节点结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // 先序遍历，因为一开始先比较了 root 是否等于 p 或 q。
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 基本情况
        if (root == nullptr || root == p || root == q)
            return root;
        // 在左子树中查找p和q, 在右子树中查找p和q
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 如果在左子树和右子树都找到了p或q，那么当前节点就是最近公共祖先
        if (left && right)
            return root;
        // 如果 left 和 right 中只有一个非空，说明 p 和 q 都在同一子树中，返回非空的那个节点。
        // 如果 left 和 right 都为空，返回 nullptr，表示在当前子树中没有找到 p 或 q。
        return left ? left : right;
    }
};

// 测试用例结构体
struct TestCase
{
    TreeNode *root;
    TreeNode *p;
    TreeNode *q;
    TreeNode *expected;
};

// 创建一个二叉树
TreeNode *createTree(vector<int> nodes, int nullVal = -1)
{
    if (nodes.empty())
        return nullptr;

    TreeNode *root = new TreeNode(nodes[0]);
    vector<TreeNode *> nodeList = {root};
    int i = 1;
    for (TreeNode *node : nodeList)
    {
        if (i < nodes.size() && nodes[i] != nullVal)
        {
            node->left = new TreeNode(nodes[i]);
            nodeList.push_back(node->left);
        }
        ++i;
        if (i < nodes.size() && nodes[i] != nullVal)
        {
            node->right = new TreeNode(nodes[i]);
            nodeList.push_back(node->right);
        }
        ++i;
    }
    return root;
}

// 查找值为val的节点
TreeNode *findNode(TreeNode *root, int val)
{
    if (!root)
        return nullptr;
    if (root->val == val)
        return root;
    TreeNode *left = findNode(root->left, val);
    if (left)
        return left;
    return findNode(root->right, val);
}

int main()
{
    Solution solution;

    // 测试用例1
    vector<int> nodes1 = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode *root1 = createTree(nodes1);
    TreeNode *p1 = findNode(root1, 5);
    TreeNode *q1 = findNode(root1, 1);
    TreeNode *expected1 = findNode(root1, 3);

    TestCase test1 = {root1, p1, q1, expected1};

    // 其他测试用例可以类似定义...

    vector<TestCase> tests = {test1};

    for (int i = 0; i < tests.size(); ++i)
    {
        TreeNode *result = solution.lowestCommonAncestor(tests[i].root, tests[i].p, tests[i].q);
        cout << "Test case " << i + 1 << ":" << endl;
        cout << "Expected result: " << tests[i].expected->val << endl;
        cout << "Actual result: " << (result ? result->val : -1) << endl;
        cout << "Test " << (result == tests[i].expected ? "PASSED" : "FAILED") << endl;
        cout << endl;
    }

    return 0;
}

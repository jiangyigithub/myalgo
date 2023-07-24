/* 前序遍历：例题三 
在二叉树中搜索值为 7 的节点，返回根节点到这些节点的路径，要求路径中有且只有一个值为 7 的节点，并且不能包含值为 3 的节点。
*/
#include "head.hpp"
#include "PrintUtil.hpp"

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                       { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                        { return !isspace(ch); })
                    .base(),
                input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input)
{
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

//       5
//      / \
//     4   8
//    /   / \
//   11  13  14
//  /  \    / \
// 7    2  5   7
class Solution
{

public:

void preOrder(TreeNode *root) {
    // 剪枝
    if (root == nullptr||root->val == 3) {
        return;
    }
    // 尝试
    path.push_back(root->val);
    if (root->val == 7) {
        // 记录解
        res.push_back(path);
    }
    preOrder(root->left);
    preOrder(root->right);
    // 回退
    path.pop_back();
}

void preOrder2(TreeNode *root) {
    // 剪枝
    if (root == nullptr||root->val == 3) {
        return;
    }
    // 尝试
    path.push_back(root->val);
    if (root->val == 7) {
        // 记录解
        res.push_back(path);
        path.pop_back();
        return;
    }
    preOrder2(root->left);
    preOrder2(root->right);
    // 回退
    path.pop_back();
}

public:
    vector<vector<int>> res;
    vector<int> path;
};

int main()
{
    string line = "[5,4,8,11,null,13,14,7,2,null,null,5,7]";

    TreeNode *root = stringToTreeNode(line);

    Solution* slt = new Solution();
     slt->preOrder(root);
    vector<vector<int>> output = slt->res;
    int a = 1;
}

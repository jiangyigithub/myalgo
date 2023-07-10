#include "head.hpp"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int node) : val(node), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        // Check if either A or B is null
        if (A == nullptr || B == nullptr) {
            return false;
        }
        
        // Check if the current nodes of A and B match
        if (isMatch(A, B)) {
            return true;
        }
        
        // Recursively check the left and right subtrees of A
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

private:
    /// (node1.val == node2.val) && isMatch(node1.left, node2.left) && isMatch(node1.right, node2.right);
    bool isMatch(TreeNode* A, TreeNode* B) {
        // If B is null, it means the entire subtree has been matched successfully
        if (B == nullptr) {
            return true;
        }
        
        // If A is null or A and B's values don't match, it's not a match
        if (A == nullptr || A->val != B->val) {
            return false;
        }
        
        // Recursively check the left and right subtrees
        return isMatch(A->left, B->left) && isMatch(A->right, B->right);
    }
};


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

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line = "[3,4,5,1,2]";
    TreeNode *A = stringToTreeNode(line);
    line = "[4,1]";
    TreeNode *B = stringToTreeNode(line);

    bool ret = Solution().isSubStructure(A, B);

    string out = boolToString(ret);
    cout << out << endl;

    return 0;
}
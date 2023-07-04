#include "head.hpp"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int node) : val(node), left(nullptr), right(nullptr) {}
};

//     3
//    / \
//   9  20
//  /  /  \
// 8  15   7

class Solution
{
public:
    vector<vector<int>> deepOrder3(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> tmp;
        deque<TreeNode *> deq;
        deq.push_back(root);
        while (!deq.empty())
        {    
            // 打印奇数层
            for (int i = deq.size(); i > 0; i--)
            {   
                // 从左向右打印
                TreeNode *node = deq.front();
                deq.pop_front();
                tmp.push_back(node->val);
                // 先左后右加入下层节点
                if (node->left)
                    deq.push_back(node->left);
                if (node->right)
                    deq.push_back(node->right);
            }
            res.push_back(tmp);
            // 若为空则提前跳出
            if (deq.empty())
                break;
            tmp.clear();
            // 打印偶数层
            for (int i = deq.size(); i > 0; i--)
            {   
                // 从右向左打印
                TreeNode *node = deq.back();
                deq.pop_back();
                tmp.push_back(node->val);
                // 先右后左加入下层节点
                if (node->right)
                    deq.push_front(node->right);
                if (node->left)
                    deq.push_front(node->left);
            }
            res.push_back(tmp);
            tmp.clear();
        }
        return res;
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

int main()
{
    string line = "[3,9,20,8,null,15,7]";

    TreeNode *root = stringToTreeNode(line);

    vector<vector<int>> rets = Solution().deepOrder3(root);

    for (auto ret : rets)
    {
        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}

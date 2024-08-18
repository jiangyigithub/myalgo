#include "head.hpp"
 
 struct TreeNode {
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

class Solution {
    private:
    vector<int> res;
    
public:
    vector<int> getRes(void){ return res;}
    void clearRes(void){res.clear();}
    void inOrder(TreeNode* root) {
        
        if(root==nullptr)  return;
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
    void preOrder(TreeNode* root) {
        if(root==nullptr)  return;
        res.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(TreeNode* root) {
        if(root==nullptr)  return;
        postOrder(root->left);
        postOrder(root->right);
        res.push_back(root->val);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line = "[3,9,20,8,null,15,7]";
  
    TreeNode* root = stringToTreeNode(line);
    Solution sol;
    sol.inOrder(root);
    vector<int> ret = sol.getRes();

    string out = integerVectorToString(ret);
    cout << "in order: "<<out << endl;

    
    sol.clearRes();
    sol.preOrder(root);
    ret = sol.getRes();
    out = integerVectorToString(ret);
    cout << "pre order: "<<out << endl;

    sol.clearRes();
    sol.postOrder(root);
    ret = sol.getRes();
    out = integerVectorToString(ret);
    cout << "post order: "<<out << endl;
    
    return 0;
}
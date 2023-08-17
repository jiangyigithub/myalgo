/*
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

 
     3
    / \
   9  20
      / \
     15  7
示例 1:



Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
示例 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

限制：

0 <= 节点个数 <= 5000
*/
#include "head.hpp"

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int node) : val(node), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i=0;i<inorder.size();i++)
            dic[inorder[i]]=i;
        return recur(0,0,inorder.size()-1);
    }

private:
    vector<int> preorder;
    unordered_map<int,int> dic;
    
    /**
     * @brief re-build tree by preorder inorder
     * 
     * @param[in] root recur param,the index of the subtree val in preorder list
     * @param[in] left recur param,the index of the subtree left border in inorder list
     * @param[in] right recur param,the index of the subtree right border in inorder list
     * @return tree
    */
    TreeNode* recur(int root,int left,int right){
        if(left>right) return nullptr;
        TreeNode* node = new TreeNode(preorder[root]);
        //switch information between inorder and preorder by hashmap
        int i = dic[preorder[root]];
        ///calc recur parameter -root -left -right
        //calc -root in perorder list
        //calc -left and -right in inorder list
        node->left = recur(root+1,left,i-1);
        node->right = recur(root+i-left+1,i+1,right);
        return node;
    }
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode* root) {
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
        string line = "[3,9,20,15,7]";
        vector<int> preorder = stringToIntegerVector(line);
        line = "[9,3,15,20,7]";
        vector<int> inorder = stringToIntegerVector(line);
        
        TreeNode* ret = Solution().buildTree(preorder, inorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    
    return 0;
}
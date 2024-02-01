/*
https://leetcode.cn/problems/xu-lie-hua-er-cha-shu-lcof/description/
序列化与反序列化二叉树


序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

 

示例 1：

输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]

示例 2：

输入：root = []
输出：[]

示例 3：

输入：root = [1]
输出：[1]

示例 4：

输入：root = [1,2]
输出：[1,2]

 

提示：

    树中结点数在范围 [0, 104] 内
    -1000 <= Node.val <= 1000

*/
#include "head.hpp"
 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int node) : val(node), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)return "[null]";
        string ret= "[";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(node!=nullptr){
                ret+=to_string(node->val);
                ret+=",";
                que.push(node->left);
                que.push(node->right);
            }
            else ret+="null,";
        }
        //delte last comma
        ret.pop_back();
        ret+="]";
        return ret;
    }
    
        //       1
        //      / \
        //     2   3
        //        / \
        //       4   5
       

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        vector<string> res = this->spilit(data,',');
        TreeNode* root = new TreeNode(stoi(res[0]));
        queue<TreeNode*> que;
        que.push(root);
        int i=1;
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(res[i]!="null"){
                node->left = new TreeNode(stoi(res[i]));
                que.push(node->left);
            }
            ++i;
            if(res[i]!="null"){
                node->right = new TreeNode(stoi(res[i]));
                que.push(node->right);
            }
            ++i;
        }
        return root;
    }

    vector<vector<int>> deepOrder2(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        if (!root) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            for (int i = que.size(); i > 0; i--) {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }

private:
    vector<string> spilit(string str,char sym){
        string str2=str.substr(1,str.size()-2);
        if(str.empty()) return{};
        vector<string> res;
        string::size_type beg=0;
        for(auto end=0;(end=str2.find(sym,end))!=string::npos;++end){
            res.push_back(str2.substr(beg,end-beg));
            beg=end+1;
        }
        //last string
        res.push_back(str2.substr(beg));
        return res;
    }




};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

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
    string line = "[1,2,3,null,null,4,5]";
    TreeNode* root = stringToTreeNode(line);

    Codec codec;
    string ret = codec.serialize(root);
    cout << "serialize: "<<ret << endl;
  
    TreeNode* root2 = codec.deserialize(codec.serialize(root));
    vector<vector<int>> rets = codec.deepOrder2(root2);
    cout << "deserialize: "<< endl;
    for(auto r:rets)
    {
    string out = integerVectorToString(r);
    cout << out << endl;
    }
    
    return 0;
}
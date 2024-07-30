两个优化点：

    1. 用一个哈希表（或者数组）预处理 inorder 每个元素的下标，这样就可以 O(1) 查到 preorder[0] 在 inorder 的位置，从而 O(1) 知道左子树的大小。
    2. 把递归参数改成子数组下标区间（左闭右开区间）的左右端点，从而避免复制数组。



class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> dfs = [&](int pre_l, int pre_r, int in_l, int in_r) -> TreeNode* {
            if (pre_l == pre_r) { // 空节点
                return nullptr;
            }
            int left_size = index[preorder[pre_l]] - in_l; // 左子树的大小
            TreeNode *left = dfs(pre_l + 1, pre_l + 1 + left_size, in_l, in_l + left_size);
            TreeNode *right = dfs(pre_l + 1 + left_size, pre_r, in_l + 1 + left_size, in_r);
            return new TreeNode(preorder[pre_l], left, right);
        };
        return dfs(0, n, 0, n); // 左闭右开区间
    }
};

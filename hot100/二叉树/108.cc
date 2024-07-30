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
// 把中间值当做中间节点，剩下的左边为左子树，右边为右子树
    TreeNode *dfs(vector<int> &nums, int i, int j)
    {
        if (i >= j)
            return nullptr;
        int m = i + (j - i) / 2;
        // 不是单纯的划分区间，而是区间之间还有单个元素，左区间-中间单个值-右区间
        TreeNode *mid = new TreeNode(nums[m]);
        mid->left = dfs(nums, i, m);
        mid->right = dfs(nums, m+1, j);
        return mid;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        return dfs(nums, 0, n);
    }
};

// 辅助函数，中序遍历二叉树并输出节点值
void inOrderTraversal(TreeNode *root)
{
    if (!root)
        return;
    inOrderTraversal(root->left);
    std::cout << root->val << " ";
    inOrderTraversal(root->right);
}

int main()
{
    std::vector<int> nums = {-10, -3, 0, 5, 9};

    // 将有序数组转换为二叉搜索树
    TreeNode *root = Solution().sortedArrayToBST(nums);

    // 输出中序遍历结果
    std::cout << "In-order traversal of the constructed BST: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    // 清理动态分配的内存（递归删除所有节点）
    // 这里省略了删除节点的代码，需要递归删除整个树以防止内存泄漏

    return 0;
}

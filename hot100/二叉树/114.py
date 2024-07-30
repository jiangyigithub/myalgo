# 定义二叉树节点类
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def flatten(self, root: TreeNode):
        # 如果根节点为空，直接返回
        if root is None:
            return

        # 递归地将左子树进行展平
        self.flatten(root.left)
        # 递归地将右子树进行展平
        self.flatten(root.right)

        # 如果左子树存在
        if root.left:
            # 找到左子树的最右节点
            cur = root.left
            while cur.right:
                cur = cur.right

            # 将当前节点的右子树连接到左子树的最右节点的右侧
            cur.right = root.right

            # 将当前节点的右子树设置为左子树
            root.right = root.left

            # 将当前节点的左子树设置为空
            root.left = None

# 二叉树结构:
#        1
#       / \
#      2   5
#     / \   \
#    3   4   6

# 创建二叉树节点
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(5)
root.left.left = TreeNode(3)
root.left.right = TreeNode(4)
root.right.right = TreeNode(6)

# 创建Solution实例并调用flatten方法
solution = Solution()
solution.flatten(root)

# 展平后的二叉树
cur = root
while cur:
    print(cur.val, end=' ')
    cur = cur.right


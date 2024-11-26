from typing import List, Optional
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        ans = []
        s = set(to_delete)
        
        def dfs(node, flag):
            if node is None:
                return None
            rootFlag = True  # 当前节点是否保留
            if node.val in s:
                rootFlag = False
            # 如果父节点被删除，当前节点需要加入到结果中
            if not flag and rootFlag:
                nonlocal ans
                ans.append(node)
            node.left = dfs(node.left, rootFlag)
            node.right = dfs(node.right, rootFlag)
            return node if rootFlag else None

        dfs(root, False)
        return ans

# 测试代码
def print_forest(forest):
    """帮助函数：打印森林中的每棵树（层序遍历）"""
    def bfs(root):
        if not root:
            return []
        queue = [root]
        res = []
        while queue:
            node = queue.pop(0)
            if node:
                res.append(node.val)
                queue.append(node.left)
                queue.append(node.right)
            else:
                res.append(None)
        # 清理尾部的 None
        while res and res[-1] is None:
            res.pop()
        return res
    
    for tree in forest:
        print(bfs(tree))

# 构造测试用例
root = TreeNode(1,
                TreeNode(2, TreeNode(4), TreeNode(5)),
                TreeNode(3, TreeNode(6), TreeNode(7)))
to_delete = [3, 5]

# 执行删除操作
solution = Solution()
forest = solution.delNodes(root, to_delete)

# 输出结果
#     1
#    / \
#   2   3
#  / \  / \
# 4   5 6  7

# to_delete = [3, 5]
print("结果森林：")
print_forest(forest)

from collections import defaultdict
from typing import List, Optional
from math import inf

# 定义树节点
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 解决方案类
class Solution:
    def verticalTraversal2(self, root: Optional[TreeNode]) -> List[List[int]]:
        data = []
        def dfs(node: Optional[TreeNode], row: int, col: int):
            if node is None:
                return
            data.append((col, row, node.val))
            dfs(node.left, row + 1, col - 1)
            dfs(node.right, row + 1, col + 1)
        dfs(root, 0, 0)

        ans = []
        last_col = inf
        data.sort()
        for col, _, val in data:
            if col != last_col:
                last_col = col
                ans.append([])
            ans[-1].append(val)
        return ans


    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        groups = defaultdict(list)  # 哈希表存储 (col -> [(row, val)])
        
        def dfs(node, row, col):
            if node is None:
                return
            groups[col].append((row, node.val))  # 将 (row, val) 存入对应的列
            dfs(node.left, row + 1, col - 1)    # 递归处理左子树
            dfs(node.right, row + 1, col + 1)   # 递归处理右子树
        
        dfs(root, 0, 0)  # 从根节点开始
        
        ans = []
        for _, g in sorted(groups.items()):  # 按列（key）排序
            g.sort()  # 按行和节点值排序
            ans.append([val for _, val in g])  # 只取节点值
        return ans

# 构建测试用例
def build_tree(values):
    """
    根据层序遍历列表构建二叉树。
    `None` 表示空节点。
    """
    if not values:
        return None
    nodes = [TreeNode(val) if val is not None else None for val in values]
    for i in range(len(values)):
        if nodes[i] is not None:
            if 2 * i + 1 < len(values):
                nodes[i].left = nodes[2 * i + 1]
            if 2 * i + 2 < len(values):
                nodes[i].right = nodes[2 * i + 2]
    return nodes[0]

# 测试用例
def test_vertical_traversal():
    solution = Solution()
    
    # 测试用例 1
    root = build_tree([1, 2, 3, 4, 5, 6, 7])
    expected = [[4], [2], [1, 5, 6], [3], [7]]
    assert solution.verticalTraversal(root) == expected, f"Test case 1 failed: {solution.verticalTraversal(root)}"
    
    # 测试用例 2
    root = build_tree([1, 2, 3, 4, 6, 5, 7])
    expected = [[4], [2], [1, 5, 6], [3], [7]]
    assert solution.verticalTraversal(root) == expected, f"Test case 2 failed: {solution.verticalTraversal(root)}"
    
    # 测试用例 3（单节点）
    root = build_tree([1])
    expected = [[1]]
    assert solution.verticalTraversal(root) == expected, f"Test case 3 failed: {solution.verticalTraversal(root)}"
    
    # 测试用例 4（空树）
    root = build_tree([])
    expected = []
    assert solution.verticalTraversal(root) == expected, f"Test case 4 failed: {solution.verticalTraversal(root)}"

# 运行测试
test_vertical_traversal()

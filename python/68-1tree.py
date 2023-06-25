from head import *
from typing import List
from json import *
import collections

# line = "[6,2,8,0,4,7,9,null,null,3,5]"
#        6
#      /    \
#     2      8
#    / \    /  \
#   0   4  7    9
#      / \
#     3   5


class Solution:
    # [3,5,1,6,2,0,8,null,null,7,4]
    # 5
    # 1
    # root 3-->5-->6-->5-->2-->7-->2-->4-->2-->5-->3
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        while root:
            if root.val<p.val and root.val<q.val:
                root=root.right
            elif root.val>p.val and root.val>q.val:
                root=root.left
            else:break
        return root


def stringToTreeNode(input):
    input = input.strip()
    input = input[1:-1]
    if not input:
        return None

    inputValues = [s.strip() for s in input.split(',')]
    root = TreeNode(int(inputValues[0]))
    nodeQueue = [root]
    front = 0
    index = 1
    while index < len(inputValues):
        node = nodeQueue[front]
        front = front + 1

        item = inputValues[index]
        index = index + 1
        if item != "null":
            leftNumber = int(item)
            node.left = TreeNode(leftNumber)
            nodeQueue.append(node.left)

        if index >= len(inputValues):
            break

        item = inputValues[index]
        index = index + 1
        if item != "null":
            rightNumber = int(item)
            node.right = TreeNode(rightNumber)
            nodeQueue.append(node.right)
    return root


def treeNodeToString(root):
    if not root:
        return "[]"
    output = ""
    queue = [root]
    current = 0
    while current != len(queue):
        node = queue[current]
        current = current + 1

        if not node:
            output += "null, "
            continue

        output += str(node.val) + ", "
        queue.append(node.left)
        queue.append(node.right)
    return "[" + output[:-2] + "]"

# print tree
def levelOrder(root: TreeNode) -> List[List[int]]:
    if not root:
        return []
    res, queue = [], collections.deque()
    queue.append(root)
    while queue:
        tmp = []
        for _ in range(len(queue)):
            node = queue.popleft()
            tmp.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        res.append(tmp)
    return res


def main():
    import sys
    import io
    line = "[6,2,8,0,4,7,9,null,null,3,5]"
    root = stringToTreeNode(line)
    treeStr = levelOrder(root)
    print(treeStr)
    p = TreeNode(3)
    q = TreeNode(5)
    ret = Solution().lowestCommonAncestor(root, p, q)
    out = treeNodeToString(ret)
    print(out)


if __name__ == '__main__':
    main()
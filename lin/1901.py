from typing import List
from math import ceil

class Solution:
    # 1 <-- left
    # 3 <-- right
    # 2
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        left, right = 1, len(mat) - 1
        while left <= right:
            i = (left + right) // 2
            mx = max(mat[i])  
            # 与对应相邻的元素做对比
            if mx > mat[i-1][mat[i].index(mx)]:  
                left = i + 1   # 右移  
            else:
                right = i - 1  # 左移
        return [right, mat[right].index(max(mat[right]))]

# 测试用例
def test_findPeakGrid():
    solution = Solution()
    tests = [
        # (测试矩阵, 预期输出)
        (
            [[1, 4, 3], 
             [9, 2, 5], 
             [8, 7, 6]], 
            [1, 0]
        ),
        (
            [[10, 20, 15], 
             [21, 30, 14], 
             [7, 16, 32]], 
            [1, 1]
        ),
        (
            [[1, 2, 3, 6], 
             [5, 6, 7, 8], 
             [9, 10, 11, 12], 
             [13, 14, 15, 16]], 
            [3, 3]
        ),
        (
            [[10, 8, 10], 
             [14, 13, 12], 
             [15, 9, 11]], 
            [2, 0]
        ),
        (
            [[1, 3, 2]], 
            [0, 1]
        ),
        (
            [[1], 
             [3], 
             [2]], 
            [1, 0]
        )
    ]
    
    for i, (mat, expected) in enumerate(tests, 1):
        result = solution.findPeakGrid(mat)
        matrix_str = "\n".join([" ".join(map(str, row)) for row in mat])
        if result == expected:
            print(f"Test Case {i}:\nMatrix:\n{matrix_str}\nResult: {result} -> passed\n")
        else:
            print(f"Test Case {i}:\nMatrix:\n{matrix_str}\nResult: {result} -> failed (expected {expected})\n")

# 运行测试用例
test_findPeakGrid()

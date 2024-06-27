from collections import deque

class Solution:
    def numIslands(self, grid):
        if not grid or not grid[0]:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        island_count = 0
        
        def bfs(r, c):
            queue = deque([(r, c)])
            grid[r][c] = '0'  # 标记为已访问
            
            directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
            
            while queue:
                row, col = queue.popleft()
                for dr, dc in directions:
                    new_row, new_col = row + dr, col + dc
                    if 0 <= new_row < rows and 0 <= new_col < cols and grid[new_row][new_col] == '1':
                        queue.append((new_row, new_col))
                        grid[new_row][new_col] = '0'  # 标记为已访问
        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1':
                    bfs(r, c)
                    island_count += 1
        
        return island_count

# 示例输入
grid1 = [
    ["1", "1", "1", "1", "0"],
    ["1", "1", "0", "1", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "0", "0", "0"]
]

grid2 = [
    ["1", "1", "0", "0", "0"],
    ["1", "1", "0", "0", "0"],
    ["0", "0", "1", "0", "0"],
    ["0", "0", "0", "1", "1"]
]

solution = Solution()
print(solution.numIslands(grid1))  # 输出: 1
print(solution.numIslands(grid2))  # 输出: 3

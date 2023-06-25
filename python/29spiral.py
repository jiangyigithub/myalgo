class Solution:
    def spiralOrder(self, matrix: [[int]]) -> [int]:
        # 非预期输入检测
        if not matrix:
            return []
        # 边界初始值
        l, r, t, b, res = 0, len(matrix[0]) - 1, 0, len(matrix) - 1, []
        while True:
            # 打印"一行"
            for i in range(l, r + 1):
                res.append(matrix[t][i])  # left to right
            # 边界更新
            t += 1
            # 边界干涉,循环退出
            if t > b:
                break
            for i in range(t, b + 1):
                res.append(matrix[i][r])  # top to bottom
            r -= 1
            if l > r:
                break
            for i in range(r, l - 1, -1):
                res.append(matrix[b][i])  # right to left
            b -= 1
            if t > b:
                break
            for i in range(b, t - 1, -1):
                res.append(matrix[i][l])  # bottom to top
            l += 1
            if l > r:
                break
        return res


def main():
    matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    ret = Solution().spiralOrder(matrix)


if __name__ == '__main__':
    main()

from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(i, j, k):
            # 检查边界条件和当前字符是否匹配
            if not 0 <= i < len(board) or not 0 <= j < len(board[0]) or board[i][j] != word[k]:
                return False
            # 如果所有字符匹配完毕，返回 True
            if k == len(word) - 1:
                return True
            # 临时标记当前字符，防止重复访问
            board[i][j] = ''
            # 递归搜索上下左右四个方向
            res = dfs(i + 1, j, k + 1) or dfs(i - 1, j, k + 1) or dfs(i, j + 1, k + 1) or dfs(i, j - 1, k + 1)
            # 恢复当前字符
            board[i][j] = word[k]
            return res

        # 遍历网格，每个点作为起始点
        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0):
                    return True
        return False

# 定义测试用例的结构体
class TestCase:
    def __init__(self, board, word, expected):
        self.board = board
        self.word = word
        self.expected = expected
        self.passed = False

# 测试函数
def runTestCases():
    # 定义测试用例
    testCases = [
        TestCase(
            board=[['A', 'B', 'C', 'E'],
                   ['S', 'F', 'C', 'S'],
                   ['A', 'D', 'E', 'E']],
            word="ABCCED",
            expected=True
        ),
        TestCase(
            board=[['A', 'B', 'C', 'E'],
                   ['S', 'F', 'C', 'S'],
                   ['A', 'D', 'E', 'E']],
            word="SEE",
            expected=True
        ),
        TestCase(
            board=[['A', 'B', 'C', 'E'],
                   ['S', 'F', 'C', 'S'],
                   ['A', 'D', 'E', 'E']],
            word="ABCB",
            expected=False
        ),
    ]

    solution = Solution()
    for testCase in testCases:
        # 运行算法并获取实际输出
        actual = solution.exist(testCase.board, testCase.word)
        # 检查实际输出是否等于预期输出
        testCase.passed = (actual == testCase.expected)
        # 打印测试用例的详细信息
        print(f"Board: {testCase.board}")
        print(f"Word: {testCase.word}")
        print(f"Expected: {testCase.expected}")
        print(f"Actual: {actual}")
        print(f"Passed: {'Yes' if testCase.passed else 'No'}\n")

if __name__ == "__main__":
    runTestCases()

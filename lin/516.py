from functools import cache

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i > j:
                return 0
            if i == j:
                return 1
            if s[i] == s[j]:
                return dfs(i + 1, j - 1) + 2
            return max(dfs(i + 1, j), dfs(i, j - 1))
        
        return dfs(0, len(s) - 1)


# ===== 测试用例 =====
if __name__ == "__main__":
    sol = Solution()

    tests = [
        "bbbab",
        "cbbd",
        "a",
        "abcde",
        "agbdba",
        "aaaabaaa",
        "abcdcba",
        ""
    ]

    for t in tests:
        print(f"Input: '{t}'  ->  longestPalindromeSubseq = {sol.longestPalindromeSubseq(t)}")

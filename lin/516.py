from dataclasses import dataclass
from functools import cache


class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        @cache
        def dfs(i, j):
            if i > j:
                return 0
            if i == j:
                return 1
            if s[i] == s[j]:
                return dfs(i + 1, j - 1) + 2
            return max(dfs(i + 1, j), dfs(i, j - 1))

        return dfs(0, len(s) - 1)


# ------------------------
# Test struct + framework
# ------------------------
@dataclass
class TestCase:
    name: str
    input_str: str
    expected: int
    actual: int = None
    passed: bool = None


def run_tests():
    sol = Solution()

    tests = [
        TestCase("Case 1", "bbbab", 4),
        TestCase("Case 2", "cbbd", 2),
        TestCase("Case 3", "a", 1),
        TestCase("Case 4", "abcde", 1),
        TestCase("Case 5", "agbdba", 5),
    ]

    for t in tests:
        t.actual = sol.longestPalindromeSubseq(t.input_str)
        t.passed = (t.actual == t.expected)

        print(f"=== {t.name} ===")
        print(f"Input     : {t.input_str}")
        print(f"Expected  : {t.expected}")
        print(f"Actual    : {t.actual}")
        print(f"Result    : {'PASS' if t.passed else 'FAIL'}\n")


if __name__ == "__main__":
    run_tests()

from typing import List
from functools import cache
from dataclasses import dataclass


class Solution:
    def longestPalindrome(self, word1: str, word2: str) -> int:
        s = word1 + word2
        ans = 0

        @cache
        def dfs(i: int, j: int) -> int:
            nonlocal ans

            if i > j:
                return 0
            # 只有一个字符
            if i == j:
                return 1
            # 都选
            if s[i] == s[j]:
                res = dfs(i + 1, j - 1) + 2
                # 必须同时使用 word1 和 word2
                if i < len(word1) <= j: # 保证最长回文包含两个字符串的字符
                    ans = max(ans, res)
                return res
            # 不选左端或不选右端
            return max(dfs(i + 1, j), dfs(i, j - 1))

        res = dfs(0, len(s) - 1)
        return ans # ans 是小于或等于res


@dataclass
class TestCase:
    name: str
    word1: str
    word2: str
    expected: int


def run_tests():
    test_cases = [
        TestCase(
            name="示例 1",
            word1="cacb",
            word2="cbba",
            expected=5
        ),
        TestCase(
            name="示例 2",
            word1="ab",
            word2="ab",
            expected=3
        ),
        TestCase(
            name="示例 3：无法形成跨 word 回文",
            word1="aa",
            word2="bb",
            expected=0
        ),
        TestCase(
            name="示例 4：单字符",
            word1="a",
            word2="a",
            expected=2
        ),
        TestCase(
            name="示例 5：ans和res对比",
            word1="a",
            word2="abcb",
            expected=2
        ),

    ]

    sol = Solution()

    print("========== 测试开始 ==========")

    for idx, tc in enumerate(test_cases, 1):
        actual = sol.longestPalindrome(tc.word1, tc.word2)
        passed = actual == tc.expected

        print(f"\n[Test {idx}] {tc.name}")
        print(f"word1           : {tc.word1}")
        print(f"word2           : {tc.word2}")
        print(f"预期结果        : {tc.expected}")
        print(f"实际结果        : {actual}")
        print(f"测试是否通过    : {'✅ PASS' if passed else '❌ FAIL'}")

    print("\n========== 测试结束 ==========")


if __name__ == "__main__":
    run_tests()

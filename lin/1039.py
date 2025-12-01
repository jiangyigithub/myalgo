from functools import cache
from dataclasses import dataclass
from typing import List


class Solution:
    def minScoreTriangulation(self, v: List[int]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i + 1 == j:
                return 0
            return min(dfs(i, k) + dfs(k, j) + v[i] * v[j] * v[k] for k in range(i + 1, j)) # k -> [i+1,j-1]
        return dfs(0, len(v) - 1)


# ====== 使用 dataclass 存储测试用例 ======
@dataclass
class TestCase:
    input_v: List[int]
    expected: int


# ====== 测试函数 ======
def run_tests():
    sol = Solution()

    tests = [
        TestCase([1, 2, 3], 6),
        TestCase([3, 7, 4, 5], 144),
        TestCase([1, 3, 1, 4, 1, 5], 13),
        TestCase([2, 2, 2], 8),
        TestCase([5, 3, 7, 2, 6], 132),
    ]

    print("Running Tests...\n")

    for idx, t in enumerate(tests, 1):
        actual = sol.minScoreTriangulation(t.input_v)
        passed = "PASS" if actual == t.expected else "FAIL"

        print(f"Test Case {idx}:")
        print(f"  Input v        : {t.input_v}")
        print(f"  Expected Result: {t.expected}")
        print(f"  Actual Result  : {actual}")
        print(f"  Status         : {passed}")
        print("-" * 40)


if __name__ == "__main__":
    run_tests()

from collections import Counter
import math

class Solution:
    def balancedString(self, s: str) -> int:
        m = len(s) // 4
        cnt = Counter(s)
        # print(cnt.keys())
        if len(cnt) == 4 and min(cnt.values()) == m:
            return 0
        ans, left = math.inf, 0
        for right, c in enumerate(s):
            cnt[c] -= 1
            # 确保剩余子串的每个字符数量都不超过 m
            while max(cnt.values()) <= m:
                ans = min(ans, right - left + 1)
                cnt[s[left]] += 1
                left += 1
        return ans

# 测试代码
def test_balancedString():
    solution = Solution()
    test_cases = [
        ("QWER", 0),
        ("QQWE", 1),
        ("QQQW", 2),
        ("QQQQ", 3),
        ("WQWRQQQW", 3)
    ]
    
    for i, (s, expected) in enumerate(test_cases, 1):
        result = solution.balancedString(s)
        assert result == expected, f"Test case {i} failed: expected {expected}, got {result}"
    
    print("passed")

# 运行测试
test_balancedString()

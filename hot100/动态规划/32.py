from functools import cache

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        
        @cache
        def dfs(i):
            # 基本条件：索引小于 0 时返回 0
            if i < 0:
                return 0
            
            # 当前字符是 ')'，检查是否可以形成有效括号子串
            if s[i] == ')':
                # 如果前一个字符是 '('，形成有效子串 "()"
                if i-1 >=0 and s[i - 1] == '(':
                    return dfs(i - 2) + 2
                
                # 如果前一个字符是 ')'，可能形成更长的有效子串
                # 扩展匹配,示例 "()(())"
                if i - dfs(i - 1) - 1 >= 0 and s[i - dfs(i - 1) - 1] == '(':
                    return dfs(i - 1) + 2 + dfs(i - dfs(i - 1) - 2) 
            return 0

        # 找到所有子串中的最大长度
        ans = 0
        for i in range(n):
            ans = max(ans, dfs(i))
        
        return ans

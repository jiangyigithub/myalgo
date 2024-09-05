 
from typing import List
from functools import cache

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        @cache
        def dfs(i: int, j: int) -> bool:
            # 如果完全匹配，返回 True
            if j == 0:
                return True
            # 如果字典遍历完了而字符串没有完全匹配
            if i < 0:
                return False
            # 如果当前单词不能匹配剩余字符串的长度，继续检查前一个单词
            if len(wordDict[i]) > j:
                return dfs(i - 1, j)
            # 检查当前单词是否可以匹配字符串的后缀
            if s[j - len(wordDict[i]):j] == wordDict[i]:
                # 递归地检查匹配当前单词后的情况或跳过当前单词
                if dfs(i, j - len(wordDict[i])) or dfs(i - 1, j):
                    return True
            # 如果当前单词不匹配，则继续检查前一个单词
            return dfs(i - 1, j)
        # 从最后一个字典单词和字符串的末尾开始
        return dfs(len(wordDict) - 1, len(s))
    
    # 分割
    '''
    递归逻辑

    遍历 end 从 start + 1 到 len(s) + 1
    在这个过程中检查所有从位置 start 开始的可能子串 s[start:end]。

    判断条件 if s[start:end] in wordSet and dfs(end):
        检查当前子串 s[start:end] 是否存在于字典 wordSet 中。
        如果存在，递归调用 dfs(end) 检查从 end 位置开始的剩余部分是否也可以被字典中的单词组合而成
    '''
    def wordBreak2(self, s: str, wordDict: List[str]) -> bool:
        wordSet = set(wordDict)  # 使用集合进行快速查找
        @cache
        def dfs(start: int) -> bool:
            if start == len(s):
                return True  # 如果遍历到字符串的末尾，返回 True
            # 检查从 start 开始的所有可能的子串
            for end in range(start + 1, len(s) + 1):
                if s[start:end] in wordSet and dfs(end):
                    return True
            return False  # 如果没有找到合适的分割，返回 False
        # 从字符串的第一个字符开始检查
        return dfs(0)



class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic, res, i = {}, 0, -1
        for j in range(len(s)):
            if s[j] in dic:
                # dic[s[j]]为该值次新指针
                i = max(dic[s[j]], i) # 更新左指针 i
            # 更新该值的最新指针
            dic[s[j]] = j # 哈希表记录
            res = max(res, j - i) # 更新结果
        return res

def main():
    s="abcabcbb"
    ret=Solution().lengthOfLongestSubstring(s)
    out = str(ret);
    print(out)
if __name__ == '__main__':
    main()
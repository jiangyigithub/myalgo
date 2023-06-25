class Solution:
    def firstUniqChar(self, s: str) -> str:
        dic={}
        for c in s:
            if c in dic: dic[c]=False
            else: dic[c]=True
        for k,v in dic.items():
            if v: return k
        return ' '

if __name__=="__main__":
    s="abaccdeff"
    ret = Solution().firstUniqChar(s)
    print(ret)
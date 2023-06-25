from typing import List
import json
class Solution:
    # [1,2,3,2,2,2,5,4,2]
    def majorityElement(self, nums: List[int]) -> int:
        rating = 0
        for num in nums:
            if rating==0:
                res=num
            if num==res:
                rating+=1
            else:
                rating-=1
        return res

def stringToIntegerList(input):
    return json.loads(input)

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            nums = stringToIntegerList(line);
            
            ret = Solution().majorityElement(nums)

            out = str(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()
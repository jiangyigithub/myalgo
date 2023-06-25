import json
from typing import List

class Solution:
    def helper(self,nums,target):
        left=0
        right=len(nums)-1
        while(left<=right):
            mid=(left+right)//2
            if(nums[mid]<=target): left=mid+1
            else: right=mid-1
        return left
    # [5,7,7,8,8,10]
    # 8
    def search(self, nums: List[int], target: int) -> int:
        return self.helper(nums,target)- self.helper(nums,target-1)

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
            line = next(lines)
            target = int(line);
            
            ret = Solution().search(nums, target)

            out = str(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()
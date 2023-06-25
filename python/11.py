import json
from typing import List

class Solution:
    # [3,4,5,1,2]
    def minArray(self, numbers: List[int]) -> int:
        left=0
        right=len(numbers)-1
        while(left<right):
            mid=(left+right)//2
            if(numbers[mid]>numbers[right]): left=mid+1
            elif(numbers[mid]<numbers[right]): right=mid
            else: right-=1
        return numbers[left]


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
            numbers = stringToIntegerList(line);
            
            ret = Solution().minArray(numbers)

            out = str(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()
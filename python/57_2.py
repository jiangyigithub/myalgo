from typing import List
import json


class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        low, high = 1, 2
        while high < target:
            curSum = (low+high)*(high-low+1)//2
            if curSum < target:
                high += 1
            elif curSum > target:
                low += 1
            else:
                res.append([i for i in range(low, high+1)])
                low += 1
        return res


if __name__ == "__main__":
    res = Solution().findContinuousSequence(9)
    print(res)

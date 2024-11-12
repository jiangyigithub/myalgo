from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 2  # 修正为数组的最后一个元素
        
        while left <=right:
            mid = left + (right - left) // 2
            if nums[mid] > nums[right+1]:
                left = mid + 1
            elif nums[mid] < nums[right+1]:
                right = mid-1
            else:
                right -= 1   
        return nums[left]

# 测试用例
def test_findMin():
    solution = Solution()
    test_cases = [
        ([3, 4, 5, 1, 2], 1),            # 旋转点在中间
        ([4, 5, 6, 7, 0, 1, 2], 0),      # 旋转点在末尾前
        ([11, 13, 15, 17], 11),          # 未旋转的数组
        ([2, 2, 2, 0, 1], 0),            # 数组中有重复元素
        ([1], 1),                        # 仅一个元素
        ([2, 1], 1),                     # 仅两个元素，已旋转
        ([1, 3, 3], 1)                   # 包含重复元素
    ]
    
    for i, (nums, expected) in enumerate(test_cases, 1):
        result = solution.findMin(nums)
        if result == expected:
            print(f"Test Case {i}: nums = {nums} -> Result: {result} -> passed")
        else:
            print(f"Test Case {i}: nums = {nums} -> Result: {result} -> failed (expected {expected})")

# 运行测试用例
test_findMin()

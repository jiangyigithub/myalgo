from typing import List
from dataclasses import dataclass

@dataclass
class TestCase:
    input: List[int]
    expected: List[int]
    actual: List[int] = None
    passed: bool = False

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Modifies nums in-place to the next permutation of numbers.
        """
        n = len(nums)
        
        def reverse(nums, i, j):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1
        # 1.尾部看升序
        k = -1
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                k = i
                break
        # 4321的情况
        if k == -1:
            reverse(nums, 0, n - 1)
            return
        
        # 2. 尾部看较大
        w = -1
        for i in range(n - 1, k, -1):
            if nums[i] > nums[k]:
                w = i
                break
        
        # 3. 交换k和w
        nums[k], nums[w] = nums[w], nums[k]

        # 4. 反转k加1
        reverse(nums, k + 1, n - 1)

# Function to test the nextPermutation method with various test cases
def run_tests():
    test_cases = [
        TestCase(input=[1,2,3,8,5,7,6,4],expected = [1,2,3,8,6,4,5,7]), # 12385764 的下一个排列就是 12386457
        # 尾部看升序，尾部看较大，交换k和w,反转k加1
        TestCase(input=[1, 2, 3], expected=[1, 3, 2]),
        TestCase(input=[3, 2, 1], expected=[1, 2, 3]),
        TestCase(input=[1, 1, 5], expected=[1, 5, 1]),
        TestCase(input=[1], expected=[1]),
        TestCase(input=[1, 3, 2], expected=[2, 1, 3])
    ]

    solution = Solution()

    for test in test_cases:
        # Copy the input list because the method modifies it in-place
        test.actual = test.input[:]
        solution.nextPermutation(test.actual)
        test.passed = test.actual == test.expected
        print(f"Input: {test.input}, Expected: {test.expected}, Actual: {test.actual}, Passed: {test.passed}")

# Run the tests
run_tests()

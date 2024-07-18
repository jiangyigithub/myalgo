class Solution:
    def threeSum(self, nums):
        nums.sort()
        res = []
        for k in range(len(nums) - 2):
            if nums[k] > 0:
                break
            if k > 0 and nums[k] == nums[k - 1]:
                continue
            i, j = k + 1, len(nums) - 1
            while i < j:
                s = nums[k] + nums[i] + nums[j]
                if s < 0:
                    i += 1
                    while i < j and nums[i] == nums[i - 1]:
                        i += 1
                elif s > 0:
                    j -= 1
                    while i < j and nums[j] == nums[j + 1]:
                        j -= 1
                else:
                    res.append([nums[k], nums[i], nums[j]])
                    i += 1
                    j -= 1
                    while i < j and nums[i] == nums[i - 1]:
                        i += 1
                    while i < j and nums[j] == nums[j + 1]:
                        j -= 1
        return res

# 定义测试用例结构体
class TestCase:
    def __init__(self, nums, expected):
        self.nums = nums
        self.expected = expected
        self.actual = None
        self.passed = None

# 比较两个二维列表是否相同
def compare_results(result1, result2):
    return sorted(result1) == sorted(result2)

# 运行测试用例并输出结果
def run_test_cases():
    test_cases = [
        TestCase([-1, 0, 1, 2, -1, -4], [[-1, -1, 2], [-1, 0, 1]]),
        TestCase([0, 1, 1], []),
        TestCase([0, 0, 0], [[0, 0, 0]]),
        TestCase([-2, 0, 1, 1, 2], [[-2, 0, 2], [-2, 1, 1]]),
        # 可以添加更多测试用例
    ]
    
    solution = Solution()
    
    for case in test_cases:
        case.actual = solution.threeSum(case.nums)
        case.passed = compare_results(case.actual, case.expected)
        print(f"Test Case - nums: {case.nums}")
        print(f"Expected: {case.expected}")
        print(f"Actual: {case.actual}")
        print(f"Passed: {'Yes' if case.passed else 'No'}\n")

# 运行测试
run_test_cases()

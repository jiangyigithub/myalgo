from typing import List
from functools import cache
from dataclasses import dataclass


class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        @cache
        def dfs(i: int, j: int, target: int) -> int:
            if i>=j:
                return 0
            ans =0 # 回溯比较
            if nums[j-1]+nums[j]==target:
                ans = max(ans,dfs(i,j-2,target)+1)
            if nums[i]+nums[j]==target:
                ans = max(ans,dfs(i+1,j-1,target)+1)
            if nums[i]+nums[i+1]==target:
                ans = max(ans,dfs(i+2,j,target)+1)
            return ans
        n=len(nums)
        ans1=dfs(0,n-3,nums[-1]+nums[-2])
        ans2=dfs(1,n-2,nums[0]+nums[n-1])
        ans3=dfs(2,n-1,nums[0]+nums[1])
        return max(ans1,ans2,ans3)+1
            


@dataclass
class TestCase:
    name: str
    nums: List[int]
    expected: int


def run_tests():
    test_cases = [
        TestCase(name="示例 1：基本用例", nums=[3, 2, 1, 2, 3, 4], expected=3),
        TestCase(name="示例 2：全部可消", nums=[1, 1, 1, 1], expected=2),
        TestCase(name="示例 3：只能一次", nums=[1, 2, 3, 4], expected=2),
        TestCase(name="示例 4：全相等", nums=[2, 2, 2, 2, 2, 2], expected=3),
        TestCase(name="示例 5：边界情况", nums=[5, 1], expected=1),
    ]

    sol = Solution()
    print("========== 测试开始 ==========")

    for idx, tc in enumerate(test_cases, 1):
        actual = sol.maxOperations(tc.nums)
        passed = actual == tc.expected

        print(f"\n[Test {idx}] {tc.name}")
        print(f"输入 nums      : {tc.nums}")
        print(f"预期结果       : {tc.expected}")
        print(f"实际结果       : {actual}")
        print(f"测试是否通过   : {'✅ PASS' if passed else '❌ FAIL'}")

    print("\n========== 测试结束 ==========")


if __name__ == "__main__":
    run_tests()

from dataclasses import dataclass
from itertools import groupby

# 1. 定义测试用例结构体
@dataclass
class TestCase:
    input_data: str  # 输入数据
    expected_output: int  # 预期结果
    actual_output: int = None  # 实际结果，默认值为 None，稍后计算并填充
    passed: bool = False  # 是否通过测试，默认 False，稍后计算并填充

MOD = 1_000_000_007
f = [1, 1, 2, 4]
g = [1, 1, 2, 4]
for _ in range(10 ** 5 - 3):  # 预处理所有长度的结果
    f.append((f[-1] + f[-2] + f[-3]) % MOD)
    g.append((g[-1] + g[-2] + g[-3] + g[-4]) % MOD)

class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        ans = 1
        for ch, s in groupby(pressedKeys):
            m = len(list(s))
            ans = ans * (g[m] if ch in "79" else f[m]) % MOD
        return ans
    
def run_tests(test_cases: list):
    # 运行所有测试用例
    for test_case in test_cases:
        # 执行测试函数并获取实际结果
        test_case.actual_output = Solution().countTexts(test_case.input_data)
        # 判断测试是否通过
        test_case.passed = test_case.actual_output == test_case.expected_output
        # 输出每个测试用例的详细信息
        print(f"Input: {test_case.input_data}")
        print(f"Expected Output: {test_case.expected_output}")
        print(f"Actual Output: {test_case.actual_output}")
        print(f"Test Passed: {'Yes' if test_case.passed else 'No'}\n")

# 3. 定义并创建测试用例
def main():
    # 这里定义多个测试用例
    test_cases = [
        TestCase(input_data="22233", expected_output=8),
        TestCase(input_data="222222222222222222222222222222222222", expected_output=82876089)
    ]
    
    # 创建 Solution 实例并运行测试
    solution = Solution()
    run_tests(test_cases)

# 4. 执行主函数
if __name__ == "__main__":
    main()
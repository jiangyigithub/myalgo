#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 定义结构体来存储测试用例
struct TestCase {
    vector<int> prices;  // 股票价格序列
    int expected;        // 预期结果
    int actual;          // 实际结果
    bool passed;         // 测试是否通过
};

// 总结: 在i<j的前提下，max(A[j] - A[i])= max (A[j] -  min A[i],其中i<j)
// 故只要维持min i<j A[i]，不断更新最大差值即可

int maxProfit(vector<int>& prices) 
{
    int ans = 0;
    int min_price = prices[0];
    for (int p : prices) {
        ans = max(ans, p - min_price); //这里min_price表示上一个周期的min_price,这样能确保 i<j
        min_price = min(min_price, p); //更新本周期的 min_price
    }
    return ans;
}

// 测试函数
void runTests(vector<TestCase>& testCases) {
    for (auto& testCase : testCases) {
        // 计算实际结果
        testCase.actual = maxProfit(testCase.prices);
        // 判断测试是否通过
        testCase.passed = (testCase.actual == testCase.expected);

        // 输出测试用例的详细信息
        cout << "Test Case: ";
        for (int p : testCase.prices) {
            cout << p << " ";
        }
        cout << "\nExpected: " << testCase.expected 
             << "\nActual: " << testCase.actual 
             << "\nTest " << (testCase.passed ? "Passed" : "Failed") 
             << "\n\n";
    }
}

int main() {
    // 初始化测试用例
    vector<TestCase> testCases = {
        {{7, 1, 5, 3, 6, 4}, 5, 0, false},  // 预期最大利润是5
        {{7, 6, 4, 3, 1}, 0, 0, false},     // 无法获得利润，预期结果是0
        {{1, 2, 3, 4, 5}, 4, 0, false},     // 预期最大利润是4
        {{5, 4, 3, 2, 1}, 0, 0, false},     // 无法获得利润，预期结果是0
        {{2, 4, 1}, 2, 0, false}            // 预期最大利润是2
    };

    // 运行测试
    runTests(testCases);

    return 0;
}

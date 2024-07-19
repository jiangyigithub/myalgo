#include <iostream>
#include <vector>
#include <algorithm>
/*
为什么双指针算法可以在每次迭代中安全地移动较短的一边，而不会错过可能的最大面积。

每次移动较短的一边，虽然减少了宽度，但有可能找到更高的高度。
移动较长的一边则没有意义，因为新的面积一定会比当前的面积小（因为高度降低或相等，宽度减小）。
*/
// 函数计算最大容器储水量
int maxArea(const std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_water = 0;
    
    while (left < right) {
        int width = right - left;
        int container_height = std::min(height[left], height[right]);
        int current_water = width * container_height;
        max_water = std::max(max_water, current_water);
        
        // 每次移动较短的一边，双指针不是更新同时更新
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_water;
}

// 结构体存储测试用例
struct TestCase {
    std::vector<int> heights;
    int expected;
    int actual;
    bool passed;
};

// 运行测试用例并输出结果
void runTestCases() {
    std::vector<TestCase> testCases = {
        {{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49, 0, false},
        {{1, 1}, 1, 0, false},
        {{4, 3, 2, 1, 4}, 16, 0, false},
        {{1, 2, 1}, 2, 0, false},
        // 添加更多测试用例
    };
    
    for (auto& test : testCases) {
        test.actual = maxArea(test.heights);
        test.passed = (test.actual == test.expected);
        std::cout << "Heights: ";
        for (int h : test.heights) {
            std::cout << h << " ";
        }
        std::cout << "\nExpected: " << test.expected << ", Actual: " << test.actual 
                  << ", Passed: " << (test.passed ? "Yes" : "No") << "\n\n";
    }
}

int main() {
    runTestCases();
    return 0;
}

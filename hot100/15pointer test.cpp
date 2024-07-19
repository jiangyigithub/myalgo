#include <iostream>
#include <vector>
#include <algorithm>
/*
该题特点: 无序 有重复 求所以解；应用的基础模版是双指针求两数之和
基础模版：两数之和应用双指针的方法求和的前提得有序，因此，需先排序，再应用双指针
跳过重复的元素nums[i] == nums[i-1]
这道题还要求要输出所有结果，所以求得结果后，还需要继续查找
*/

/// 函数计算和为 0 的三元组
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    sort(nums.begin(),nums.end());

    
}

// 结构体存储测试用例
struct TestCase {
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
    std::vector<std::vector<int>> actual;
    bool passed;
};

// 检查两个二维向量是否相同
bool compareVectors(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// 打印二维向量
void printVector(const std::vector<std::vector<int>>& vec) {
    std::cout << "[";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << "[";
        for (int j = 0; j < vec[i].size(); ++j) {
            std::cout << vec[i][j];
            if (j < vec[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << "]";
}

// 运行测试用例并输出结果
void runTestCases() {
    std::vector<TestCase> testCases = {
        {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}, {}, false},
        {{0, 1, 1}, {}, {}, false},
        {{0, 0, 0}, {{0, 0, 0}}, {}, false},
        {{-2, 0, 1, 1, 2}, {{-2, 0, 2}, {-2, 1, 1}}, {}, false},
        // 添加更多测试用例
    };
    
    for (auto& test : testCases) {
        test.actual = threeSum(test.nums);
        test.passed = compareVectors(test.actual, test.expected);
        
        std::cout << "Test Case - nums: ";
        for (int num : test.nums) {
            std::cout << num << " ";
        }
        std::cout << "\nExpected: ";
        printVector(test.expected);
        std::cout << "\nActual: ";
        printVector(test.actual);
        std::cout << "\nPassed: " << (test.passed ? "Yes" : "No") << "\n\n";
    }
}

int main() {
    runTestCases();
    return 0;
}

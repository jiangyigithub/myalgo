#include <iostream>
#include <vector>
#include <algorithm>

// 函数计算和为 0 的三元组
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size(); ++i) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        
        int left = i + 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            /// 先固定一个，再求两数之和
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                /// 有多个解，怎么在找到一个解之后，继续求解
                result.push_back({nums[i], nums[left], nums[right]});
                
                while (left < right && nums[left] == nums[left + 1]) {
                    ++left;
                }
                
                while (left < right && nums[right] == nums[right - 1]) {
                    --right;
                }
                
                ++left;
                --right;
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }
    
    return result;
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

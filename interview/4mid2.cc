#include <iostream>
#include <vector>
#include <algorithm> // for std::max and std::min
// 定义结构体存储测试用例
struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
    double expectedMedian;
};

// 找到两个正序数组的中位数
double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    // Make sure nums1 is the smaller array
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();
    int imin = 0, imax = m;
    int half_len = (m + n + 1) / 2;

    while (imin <= imax) {
        int i = (imin + imax) / 2;
        int j = half_len - i;

        if (i < m && nums1[i] < nums2[j-1]) {
            imin = i + 1; // i is too small, must increase it
        } else if (i > 0 && nums1[i-1] > nums2[j]) {
            imax = i - 1; // i is too big, must decrease it
        } else {
            int max_of_left;
            if (i == 0) { max_of_left = nums2[j-1]; }
            else if (j == 0) { max_of_left = nums1[i-1]; }
            else { max_of_left = std::max(nums1[i-1], nums2[j-1]); }

            if ((m + n) % 2 == 1) {
                return max_of_left;
            }

            int min_of_right;
            if (i == m) { min_of_right = nums2[j]; }
            else if (j == n) { min_of_right = nums1[i]; }
            else { min_of_right = std::min(nums1[i], nums2[j]); }

            return (max_of_left + min_of_right) / 2.0;
        }
    }

    return 0.0;
}

// 测试函数，执行所有测试用例并输出详细信息
void runTestCases(const std::vector<TestCase>& testCases) {
    // std::cout << std::fixed << std::setprecision(5); // 设置输出小数精度为5位

    for (size_t i = 0; i < testCases.size(); ++i) {
        const TestCase& testCase = testCases[i];
        double actualMedian = findMedianSortedArrays(testCase.nums1, testCase.nums2);
        bool testPassed = ((actualMedian - testCase.expectedMedian) < 1e-5); // 判断浮点数是否相等

        std::cout << "Test Case " << i + 1 << ": ";
        std::cout << "Expected Median = " << testCase.expectedMedian << ", ";
        std::cout << "Actual Median = " << actualMedian << ", ";

        if (testPassed) {
            std::cout << "[PASSED]";
        } else {
            std::cout << "[FAILED]";
        }

        std::cout << std::endl;
    }
}

int main() {
    // 定义测试用例数组
    std::vector<TestCase> testCases = {
        {{1, 3}, {2}, 2.0},
        {{1, 2}, {3, 4}, 2.5},
        {{0, 0}, {0, 0}, 0.0},
        {{}, {1}, 1.0},
        {{2}, {}, 2.0},
        {{1, 3, 8}, {2, 4, 7}, 3.5}
    };

    // 执行测试用例并输出结果
    runTestCases(testCases);

    return 0;
}

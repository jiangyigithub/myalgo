#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
该题特点: 无序 有重复 求所以解；应用的基础模版是双指针求两数之和
基础模版：两数之和应用双指针的方法求和的前提得有序，因此，需先排序，再应用双指针
跳过重复的元素nums[i] == nums[i-1]
这道题还要求要输出所有结果，所以求得结果后，还需要继续查找
*/
// 函数计算和为 0 的三元组

vector<vector<int>> threeSum2(vector<int> &nums)
{
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; ++i)
    {
        int x = nums[i];
        if (x > 0 && nums[x] == nums[x - 1])
            continue;
        if (x + nums[i + 1] + nums[i + 2] > 0)
            break; // 优化一
        if (x + nums[n - 2] + nums[n - 1] < 0)
            continue; // 优化二
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int sum = x + nums[left] + nums[right];
            if (sum < 0)
                left++;
            else if (sum > 0)
                right--;
            else
            {
                ret.push_back({x, nums[left], nums[right]});
                ++left;
                while (left < right && nums[left] == nums[left - 1])
                    ++left;
                --right;
                while (left < right && nums[right] == nums[right + 1])
                    --right;  
            }
        }
    }
    return ret;
}

vector<std::vector<int>> threeSum(vector<int> &nums)
{
    vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2; ++i)
    {
        int x = nums[i];
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        if (x + nums[i + 1] + nums[i + 2] > 0)
            break; // 优化一
        // 优化一的作用
        // 如果当前数 x 加上数组中接下来的两个数的和大于0，那么由于数组是排序的，
        // 接下来的所有数都会大于 x，因此不可能找到任何和为0的三元组。所以可以提前退出循环，节省时间。

        // 优化二的作用
        // 当当前数x和数组中最后两个数的和仍然小于0时，
        // 说明即使将最小的两个数加在一起，也无法使和达到0。
        // 因此，可以跳过当前数，直接进行下一个数的检查，从而提高效率。
        if (x + nums[n - 2] + nums[n - 1] < 0)
            continue; // 优化二

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            /// 先固定一个，再求两数之和(两数之和应用双指针的方法求和的前提得有序)
            int sum = x + nums[left] + nums[right];
            cout << "nums sum" << sum << endl;
            if (sum > 0)
            {
                --right;
            }
            else if (sum < 0)
            {
                ++left;
            }

            else
            {
                /// 有多个解，怎么在找到一个解之后，继续求解
                std::vector<int> temp = {x, nums[left], nums[right]};
                result.push_back(temp);

                cout << "nums[left]" << nums[left] << endl;
                cout << "nums[left]" << nums[right] << endl;
                ++left;
                while (left < right && nums[left] == nums[left - 1])
                {
                    ++left;
                }
                --right;
                while (left < right && nums[right] == nums[right + 1])
                {
                    --right;
                }
                
                

                cout << "nums[left]" << nums[left] << endl;
                cout << "nums[left]" << nums[right] << endl;
            }
        }
    }

    return result;
}

// 结构体存储测试用例
struct TestCase
{
    std::vector<int> nums;
    std::vector<std::vector<int>> expected;
    std::vector<std::vector<int>> actual;
    bool passed;
};

// 检查两个二维向量是否相同
bool compareVectors(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

// 打印二维向量
void printVector(const std::vector<std::vector<int>> &vec)
{
    std::cout << "[";
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << "[";
        for (int j = 0; j < vec[i].size(); ++j)
        {
            std::cout << vec[i][j];
            if (j < vec[i].size() - 1)
                std::cout << ", ";
        }
        std::cout << "]";
        if (i < vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]";
}

// 运行测试用例并输出结果
void runTestCases()
{
    std::vector<TestCase> testCases = {
        // {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}, {}, false},
        // {{0, 1, 1}, {}, {}, false},
        // {{0, 0, 0}, {{0, 0, 0}}, {}, false},
        {{-2, 0, 1, 1, 2}, {{-2, 0, 2}, {-2, 1, 1}}, {}, false},
        {{0, 0, 0, 0}, {{0, 0, 0}}, {}, false},
        // 添加更多测试用例
    };

    for (auto &test : testCases)
    {
        test.actual = threeSum(test.nums);
        test.passed = compareVectors(test.actual, test.expected);

        std::cout << "Test Case - nums: ";
        for (int num : test.nums)
        {
            std::cout << num << " ";
        }
        std::cout << "\nExpected: ";
        printVector(test.expected);
        std::cout << "\nActual: ";
        printVector(test.actual);
        std::cout << "\nPassed: " << (test.passed ? "Yes" : "No") << "\n\n";
    }
}

int main()
{
    runTestCases();
    return 0;
}

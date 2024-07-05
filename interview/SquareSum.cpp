#include <cmath>
#include <iostream>
#include <vector>
// 平方数之和
using namespace std;
bool judgeSquareSum(int c)
{
    long left = 0;
    long right = static_cast<long>(sqrt(c)); // 使用 long 来避免溢出问题

    while (left <= right)
    {
        long currentSum = left * left + right * right;
        if (currentSum == c)
        {
            return true;
        }
        else if (currentSum < c)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return false;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
    int l = 0, r = numbers.size() - 1, sum;
    while (l < r)
    {
        sum = numbers[l] + numbers[r];
        if (sum == target)
            break;
        if (sum < target)
            ++l;
        else
            --r;
    }
    return vector<int>{l + 1, r + 1};
}

// 二分查找也可以看作双指针的一种特殊情况，但我们一般会将二者区分。双指针类型的题，
// 指针通常是一步一步移动的，而在二分查找里，指针每次移动半个区间长度
int mySqrt(int a)
{
    if (a == 0)
        return a;
    int l = 1, r = a, mid, sqrt;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        sqrt = a / mid;
        if (sqrt == mid)
        {
            return mid;
        }
        else if (mid > sqrt)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return r;
}

int binary_search(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int c1 = 5;
    int c2 = 3;

    std::cout << std::boolalpha;                                                       // 使得布尔值以 true/false 形式输出
    std::cout << "judgeSquareSum(" << c1 << ") = " << judgeSquareSum(c1) << std::endl; // 输出：true
    std::cout << "judgeSquareSum(" << c2 << ") = " << judgeSquareSum(c2) << std::endl; // 输出：false

    return 0;
}

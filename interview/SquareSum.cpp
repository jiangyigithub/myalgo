#include <cmath>
#include <iostream>
// 平方数之和
bool judgeSquareSum(int c) {
    long left = 0;
    long right = static_cast<long>(sqrt(c)); // 使用 long 来避免溢出问题

    while (left <= right) {
        long currentSum = left * left + right * right;
        if (currentSum == c) {
            return true;
        }
        else if (currentSum < c) {
            left++;
        }
        else {
            right--;
        }
    }

    return false;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1, sum;
    while (l < r) {
        sum = numbers[l] + numbers[r];
        if (sum == target) break;
        if (sum < target) ++l;
        else --r;
    }
    return vector<int>{l + 1, r + 1};
}

int main() {
    int c1 = 5;
    int c2 = 3;

    std::cout << std::boolalpha; // 使得布尔值以 true/false 形式输出
    std::cout << "judgeSquareSum(" << c1 << ") = " << judgeSquareSum(c1) << std::endl; // 输出：true
    std::cout << "judgeSquareSum(" << c2 << ") = " << judgeSquareSum(c2) << std::endl; // 输出：false

    return 0;
}

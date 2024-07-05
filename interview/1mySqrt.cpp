#include <iostream>
#include <vector>
// 二分查找也可以看作双指针的一种特殊情况，但我们一般会将二者区分。双指针类型的题，
// 指针通常是一步一步移动的，而在二分查找里，指针每次移动半个区间长度

using namespace std;
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
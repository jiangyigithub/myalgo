/*
剑指 Offer 51. 数组中的逆序对

    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
逆序对的数目可以标识一个数组和有序数组之间的距离，逆序对的数目越少，也数组变成有序数组的步数就越少，逆序对越多，原数组变成有序数组就需要更多的步骤。
对于一个有序的数组而言，逆序对的数目就是 0，而一个完全逆序的数组，逆序对的数目当然也就最多！
举个例子(前提假设升序为有序)，数组[1，2，3]，逆序对的数目为零；而数组[3，2，1]的逆序对就是3，分别为(3，2)、(3，1)和(2，1)。
举一个很具普适性的例子，对于一个包含 n 个数且无重复的逆序数组，逆序对的数目就等于 (n-1)+(n-2)+……+3+2+1=n(n-1)/2。

示例
输入: arr[]={8，5，4，2，1}
输出: 10
解释: 逆序对为(8，5)、(8，4)、(8，2)、(8，1)，(5，4)、(5，2)、(5，1)，还有(4，2)、(4，1)和(2，1)，总共10个。其实也可以直接计算5(5-1)/2=10，前提是知道数组完全逆序

输入: arr[]={5，1，4，2，8}
输出: 4
解释: 逆序对为(5，1)、(5，4)、(5，2)，还有(4，2)，总共4个。
在这里也可以看出数组{5，1，4，2，8}比{8，5，4，2，1}更有序，逆序对的数目可以衡量一个数组的有序程度。
*/
#include "head.hpp"

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        vector<int> tmp(nums.size());
        return mergeSort(0, nums.size() - 1, nums, tmp);
    }

private:
    int mergeSort(int l, int r, vector<int> &nums, vector<int> &tmp)
    {
        // recur end
        if (l >= r)
            return 0;
        int m = (l + r) / 2; //binary split
        // recur body
        int res = mergeSort(l, m, nums, tmp) + mergeSort(m + 1, r, nums, tmp);
        // double point i,j
        int i = l, j = m + 1; // i: the first element index of left sub array,j: the first element index of right sub array
        // copy elements from nums[] to temp[]
        for (int k = l; k <= r; k++)
        {
            tmp[k] = nums[k];
        }
        // select element from left sub-array and right sub-array
        for (int k = l; k <= r; k++)
        {
            // 左子数组已合并完 +1
            if (i == m + 1)
            {
                nums[k] = tmp[j];
                j++;
            }
            // 右子数组已合并完 +1
            else if (j == r + 1)
            {
                nums[k] = tmp[i];
                i++;
            }
            //if right >= left
            else if (tmp[i] <= tmp[j])
            {
                nums[k] = tmp[i]; //select left element
                i++;
            }
            //if left > right
            else if (tmp[i] > tmp[j])
            {
                nums[k] = tmp[j]; //select right element
                j++;
                res += (m - i + 1); //reverse pair
            }
            else
            {
                /** do nothing **/
            }
        }
        return res;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
                                       { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
                        { return !isspace(ch); })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

int main()
{
    string line = "[7,5,6,4]";
    // string line = "[7,3,2,6,0,1,5,4]";

    vector<int> nums = stringToIntegerVector(line);

    int ret = Solution().reversePairs(nums);

    string out = to_string(ret);
    cout << out << endl;

    return 0;
}
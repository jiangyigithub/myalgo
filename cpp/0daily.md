## 06/29 **Day 1**  **栈与队列（简单）**
1. 剑指 Offer 09. 用两个栈实现队列
2. 剑指 Offer 30.  包含 min 函数的栈

## 06/30 **Day 2** **链表（简单）**  
1. 剑指 Offer 06. 从尾到头打印链表
2. 剑指 Offer 24. 反转链表
3. 剑指 Offer 35. 复杂链表的复制

## 7/01 **Day 3**  **字符串（简单）**
1. 剑指 Offer 05. 替换空格
2. 剑指 Offer 58 - II. 左旋转字符串

## 7/02 **Day 4**  **查找算法（简单）** 
* Goal: binary search

* detail
双闭区间
optimize item: m = i + (j - i) / 2
i=m+1 j=m-1

* scenario
二分查找仅适用于有序数据

* extension
二分查找边界
二维

```c++
/// initinazation
int low = 0;
int high = arr.size() - 1;

/// dynamics update
low high mid
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
```

* `重复 VS 第一次出现`, these two concept is same

1. 剑指 Offer 03. 数组中重复的数字
`哈希查找`

2. 剑指 Offer 53 - I. 在排序数组中查找数字出现的次数
`二分查找边界` https://www.hello-algo.com/chapter_searching/binary_search_edge/#1022

3. 剑指 Offer 53 - II. 0～n-1 中缺失的数字
`二分查找`

## 7/03 **Day 5**  **查找算法（中等）**
1. 剑指 Offer 04. 二维数组中的查找
`二分查找`

2. 剑指 Offer 11. 旋转数组的最小数字
`二分查找`

3. 剑指 Offer 50. 第一个只出现一次的字符
`哈希查找`


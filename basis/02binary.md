* Goal:

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
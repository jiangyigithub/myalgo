"""
1. 对区间进行排序，根据左边界排序（对左边界排序后，就可以只考虑如何更新右边界的问题了）
2. intervals[i] 与result[-1]发现重叠区间，更新result[-1]的右边界
2. intervals[i] 与result[-1]无重叠，intervals[i]设置为result[-1]

两个对象:
待更新项：result[-1]
待merge项: intervals[i]

trick:
1. 跟消消乐有点像，可能会触发连环消消乐
2. for (if, else) 结构
https://leetcode.cn/problems/merge-intervals/description/
"""
def merge_segments(intervals):
    result = []
    if len(intervals) == 0:
        return result  # 区间集合为空直接返回

    intervals.sort(key=lambda x: x[0])  # 按照区间的左边界进行排序

    result.append(intervals[0])  # 第一个区间可以直接放入结果集中，一开始result[-1]是第一个区间，后面result[-1]会更新

    for i in range(1, len(intervals)):
        if result[-1][1] >= intervals[i][0]:  # 发现重叠区间
            # 合并区间，只需要更新结果集最后一个区间的右边界，因为根据排序，左边界已经是最小的
            result[-1][1] = max(result[-1][1], intervals[i][1])
        else:
            result.append(intervals[i])  # 区间不重叠，才会被放在result中，result[-1]的左边界不会再更新，在下一次迭代中，右边界可能会被更新，result[-2]倒数第二个元素的边界不会再更新，

    return result

# 测试代码
segments = [[1, 3], [2, 6], [8, 10], [15, 18]]
merged = merge_segments(segments)
print("拼接后的线段：", merged)
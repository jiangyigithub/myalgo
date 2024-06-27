"""
1. 对区间进行排序，根据左边界排序
2. 更新区间右边界
2. 无法再更新，则存放merge好的结果
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
            result.append(intervals[i])  # 区间不重叠，才会被放在result中

    return result

# 测试代码
segments = [[1, 3], [2, 6], [8, 10], [15, 18]]
merged = merge_segments(segments)
print("拼接后的线段：", merged)
def merge(nums1, m, nums2, n):
    i, j, k = m - 1, n - 1, m + n - 1

    while i >= 0 and j >= 0:
        if nums1[i] > nums2[j]:
            nums1[k] = nums1[i]
            i -= 1
        else:
            nums1[k] = nums2[j]
            j -= 1
        k -= 1

    while j >= 0:
        nums1[k] = nums2[j]
        j -= 1
        k -= 1

# 测试用例
test_cases = [
    # 基本情况
    ([1, 2, 3, 0, 0, 0], 3, [2, 5, 6], 3, [1, 2, 2, 3, 5, 6]),
    # nums2 为空
    ([1, 2, 3, 0, 0, 0], 3, [], 0, [1, 2, 3, 0, 0, 0]),
    # nums1 为空（只有填充位）
    ([0, 0, 0], 0, [2, 5, 6], 3, [2, 5, 6]),
    # 所有元素都相同
    ([1, 1, 1, 0, 0, 0], 3, [1, 1, 1], 3, [1, 1, 1, 1, 1, 1]),
    # nums1 中的所有元素都小于 nums2 中的所有元素
    ([1, 2, 3, 0, 0, 0], 3, [4, 5, 6], 3, [1, 2, 3, 4, 5, 6]),
    # nums1 中的所有元素都大于 nums2 中的所有元素
    ([4, 5, 6, 0, 0, 0], 3, [1, 2, 3], 3, [1, 2, 3, 4, 5, 6]),
    # 不同长度的数组
    ([1, 3, 5, 0, 0], 3, [2, 4], 2, [1, 2, 3, 4, 5]),
    ([1, 2, 0, 0, 0, 0, 0], 2, [3, 4, 5, 6, 7], 5, [1, 2, 3, 4, 5, 6, 7])
]

# 运行测试
for nums1, m, nums2, n, expected in test_cases:
    merge(nums1, m, nums2, n)
    print(f"nums1 after merging: {nums1}, expected: {expected}, passed: {nums1 == expected}")

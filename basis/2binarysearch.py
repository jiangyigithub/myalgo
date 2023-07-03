def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1


def main():
    # Example test cases
    arr = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
    target1 = 12
    target2 = 7

    # Test case 1: Target value exists in the array
    index1 = binary_search(arr, target1)
    if index1 != -1:
        print(f"Target value {target1} found at index {index1}")
    else:
        print(f"Target value {target1} not found in the array")

    # Test case 2: Target value does not exist in the array
    index2 = binary_search(arr, target2)
    if index2 != -1:
        print(f"Target value {target2} found at index {index2}")
    else:
        print(f"Target value {target2} not found in the array")


if __name__ == "__main__":
    main()

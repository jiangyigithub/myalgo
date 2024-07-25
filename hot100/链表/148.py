class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortList2(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head # termination.
        # cut the LinkedList at the mid index.
        slow, fast = head, head.next
        while fast and fast.next:
            fast, slow = fast.next.next, slow.next
        mid, slow.next = slow.next, None # save and cut.
        # recursive for cutting.
        left, right = self.sortList(head), self.sortList(mid) # 递归终止时，执行下面的代码
        # merge left and right linked list and return it.
        h = res = ListNode(0)
        while left and right:
            if left.val < right.val: h.next, left = left, left.next
            else: h.next, right = right, right.next
            h = h.next
        h.next = left if left else right
        return res.next
    

    def sortList(self, head: ListNode) -> ListNode:
        h, length, intv = head, 0, 1
        while h: h, length = h.next, length + 1
        res = ListNode(0)
        res.next = head
        # merge the list in different intv.
        while intv < length:
            pre, h = res, res.next
            while h:
                # get the two merge head `h1`, `h2`
                h1, i = h, intv
                while i and h: h, i = h.next, i - 1
                if i: break # no need to merge because the `h2` is None.
                h2, i = h, intv
                while i and h: h, i = h.next, i - 1
                c1, c2 = intv, intv - i # the `c2`: length of `h2` can be small than the `intv`.
                # merge the `h1` and `h2`.
                while c1 and c2:
                    if h1.val < h2.val: pre.next, h1, c1 = h1, h1.next, c1 - 1
                    else: pre.next, h2, c2 = h2, h2.next, c2 - 1
                    pre = pre.next
                pre.next = h1 if c1 else h2
                while c1 > 0 or c2 > 0: pre, c1, c2 = pre.next, c1 - 1, c2 - 1
                pre.next = h 
            intv *= 2
        return res.next


# Helper functions to create a linked list from a list and to convert a linked list to a list
def createLinkedList(values):
    dummy = ListNode(0)
    current = dummy
    for value in values:
        current.next = ListNode(value)
        current = current.next
    return dummy.next

def linkedListToList(head):
    result = []
    while head:
        result.append(head.val)
        head = head.next
    return result

# Structure to store test cases
class TestCase:
    def __init__(self, input_list, expected_list):
        self.input = createLinkedList(input_list)
        self.expected = expected_list
        self.actual = []
        self.passed = False

# Function to run test cases
def runTestCases():
    solution = Solution()
    testCases = [
        TestCase([4, 2, 1, 3], [1, 2, 3, 4])
        # ,
        # TestCase([-1, 5, 3, 4, 0], [-1, 0, 3, 4, 5]),
        # TestCase([], []),
        # TestCase([1], [1])
    ]

    for testCase in testCases:
        result = solution.sortList(testCase.input)
        testCase.actual = linkedListToList(result)
        testCase.passed = (testCase.actual == testCase.expected)

    # Print test results
    for i, testCase in enumerate(testCases):
        print(f"Test Case {i + 1}:")
        print(f"Input: {linkedListToList(testCase.input)}")
        print(f"Expected: {testCase.expected}")
        print(f"Actual: {testCase.actual}")
        print(f"Passed: {'Yes' if testCase.passed else 'No'}\n")

if __name__ == "__main__":
    runTestCases()

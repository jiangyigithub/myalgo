class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        if not head:
            return None
        p = head
        # 第一步，在每个原节点后面创建一个新节点
        # 1->1'->2->2'->3->3'
        while p:
            new_node = Node(p.val,None,None)
            new_node.next = p.next
            p.next = new_node
            p = new_node.next
        p = head
        # 第二步，设置新节点的随机节点
        while p:
            if p.random:
                p.next.random = p.random.next
            p = p.next.next
        # 第三步，将两个链表分离
        p = head
        dummy = Node(-1,None,None)
        cur = dummy
        while p:
            cur.next = p.next
            cur = cur.next
            p.next = cur.next
            p = p.next
        return dummy.next

def print_list(node: Node):
    while node:
        random_val = node.random.val if node.random else "NULL"
        print(f"Node(val: {node.val}, random: {random_val})")
        node = node.next

def list_to_vector(node: Node):
    result = []
    while node:
        random_val = node.random.val if node.random else -1
        result.append((node.val, random_val))
        node = node.next
    return result

def compare_vectors(actual, expected):
    if len(actual) != len(expected):
        return False
    for a, e in zip(actual, expected):
        if a != e:
            return False
    return True

def run_test_case(test_case, solution):
    head, expected_values = test_case
    copied_list = solution.copyRandomList(head)
    actual_values = list_to_vector(copied_list)
    
    # Print the actual copied list
    print("Copied list:")
    print_list(copied_list)
    
    # Check if the result matches the expected values
    pass_test = compare_vectors(actual_values, expected_values)
    
    # Print the detailed results
    print("Expected values:")
    for v in expected_values:
        random_val = "NULL" if v[1] == -1 else v[1]
        print(f"(val: {v[0]}, random: {random_val})")
    
    print("Actual values:")
    for v in actual_values:
        random_val = "NULL" if v[1] == -1 else v[1]
        print(f"(val: {v[0]}, random: {random_val})")
    
    print(f"Test case {'PASSED' if pass_test else 'FAILED'}")
    print()

# Test cases
test_cases = [
    (None, []),  # Test case 1: Empty list

    (Node(1), [(1, -1)]),  # Test case 2: Single node with no random pointer

    (Node(2, random=None), [(2, 2)]),  # Test case 3: Single node with a random pointer to itself

    (Node(3, Node(4, Node(5))), [(3, -1), (4, -1), (5, -1)]),  # Test case 4: Multiple nodes with no random pointers

    # Test case 5: Multiple nodes with random pointers
    (Node(6, Node(7, Node(8, Node(9)))), [(6, 8), (7, 6), (8, 9), (9, 7)]),
]

# Set up random pointers for test case 5
node6 = test_cases[4][0]
node7 = node6.next
node8 = node7.next
node9 = node8.next
node6.random = node8
node7.random = node6
node8.random = node9
node9.random = node7

# Initialize Solution object
sol = Solution()

# Run all test cases
for i, test_case in enumerate(test_cases):
    print(f"Running Test Case {i + 1}")
    run_test_case(test_case, sol)


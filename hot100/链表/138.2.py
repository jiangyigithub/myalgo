class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        if not head:
            return None
        # 创建一个哈希表，key是原节点，value是新节点    
        d = dict()
        p = head
        # 将原节点和新节点放入哈希表中
        while p:
            new_node = Node(p.val,None,None)
            d[p] = new_node
            p = p.next
        p = head
        # 遍历原链表，设置新节点的next和random
        while p:
            # p是原节点，d[p]是对应的新节点，p.next是原节点的下一个
            # d[p.next]是原节点下一个对应的新节点
            if p.next:
                d[p].next = d[p.next]
            # p.random是原节点随机指向
            # d[p.random]是原节点随机指向  对应的新节点    
            if p.random:
                d[p].random = d[p.random]
            p = p.next
        # 返回头结点，即原节点对应的value(新节点)
        return d[head]

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


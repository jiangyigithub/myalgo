#include <iostream>
#include <vector>
#include <tuple>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 反转链表的前 k 个节点
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *dummy = new ListNode(0, head), *p0 = dummy, *cur = head, *pre = nullptr;
    int len = 0;
    while (cur)
    {
        len++;
        cur = cur->next;
    }
    // p0 前一个节点，动态前一个节点
    cur = head; // re init
    while (len >= k)
    {
        len -= k;
        for (int i = 0; i < k; ++i)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;// 移动
            cur = nxt;
        }

        // 构建链接，更新p0
        // p0->pre->cur
        ListNode *nxtp0 = p0->next;
        p0->next->next = cur;
        p0->next = pre;
        p0 = nxtp0;
    }
    return dummy->next;
}

// Helper function to create a linked list from a vector
ListNode *createLinkedList(const std::vector<int> &values)
{
    ListNode dummy;
    ListNode *current = &dummy;
    for (int value : values)
    {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy.next;
}

// Helper function to convert a linked list to a vector
std::vector<int> linkedListToVector(ListNode *head)
{
    std::vector<int> result;
    while (head)
    {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Test the reverseKGroup function
void testReverseKGroup()
{
    struct TestCase
    {
        std::vector<int> input;
        int k;
        std::vector<int> expected;
    };

    std::vector<TestCase> testCases = {
        {{1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5}},
        {{1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5}},
        {{1}, 1, {1}},
        {{1, 2}, 1, {1, 2}},
        {{1, 2, 3, 4}, 4, {4, 3, 2, 1}}};

    for (int i = 0; i < testCases.size(); ++i)
    {
        const auto &[inputVec, k, expected] = testCases[i];
        ListNode *head = createLinkedList(inputVec);
        ListNode *newHead = reverseKGroup(head, k);
        std::vector<int> actual = linkedListToVector(newHead);

        std::cout << "Test Case " << (i + 1) << ":\n";
        std::cout << "Input: ";
        for (int val : inputVec)
            std::cout << val << " ";
        std::cout << "\nExpected: ";
        for (int val : expected)
            std::cout << val << " ";
        std::cout << "\nActual: ";
        for (int val : actual)
            std::cout << val << " ";
        std::cout << "\nPassed: " << (actual == expected ? "Yes" : "No") << "\n\n";

        // Clean up linked list memory
        while (newHead != nullptr)
        {
            ListNode *temp = newHead;
            newHead = newHead->next;
            delete temp;
        }
    }
}

int main()
{
    testReverseKGroup();
    return 0;
}

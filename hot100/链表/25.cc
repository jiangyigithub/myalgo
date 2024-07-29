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
            // 构建链接
            cur->next = pre;
            // 移动,更新pre,cur
            pre = cur;
            cur = nxt;
        }

        // dummy 固定head的前一个节点，当前区间的p0，下个区间的nxtp0，
        // p0动态dummy,p0->next为链表头，反转后为反转链表的尾巴
        /// p0为区间动态dummy,存放原始区间链表的前一个节点和头节点
        ListNode *nxtp0 = p0->next; // 反转后，头节点为下一个区间的前一个节点  p0->区间1，以p0->next结尾->区间2
        // p0->nxtp0 AB-> CD
        // P0-> BA nxtp0->CD
        // BA nxtp0为 pre，CD 为cur
        // 构建链接 p0->pre ...nxtp0->cur
        p0->next = pre;
        nxtp0->next = cur;
        //更新p0 
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
        {{1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5}},
        {{1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5}},
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

#include <iostream>
#include <vector>
#include <tuple>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to reverse a linked list
ListNode* reverse(ListNode* head) {
    // 单链表为空或只有一个节点，直接返回原单链表
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // 前一个节点指针
    ListNode* preNode = nullptr;
    // 当前节点指针
    ListNode* curNode = head;
    // 下一个节点指针
    ListNode* nextNode = nullptr;
    while (curNode != nullptr) {
        nextNode = curNode->next; // nextNode 指向下一个节点, 保存当前节点后面的链表。
        curNode->next = preNode;  // 将当前节点 next 域指向前一个节点
        preNode = curNode;        // preNode 指针向后移动。preNode 指向当前节点。
        curNode = nextNode;       // curNode 指针向后移动。下一个节点变成当前节点
    }
    return preNode;
}

// 反转链表的前 k 个节点
ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k <= 1) return head;

    ListNode *dummy = new ListNode(0);  // 虚拟头节点
    dummy->next = head;
    ListNode *cur = dummy, *nex = dummy, *pre = dummy;
    int count = 0;

    // 计算链表长度
    while (cur->next != nullptr) {
        cur = cur->next;
        count++;
    }

    // 进行反转
    while (count >= k) {
        cur = pre->next;  // 每次操作的开始节点
        nex = cur->next; // 每次操作的第二节点
        for (int i = 1; i < k; ++i) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        count -= k;
    }

    return dummy->next;
}


// Function to reverse every k nodes in the linked list
ListNode* reverseKGroup2(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) return head;

    // 定义一个假的节点。
    ListNode dummy(0);
    // 假节点的 next 指向 head。
    // dummy -> 1 -> 2 -> 3 -> 4 -> 5
    dummy.next = head;
    // 初始化 pre 和 end 都指向 dummy。pre 指每次要翻转的链表的头结点的上一个节点。end 指每次要翻转的链表的尾节点
    ListNode* pre = &dummy;
    ListNode* end = &dummy;

    while (end->next != nullptr) {
        // 循环 k 次，找到需要翻转的链表的结尾, 这里每次循环要判断 end 是否等于空，因为如果为空，end.next 会报空指针异常。
        // dummy -> 1 -> 2 -> 3 -> 4 -> 5 若 k 为 2，循环 2 次，end 指向 2
        for (int i = 0; i < k && end != nullptr; ++i) {
            end = end->next;
        }
        // 如果 end == nullptr，即需要翻转的链表的节点数小于 k，不执行翻转。
        if (end == nullptr) break;

        // 先记录下 end.next, 方便后面链接链表
        ListNode* next = end->next;
        // 然后断开链表
        end->next = nullptr;

        // 记录下要翻转链表的头节点
        ListNode* start = pre->next;
        // 翻转链表, pre.next 指向翻转后的链表。1 -> 2 变成 2 -> 1。 dummy -> 2 -> 1
        pre->next = reverse(start);
        // 翻转后头节点变到最后。通过 .next 把断开的链表重新链接。
        start->next = next;
        // 将 pre 换成下次要翻转的链表的头结点的上一个节点。即 start
        pre = start;
        // 翻转结束，将 end 置为下次要翻转的链表的头结点的上一个节点。即 start
        end = pre;
    }
    return dummy.next;
}

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode dummy;
    ListNode* current = &dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy.next;
}

// Helper function to convert a linked list to a vector
std::vector<int> linkedListToVector(ListNode* head) {
    std::vector<int> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// Test the reverseKGroup function
void testReverseKGroup() {
    struct TestCase {
        std::vector<int> input;
        int k;
        std::vector<int> expected;
    };

    std::vector<TestCase> testCases = {
        {{1, 2, 3, 4, 5}, 3, {3, 2, 1, 4, 5}},
        {{1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5}},
        {{1}, 1, {1}},
        {{1, 2}, 1, {1, 2}},
        {{1, 2, 3, 4}, 4, {4, 3, 2, 1}}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        const auto& [inputVec, k, expected] = testCases[i];
        ListNode* head = createLinkedList(inputVec);
        ListNode* newHead = reverseKGroup(head, k);
        std::vector<int> actual = linkedListToVector(newHead);

        std::cout << "Test Case " << (i + 1) << ":\n";
        std::cout << "Input: ";
        for (int val : inputVec) std::cout << val << " ";
        std::cout << "\nExpected: ";
        for (int val : expected) std::cout << val << " ";
        std::cout << "\nActual: ";
        for (int val : actual) std::cout << val << " ";
        std::cout << "\nPassed: " << (actual == expected ? "Yes" : "No") << "\n\n";

        // Clean up linked list memory
        while (newHead != nullptr) {
            ListNode* temp = newHead;
            newHead = newHead->next;
            delete temp;
        }
    }
}

int main() {
    testReverseKGroup();
    return 0;
}

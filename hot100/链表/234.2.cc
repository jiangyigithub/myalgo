#include <iostream>
#include <vector>
using namespace std;

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 判断链表是否为回文链表的函数
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    
    // 找到链表的中间节点（慢指针到达的位置）
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // 反转链表的后半部分
    ListNode* prev = nullptr;
    while (slow) {
        ListNode* next_node = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next_node;
    }
    
    // 比较前半部分和后半部分
    ListNode* left = head;
    ListNode* right = prev;
    while (right) { // 只需要比较后半部分的长度
        if (left->val != right->val) return false;
        left = left->next;
        right = right->next;
    }
    
    return true;
}

// 测试用例结构体
struct TestCase {
    vector<int> node_values;
    bool expected;
    bool actual;
    bool passed;

    TestCase(vector<int> values, bool exp) : node_values(values), expected(exp) {
        ListNode* head = createLinkedList(node_values);
        actual = isPalindrome(head);
        passed = (actual == expected);
    }

    ListNode* createLinkedList(const vector<int>& values) {
        if (values.empty()) return nullptr;
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        for (size_t i = 1; i < values.size(); ++i) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        return head;
    }

    void print() const {
        cout << "Node values: ";
        for (int val : node_values) cout << val << " ";
        cout << "\nExpected: " << (expected ? "True" : "False")
             << "\nActual: " << (actual ? "True" : "False")
             << "\nPassed: " << (passed ? "True" : "False") << "\n";
    }
};

int main() {
    // 创建测试用例
    vector<TestCase> test_cases = {
        TestCase({1, 2, 3, 2, 1}, true),
        TestCase({1, 2, 3, 4, 5}, false),
        TestCase({1, 2, 2, 1}, true),
        TestCase({1, 2, 3, 4, 3, 2, 1}, true),
        TestCase({1}, true),
        TestCase({}, true),
    };

    // 输出每个测试用例的详细信息
    for (size_t i = 0; i < test_cases.size(); ++i) {
        cout << "Test Case " << i + 1 << ":\n";
        test_cases[i].print();
        cout << "--------------------------------------------------\n";
    }

    return 0;
}

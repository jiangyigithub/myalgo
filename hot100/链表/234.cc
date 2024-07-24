#include <iostream>
#include <vector>

// 定义链表节点
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 定义测试用例结构体
struct TestCase
{
    std::vector<int> values;
    bool expected;
    ListNode *head;
    bool actual;
    bool passed;

    // 构造函数
    TestCase(std::vector<int> vals, bool exp) : values(vals), expected(exp), head(nullptr), actual(false), passed(false)
    {
        head = createLinkedList(values);
    }

    // 创建链表
    ListNode *createLinkedList(const std::vector<int> &vals)
    {
        if (vals.empty())
            return nullptr;
        ListNode *head = new ListNode(vals[0]);
        ListNode *current = head;
        for (size_t i = 1; i < vals.size(); ++i)
        {
            current->next = new ListNode(vals[i]);
            current = current->next;
        }
        return head;
    }
};

// 深拷贝链表
ListNode *deepCopyList(ListNode *head)
{
    if (!head)
        return nullptr;

    ListNode *newHead = new ListNode(head->val);
    ListNode *currentOriginal = head->next;
    ListNode *currentNew = newHead;

    while (currentOriginal)
    {
        currentNew->next = new ListNode(currentOriginal->val);
        currentNew = currentNew->next;
        currentOriginal = currentOriginal->next;
    }

    return newHead;
}

// 反转链表
ListNode *reverseList(ListNode *head)
{
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur)
    {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

bool isPalindrome(ListNode *head)
{
    ListNode *a = deepCopyList(head);
    ListNode *b = reverseList(head);
    bool ret = true;
    while (a != nullptr)
    {
        if (a->val != b->val)
        {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return ret;
}

// 判断是否为回文链表的函数
bool isPalindrome2(ListNode *head)
{
    if (!head || !head->next)
        return true;

    // 找到中间节点
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 反转后半部分链表
    ListNode *prev = nullptr;
    while (slow)
    {
        ListNode *next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // 比较前半部分和反转后的后半部分
    ListNode *left = head;
    ListNode *right = prev;
    while (right)
    {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }

    return true;
}

// 打印测试结果
void printTestResult(const TestCase &test)
{
    std::cout << "Test case: ";
    for (int val : test.values)
    {
        std::cout << val << " ";
    }
    std::cout << "\nExpected result: " << (test.expected ? "true" : "false");
    std::cout << "\nActual result: " << (test.actual ? "true" : "false");
    std::cout << "\nTest passed: " << (test.passed ? "true" : "false");
    std::cout << "\n----------------------------------------\n";
}

// 运行测试
void runTests(std::vector<TestCase> &testCases)
{
    for (auto &test : testCases)
    {
        test.actual = isPalindrome(test.head);
        test.passed = (test.actual == test.expected);
        printTestResult(test);
    }
}

int main()
{
    // 测试用例
    std::vector<TestCase> testCases = {
        TestCase({1, 1, 2, 1}, false)
        // ,
        // TestCase({1, 2, 2, 1}, true),
        // TestCase({1, 2}, false),
        // TestCase({1, 2, 3, 2, 1}, true),
        // TestCase({}, true),
        // TestCase({1}, true)
    };

    // 运行测试
    runTests(testCases);

    return 0;
}

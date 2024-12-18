#include <iostream>
#include <vector>

using namespace std;
/*
sum+=a;
sum+=b;
--> sum = a+b;

移位-->和指针移动

*/
// 定义链表节点结构体
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 添加两个链表表示的数字并返回结果链表
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0);          // 哨兵节点，简化代码
    ListNode *cur = &dummy; // 指向当前处理的节点
    int carry = 0;              // 进位

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int sum = 0;

        if (l1 != nullptr)
        {
            sum += l1->val; // 加上l1的值
            l1 = l1->next;  // 移动到下一个节点
        }

        if (l2 != nullptr)
        {
            sum += l2->val; // 加上l2的值
            l2 = l2->next;  // 移动到下一个节点
        }

        if (carry != 0)
        {
            sum += carry;
        }
        carry = sum / 10;                       // 更新进位，carry值由当前周期计算得到，但在下一个周期才被使用
        cur->next = new ListNode(sum % 10); // 创建新节点存储当前位的数字
        cur = cur->next;                // 移动到下一个节点
    }

    return dummy.next; // 返回结果链表
}

// 打印链表
void printList(ListNode *node)
{
    while (node != nullptr)
    {
        std::cout << node->val;
        node = node->next;
        if (node != nullptr)
        {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

// 创建链表
ListNode *createList(const std::vector<int> &nums)
{
    ListNode dummy(0);
    ListNode *cur = &dummy;
    for (int num : nums)
    {
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    return dummy.next;
}

// 释放链表内存
void freeList(ListNode *node)
{
    while (node != nullptr)
    {
        ListNode *temp = node;
        node = node->next;
        delete temp;
    }
}

// 定义测试用例结构体
struct TestCase
{
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> expected;
};

// 运行单个测试用例
void runTestCase(const TestCase &testCase)
{
    ListNode *l1 = createList(testCase.nums1);
    ListNode *l2 = createList(testCase.nums2);
    ListNode *result = addTwoNumbers(l1, l2);

    // 打印测试用例信息
    std::cout << "Input: ";
    printList(l1);
    std::cout << "       ";
    printList(l2);
    std::cout << "Expected Output: ";
    printList(createList(testCase.expected));
    std::cout << "Actual Output: ";
    printList(result);

    // 比较实际输出和预期输出
    ListNode *expectedList = createList(testCase.expected);
    ListNode *p1 = expectedList;
    ListNode *p2 = result;
    bool passed = true;

    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->val != p2->val)
        {
            passed = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    if (passed && p1 == nullptr && p2 == nullptr)
    {
        std::cout << "Passed" << std::endl;
    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    // 释放内存
    freeList(l1);
    freeList(l2);
    freeList(result);
    freeList(expectedList);
}

// 主测试函数
void testAddTwoNumbers()
{
    std::vector<TestCase> testCases = {
        // 测试用例 1
        {{2, 4, 3}, {5, 6, 4}, {7, 0, 8}},

        // 测试用例 2
        {{9, 9, 9}, {1}, {0, 0, 0, 1}},

        // 测试用例 3
        {{1, 8}, {0}, {1, 8}},

        // 测试用例 4
        {{3, 3, 3}, {7, 7, 7}, {0, 1, 1, 1}},

        // 测试用例 5
        {{}, {9, 9, 9}, {9, 9, 9}},

        // 测试用例 6
        {{}, {}, {}}};

    std::cout << "Running Test Cases..." << std::endl;
    for (int i = 0; i < testCases.size(); ++i)
    {
        std::cout << "Test Case " << i + 1 << ": ";
        runTestCase(testCases[i]);
        std::cout << std::endl;
    }
}

int main()
{
    testAddTwoNumbers();
    return 0;
}

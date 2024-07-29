#include <iostream>
#include <vector>

using namespace std;

// 定义链表节点结构体
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 创建新节点的函数
ListNode *createNode(int val)
{
    return new ListNode(val);
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0), *cur = dummy;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy->next;
}

std::vector<int> listToArray(ListNode *head)
{
    std::vector<int> result;
    while (head != nullptr)
    {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// 辅助函数：打印向量
void printArray(const std::vector<int> &arr)
{
    for (int val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

struct TestCase
{
    ListNode *l1;
    ListNode *l2;
    std::vector<int> expected;
    std::string description;
};

void test(TestCase testCase)
{
    ListNode *result = mergeTwoLists(testCase.l1, testCase.l2);
    std::vector<int> resultArray = listToArray(result);

    std::cout << "测试描述: " << testCase.description << std::endl;
    std::cout << "预期结果: ";
    printArray(testCase.expected);
    std::cout << "实际结果: ";
    printArray(resultArray);

    if (resultArray == testCase.expected)
    {
        std::cout << "测试通过" << std::endl;
    }
    else
    {
        std::cout << "测试未通过" << std::endl;
    }
    std::cout << "---------------------" << std::endl;
}

int main()
{
    // 测试用例1
    ListNode *l1_1 = createNode(1);
    l1_1->next = createNode(2);
    l1_1->next->next = createNode(4);

    ListNode *l2_1 = createNode(1);
    l2_1->next = createNode(3);
    l2_1->next->next = createNode(4);

    TestCase testCase1 = {l1_1, l2_1, {1, 1, 2, 3, 4, 4}, "测试用例1：两个有序链表均有多个元素"};

    // 测试用例2
    ListNode *l1_2 = nullptr;
    ListNode *l2_2 = nullptr;

    TestCase testCase2 = {l1_2, l2_2, {}, "测试用例2：两个链表均为空"};

    // 测试用例3
    ListNode *l1_3 = nullptr;
    ListNode *l2_3 = createNode(0);

    TestCase testCase3 = {l1_3, l2_3, {0}, "测试用例3：一个链表为空，另一个链表有一个元素"};

    // 测试用例4
    ListNode *l1_4 = createNode(2);
    l1_4->next = createNode(6);
    ListNode *l2_4 = createNode(1);
    l2_4->next = createNode(8);

    TestCase testCase4 = {l1_4, l2_4, {1, 2, 6, 8}, "测试用例4：两个链表均有不同长度"};

    // 运行测试用例
    test(testCase1);
    test(testCase2);
    test(testCase3);
    test(testCase4);

    return 0;
}

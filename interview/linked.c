#include <stdio.h>
#include <stdlib.h>

// 结构定义
typedef struct node_t {
    int value;
    struct node_t* next;
} Node;

// 查找列表中是否存在某个节点，如果未找到则返回 "0"
int inList(Node* pHead, int value) {
    Node* current = pHead;
    while (current != NULL) {
        if (current->value == value) {
            return 1; // 节点存在
        }
        current = current->next;
    }
    return 0; // 节点不存在
}

// 从列表中移除一个值。如果该值不存在于列表中，则返回 "0"
int removeValue(Node** ppHead, int value) {
    Node* current = *ppHead;
    Node* previous = NULL;

    // 遍历链表直到找到值或到达末尾
    while (current != NULL) {
        if (current->value == value) {
            // 找到了要删除的值
            if (previous == NULL) {
                // 如果要删除的值是头节点，则更新头指针
                *ppHead = current->next;
            } else {
                // 如果要删除的值不是头节点，则调整前一个节点的指针
                previous->next = current->next;
            }
            free(current); // 释放内存
            return 1; // 删除成功
        }
        previous = current;
        current = current->next;
    }
    return 0; // 未找到要删除的值
}

// 测试函数
int main() {
    // 创建链表: 1 -> 2 -> 3 -> NULL
    Node* head = (Node*)malloc(sizeof(Node));
    head->value = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->value = 2;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->value = 3;
    head->next->next->next = NULL;

    // 测试inList函数
    printf("Testing inList function:\n");
    printf("Does 2 exist in the list? %d\n", inList(head, 2)); // 应输出 1
    printf("Does 4 exist in the list? %d\n", inList(head, 4)); // 应输出 0

    // 测试removeValue函数
    printf("\nTesting removeValue function:\n");
    printf("Removing value 2 from the list...\n");
    removeValue(&head, 2);
    printf("Does 2 exist in the list now? %d\n", inList(head, 2)); // 应输出 0

    // 释放链表的内存
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include"CycleLinkList.h"

// 创建一个带头节点的循环链表，包含 n 个结点，数据从 1 到 n
void CreateList(CycleLinkList *L, int n) {
    int a[n];
    *L = (LNode *)malloc(sizeof(LNode));
    if (!*L) {
        exit(1);
    }
    (*L)->data = n;
    (*L)->next = *L;
    printf("请输入链表");
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    
    LNode *current = *L;

    for (int i = 1; i <= n; i++) {
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        if (!newNode) {
            exit(1);
        }
        newNode->data = a[i-1];
        newNode->next = current->next;
        current->next = newNode;
        current = newNode;
    }
}



// 就地逆置链表
void ReverseList(CycleLinkList *L) {
    LNode *pre = (*L)->next;
    LNode *current = pre->next;

    while (current != *L) {
        pre->next = current->next;
        current->next = (*L)->next;
        (*L)->next = current;
        current = pre->next;
    }
}

int main() {
    CycleLinkList L;
    int n;  // 假设有 6 个结点
    printf("请输入链表长度");
    scanf("%d",&n);

    InitList(&L);
    CreateList(&L, n);

    printf("初始链表：");
    PrintList(L);

    ReverseList(&L);
    printf("逆置后的链表：");
    PrintList(L);
    return 0;
}

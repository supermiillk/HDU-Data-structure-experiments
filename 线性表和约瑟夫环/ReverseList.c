#include <stdio.h>
#include <stdlib.h>
#include"CycleLinkList.h"

int main() {
    CycleLinkList L;
    int n;  // 假设有 6 个结点
    printf("请输入链表长度");
    scanf("%d",&n);

    InitList(&L);
    CreateList(&L,n);

    printf("初始链表：");
    PrintList(L);

    ReverseList(&L);
    printf("逆置后的链表：");
    PrintList(L);
    return 0;
}

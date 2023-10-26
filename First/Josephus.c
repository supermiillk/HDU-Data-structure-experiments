#include<stdio.h>
#include<stdlib.h>
#include"CycleLinkList.h"

void CreateList(CycleLinkList *L, int n) {
    (*L)->data=1;
    LNode *current = *L;
    for (int i = 2; i <= n; i++) {
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        if (!newNode) {
            exit(1);
        }
        newNode->data = i;
        newNode->next = current->next;
        current->next = newNode;
        current = newNode;
    }
}

void Josephus(CycleLinkList L, int m) {
    LNode *current = L;
    LNode *pre = L;
    while (current->next != current) {
        int count = 0;
        while (count < m-1) {
            pre = current;
            current = current->next;
            count++;
        }
        pre->next = current->next;
        printf("%d ", current->data);
        free(current);
        current = pre->next;
    }
    printf("%d\n", current->data);
}

int main() {
    int n, m;
    printf("请输入总人数 n：");
    scanf("%d", &n);
    printf("请输入报数间隔 m：");
    scanf("%d", &m);
    CycleLinkList L;
    InitList(&L);
    CreateList(&L,n);
    int a;
    GetElem(L,1,&a);
    printf("%d/n",a);
    Josephus(L, m);
    DestroyList(&L);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include"CycleLinkList.h"

// ����һ����ͷ�ڵ��ѭ���������� n ����㣬���ݴ� 1 �� n
void CreateList(CycleLinkList *L, int n) {
    int a[n];
    *L = (LNode *)malloc(sizeof(LNode));
    if (!*L) {
        exit(1);
    }
    (*L)->data = n;
    (*L)->next = *L;
    printf("����������");
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



// �͵���������
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
    int n;  // ������ 6 �����
    printf("������������");
    scanf("%d",&n);

    InitList(&L);
    CreateList(&L, n);

    printf("��ʼ����");
    PrintList(L);

    ReverseList(&L);
    printf("���ú������");
    PrintList(L);
    return 0;
}

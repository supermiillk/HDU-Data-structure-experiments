#include "CycleLinkList.h"
#include<stdlib.h>
#include<stdio.h>

void InitList(CycleLinkList *L){
    *L = (LNode*)malloc(sizeof(LNode));
    if (!*L) exit(1);
    (*L)->data = 0;
    (*L)->next = *L;
}

void DestroyList(CycleLinkList *L){
  ClearList(L);
    free(*L);
    *L = NULL;
}

void ClearList(CycleLinkList *L){
    if (*L == NULL) {
        return;
    }

    LNode *current = (*L)->next;
    while (current != *L) {
        LNode *temp = current;
        current = current->next;
        free(temp);
    }

    (*L)->next = *L;
}

int ListEmpty(CycleLinkList L){
    return L == NULL || L->next == L;
}

int ListLength(CycleLinkList L){
    if (L == NULL) {
        return 0;
    }
    int length = 0;
    LNode *current = L->next;
    while (current != L) {
        length++;
        current = current->next;
    }
    return length;
}

void GetElem(CycleLinkList L,int i,ElemType *e){
    if (L == NULL || i <= 0) {
        printf("����������");
        exit(1); // ʧ�ܣ�����Ϊ�ջ�������Ч
    }

    CycleLinkList current = L->next;
    int count = 1;

    while (count < i) {
        current = current->next;
        count++;

        if (current == L) {
            printf("����������");
            exit(1); // ʧ�ܣ���������������
        }
    }

    *e = current->data; // �ɹ���e �д洢�˵� i ��λ�õ�ֵ
}


void ListInsert(CycleLinkList *L,int i,ElemType e){
   LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL) {
        // �ڴ����ʧ�ܴ���
        exit(1);
    }
    newNode->data = e;

    LNode *current = *L;
    int count = 0;

    while (count < i && current->next != *L) {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    current->next = newNode;
    if (i == 1) {
        *L = newNode; // ���ڵ�һ��λ�ò��룬��Ҫ����ͷָ��
    }
}

void ListDelete(CycleLinkList *L,int i,ElemType *e){
    if (*L == NULL || i < 1) {
        // ��Ч��ɾ��λ��
        return;
    }

    LNode *current = *L;
    int count = 1;

    while (count < i && current->next != *L) {
        current = current->next;
        count++;
    }

    LNode *deletedNode = current->next;
    *e = deletedNode->data;
    current->next = deletedNode->next;

    if (i == 1) {
        *L = deletedNode->next; // ���ɾ�����ǵ�һ��Ԫ�أ���Ҫ����ͷָ��
    }

    free(deletedNode);
}

void PrintList(CycleLinkList L) {
    LNode *current = L->next;
    while (current != L) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void AppendElement(CycleLinkList *L, ElemType e) {
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (!newNode) {
        exit(1);
    }
    newNode->data = e;

    if (*L == NULL) {
        *L = newNode;
        newNode->next = newNode;  // �������Ϊ�գ�ָ�������γ�ѭ��
    } else {
        LNode *current = (*L)->next;  // ��λ����һ���ڵ�
        while (current->next != *L) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

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
    
    LNode *current = (*L);

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
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
        printf("超出链表长度");
        exit(1); // 失败，链表为空或索引无效
    }

    CycleLinkList current = L->next;
    int count = 1;

    while (count < i) {
        current = current->next;
        count++;

        if (current == L) {
            printf("超出链表长度");
            exit(1); // 失败，索引超出链表长度
        }
    }

    *e = current->data; // 成功，e 中存储了第 i 个位置的值
}


void ListInsert(CycleLinkList *L,int i,ElemType e){
   LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL) {
        // 内存分配失败处理
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
        *L = newNode; // 若在第一个位置插入，需要更新头指针
    }
}

void ListDelete(CycleLinkList *L,int i,ElemType *e){
    if (*L == NULL || i < 1) {
        // 无效的删除位置
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
        *L = deletedNode->next; // 如果删除的是第一个元素，需要更新头指针
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
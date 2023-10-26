#include <stdio.h>
#include <stdlib.h>
#include"CycleLinkList.h"


CycleLinkList MergeSortedLists(CycleLinkList list1, CycleLinkList list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    LNode *current1 = list1->next;
    LNode *current2 = list2->next;
    CycleLinkList mergedList = NULL;

    // 创建合并后的链表
    mergedList = list1;
    LNode *tail = mergedList;



    while (current1 != list1 && current2 != list2) {
        if (current1->data < current2->data) {
            tail->next = current1;
            current1 = current1->next;
        } else {
            tail->next = current2;
            current2 = current2->next;
        }
        tail = tail->next;
    }

    // 处理剩余部分
    if (current1 != list1) {
        tail->next = current1;
    } else {
        tail->next = current2;
    }
    tail = mergedList;
    while (tail->next != list1) {
        tail = tail->next;
    }

    // 使链表循环
    tail->next = mergedList;

    return mergedList;
}


int main(){
  int n1,n2;
  CycleLinkList L1;
  CycleLinkList L2;

  InitList(&L1);
  printf("L1\n");
  scanf("%d",&n1);
  CreateList(&L1, n1);

  InitList(&L2);
  printf("L2\n");
  scanf("%d",&n2);
  CreateList(&L2, n2);


  printf("有序链表1：");
  PrintList(L1);
  printf("有序链表2：");
  PrintList(L2);
  CycleLinkList mergedList=MergeSortedLists(L1,L2);
  printf("合并后的有序链表：");
  PrintList(mergedList);
  DestroyList(&L1);
  DestroyList(&L2);
  DestroyList(&mergedList);
  return 0;

}
#include "CycleLinkList.h"
#include<stdlib.h>
#include<stdio.h>

void InitList(CycleLinkList *L){
    *L = (LNode*)malloc(sizeof(LNode));
    if (!*L) exit(1);
    (*L)->data = 0;
    (*L)->next = *L;
};

void DestroyList(CycleLinkList *L){
  if (*L) {
        CycleLinkList current = (*L)->next; 
        CycleLinkList next;

        while (current != *L) {
            next = current->next; 
            free(current); 
            current = next; 
        }

        
        free(*L);
        *L = NULL; 
    }
}

void ClearList(CycleLinkList *L){
    if (*L) {
        CycleLinkList current = (*L)->next; 
        CycleLinkList next;

        while (current != *L) {
            next = current->next; 
            free(current); 
            current = next; 
        }

        // Free the header node
        (*L)->data=0;
        (*L)->next= *L; 
    }
}

void ListEmpty(CycleLinkList *L){
    return 0;
}

void ListLength(CycleLinkList *L){
    return 0;
}

void GetElem(CycleLinkList *L){
    return 0;
}

void LocateElem(CycleLinkList *L){
    return 0;
}

void PriorElem(CycleLinkList *L){
    return 0;
}

void NextElem(CycleLinkList *L){
    return 0;
}
void ListInsert(CycleLinkList *L){
    return 0;
}
void ListDelete(CycleLinkList *L){
    return 0;
}
void ListTraverse(CycleLinkList *L){
    return 0;
}

#ifndef _CYCLELINKLIST_H
#define _CYCLELINKLIST_H

typedef int ElemType;

typedef struct LNode
{
	ElemType data; //数据域
	struct LNode *next; //指针域
}LNode,*CycleLinkList;


void InitList(CycleLinkList *L);
void DestroyList(CycleLinkList *L);
void ClearList(CycleLinkList *L);
void ListEmpty(CycleLinkList *L);
void ListLength(CycleLinkList *L);
void GetElem(CycleLinkList *L);
void LocateElem(CycleLinkList *L);
void PriorElem(CycleLinkList *L);
void NextElem(CycleLinkList *L);
void ListInsert(CycleLinkList *L);
void ListDelete(CycleLinkList *L);
void ListTraverse(CycleLinkList *L);

#endif
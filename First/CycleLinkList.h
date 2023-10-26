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
void GetElem(CycleLinkList L,int i,ElemType *e);
int ListEmpty(CycleLinkList L);
int ListLength(CycleLinkList L);
void ListInsert(CycleLinkList *L,int i,ElemType e);
void ListDelete(CycleLinkList *L,int i,ElemType *e);
void PrintList(CycleLinkList L);

#endif


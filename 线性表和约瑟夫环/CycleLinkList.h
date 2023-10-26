#ifndef _CYCLELINKLIST_H
#define _CYCLELINKLIST_H

typedef int ElemType;

typedef struct LNode
{
	ElemType data; // ˝æ›”Ú
	struct LNode *next; //÷∏’Î”Ú
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
void AppendElement(CycleLinkList *L, ElemType e);
void ReverseList(CycleLinkList *L);
void CreateList(CycleLinkList *L, int n);


#endif


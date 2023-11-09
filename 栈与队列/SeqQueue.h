#ifndef SEQQUEUE_H
#define SEQQUEUE_H

typedef int ElemType;
 
/*结点结构*/
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode,*QNodePtr;
 
typedef struct 
{
    QNodePtr front,rear;//队头、队尾指针
}LinkQueue,*LinkQueuePtr;

int InitQueue(LinkQueuePtr Q);/*初始化一个空队列*/
int Queue_Empty(LinkQueuePtr Q);
int EnQueue(LinkQueuePtr Q,ElemType e); /*入队操作*/
int DeQueue(LinkQueuePtr Q,ElemType *e);  /*出队操作*/

#endif
#include<stdio.h>
#include<stdlib.h>
#include"SeqQueue.h"

int InitQueue(LinkQueuePtr Q)
{
    Q=(LinkQueuePtr)malloc(sizeof(LinkQueue));
    QNodePtr head=(QNodePtr)malloc(sizeof(QNodePtr));
    
    if(head!=NULL && Q!=NULL)
    {
        head->next=NULL;
        Q->front=head;
        Q->rear=head;
    }
    return 1;
}
 
/*判空*/
int Queue_Empty(LinkQueuePtr Q)
{
    return Q->front==Q->rear;
}
 
/*入队操作*/
int EnterQueue(LinkQueuePtr Q,ElemType e)
{
    QNodePtr s=(QNodePtr)malloc(sizeof(QNode));
    if(s==NULL){
        return 0;
    }    
    //初始化新结点
    s->data=e;
    s->next=NULL;
    //建立新联系
    Q->rear->next=s;
    Q->rear=s;
 
    return 1;
}
 
/*出队操作*/
int DeQueue(LinkQueuePtr Q,ElemType *e)
{
    QNodePtr p;
    if(LinkQueue_Empty(Q)){
        return 0;
    } 
       
    //保留删除结点的信息
    p=Q->front->next;
    *e=p->data;
 
    //建立新联系
    Q->front->next=p->next;
   
    if(Q->rear==p)
    {
        Q->rear=Q->front;
    }
    
    free(p);
 
    return 1;
}
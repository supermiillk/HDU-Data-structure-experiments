#ifndef PARKINGQUESTION_H
#define PARKINGQUESTION_H
#define stackSize 3
typedef int ElementType;

typedef struct{
   int BNo;
   int arrivetime;
   int pushtime;
   int departuretime;
}BusInf;

typedef struct{
    BusInf elem[stackSize];
    int top;
}SeqStack;


//队列
typedef struct Node{
    BusInf Bus;
    struct Node * next;
}LinkQueueNode;
typedef struct{
    LinkQueueNode *front;//头指针
    LinkQueueNode *rear;//队尾指针
}LinkQueue;


int InitQueue(LinkQueue *Q);//初始化队列--将Q初始化为一个空的链队列
int EnterQueue(LinkQueue *Q,BusInf bus);//入队操作
int DeleteQueue(LinkQueue *Q,BusInf *bus);//出队操作
int searchBusNo(SeqStack *s,BusInf bus);//查找栈中有无车牌信息--temp代表出栈的位置....-1代表无车牌
void showBus(SeqStack *s);
void showQBus(LinkQueue *l);//显示队列里的车
void inputCarData(SeqStack *s,LinkQueue *l);//输入车辆信息并且入栈或入队
void leaveStack(SeqStack *s,SeqStack *se,LinkQueue *Q);//离开停车位

#endif

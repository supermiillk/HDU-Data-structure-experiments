#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <malloc.h>
#include"ParkingQuestion.h"

int menu()
{
    char n;
    printf("\n    ************* 停车场管理系统 **************\n");
    printf("    *%15c1---停车%19c\n",' ','*');
    printf("    *%15c2---离开%19c\n",' ','*');
    printf("    *%15c3---结束程序%15c\n",' ','*');
    printf("    *******************************************\n");
    printf("菜单选择：1,2,3: ");
    do{
	     n=getch();
	     }while(n<'1' || n>'3');
     printf("\n");
     return(n-48);
}
int main()
{
    
    SeqStack *s =(SeqStack*)malloc(sizeof(SeqStack));
    InitStack(s);
    LinkQueue *l=(LinkQueue *)malloc(sizeof(LinkQueue));
    InitQueue(l);
    SeqStack *se = (SeqStack*)malloc(sizeof(SeqStack));//辅助栈存储让位的信息
    InitStack(se);
    while(1)
    {
        switch(menu()){
            case 1:inputCarData(s,l);
            break;
            case 2:leaveStack(s,se,l);
            break;
            case 3:return 0;
        }
    }
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 200

typedef struct BiNode
{
    char data;
    struct BiNode *lc;
    struct BiNode *rc;
	int ltag;
	int rtag;
}BiTree;

int countLeaves(BiTree *bt); // ����Ҷ�ӽڵ���
int treeDepth(BiTree *bt); // �����������

int leafCount = 0; // Ҷ�ӽڵ����
int maxDepth = 0;  // ����������

int countLeaves(BiTree *bt) {
    if (bt == NULL) {
        return 0;
    }
    if (bt->lc == NULL && bt->rc == NULL) {
        return 1;
    }
    return countLeaves(bt->lc) + countLeaves(bt->rc);
}

// �����������
int treeDepth(BiTree *bt) {
    if (bt == NULL) {
        return 0;
    }
    int leftDepth = treeDepth(bt->lc);
    int rightDepth = treeDepth(bt->rc);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

//�Թ�������ʽ����������
BiTree *CreatBiTreepre(char *str)
{
    BiTree *bt,*stack[MAXSIZE],*p=NULL;
    int top=-1,k,j=0;
    char ch;
    bt=NULL;
    ch=str[j];
    while(ch!='\0')
    {
        switch(ch)
        {
        case '(':
            {
                top++;
                stack[top]=p;
                k=1;
                break;
            }
        case ')':
            {
                top--;
                break;
            }
        case ',':
            {
                k=2;
                break;
            }
        default:
            {
                p=(BiTree *)malloc(sizeof(BiTree));
                p->data=ch;
                p->lc=p->rc=NULL;
                if(bt==NULL)
                {
                    bt=p;
                }
                else
                {
                    switch(k)
                    {
                    case 1:
                        {
                            stack[top]->lc=p;
                            break;
                        }
                    case 2:
                        {
                            stack[top]->rc=p;
                            break;
                        }
                    }
                }
            }
        }
        j++;
        ch=str[j];
    }
    return bt;
}

//���ð��뷨���������
void OutBiTree(BiTree *bt)
{
    BiTree *stack[MAXSIZE],*p;
    int feature[MAXSIZE][2],top,n,i,width=4;
    char type;
    if(bt!=NULL)
    {
        top=1;
        stack[top]=bt;
        feature[top][0]=width;
        feature[top][1]=2;
        while(top>0)
        {
            p=stack[top];
            n=feature[top][0];
            switch(feature[top][1])
            {
            case 0:
                {
                    type='l';
                    break;
                }
            case 1:
                {
                    type='R';
                    break;
                }
            case 2:
                {
                    type='G';
                    break;
                }
            }
            for(i=1;i<=n;i++)
                printf(" ");
            printf("%c(%c)\n",p->data,type);
            top--;
            if(p->lc!=NULL)
            {
                top++;
                stack[top]=p->lc;
                feature[top][0]=n+width;
                feature[top][1]=0;
            }
            if(p->rc!=NULL)
            {
                top++;
                stack[top]=p->rc;
                feature[top][0]=n+width;
                feature[top][1]=1;
            }

        }
    }
}

void PrintTree(BiTree *bt,int nLayer)
{
    if(bt==NULL)
        return ;
    PrintTree(bt->rc,nLayer+1);
    for(int i=0;i<nLayer;i++)
        printf("  ");
    printf("%c\n",bt->data);
    PrintTree(bt->lc,nLayer+1);
}

void inOrderTraversal(BiTree *bt) {
    if (bt != NULL) {
        inOrderTraversal(bt->lc);
        printf("%c ", bt->data);
        inOrderTraversal(bt->rc);
    }
}

void InThreaded(BiTree *p)
{
	static BiTree *pre=NULL;
	if(p)
	{
		InThreaded(p->lc);

		if(!p->lc)
		{
			p->ltag=1;
			p->lc=pre;
		}

		if(pre&&!pre->rc)
		{
			pre->rtag=1;
			pre->rc=p;
		}
		pre=p;

		InThreaded(p->rc);
	}
}

BiTree *Next(BiTree *t)
{
	if(t->rtag==1)
	{
		t=t->rc;
	 }
	 else
	{
	 	t=t->rc;
		 while(t->ltag==0)
		{
		 	t=t->lc;
		 }
	}
	return t;
}

BiTree *Prior(BiTree *t)
{
	if(t->ltag==1)
	{
		t=t->lc;
	 }
	else
	{
		t=t->lc;
		while(t->rtag==0)
		{
			t=t->rc;
		 }
	}

	return t;
}

//��������ʵ���������
void InorderTraverse(BiTree *t)
{
	if(!t)
	{
		return;
	}

	while(t->ltag==0)
	{
		t=t->lc;
	}
	printf("%c ",t->data);
	while(t->rc)
	{
		t=Next(t);
		printf("%c ",t->data);
	}
}


int main()
{
    BiTree *bt;
    char *gyb,str[MAXSIZE];
    int j=1;
    printf("������������Ĺ������ʽ��\n");
    gyb=str;
    scanf("%s",str);
    bt =CreatBiTreepre(gyb);
    printf("�����������ɹ���\n");
    printf("�˶������İ��뷨��ʾΪ��\n");
    OutBiTree(bt);
    printf("��״��ӡ��������\n");
    PrintTree(bt,1);
    printf("\nҶ�ӽڵ�����%d\n", countLeaves(bt));
    printf("������ȣ�%d\n", treeDepth(bt));
	  printf("����������!\n");
	  InThreaded(bt);
	  printf("\n");

	  printf("�������:");
	  InorderTraverse(bt);
	  printf("\n");
    pause
    return 0;
}
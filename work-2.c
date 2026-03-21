#include<stdio.h>
#define MAXSIZE 9

typedef struct{
    char element[MAXSIZE];
    int rear;
    int front;
    int tag;
}SeqQueue;

void InitQueue(SeqQueue *q);
int EnterQueue(SeqQueue *q,char x);
int DeleteQueue(SeqQueue *q,char *x);
void PrintStatus(SeqQueue *q);
void PrintQueue(SeqQueue *q);
void PrintArray(SeqQueue *q);

int main()
{
    SeqQueue q;
    InitQueue(&q);
    char e;
    char input1[]={'a','l','l','e','v','i','a','t','e'};
    int len1=sizeof(input1)/sizeof(input1[0]);
    printf("input1 enter\n");
    for(int i=0;i<len1;i++)      //入队
    {
        EnterQueue(&q,input1[i]);
    }
    PrintStatus(&q);
    PrintQueue(&q);
    printf("\n");
    for(int i=0;i<4;i++)        //出队
    {
        DeleteQueue(&q,&e);
        printf("out:%c\n",e);
    }
    PrintStatus(&q);
    PrintQueue(&q);
    printf("\n");
    char input2[]={'o','b','l','i'};
    int len2=sizeof(input2)/sizeof(input2[0]);
    printf("input2 enter\n");
    for(int i=0;i<len2;i++)
    {
        EnterQueue(&q,input2[i]);
    }
    PrintStatus(&q);
    PrintQueue(&q);
    printf("\n");
    printf("end\n");
    PrintArray(&q);
    PrintStatus(&q);
    return 0;
}
//初始化
void InitQueue(SeqQueue *q){
    q->front=q->rear=0;
    q->tag=0;
    for(int i=0;i<MAXSIZE;i++)
    {
        q->element[i]=0;
    }
}
//入队
int EnterQueue(SeqQueue *Q,char x)
{
    if(Q->front==Q->rear&&Q->tag==1)
    {
        printf("fulll\n");
        return 0;
    }
    Q->element[Q->rear]=x;
    Q->rear=(Q->rear+1)%MAXSIZE;
    Q->tag=1;
    return 1;
}
//出队
int DeleteQueue(SeqQueue *Q,char *x)
{
    if(Q->rear==Q->front&&Q->tag==0)
    {
        printf("no\n");
        return 0;
    }
    *x=Q->element[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    if(Q->front==Q->rear)
    {Q->tag=0;}
    return 1;
}
//打印全部
void PrintArray(SeqQueue *Q)
{
   int t=Q->front;
   int m=MAXSIZE;
   while (m--)
   {
    printf("%c ",Q->element[t]);
    t=(t+1)%MAXSIZE;
   }
   printf("\n");
}
//打印状态
void PrintStatus(SeqQueue *Q)
{
    printf("now:first=%c, end=%c, tag=%d\n",Q->element[Q->front],Q->element[(Q->rear-1+MAXSIZE)%MAXSIZE],Q->tag);
}

//打印有效元素
void PrintQueue(SeqQueue *Q)
{
    int t=Q->front;
    printf("True element:\n");
    if(Q->rear==Q->front&&Q->tag==1)
    {
        PrintArray(Q);
    }
    else if(Q->tag==1)
   {
    while(t!=Q->rear)
    {
        printf("%c ",Q->element[t]);
        t=(t+1)%MAXSIZE;
    }
   }
   else
   {
    printf("NULL");
   }
    printf("\n");
}

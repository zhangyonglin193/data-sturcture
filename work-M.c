#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct 
{
    /* data */
    int row,col;
    int e;
}Triple;
typedef struct
{
    /* data */
    int m,n,len;
    Triple data[MAXSIZE+1];
}TSMatrix;

void CreateSMatrix(TSMatrix *M)
{
    M->m=3;
    M->n=4;
    M->len=5;
    M->data[1].row=1;
    M->data[1].col=1;
    M->data[1].e=-3;
    
    M->data[2].row=1;
    M->data[2].col=4;
    M->data[2].e=5;
   
    M->data[3].row=2;
    M->data[3].col=2;
    M->data[3].e=-1;
    
    M->data[4].row=3;
    M->data[4].col=1;
    M->data[4].e=8;
   
    M->data[5].row=3;
    M->data[5].col=4;
    M->data[5].e=7;
}
void PrintTripleTable(TSMatrix *M)
{
    printf("=======Array-M-Table========\n");
    printf("|-order-|--row--|--col--|--e--|\n");
    for(int i=1;i<=M->len;i++)
    {
        printf("%6d%7d%7d%7d\n",i,M->data[i].row,M->data[i].col,M->data[i].e);
    }
}

int main()
{
    TSMatrix M;
    CreateSMatrix(&M);
    PrintTripleTable(&M);
    return 0;
}
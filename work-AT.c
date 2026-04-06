#include<stdio.h>
#define MAXSIZE 10
typedef struct 
{
    /* data */
    int row,col;
    char e;
}Triple;
typedef struct
{
    /* data */
    int m,n,len;
    Triple data[MAXSIZE+1];
}TSMatrix;
void CreateSMatrixTable(TSMatrix *M)
{
    M->m=3;
    M->n=3;
    M->len=4;
    M->data[1].row=1;
    M->data[1].col=1;
    M->data[1].e='A';

    M->data[2].row=1;
    M->data[2].col=3;
    M->data[2].e='B';
    
    M->data[3].row=2;
    M->data[3].col=1;
    M->data[3].e='C';
    
    M->data[4].row=3;
    M->data[4].col=2;
    M->data[4].e='D';
}
void TransposeSMatrix(TSMatrix M,TSMatrix *T)
{
    T->m=M.n;
    T->n=M.m;
    T->len=M.len;
    int k=1;
    for(int i=1;i<=M.n;i++)
    {
        for(int j=1;j<=M.len;j++)
        {
            if(M.data[j].col==i)
            {
                T->data[k].row=M.data[j].col;
                T->data[k].col=M.data[j].row;
                T->data[k].e=M.data[j].e;
                printf("the num:%d\n",k);
                printf("row:%5d    col:%5d    e:%5c\n",T->data[k].row,T->data[k].col,T->data[k].e);
                k++;
            }
        }
    }

}
int main()
{
    TSMatrix M,T;
    CreateSMatrixTable(&M);
    TransposeSMatrix(M,&T);
    return 0;
}
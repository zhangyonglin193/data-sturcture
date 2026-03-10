#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
LinkList CreateList(int a[], int n);
void PrintList(LinkList L);
void MergeInsert(LinkList LA, LinkList LB);
int main()
{
    int a[]={2,3,3},b[]={1,3,3,4};
    LinkList LA=CreateList(a,3);
    LinkList LB=CreateList(b,4);
    printf("first-LA:");
    PrintList(LA);
    printf("first-LB:");
    PrintList(LB);
    MergeInsert(LA,LB);
    return 0;
}
LinkList CreateList(int a[], int n)
{
    LinkList L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        printf("error");
        exit(1);
    }
    L->next = NULL;
    LinkList r = L;
    for (int i = 0; i < n; i++)
    {
        LinkList p = (LNode *)malloc(sizeof(LNode));
        if (p == NULL)
        {
            printf("error");
            exit(1);
        }
        p->data = a[i];
        p->next = NULL;
        r->next = p;
        r = p;
    }
    return L;
}
void PrintList(LinkList L)
{
    LinkList p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void MergeInsert(LinkList LA, LinkList LB)
{
    LinkList pa = LA;
    LinkList pb = LB ->next;
    while (pb != NULL)
    {
        while (pa->next!=NULL&&pa->next->data <= pb->data)
        {
            pa=pa->next ;
        }
        LinkList next_pb = pb->next;
        pb->next = pa->next;
        pa ->next = pb;
        pa = LA;
        printf("Insert%d:",pb->data);
        PrintList(LA);
        pb = next_pb;
    }
    free(LB);
}
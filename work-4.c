#include <stdio.h>
#define MAXN 20
int visited[MAXN];
int adjList[MAXN][MAXN];
void add_Edge(int num1, int num2)
{
    adjList[num1][num2] = 1;
    adjList[num2][num1] = 1;
}
void init_Graph()
{
    for (int i = 0; i < MAXN; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < MAXN; j++)
        {
            adjList[i][j] = 0;
        }
    }
}
void dfs(int first)
{
    visited[first] = 1;
    printf("%d ", first);
    for (int i = 0; i < MAXN; i++)
    {
        if (!visited[i]&&adjList[first][i]==1)
        {
            dfs(i);
        }
    }
}
void bfs(int first)
{
    int queue[MAXN], rear = 0, front = 0;
    queue[rear++] = first;
    visited[first] = 1;
    while (rear != front)
    {
        int nowvex = queue[front++];
        printf("%d ", nowvex);
        for (int i = 0; i < MAXN; i++)
        {
            if (!visited[i] && adjList[nowvex][i] == 1)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}
int main(){
    init_Graph();
    add_Edge(1,2);
    add_Edge(1,3);
    add_Edge(1,4);
    add_Edge(2,3);
    add_Edge(2,5);
    add_Edge(3,4);
    add_Edge(3,6);
    add_Edge(4,7);
    add_Edge(5,6);
    add_Edge(5,8);
    add_Edge(6,7);
    add_Edge(6,8);
    add_Edge(7,8);
    printf("bfs: ");
    bfs(1);
    for (int i = 0; i < MAXN; i++)
        visited[i] = 0;
    printf("\n");
    printf("dfs: ");
    dfs(1);
    return 0;

}
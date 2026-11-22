
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n, front = 0, rear = -1;

// Depth First Search
void DFS(int vertex)
{
    int i;
    visited[vertex] = 1;

    printf("%d ", vertex);

    for(i = 0; i < n; i++)
    {
        if(graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// Breadth First Search
void BFS(int start)
{
    int i, vertex;

    for(i = 0; i < n; i++)
        visited[i] = 0;

    front = 0;
    rear = -1;

    visited[start] = 1;
    queue[++rear] = start;

    while(front <= rear)
    {
        vertex = queue[front++];
        printf("%d ", vertex);

        for(i = 0; i < n; i++)
        {
            if(graph[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS Traversal: ");
    for(i = 0; i < n; i++)
        visited[i] = 0;

    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}


#include <stdio.h>

#define MAX 20

int parent[MAX];

int find(int i)
{
    while(parent[i] != i)
    {
        i = parent[i];
    }

    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}

int main()
{
    int cost[MAX][MAX];
    int n, i, j;
    int min, a, b;
    int edges = 0;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 9999;
        }

        parent[i] = i;
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1)
    {
        min = 9999;
        a = -1;
        b = -1;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if(a == -1 || min == 9999)
        {
            printf("Graph is not connected.\n");
            return 0;
        }

        if(find(a) != find(b))
        {
            printf("%d - %d : %d\n", a, b, min);

            totalCost += min;
            unionSet(a, b);
            edges++;
        }

        cost[a][b] = 9999;
        cost[b][a] = 9999;
    }

    printf("\nMinimum Cost = %d\n", totalCost);

    return 0;
}

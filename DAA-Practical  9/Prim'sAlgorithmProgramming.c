
#include <stdio.h>

#define MAX 20
#define INF 9999

int main()
{
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int n, i, j;
    int edges = 0, min, a, b;
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
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if(min == INF)
        {
            printf("Graph is not connected.\n");
            return 0;
        }

        printf("%d - %d : %d\n", a, b, min);

        totalCost += min;
        visited[b] = 1;
        edges++;
    }

    printf("\nMinimum Cost = %d\n", totalCost);

    return 0;
}


#include <stdio.h>

#define MAX 10
#define INF 999999

int n;
int cost[MAX][MAX];
int visited[MAX] = {0};
int minCost = INF;

void tsp(int city, int count, int totalCost)
{
    int i;

    if(count == n && cost[city][0] != 0)
    {
        int finalCost = totalCost + cost[city][0];

        if(finalCost < minCost)
        {
            minCost = finalCost;
        }

        return;
    }

    for(i = 0; i < n; i++)
    {
        if(!visited[i] && cost[city][i] != 0)
        {
            visited[i] = 1;

            tsp(i, count + 1,
                totalCost + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1;

    tsp(0, 1, 0);

    if(minCost == INF)
        printf("\nNo valid tour exists.\n");
    else
        printf("\nMinimum travelling cost = %d\n", minCost);

    return 0;
}

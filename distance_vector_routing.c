#include <stdio.h>

struct node
{
    unsigned dist[20];
    unsigned from[20];
} router[10];

int main()
{
    int dmat[20][20];
    int i, j, k;
    int n; // Number of nodes
    int count = 0;

    printf("\n Enter the number of routers in the network :");
    scanf("%d", &n);
    printf("\n Enter the cost matrix : \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &dmat[i][j]);
            dmat[i][i] = 0;
            router[i].dist[j] = dmat[i][j];
            router[i].from[j] = j;
        }
    do
    {
        count = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = 0; k < n; k++)
                    if (router[i].dist[j] > dmat[i][k] + router[k].dist[j])
                    {
                        router[i].dist[j] = dmat[i][k] + router[k].dist[j];
                        router[i].from[j] = k;
                        count++;
                    }
    } while (count != 0);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\n The distance from %d to %d is %d and is through router %d", i + 1, j + 1, router[i].dist[j], router[i].from[j] + 1);
        }
    }
}

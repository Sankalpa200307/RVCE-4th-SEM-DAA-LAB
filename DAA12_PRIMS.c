#include <stdio.h>
#include <stdlib.h>

void prims(int n, int cost[10][10]) {
    int visited[10] = {0};
    int ne = 1;
    int mincost = 0;

    visited[1] = 1; // Start with the first4 node
    printf("\nThe edges considered for MST:\n");

    while (ne < n) {
        int min = 999;
        int u = -1, v = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d Edge(%d,%d) = %d\n", ne++, u, v, min);
            mincost += min;
            visited[v] = 1;
            cost[u][v] = cost[v][u] = 999;
        }
    }

    printf("\nCost of constructing MST is %d\n", mincost);
}

int main() {
    int n, cost[10][10];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // Replace 0 with a large number to indicate no connection
        }
    }

    prims(n, cost);

    return 0;
}


#include <stdio.h>

#define INF 999

int main() {
    int i, j, n, v, k, min, u;
    int c[20][20], s[20], d[20];

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (enter 999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    // Initialize distance and visited arrays
    for (i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = c[v][i];
    }

    d[v] = 0;
    s[v] = 1;

    // Dijkstra's algorithm core loop
    for (k = 2; k <= n; k++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            if (!s[i] && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        s[u] = 1;

        for (i = 1; i <= n; i++) {
            if (!s[i] && d[i] > d[u] + c[u][i]) {
                d[i] = d[u] + c[u][i];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        if (d[i] == INF)
            printf("%d --> %d = ∞ (unreachable)\n", v, i);
        else
            printf("%d --> %d = %d\n", v, i, d[i]);
    }

    return 0;
}

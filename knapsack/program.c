#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int w[], int p[], int c) {
    int v[100][100]; // Assumes max size needed is within 100
    int i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i - 1] > j)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i - 1]] + p[i - 1]);
        }
    }

    printf("\nMaximum Profit is: %d\n", v[n][c]);
    printf("\nDP Table:\n");

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            printf("%3d ", v[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, c, i;
    int w[100], p[100];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the profits of the items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &c);

    knapsack(n, w, p, c);

    return 0;
}

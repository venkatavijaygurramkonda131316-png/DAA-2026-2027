#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, k, L;
    int p[20];
    int m[20][20];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter dimensions of matrices:\n");
    printf("For example, for A1(10x20), A2(20x30), A3(30x40), enter: 10 20 30 40\n");

    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

     for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k < j; k++) {
                int cost = m[i][k] +
                            m[k + 1][j] +
                            p[i - 1] * p[k] * p[j];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    printf("\nMinimum number of scalar multiplications = %d\n", m[1][n]);

    return 0;
}
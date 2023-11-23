#include <stdio.h>
#include <math.h>

long long det(int a, int b) {
    long long delta;
    if (a >= 0 && b >= 0)
        delta = pow(2, a+1) * pow(3, b+1);
    else
        delta = -1;
    return delta;
}

int main() {
    int m, n, x, y, obstacle;
    scanf("%d%d%d%d", &m, &n, &x, &y);

    long long matrix[m + 1][n + 1];
    long long banned[9];

    banned[0] = det(x, y);
    banned[1] = det(x - 1, y + 2);
    banned[2] = det(x - 2, y + 1);
    banned[3] = det(x - 2, y - 1);
    banned[4] = det(x - 1, y - 2);
    banned[5] = det(x + 1, y - 2);
    banned[6] = det(x + 2, y - 1);
    banned[7] = det(x + 2, y + 1);
    banned[8] = det(x + 1, y + 2);

    for (int k = 1; k <= m; k++) {
        for (int t = 0; t <= 8; t++) {
            if ( det(k, 0) == banned[t]) {
                for(int p=k;p<=m;p++) matrix[p][0] = 0;
                obstacle = 1;
                break;
            } else {
                matrix[k][0] = 1;
            }
        }
        if (obstacle == 1) break;
    }

    obstacle = 0;

    for (int k = 1; k <= n; k++) {
        for (int t = 0; t <= 8; t++) {
            if (banned[t] != -1 && det(0, k) == banned[t]) {
                for(int p=k;p<=n;p++) matrix[0][p] = 0;
                obstacle = 1;
                break;
            } else {
                matrix[0][k] = 1;
            }
        }
        if (obstacle == 1) break;
    }

    for (int k = 1; k <= n; k++) {
        for (int t = 1; t <= m; t++) {
            for (int i = 0; i <= 8; i++) { 
                if (banned[i] != -1 && det(t, k) == banned[i]) {
                    matrix[t][k] = 0;
                    break;
                } else {
                    matrix[t][k] = matrix[t - 1][k] + matrix[t][k - 1];
                }
            }
        }
    }

    printf("%lld", matrix[m][n]);

    return 0;
}


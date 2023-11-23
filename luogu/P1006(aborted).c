#include <stdio.h>
#include <stdlib.h>

#define MAX_N 60
int result[MAX_N][MAX_N][MAX_N][MAX_N];
int m, n;

int max(int x, int y) {
    return x >= y ? x : y;
}

int findpath(int x1, int y1, int x2, int y2, int value[MAX_N][MAX_N]) {
    if (result[x1][y1][x2][y2] != -1) return result[x1][y1][x2][y2];
    if (x1 > m || y1 > n || x2 > m || y2 > n) {
        return 0;
    }

    if (x1 == m && y1 == n && x2 == m && y2 == n) {
        return value[m][n];
    }

    int x1Next = x1 + 1;
    int y1Next = y1 + 1;
    int x2Next = x2 + 1;
    int y2Next = y2 + 1;

    int x1EqualX2 = (x1Next == x2Next) ? 1 : 0;
    int y1EqualY2 = (y1Next == y2Next) ? 1 : 0;

    result[x1][y1][x2][y2] = max(
        max(findpath(x1Next, y1, x2Next, y2, value) * ((x1EqualX2 == 0 || y1EqualY2 == 0) ? 1 : 0),
            findpath(x1, y1Next, x2, y2Next, value) * ((x1EqualX2 == 0 || y1EqualY2 == 0) ? 1 : 0)),
        max(findpath(x1Next, y1, x2, y2Next, value) * ((x1EqualX2 == 0 || y1EqualY2 == 0) ? 1 : 0),
            findpath(x1, y1Next, x2Next, y2, value) * ((x1EqualX2 == 0 || y1EqualY2 == 0) ? 1 : 0))
    ) + value[x1][y1] + value[x2][y2];

    return result[x1][y1][x2][y2];
}

int main() {
    scanf("%d%d", &m, &n);
    int value[MAX_N][MAX_N] = {0};

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &value[i][j]);
        }
    }

    for (int a = 0; a <= m; a++) {
        for (int b = 0; b <= n; b++) {
            for (int c = 0; c <= m; c++) {
                for (int d = 0; d <= n; d++) {
                    result[a][b][c][d] = -1;
                }
            }
        }
    }

    printf("%d", findpath(1, 1, 1, 1, value));
    system("pause");
    return 0;
}

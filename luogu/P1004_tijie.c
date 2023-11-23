#include <stdio.h>
#include<stdlib.h>
#define MAX_N 15

int N = 0;
int value[MAX_N][MAX_N];
int f[MAX_N][MAX_N][MAX_N][MAX_N];

int max(int x, int y) {
    return (x >= y) ? x : y;
}

int dfs(int x1, int y1, int x2, int y2) {
    if (f[x1][y1][x2][y2] != -1) return f[x1][y1][x2][y2]; //记录已算过的点的数据，避免重复算浪费时间
    if (x1 == N && y1 == N && x2 == N && y2 == N) return 0;

    int M = 0;

    if (x1 < N && x2 < N)
        M = max(M, dfs(x1 + 1, y1, x2 + 1, y2) + value[x1 + 1][y1] + value[x2 + 1][y2] - (value[x1 + 1][y1] * (x1 + 1 == x2 + 1 && y1 == y2)));

    if (x1 < N && y2 < N)
        M = max(M, dfs(x1 + 1, y1, x2, y2 + 1) + value[x1 + 1][y1] + value[x2][y2 + 1] - (value[x1 + 1][y1] * (x1 + 1 == x2 && y1 == y2 + 1)));

    if (y1 < N && x2 < N)
        M = max(M, dfs(x1, y1 + 1, x2 + 1, y2) + value[x1][y1 + 1] + value[x2 + 1][y2] - (value[x1][y1 + 1] * (x1 == x2 + 1 && y1 + 1 == y2)));

    if (y1 < N && y2 < N)
        M = max(M, dfs(x1, y1 + 1, x2, y2 + 1) + value[x1][y1 + 1] + value[x2][y2 + 1] - (value[x1][y1 + 1] * (x1 == x2 && y1 + 1 == y2 + 1)));

    f[x1][y1][x2][y2] = M;
    return M;
}

int main() {

    scanf("%d", &N);

    for (int a = 0; a <= N; a++) {
        for (int b = 0; b <= N; b++) {
            for (int c = 0; c <= N; c++) {
                for (int d = 0; d <= N; d++) {
                    f[a][b][c][d] = -1;
                }
            }
        }
    }

    while (1) {
        int t1 = 0, t2 = 0, t3 = 0;
        scanf("%d%d%d", &t1, &t2, &t3);
        if (t1 == 0 && t2 == 0 && t3 == 0) break;
        value[t1][t2] = t3;
    }

    printf("%d", dfs(1, 1, 1, 1) + value[1][1]);
    system("pause");
    return 0;
}

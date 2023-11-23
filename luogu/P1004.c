#include <stdio.h>
#include <stdlib.h>

#define MAX_N 30
int result[MAX_N][MAX_N][MAX_N][MAX_N];
int n;

int max(int x, int y) {
    return x >= y ? x : y;
}


//这里的findpath函数即为深度优先算法dfs的应用
int findpath(int x1, int y1, int x2, int y2, int value[MAX_N][MAX_N]) {
    if (result[x1][y1][x2][y2] != -1) return result[x1][y1][x2][y2]; //这行节省了400~1200ms的运算，非常重要
    if (x1 >n || y1 >n || x2 >n || y2 >n) {
        return 0;
    }
    
    if (x1 == n && y1 == n && x2 == n && y2 == n) {
        return value[n][n];
    }
    
    result[x1][y1][x2][y2] = max(
        max(findpath(x1 + 1, y1, x2 + 1, y2, value), findpath(x1, y1 + 1, x2, y2 + 1, value)),
        max(findpath(x1 + 1, y1, x2, y2 + 1, value), findpath(x1, y1 + 1, x2 + 1, y2, value))
    ) + value[x1][y1] + value[x2][y2];
    
    if (x1 == x2 && y1 == y2) {
        result[x1][y1][x2][y2] -= value[x1][y1];
    }
    
    return result[x1][y1][x2][y2];
}

int main() {
    int x, y, t;
    scanf("%d", &n);
    int value[MAX_N][MAX_N] = {0};

    for (int a = 0; a < MAX_N; a++) {
        for (int b = 0; b < MAX_N; b++) {
            for (int c = 0; c < MAX_N; c++) {
                for (int d = 0; d < MAX_N; d++) {
                    result[a][b][c][d] = -1;
                }
            }
        }
    }
    while (1) {
        scanf("%d%d%d", &x, &y, &t);
        if (x == 0 && y == 0 && t == 0) break;
        value[x][y] = t;
    }
    
    printf("%d", findpath(1, 1, 1, 1, value));
    system("pause");
    return 0;
}

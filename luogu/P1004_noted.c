#include <stdio.h>
#include <stdlib.h>

#define MAX_N 30
int result[MAX_N][MAX_N][MAX_N][MAX_N]; // 用于保存计算结果的数组
int n; // 表示矩阵的大小

int max(int x, int y) {
    return x >= y ? x : y; // 返回两个整数中的较大值
}

// 这里的findpath函数使用深度优先搜索算法来解决问题
int findpath(int x1, int y1, int x2, int y2, int value[MAX_N][MAX_N]) {
    if (result[x1][y1][x2][y2] != -1) return result[x1][y1][x2][y2]; // 如果已经计算过，直接返回保存的结果，避免重复计算

    if (x1 > n || y1 > n || x2 > n || y2 > n) {
        return 0; // 如果越界，返回0
    }
    
    if (x1 == n && y1 == n && x2 == n && y2 == n) {
        return value[n][n]; // 如果两个路径都到达右下角，返回右下角的值
    }
    
    // 递归计算所有可能的路径并保存结果
    result[x1][y1][x2][y2] = max(
        max(findpath(x1 + 1, y1, x2 + 1, y2, value), findpath(x1, y1 + 1, x2, y2 + 1, value)),
        max(findpath(x1 + 1, y1, x2, y2 + 1, value), findpath(x1, y1 + 1, x2 + 1, y2, value))
    ) + value[x1][y1] + value[x2][y2];
    
    if (x1 == x2 && y1 == y2) {
        result[x1][y1][x2][y2] -= value[x1][y1]; // 如果两个路径相交，需要减去重复计算的值
    }
    
    return result[x1][y1][x2][y2]; // 返回计算结果
}

int main() {
    int x, y, t;
    scanf("%d", &n); // 输入矩阵的大小
    int value[MAX_N][MAX_N] = {0}; // 初始化矩阵值为0

    for (int a = 0; a < MAX_N; a++) {
        for (int b = 0; b < MAX_N; b++) {
            for (int c = 0; c < MAX_N; c++) {
                for (int d = 0; d < MAX_N; d++) {
                    result[a][b][c][d] = -1; // 初始化计算结果为-1，表示未计算过
                }
            }
        }
    }
    
    // 输入每个格子的值，直到输入 (0,0,0) 为止
    while (1) {
        scanf("%d%d%d", &x, &y, &t);
        if (x == 0 && y == 0 && t == 0) break;
        value[x][y] = t;
    }
    
    printf("%d", findpath(1, 1, 1, 1, value)); // 调用函数计算最大得分并输出
    system("pause"); // 暂停等待用户输入后关闭程序
    return 0;
}

#include <bits/stdc++.h>

void findPaths(int x, int y, int maxX, int maxY, char path[], int pathLength) {
    if (x == maxX && y == maxY) {
        // 已经到达目标点，打印路径
        for (int i = 0; i < pathLength; i++) {
            printf("%c ", path[i]);
        }
        printf("\n");
        return;
    }

    if (x < maxX) {
        // 向右移动一格
        path[pathLength] = 'R';
        findPaths(x + 1, y, maxX, maxY, path, pathLength + 1);
    }

    if (y < maxY) {
        // 向上移动一格
        path[pathLength] = 'U';
        findPaths(x, y + 1, maxX, maxY, path, pathLength + 1);
    }
}

int main() {
    int maxX, maxY;
    printf("Enter the maximum x and y coordinates: ");
    scanf("%d %d", &maxX, &maxY);

    char path[maxX + maxY]; // 保存路径
    int pathLength = 0;

    findPaths(0, 0, maxX, maxY, path, pathLength);
    system("pause");
    return 0;
}

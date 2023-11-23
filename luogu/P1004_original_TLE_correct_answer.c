#include <stdio.h>
#include <stdlib.h>

#define MAXNUMBER 30

int max(int x, int y) {
    return x >= y ? x : y;
}

int findpath(int x1, int y1, int x2, int y2, int value[MAXNUMBER][MAXNUMBER]) {
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) {
        return 0;
    }
    
    if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) {
        return value[0][0];
    }
    
    int result = max(
        max(findpath(x1 - 1, y1, x2 - 1, y2, value), findpath(x1, y1 - 1, x2, y2 - 1, value)),
        max(findpath(x1 - 1, y1, x2, y2 - 1, value), findpath(x1, y1 - 1, x2 - 1, y2, value))
    ) + value[x1][y1] + value[x2][y2];
    
    if (x1 == x2 && y1 == y2) {
        result -= value[x1][y1];
    }
    
    return result;
}

int main() {
    int n, x, y, t;
    scanf("%d", &n);
    int value[MAXNUMBER][MAXNUMBER] = {0};
    
    while (scanf("%d%d%d", &x, &y, &t) != EOF && (x || y || t)) {
        value[x][y] = t;
    }
    
    if (n >= 0 && n < MAXNUMBER) {
        int result = findpath(n, n, n, n, value);
        printf("%d\n", result);
    } else {
        printf("Input value n is out of bounds.");
    }
    system("pause");
    return 0;
}
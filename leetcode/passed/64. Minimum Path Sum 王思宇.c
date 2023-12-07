
int result[200][200];

int min(int a, int b) {
    return a < b ? a : b;
}

int sum(int** grid, int i, int j) {
    int sum = 0;
    for (int k = 0; k <= i; k++) {
        for (int l = 0; l <= j; l++) {
            sum += grid[k][l];
        }
    }
    return sum;
}

int recur(int** grid, int i, int j) {
    if (i == 0 && j == 0) {
        result[0][0] = grid[0][0];
        return result[0][0];
    }
    if (i == 0 && j) {
        if (result[0][j]) return result[0][j];
        result[0][j] = sum(grid, 0, j);
        return result[0][j];
    }
    if (j == 0 && i) {
        if (result[i][0]) return result[i][0];
        result[i][0] = sum(grid, i, 0);
        return result[i][0];
    }

    if (result[i][j]) return result[i][j];
    result[i][j] = min(recur(grid, i - 1, j), recur(grid, i, j - 1)) + grid[i][j];
    return result[i][j];
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    for(int i = 0; i<gridSize; i++)
        for(int j = 0; j<*gridColSize; j++)
            result[i][j] = 0;

    return recur(grid, gridSize - 1, *gridColSize - 1);
}

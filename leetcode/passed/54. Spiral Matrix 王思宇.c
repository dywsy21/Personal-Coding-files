/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* ret = (int*) malloc(matrixSize * matrixColSize[0] * sizeof(int));
    *returnSize = matrixSize * matrixColSize[0];

    int i = 0, min_x = 0, min_y = 0, max_y = matrixSize - 1, max_x = matrixColSize[0] - 1;
    int cur_x = 0, cur_y = 0;

    if (matrix == NULL || matrixSize == 0 || matrixColSize == NULL) {
        *returnSize = 0;
        return NULL;
    }

    while(i < *returnSize){
        if(cur_x == min_x && cur_y == min_y){ //向右
            while(cur_x <= max_x) ret[i++] = matrix[cur_y][cur_x++];
            cur_x--;
            min_y++;
            cur_y++;
            continue;
        }

        if(cur_x == max_x && cur_y == min_y){ //向下
            while(cur_y <= max_y) ret[i++] = matrix[cur_y++][cur_x];
            cur_y--;
            max_x--;
            cur_x--;
            continue;
        }

        if(cur_x == max_x && cur_y == max_y){ //向左
            while(cur_x >= min_x) ret[i++] = matrix[cur_y][cur_x--];
            cur_x++;
            max_y--;
            cur_y--;
            continue;
        }

        if(cur_x == min_x && cur_y == max_y){ //向上
            while(cur_y >= min_y) ret[i++] = matrix[cur_y--][cur_x];
            cur_y++;
            min_x++;
            cur_x++;
            continue;
        }
    }
    return ret;

}
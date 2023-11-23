
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
    for(int i = 0; i < matrixSize; i++){
        int row = i, col = 0, val = matrix[i][0];
        while(row < matrixSize && col < *matrixColSize){
            if(matrix[row][col] != val) return false;
            row++; col++;
        }
    }

    for(int i = 1; i < *matrixColSize; i++){
        int row = 0, col = i, val = matrix[0][i];
        while(row < matrixSize && col < *matrixColSize){
            if(matrix[row][col] != val) return false;
            row++; col++;
        }
    }
    return true;

}
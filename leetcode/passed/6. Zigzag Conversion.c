#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void set_all_elements_to_0(char** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = '0';
        }
    }
}

void next_character(char* oristr, int* index_oristr, char** matrix, int rows, int cols, int* index_row, int* index_col) {
    if (((*index_row) > 0 && matrix[(*index_row) - 1][(*index_col)] != '0' && (*index_row) != rows-1) || (*index_row) == 0) {
        matrix[*index_row][*index_col] = oristr[*index_oristr];
        (*index_row)++;
        (*index_oristr)++;
        return;
    }

    if (((*index_row) == rows-1) || ((*index_row) > 0 && matrix[(*index_row) - 1][(*index_col)] == '0')) {
        matrix[*index_row][*index_col] = oristr[*index_oristr];
        (*index_row)--;
        (*index_col)++;
        (*index_oristr)++;
        return;
    }
}

void calculate_the_result(char** matrix, int rows, int cols, char* ret) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != '0') {
                ret[k] = matrix[i][j];
                k++;
            }
        }
    }
    ret[k] = '\0';  // Add null-terminator to mark the end of the string
}

char* convert(char* s, int numRows) {
    if(numRows==1) return s;
    int cols = 1010;
    char** matrix = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; i++)
        matrix[i] = (char*)malloc(cols * sizeof(char));

    char* ret = (char*)malloc(2 * strlen(s) * sizeof(char));

    set_all_elements_to_0(matrix, numRows, cols);

    int index_s = 0, index_r = 0, index_c = 0;

    while (s[index_s])
        next_character(s, &index_s, matrix, numRows, cols, &index_r, &index_c);

    calculate_the_result(matrix, numRows, cols, ret);

    for(int p=0;p<numRows;p++) free(matrix[p]);
    free(matrix);

    return ret;
}

int main() {
    char s[] = "PAYPALISHIRING";
    int numRows = 3;
    char* result = convert(s, numRows);
    printf("Result: %s\n", result);

    // Free the allocated memory
    free(result);
    system("pause");
    return 0;
}

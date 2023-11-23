#define max(a,b) ((a)>=(b)?(a):(b))

int comp(const void* a,const void* b){
    return *(int*)b - *(int*)a;   //降序
}

int Convert_1s_of_row_into_number(int** matrix, int row, int columnsize) {
    int ret = 0;
    int place_value = 1;  // Initialize place value for ones digit
    for (int j = columnsize - 1; j >= 0; j--) {
        if (matrix[row][j] == 1) {
            ret += place_value;
        }
        place_value *= 10;  // Update the place value for the next digit
    }
    return ret;
}

int Convert_0s_of_row_into_number(int** matrix, int row, int columnsize) {
    int ret = 0;
    int place_value = 1;  // Initialize place value for ones digit
    for (int j = columnsize - 1; j >= 0; j--) {
        if (matrix[row][j] == 0) {
            ret += place_value;
        }
        place_value *= 10;  // Update the place value for the next digit
    }
    return ret;
}


int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize){
    int m=matrixSize, n=matrixColSize[0]; //m行n列
    int det[2*m+100];  //m行，每行有两个特征值，分别是1的和0的
    int i=0;  //i-->2i,2i+1
    for(i=0;i<=m-1;i++){
        det[2*i]=Convert_0s_of_row_into_number(matrix, i, n);
        det[2*i+1]=Convert_1s_of_row_into_number(matrix, i, n);
    }
    qsort(det,2*m,sizeof(int),comp);

    int ret=0,k=0,k_temp;
    while(k<=2*m-2&&det[k]!=0){
        if(det[k]==det[k+1]){
            k_temp=k;
            while(det[k]==det[k+1]&&k<=2*m-2) k++;
            ret=max(ret, k-k_temp+1);
        }
        k++;
    }
//处理det=0的情况
    if(det[k]==0) ret=max(ret, 2*m-k);
    return ret;
}
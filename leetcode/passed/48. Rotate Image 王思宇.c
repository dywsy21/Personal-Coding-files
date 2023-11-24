//题目限制：矩阵中所有元素绝对值小于1000
int abs(int a){
    return a > 0 ? a : (-a);
}

int transform(int new, int old){
    return 10000* new + old;
}

int fetch_new(int num){
    int raw_num = num / 10000;
    if(abs(num - 10000 * raw_num) > 5000) return num < 0 ? raw_num - 1 : raw_num + 1;
    else return raw_num;
}

int fetch_old(int num){
    return num - 10000 * fetch_new(num);
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    //整数a要被转到整数b的位置上时，把整数b的位置修改成10000*a + b，
    //这样a，b的信息都能保留下来，同时不malloc新的矩阵
    //a：new  b：old

    int n = matrixSize; //n*n
    for(int p = 0; p < n; p++)
        for(int i = 0; i < n; i++)
            matrix[i][n-1-p] = transform(fetch_old(matrix[p][i]), fetch_old(matrix[i][n-1-p]));

    for(int p = 0; p < n; p++)
        for(int i = 0; i < n; i++)
            matrix[p][i] = fetch_new(matrix[p][i]);

}

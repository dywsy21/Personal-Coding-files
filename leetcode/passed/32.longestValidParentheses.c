#include <bits/stdc++.h>

#define MAXSIZE 3200
#define max(a, b) ((a) >= (b) ? (a) : (b))

void qiantao(char* s, int* left, int* right, int* det) {
    if((*left)-1>=0&&((*right)+1)>=0){    //这行一定别缺！！！缺了就溢出！！！
    if (s[*left - 1] == '(' && s[*right + 1] == ')') {
        (*left)--;
        (*right)++;
        (*det)++;
        qiantao(s, left, right, det);
    }
    }
}

void seed_growing(char* s, int** seed, int* maxlen, int* det) {
 //seed[i][0],seed[i][1]分别表示第i个seed的左端和右端位置，
 //假设seed已从左到右排列，seed中无用的部分全设为-1
    int state_seed[MAXSIZE] = {0};  // Initialize to 0
    int** temp_seed = (int**)malloc(MAXSIZE * sizeof(int*));
    for (int i = 0; i < MAXSIZE; i++) {
        temp_seed[i] = (int*)malloc(2 * sizeof(int));
    }

//如果上一次迭代全程未执行任何并列或嵌套的操作，则直接返回，结束迭代
    if ((*det) == 0)
        return;
    (*det) = 0;

//state_seed初始化，若一个seed的右边有相邻的seed，则设为1，否则是0(并列操作中会使用)
    int i = 0, j = 0;
    while (seed[i][0] != -1 && seed[i + 1][0] != -1) {
        if (seed[i][1] + 1 == seed[i + 1][0])  // Check if adjacent seeds
            state_seed[i] = 1;
        i++;
    }


//并列操作    
    i = 0;
    j = 0;
    while (seed[i][0] != -1) {
        temp_seed[j][0] = seed[i][0];
        while (state_seed[i] == 1) {
            i++;
            (*det)++;
        }
        temp_seed[j][1] = seed[i][1];
        i++;
        j++;
    }


//temp_seed中多余的项归为-1
    for (; j < MAXSIZE; j++) {
        temp_seed[j][0] = -1;
        temp_seed[j][1] = -1;
    }

//嵌套操作
    i = 0;
    while (temp_seed[i][0] != -1) {
        qiantao(s, &temp_seed[i][0], &temp_seed[i][1], det);
        i++;
    }

//更新maxlen
    i = 0;
    while (temp_seed[i][0] != -1) {
        *maxlen = max(*maxlen, temp_seed[i][1] - temp_seed[i][0]);
        i++;
    }

//进入下一轮迭代
    seed_growing(s, temp_seed, maxlen, det);

}

int longestValidParentheses(char* s) {
    if(strlen(s)==0) return 0;
    int det = 1;
    int maxlen = 0;
    int** seed = (int**)malloc(MAXSIZE * sizeof(int*));

//找到初始的seed数组，并将多余的项设为-1
    for (int i = 0; i < MAXSIZE; i++) {
        seed[i] = (int*)malloc(2 * sizeof(int));
        seed[i][0] = -1;
        seed[i][1] = -1;
    }

    int i = 0, j = 0;
    while (i < strlen(s) - 1) {
        if (s[i] == '(' && s[i + 1] == ')') {
            seed[j][0] = i;
            seed[j][1] = i + 1;
            j++;
            i++;
        }
        i++;
    }

    seed_growing(s, seed, &maxlen, &det);

    // Free allocated memory for seed
    for (int i = 0; i < MAXSIZE; i++) {
        free(seed[i]);
    }
    free(seed);

    if(maxlen!=0)     return maxlen+1;
    else return 0;
}

int main() {
    char str1[40000];
    gets(str1);
    clock_t start_time = clock();  // 记录起始时间
    printf("%d\n", longestValidParentheses(str1));
    clock_t end_time = clock();  // 记录结束时间
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;  // 计算经过的时间，单位为秒
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    system("pause");
    return 0;
}

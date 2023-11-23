#include <bits/stdc++.h>

#define RATE 0.55
#define PI 3.14159265
#define X_LENGTH 28
#define Y_LENGTH 80
#define SCALE 20


//修改该函数可得到不同的图像；
//该函数只支持r=r(theta)，即左边只有r，右边为关于theta的表达式的形式
double func(double a) { 
    double r = 1-cos(a);
    return r;
}

int main() {
    char canvas[X_LENGTH][Y_LENGTH] = {'\0'}; // 使用单引号初始化字符数组

    for (int theta = 0; theta <= 360; theta++) {
        double alpha = theta / 180.0 * PI;
        double r = func(alpha) * SCALE;
        double x = r * cos(alpha);
        double y = r * sin(alpha);

        // 计算数组索引，确保不越界
        int i = X_LENGTH / 2 - round(RATE * y);
        int j = Y_LENGTH / 2 + x;

        // 检查索引是否越界
        if (i >= 0 && i < X_LENGTH && j >= 0 && j < Y_LENGTH) {
            canvas[i][j] = '*';
        }
    }

    for (int i = 0; i < X_LENGTH; i++) {
        for (int j = 0; j < Y_LENGTH; j++) {
            if (canvas[i][j] != '*') {
                printf(" ");
            } else {
                printf("%c", canvas[i][j]);
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

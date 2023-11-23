#include<bits/stdc++.h>
using namespace std;

int num[3];
int digit[20];

int qushuwei(int where, int n) {
    if (where > 1) {
        return ((n - n % (int)pow(10, where - 1)) / (int)pow(10, where - 1)) % 10;
    }
    else {
        return n % 10;
    }
}

bool repeat_or_zero(int num[3]) {
    int digit_count[10] = { 0 }; // 使用数组记录数字出现次数

    for (int i = 0; i < 3; i++) {
        int n = num[i];
        for (int j = 0; j < 3; j++) {
            int d = qushuwei(j + 1, n);
            if (d == 0) {
                return true; // 如果数字包含0，返回true
            }
            digit_count[d]++;
            if (digit_count[d] > 1) {
                return true; // 如果数字重复出现，返回true
            }
        }
    }

    return false; // 没有0或重复数字，返回false
}

int main() {
    for (num[0] = 123; num[0] <= 329; num[0]++) {
        num[1] = 2 * num[0];
        num[2] = 3 * num[0];

        if (!repeat_or_zero(num)) {
            cout << num[0] << " " << num[1] << " " << num[2] << endl;
        }
    }

    system("pause");
    return 0;
}

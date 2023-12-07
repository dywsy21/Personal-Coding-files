#include<bits/stdc++.h>
typedef long long ll;


int min(int x, int y){
    return x < y ? x : y;
}

int max(int x, int y){
    return x > y ? x : y;
}

int comp(int x, int y, int (*ptr)(int, int)) {
    return ptr(x, y);
}

int main() {
    int (*ptr[2])(int, int);
    int x = 5, y = 8;
    ptr[0] = min;
    ptr[1] = max;
    std::cout << ptr[0](x, y) << ptr[1](x, y) << comp(x, y, min);

    getchar();
    return 0;
}

#include<bits/stdc++.h>

int min(int x, int y){
    return x < y ? x : y;
}

int max(int x, int y){
    return x > y ? x : y;
}

int main(){
    int (*ptr[2])(int, int); // Fix: Declare ptr as an array of function pointers
    int x{5}, y{8};
    ptr[0] = min; // Fix: Assign function pointer to ptr[0]
    ptr[1] = max; // Fix: Assign function pointer to ptr[1]
    std::cout << ptr[0](x, y) << ptr[1](x, y); // Fix: Call functions using function pointers

    getchar();
}
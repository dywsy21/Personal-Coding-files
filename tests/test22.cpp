#include<bits/stdc++.h>

int main(){
    int a[2][2][2];
    for(int i = 0; i < 2; i++) 
        for(int j = 0; j < 2; j++) 
            for(int k = 0; k < 2; k++) 
                std::cout << &a[i][j][k] << " " << a[i][j]+k << " " << *(a[i]+j)+k << " " << *(*(a+i)+j)+k << "\n";
    getchar();
}
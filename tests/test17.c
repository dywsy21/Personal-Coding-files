#include<bits/stdc++.h>
#define DEBUG printf("\nI'm here!\n")
using namespace std;


int main(){
    int n;
    cin >> n;
    int i=1;

    while(i*i<=n/2){
        if((int)sqrt(n-i*i)==sqrt(n-i*i)) printf("%d=%d^2+%d^2\n",n,i,(int)sqrt(n-i*i));
        i++;
    }


    system("pause");
    return 0;
}
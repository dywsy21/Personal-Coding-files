#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int result=1;

int Dprime(int x){
    for (int i=2;(double)i<=sqrt((double)x);i++){
        if(x%i==0){
            result=0;
            break;
        }
    }
    return result;
}

int main(){
    int n;
    printf("Input number n:");
    scanf("%d",&n);
    if(Dprime(n)==0){printf("\n%d is not a prime.",n);}
    else {printf("\n%d is a prime.",n);}
    system("pause");
    return 0;
}
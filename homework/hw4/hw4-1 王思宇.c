#include<stdio.h>
#include<stdlib.h>
#include<math.h>


long long BinomicalCoefficient(int n, int m){
    long long result=1;
    for (int i = 1; i <= m; i++) {
        result *= n;
        result /= i;
         n--;
    }
    return result;
}

int main(){
    int a,b;
    printf("Input n and m. (nCm)\n");
    scanf("%d%d",&a,&b);
    printf("The result is %lld\n", BinomicalCoefficient(a,b));
    system("pause");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


int factorial(int k){
    int product=1,i=1;
    while(i<=k){
        product*=i;
        i++;
    }
    return product;
}


void output(int p){
    for(int i=1;i<=p;i++) printf("output!\n");
}



int main(){
    int a=1,b,sum;
    cout << "Hello world! ";
    cin >> b;

    for(int i=0;i<=100;i=i+1)
        sum=sum+i;

    printf("%d",factorial(10));
    output(b);

    system("pause");
    return 0;








}
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,sum;
    printf("Input number n:");
    scanf("%d",&n);
    int a[n];
    printf("\nInput %d numbers:",n);
    for(int i=0;i<=n-1;i++) scanf("%d",&a[i]);
    for(int i=0;i<=n-1;i++) sum+=a[i];
    printf("\nThe sum is %d",sum);

    
    system("pause");
    return 0;
}

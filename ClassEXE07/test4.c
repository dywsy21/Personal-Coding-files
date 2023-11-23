#include<stdio.h>
#define N 5
int main()
{
    int a[N][N]={0},m=0,n=N/2,new_m,new_n;
    a[m][n]=1;
    for(int i=2;i<=N*N;i++)
    {
        new_m=m-1; new_n=n+1;
        if(new_m<0) new_m=N-1;
        if(new_n>N-1) new_n=0;
        if(a[new_m][new_n]!=0)
        {new_m=m+1; new_n=n;}
        a[new_m][new_n]=i;
        m=new_m; n=new_n;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            printf("%-3d",a[i][j]);
        printf("\n");
    }
        
    return 0;
}
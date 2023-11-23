#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define max(a,b) ((a)>=(b)?(a):(b))

int main(){
    int n,s,t,x,y,a,b;
    scanf("%d%d%d%d%d%d%d",&n,&s,&t,&x,&y,&a,&b);
    long long big,small,ans=0,temp;
    big=n*x; small=n*y;

    if(s<=big){
        ans+=(big-s)*a+max(small-t,0)*b;
    }
    else{
        temp=t+s-big;
        ans+=max(small-temp,0)*b;
    }

    printf("%lld",ans);


    system("pause");
    return 0;
}
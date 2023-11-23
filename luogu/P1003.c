#include<bits/stdc++.h>

int main(){
    int n,x,y,result=-1;
    scanf("%d",&n);
    int a[n],b[n],g[n],k[n];
    for(int i=0;i<=n-1;i++) scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
    scanf("%d%d",&x,&y);
    for(int i=0;i<=n-1;i++){
        if(x>=a[i]&&x<=a[i]+g[i]&&y>=b[i]&&y<=b[i]+k[i]) result=i+1;
    }
    printf("%d",result);
    system("pause");
    return 0;
}
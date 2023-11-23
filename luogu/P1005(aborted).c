#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define min(a,b) ((a)<=(b)?(a):(b))

int main(){
    long long result=0;
    int m,n,cache1,cache2,value[85][85],coords[10];
    double p=1.0;
    scanf("%d%d",&n,&m);


    for(int j=0;j<=m-1;j++){
        for(int i=0;i<=n-1;i++) 
            scanf("%d",&value[i][j]);  //n行m列
    }

    for(int i=0;i<=m-1;i++){ //共操作m次
        for(int j=0;j<=n-1;j++){ //每次操作，对每行都要取值，共操作n次
            for(int k=0;k<=m-1;k++){
                if(value[j][k]!=-1) {cache1=value[j][k];
                coords[1]=j;coords[2]=k;break;}
            }
            for(int k=m-1;k>=0;k--){
                if(value[j][k]!=-1) {cache2=value[j][k];
                coords[3]=j;coords[4]=k;break;}
            }
            result=result+(long long)((int)pow(2.0,p)*min(cache1,cache2));

            if(min(cache1,cache2)==cache1){value[coords[1]][coords[2]]=-1;}
                else{value[coords[3]][coords[4]]=-1;}

        }
        p++;
    }
    printf("%lld",result);
    system("pause");
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define min(a,b) ((a)<=(b)?(a):(b))

int value[90][90];
double p=1.0;
long long result=0;
int q=1;

long long Msolve(int R,int C){
    if(C==0) return result;

        for(int i=0;i<=R-1;i++){
         result+=pow(2.0,p)*min(value[i][0],value[i][C-1]);
         //printf("%lld\n",result);
         if(value[i][C-1]>=value[i][0]) {for(int j=1;j<=C-1;j++) value[i][j-1]=value[i][j];}



        }

    
        /*for(int v=0;v<=R-1;v++){
            for(int u=0;u<=C-1;u++){
                printf("%d ",value[v][u]);
            }
            printf("\n");
        }*/
    p++;
    return Msolve(R,C-1);
    }



int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int g=0;g<=n-1;g++){
        for(int h=0;h<=m-1;h++){
            scanf("%d",&value[g][h]);    //输入没问题
        }
    }

    printf("%lld",Msolve(n,m));
    system("pause");
    return 0;
}
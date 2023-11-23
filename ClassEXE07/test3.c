#include<stdio.h>
int main()
{
    double a[10],b[10],EX=0,EY=0,EXY=0,varX=0,varY=0;
    printf("enter X(5 numbers):");
    for(int i=0;i<5;i++) scanf("%lf",&a[i]);
    printf("enter Y(5 numbers):");
    for(int i=0;i<5;i++) scanf("%lf",&b[i]);
    for(int i=0;i<5;i++)
    {EX+=a[i]; EY+=b[i]; EXY+=a[i]*b[i];}
    EX/=5; EY/=5; EXY/=5;
    for(int i=0;i<5;i++)
    {varX+=(a[i]-EX)*(a[i]-EX); varY+=(b[i]-EY)*(b[i]-EY);}
    varX/=5; varY/=5;
    printf("avg(X)=%lf\navg(Y)=%lf\n",EX,EY);
    printf("var(X)=%lf\nvar(Y)=%lf",varX,varY);
    printf("cov(A,B)=%lf\n",EXY-EX*EY);
    return 0;
}
#include<stdio.h>

int sum(int n){
	int s=0,i;
	for (i=1;i<=n;i++) s=s+i;
	return s;
} 

int main(){
	int n;
	printf("Please input an integer:\n");
	scanf("%d",&n);
	if(n>=4) printf("1+2+...+%d=%d",n,sum(n));
	if(n==3) printf("1+2+3=%d",sum(n));
	if(n==2) printf("1+2=%d",sum(n));
	if(n==1) printf("1=%d",sum(n));
	
	return 0;
}

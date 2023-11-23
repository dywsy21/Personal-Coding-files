#include<stdio.h>

void min(int a,int b,int c){
	int x=a;
	if(x>b) x=b;
	if(x>c) x=c;
	printf("The minimum is %d",x);	
}


int main(){
	printf("Please input 3 integers:\n");
	int a[3];
	for(int i=0;i<=2;i++) scanf("%d",&a[i]);
	min(a[0],a[1],a[2]);
	
	return 0;
} 

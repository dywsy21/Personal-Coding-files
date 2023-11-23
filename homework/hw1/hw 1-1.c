#include<stdio.h>

int main(){
	printf("Input the number of rows: ");
	int n,i,k;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		for (k=1;k<=n;k++) printf("*");
		printf("\n");
	}
	
	
	
	
	
	
	return 0;
} 

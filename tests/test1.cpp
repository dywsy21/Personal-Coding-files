#include <stdio.h>
int main(){
int n,i;
printf("Please input how many numbers you want to sort:\n");
scanf("%d",&n);
float a[n];
printf("Please input the numbers you want to sort:\n");
for(i=0;i<=n-1;i=i+1) scanf("%f",&a[i]);
int b[n],delta=n-1,k;
for(i=0;i<=n-1;i=i+1) b[i]=0;
for(i=0;i<=n-1;i=i+1) {
	for(k=0;k<=n-1;k=k+1){
		if(a[i]<a[k]) b[i]=b[i]+1;		
		}
	}

	printf("The ascending order of these numbers is ");
while (delta>=0){
		for (i=n-1;i>=0;i=i-1) if (b[i]==delta) printf("%f ",a[i]);
		delta=delta-1;

	}
	
	printf("\nThe descending order of these numbers is ");
	delta=0;
	while (delta<=n-1){
		for (i=n-1;i>=0;i=i-1) if (b[i]==delta) printf("%f ",a[i]);
		delta=delta+1;

	}
	return 0;
}

	
	
	


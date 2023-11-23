#include<bits/stdc++.h>
#define LEN 1024

int main(){
	
	char str[LEN]="\0",x;
	char obj[LEN]="\0";
	char cache[LEN]="\0";
	printf("Please input a string:\n");
	gets(str);
	printf("Please  input the character:\n");
	scanf("%c",&x);
	printf("Please input the objective string:\n");
	scanf("%s",obj);
	int L1=strlen(str),i,j,k=0;
	
	for (i=L1;i>=0;i=i-1){   
	 
	 
	 if (str[i]==x) {
	 	for (j=i+1;str[j]!='\0';j++){
	 		cache[k]=str[j];
	 		k++;
		 }
	 	
	 	

	 	str[i]='\0';
	 
	 	strcat(str,obj);
	 	strcat(str,cache);
	 	k=0;

	 
	 		
	 		
		 


	}
}
	 puts(str);
	 system("pause");
return 0;
} 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAXSIZE 100000

void ToLowerCase(char* str){
    for(int i=0;str[i]!='\0';i++){
        if('A'<=str[i]&&str[i]<='Z') str[i]+=32;
    }
}



int main(){
    char* string=(char*) malloc(MAXSIZE*sizeof(char));
    printf("Input a string:\n");
    gets(string);
    ToLowerCase(string);
    printf("The converted version is:");
    puts(string);

    system("pause");
    return 0;
}
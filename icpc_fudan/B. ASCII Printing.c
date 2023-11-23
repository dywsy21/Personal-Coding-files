#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    char s[160];
    int i=0;
    gets(s);
    while(i<strlen(s)-1){
        printf("%d ",s[i]);
        i++;
    }
    printf("%d", s[i]);
    system("pause");
    return 0;
}
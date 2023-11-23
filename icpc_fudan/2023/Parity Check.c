#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
    char* array=(char*) malloc(1000009*sizeof(char));
    char det;
    int ans=0, num_of_1=0, i=0;
    scanf("%c",&det);
    getchar();
    fgets(array, sizeof(array), stdin);    
    while(array[i]){
        if(array[i]=='1') num_of_1++;
        i++;
    }

    if(det=='O'){
        if((num_of_1+ans)%2!=1) ans++;
    }
    else{
        if((num_of_1+ans)%2!=0) ans++;
    }
    printf("%d",ans);


    system("pause");
    return 0;
}
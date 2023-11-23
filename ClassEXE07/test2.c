#include<stdio.h>
int main()
{
    char str[128];
    gets(str);
    int i=1,count=0;
    while(str[i]!='\0')
    {
        if(str[i]==str[i-1]) count++;
        else
        {
            if(count) printf("%d%c",count+1,str[i-1]);
            else printf("%c",str[i-1]);
            count=0;
        }
        i++;
    }
    if(count) printf("%d%c",count+1,str[i-1]);
    else printf("%c",str[i-1]);
    return 0;
}
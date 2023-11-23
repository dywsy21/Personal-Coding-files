#include<stdio.h>
int main()
{
    char str[128];int i=0,blank=0;
    gets(str);
    while(str[i]!='\0')
    {
        if(i==0&&str[i]>='a'&&str[i]<='z') str[i]+='A'-'a';
        if(blank&&str[i]>='a'&&str[i]<='z')
        {
            str[i]+='A'-'a';
            blank=0;
        }
        if(str[i]==' ') blank=1;
        i++;
    }
    printf("%s\n",str);
    return 0;
}
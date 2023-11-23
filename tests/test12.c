#include<stdio.h>
void swap(char *a,char *b)
{
    char **temp= &a;
    &a=&b;
    &b=temp;
}
int main()
{
    char *s1="Beijing",*s2="Shanghai";
    swap(s1,s2);
    printf("%s\n%s",s1,s2);
    getchar();
    return 0;
}
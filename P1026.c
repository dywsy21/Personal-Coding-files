#include<stdio.h>
int main()
{
    char str[256]={'\0'},c,word[6][128]={'\0'};
    int p,k,s,wordlen[6],note[256]={0},cut[256]={0},wordcount=0;
    scanf("%d %d",&p,&k);
    getchar();
    int j=0;
    for(int i=0;i<p;i++)
    {
        while((c=getchar())!='\n')
            str[j++]=c;
    }
    scanf("%d",&s);
    for(int i=0;i<s;i++)
    {
        int m=0;
        while((c=getchar())!='\n')
            word[i][m++]=c;
        wordlen[i]=m;
        for(int j=0;j<=20*p-wordlen[i];j++)
        {
            int check=1;
            for(int k=0;k<wordlen[i];k++)
                if(str[j+k]!=word[i][k]) check=0;
            if(check)
            {
                if(note[j]==0)
                {
                    note[j]=wordlen[i];
                    wordcount++;
                }
                else if(wordlen[i]<note[j]) note[j]=wordlen[i];
            }
        }
    }
    for(int i=1;i<p*20;i++)
        for(int j=0;j<i;j++)
            if(j+note[j]-1>=i) cut[i]++;
    int temp;
    for(int i=1;i<p*20;i++)
        for(int j=0;j<p*20-i;j++)
            if(cut[i]<cut[i+1])
            {temp=cut[i]; cut[i]=cut[i+1]; cut[i+1]=temp;}
    for(int i=0;i<k-1;i++)
        wordcount-=cut[i];
    printf("%d",wordcount);
    return 0;
}
/*
thisisabookyouareaoh
thisisabookyouareaoh
*/
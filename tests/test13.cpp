#include <bits/stdc++.h>

int isp(int x)
{
    int i;
    for(i=2;i*i<=x;i++)
    {
        if (x%i==0) {
            return 0;
            break;
        }
        
    }
    return x;
}

int main()
{
/*    int mynum;
    int i;
    int countnum=2;

    printf("Please input a number:\n");
    scanf("%d",&mynum);
    for(i=4;i<=mynum;i++){
        if(isp(i)) 
        {countnum++;
        printf("%d  ",isp(i));}
    }
    printf("\n There are %d prime numbers\n", countnum);
*/
    int i = 0;
    char c[5] = "abcd";
    while(c[++i]);
    std::cout << i;
    system("pause");
    return 0;
}


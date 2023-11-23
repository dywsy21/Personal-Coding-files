#include <stdio.h>
#include <stdlib.h> // itoa 所在头文件
int main()
{
    int num = 3;
    char str[10];
    // num:待转换的整数；str:转换后的字符串;10:转换进制数
    itoa(num, str, 10);
    printf("%s\n", str);

    char s[] = "22";
    // s:待转换字符串;函数返回值:转换后的整数int
    int num1 = atoi(s);
    printf("%d\n", num1);



    system("pause");
    return 0;
}
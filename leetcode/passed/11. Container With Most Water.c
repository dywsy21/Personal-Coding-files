#include<bits/stdc++.h>
using namespace std;
int maxArea(int* height, int heightSize){
    int result=0;
    for(int i=0;i<=heightSize-1;i++){
        for(int j=i+1;j<=heightSize;j++){
            result=result>=(j-i)*(height[i]<=height[j]?height[i]:height[j])?result:(j-i)*(height[i]<=height[j]?height[i]:height[j]);
        }
    }

    return result;
}

int main(){
     int n; // 数组的大小
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *height = (int *)malloc(n * sizeof(int)); // 动态分配数组内存

    printf("Enter %d integers for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]); // 输入每个元素的值
    }

    // 现在 height 数组包含了输入的整数值
    printf("%d",maxArea(height,n));
    // 在使用完数组后，不要忘记释放内存
    free(height);





    system("pause");
    return 0;
}
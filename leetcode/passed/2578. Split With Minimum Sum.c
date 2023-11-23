#include<bits/stdc++.h>
using namespace std;

int comp(const void* a,const void* b){
    return *(int*)b - *(int*)a;   //降序
}
int digit_number(int num) {
    int i = 0;
    while (num != 0) {
        num /= 10;
        i++;
    }
    return i;
}


int* digit(int num) {
    int numDigits = digit_number(num);
    int* digits = (int*)malloc(numDigits * sizeof(int));

    for (int i = numDigits - 1; i >= 0; i--) {
        digits[i] = num % 10;
        num /= 10;
    }

    return digits;
}

int splitNum(int num){
    int* digits=digit(num);
    qsort(digits,digit_number(num),sizeof(int),comp); //降序
    int i=0,ans=0;  //2i,2i+1
    while(2*i<=digit_number(num)-1){
        ans+=(int)pow(10,i)*digits[2*i];
        if(2*i+1<=digit_number(num)-1)  ans+=(int)pow(10,i)*digits[2*i+1];
        else break;

        i++;
    }
    free(digits);
    return ans;
}

int main(){
    int s;
    cin >> s;
    cout << digit_number(s)  << endl;
    cout << splitNum(s)  << endl;
    system("pause");
    return 0;
}
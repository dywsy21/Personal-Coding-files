#include<bits/stdc++.h>

int check_the_validity_of(char* s, int start, int end){   //check from s[start] to s[end], 1 for valid, 0 for invalid
    if(end>strlen(s)-1) return 0;
    int left=0, right=0;
    int mid;
    if((end-start+1)%2==0) mid=(end-start+1)/2;
        else mid=(end-start)/2;
    for(int i=start; i<=end; i++){
        if(s[i]=='(') left++;
        if(s[i]==')') right++;
        if(right>left) return 0;
        if(left>mid) return 0;
    }

    if(right==left) return 1;
    else return 0;

}

int longestValidParentheses(char* s){
    int slen= strlen(s);
    int i_0;
    if(slen%2==0) i_0=slen;
        else i_0=slen-1;

    for(int i=i_0;i>=2;i=i-2){   //i表示长度
        for(int j=0;j<=slen-i+1;j++){   //j表示start，因而，end=j+1-1
            if(check_the_validity_of(s,j,j+i-1)==1) {
                return i;
            }
        }
    }
    return 0;
}

int main() {
    char str1[40000];
    gets(str1);
    clock_t start_time = clock();  // 记录起始时间
    printf("%d\n", longestValidParentheses(str1));
    clock_t end_time = clock();  // 记录结束时间
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;  // 计算经过的时间，单位为秒
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    system("pause");
    return 0;
}
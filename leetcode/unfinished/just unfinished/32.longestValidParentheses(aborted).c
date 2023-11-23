#include<bits/stdc++.h>
#define min(a,b) ((a)<=(b)?(a):(b))

int longestValidParentheses(char* s){
    int s_len=strlen(s)-1;
    int a[s_len],b[s_len];
    for(int p=0;p<=s_len-1;p++){
        a[p]=0; b[p]=0;
    }

    int i=0,j=0,k=0;
    while(i<=s_len){
        while(s[i]=='('){
           a[j]++; 
           i++;
        }
        j++;
        while(s[i]==')'){
            b[k]++;
            i++;
        }
        k++;
    }

    int ans=0;
    for(int q=0;q<=s_len-1;q++){
        ans+=min(a[q],b[q]);
        if(a[q]>b[q]) a[q+1]+=a[q]-b[q];
    }

    return 2*ans;
}

int main(){
    char str[]="(()";
    printf("%d",longestValidParentheses(str));
    
    system("pause");
    return 0;
}
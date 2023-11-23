#include<bits/stdc++.h>

int check_if_prime(int n){
    int det=0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            det++;
            break;
        }
    }

    if(det==0) return 1;
    else return 0;
}

int main(){
    int a,b,c,d;
    for(a=1;a<=4;a++){
        for(b=1;b<=4;b++){
            for(c=1;c<=4;c++){
                for(d=1;d<=4;d++){
                    if((!(a==b||a==c||a==d||b==c||b==d||c==d))&&check_if_prime(1000*a+100*b+10*c+d)==1)
                        printf("%d\n",1000*a+100*b+10*c+d);
                }
            }
        }
    }

    system("pause");
    return 0;
}
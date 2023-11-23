#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,num[20]={0},k=0;
    cin >> n;
    for(int i=15;i>=0;i--){
        if(n>=(int)pow(2,i)){
            if(i!=0){
                num[k]=i;
                k++;
                n-=(int)pow(2,i);}
            else{
                num[k]=20;
                break;
            }
        }
    }

    for(int t=0;t<=18;t++){
        if(num[t]!=0){
        switch(num[t]){
            case 15:
                cout <<  "2(2(2+2(0))+2(2)+2+2(0))";
                break;
            case 14:
                cout <<  "2(2(2+2(0))+2(2)+2)";
                break;
            case 13:
                cout <<  "2(2(2+2(0))+2(2)+2(0))";
                break;
            case 12:
                cout <<  "2(2(2+2(0))+2(2))";
                break;
            case 11:
                cout <<  "2(2(2+2(0))+2+2(0))";
                break;
            case 10:
                cout <<   "2(2(2+2(0))+2)";
                break;
            case 9:
                cout <<     "2(2(2+2(0))+2(0))";
                break;
            case 8:
                cout <<     "2(2(2+2(0)))";
                break;
            case 7:
                cout <<     "2(2(2)+2+2(0))";
                break;
            case 6:
                cout <<     "2(2(2)+2)";
                break;
            case 5:
                cout <<     "2(2(2)+2(0))";
                break;
            case 4:
                cout <<     "2(2(2))";
                break;
            case 3:
                cout <<     "2(2+2(0))";
                break;
            case 2:
                cout <<     "2(2)";
                break;
            case 1:
                cout <<     "2";
                break; 
            case 20:
                cout <<     "2(0)";
                break; 
            }
        if(num[t+1]==0) {
            break;
        }
        else{
            cout << "+";
        }            
        }
        else{
            break;
        }
    }
    system("pause");
    return 0;
}
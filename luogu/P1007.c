#include<bits/stdc++.h>
using namespace std;
#define max(a,b) (a)>=(b)?(a):(b)
#define min(a,b) (a)<=(b)?(a):(b)

int main(){
    int L,N,min1=0,max1=0;
    cin >> L >> N;
    int a[N];
    for(int i=0;i<=N-1;i++) {
        cin >> a[i];
        min1=max(min(a[i],(L+1-a[i])),min1);
        max1=max(max(a[i],(L+1-a[i])),max1);
        }

    cout << min1 << " " << max1;
    system("pause");
    return 0;
}
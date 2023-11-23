
//一般方法
int mySqrt(int x){
    long long ret=x/2;
    while(ret*ret>x) ret/=2;
    while((ret+1)*(ret+1)<=x) ret++;
    return (int)ret;
}



//二分查找
int mySqrt(int x){
    if(x==1) return 1;
    int l=0,r=x,ans=0;
    long long mid;
    while(l<=r){
        mid=(l+r)/2;
        if(mid*mid>x) r=mid-1;
        if(mid*mid<x) {l=mid+1;   ans=mid;}
        if(mid*mid==x) return mid;
    }
    return ans;

}
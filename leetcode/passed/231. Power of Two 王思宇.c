bool isPowerOfTwo(int n){
    if(n==0) return false;
    if((int)pow(2,(int)(log(n)/log(2)))==n) return true;
    else return false;
}
double myPow(double x, int n) {
    long new_n = n; //为了避免n == -INT_MAX 导致越界
    if(new_n < 0){
        x = 1 / x; new_n = -new_n;
    }
    double ret = 1;

    //eg. x == 9 == '1001', x^9 == x^1 * x^8; 1001对应x^8(√), x^4, x^2, x^1(√)
    while(new_n){
        if(new_n & 1) ret *= x; //位预算与：判断二进制末位是不是1
        x *= x;
        new_n = new_n >> 1;  //or: new_n >>= 1
    }
    return ret;
}
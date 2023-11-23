long long mypow(long long pow_4, long long pow_5, int modu){
    if(pow_4 == 0 && pow_5 == 0) return 1;

    if(pow_4 % 2 == 0 && pow_5 % 2 == 0){
        long long tmp = mypow(pow_4 / 2, pow_5 / 2, modu);
        return tmp * tmp % modu;
    }
    if(pow_4 % 2 == 0 && pow_5 % 2 == 1){
        long long tmp = mypow(pow_4 / 2, pow_5 / 2, modu);
        long long tmp2 = tmp * 5 % modu;
        return tmp * tmp2 % modu;
    }
    if(pow_4 % 2 == 1 && pow_5 % 2 == 0){
        long long tmp = mypow(pow_4 / 2, pow_5 / 2, modu);
        long long tmp2 = tmp * 4 % modu;
        return tmp * tmp2 % modu;
    }
    if(pow_4 % 2 == 1 && pow_5 % 2 == 1){
        long long tmp = mypow(pow_4 / 2, pow_5 / 2, modu);
        long long tmp2 = tmp * 20 % modu;
        return tmp * tmp2 % modu;
    }
    return 1;
}

int countGoodNumbers(long long n) {
    long long pow_4 = n / 2;
    long long pow_5 = n - pow_4;
    int modu = 1000000007;
    return mypow(pow_4, pow_5, modu);
}
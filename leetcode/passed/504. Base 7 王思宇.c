char* convertToBase7(int num) {
    char* ret = (char*)malloc(32 * sizeof(char));
    if(num==0){
        ret[0]='0'; ret[1]='\0';
        return ret;
    }
    int isNegative=0;

    if (num<0) {
        isNegative=1;
        num=-num;
    }

    int maxpow = 12;
    while ((long)pow(7, maxpow) > num) maxpow--;

    for (int i = maxpow; i >= 0; i--) {
        int digit = num / (int)pow(7, i);
        ret[maxpow - i] = digit + '0';
        num %= (int)pow(7, i);
    }
    ret[maxpow + 1] = '\0';
    if (isNegative) {
        char* resultWithSign = (char*)malloc((maxpow + 3) * sizeof(char));
        resultWithSign[0] = '-';
        strcpy(resultWithSign + 1, ret);
        free(ret);
        return resultWithSign;
    }
    return ret;
}
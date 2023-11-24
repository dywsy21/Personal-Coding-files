#define max(a,b) ((a)>(b)?(a):(b))

char* addStrings(char* num1, char* num2) {
    int i = strlen(num1) - 1, j = strlen(num2) - 1, carry = 0;
    char* ret = (char*)malloc(sizeof(char) * (max(i, j) + 5));
    int len = 0;
    while (i >= 0 || j >= 0 || carry != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + carry;
        ret[len++] = '0' + result % 10;
        carry = result / 10;
        i--; j--;
    }
    //flip ret
    for (int i = 0; 2 * i < len; i++) {
        int temp = ret[i];
        ret[i] = ret[len - i - 1]; 
        ret[len - i - 1] = temp;
    }
    ret[len] = '\0';
    return ret;
}

char* single_digit_multiply(char* num1, char num2) {
    int i = strlen(num1) - 1, carry = 0;
    int k = num2 - '0';
    char* ret = (char*)malloc(sizeof(char) * (i + 5));
    int len = 0;
    while (i >= 0 || carry != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int result = x * k + carry;
        ret[len++] = '0' + result % 10;
        carry = result / 10;
        i--;
    }
    //flip ret
    for (int i = 0; 2 * i < len; i++) {
        int temp = ret[i];
        ret[i] = ret[len - i - 1]; 
        ret[len - i - 1] = temp;
    }
    ret[len] = '\0';
    return ret;
}

char* add_zero_to_end(char* num, int n) {
    int len = strlen(num);
    char* ret = (char*) malloc(sizeof(char) * (len + n + 5));
    strcpy(ret, num);
    for (int i = 0; i < n; i++) {
        ret[len + i] = '0';
    }
    ret[len + n] = '\0';
    return ret;
}

char* multiply(char* num1, char* num2) {
    if(num1[0] == '0' || num2[0] == '0') return "0";
    int len1 = strlen(num1) - 1, len2 = strlen(num2) - 1, carry = 0;
    char* ret = (char*) malloc(sizeof(char) * 2);
    ret[0] = '0'; ret[1] = 0;

    for(int i = 0; i <= len2; i++) {
        char* temp = single_digit_multiply(num1, num2[len2 - i]);
        char* temp2 = add_zero_to_end(temp, i);
        char* temp3 = addStrings(ret, temp2);
        free(ret);
        free(temp);
        free(temp2);
        ret = temp3;
    }
    
    return ret;
}   
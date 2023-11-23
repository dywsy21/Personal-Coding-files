#include <stdio.h>
#include <math.h>

int myAtoi(char *s) {
    int i = 0, det = 1;  // det=1 for positive, det=0 for negative
    long long ret = 0;

    if (s[i] != '-' && s[i] != '+' && (!(s[i] >= '0' && s[i] <= '9')) && s[i] != ' ')
        return 0;

    if (s[i] >= '0' && s[i] <= '9') {
        int p = i;
        while (s[p + 1] >= '0' && s[p + 1] <= '9')
            p++;

        for (int q = p; q >= i; q--)
            ret += (long long)pow(10, p - q) * (s[q] - '0');

        if (ret >= 2147483647)
            return 2147483647;
        return (int)ret;
    }

    while (s[i] == ' ' || s[i] == '0')
        i++;

    if (s[i] == '-')
        det = 0;

    if (!s[i])
        return 0;

    int j = i;  // s[i+1-->j] is the target number
    while (s[j + 1] >= '0' && s[j + 1] <= '9')
        j++;

    if (j == i) {
        if (s[i] >= '0' && s[i] <= '9')
            return s[i] - '0';
        else
            return 0;
    }

    if (j - i >= 16) {
        if (det == 0)
            return -2147483648;
        if (det == 1)
            return 2147483647;
    }

    for (int k = j; k >= i; k--)
        ret += (long long)pow(10, j - k) * (s[k] - '0');

    if (ret >= 2147483647) {
        if (det == 0 && ret != 2147483647)
            return -2147483648;
        if (det == 0 && ret == 2147483647)
            return -2147483647;
        if (det == 1)
            return 2147483647;
    }

    if (det == 0)
        ret = -ret;

    return (int)ret;
}

int main() {
    char str[] = "  0000000000012345678";
    printf("Output: %d\n", myAtoi(str));  // Expected: 12345678

    return 0;
}

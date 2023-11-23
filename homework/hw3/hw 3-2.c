#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ToBinary(int n, int* len, int** digit) {
    *len = (int)(log2((double)n) + 1);
    *digit = (int*)malloc(*len * sizeof(int));

    for (int i = *len - 1; i >= 0; i--) {
        if (n >= (int)pow(2.0, (double)i)) {
            (*digit)[i] = 1;  
            n -= (int)pow(2.0, (double)i);
        } else {
            (*digit)[i] = 0;  
        }
        printf("%d", (*digit)[i]);  
    }
}

int main() {
    int n;
    printf("Please input the number you wish to convert to a binary number:\n");
    scanf("%d", &n);

    int len;
    int* digits;

    printf("The corresponding binary number is: ");
    ToBinary(n, &len, &digits);
    free(digits);  

    system("pause");
    return 0;
}

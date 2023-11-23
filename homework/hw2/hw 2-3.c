#include <stdio.h>
#include <stdlib.h>
#define min(a, b) ((a) <= (b) ? (a) : (b))

int main() {
    int n;
    printf("Input number n:");
    scanf("%d", &n);
    double a[n + 10];
    printf("\nInput %d real numbers.", n);
    for (int i = 0; i <= n - 1; i++) scanf("%lf", &a[i]);
    double result = 1.0; 
    for (int i = 0; i < n; i++) result = min(result, a[i]);
    printf("\nThe minimum is %.2lf", result);
    system("pause");
    return 0;
}

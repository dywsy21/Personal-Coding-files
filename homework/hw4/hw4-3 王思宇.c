#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x) {
    return exp(x * x);
}

double integral(double a, double b, double err) {
    double LR = b-a;
    double Lresult, Rresult;
    int t = 0;

    do {
        double i=a;
        Lresult=0;
        Rresult=0;

        while (i <= b) {
            Lresult += func(i) * LR;
            Rresult += func(i+LR)*LR;
            i += LR;
        }

        LR /= 10;
        t++;
    } while (abs(Rresult - Lresult) >= err);

    return (Rresult + Lresult) / 2;
}

int main() {
    double A, B, ERR;
    printf("Input the lower limit, upper limit, and the precision of the Integral:\n");
    scanf("%lf%lf%lf", &A, &B, &ERR);
    double res = integral(A, B, ERR);
    printf("The integral of e^(x^2) from %lf to %lf is %lf\n", A, B, res);
    system("pause");
    return 0;
}

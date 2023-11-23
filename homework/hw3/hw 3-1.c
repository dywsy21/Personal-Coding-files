#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

//采用c99编译标准

void SolveQuadraticEquation(double a, double b, double c, int *numSolutions, double _Complex *solution) {
    double delta = b * b - 4 * a * c;
    if (delta > 0) {
        *numSolutions = 2;
        double _Complex* solution = (double _Complex*) malloc(*numSolutions * sizeof(double _Complex));
        solution[0] = (-b - csqrt(delta)) / (2 * a);
        solution[1] = (-b + csqrt(delta)) / (2 * a);
        printf("This equation has 2 real and different roots: %.2f, %.2f\n", creal(solution[0]), creal(solution[1]));
    } else if (delta == 0) {
        *numSolutions = 1;
        double _Complex* solution = (double _Complex*) malloc(*numSolutions * sizeof(double _Complex));
        solution[0] = -b / (2 * a);
        printf("This equation has 1 real root: %.2f\n", creal(solution[0]));
    } else {
        *numSolutions = 2;
        double _Complex* solution = (double _Complex*) malloc(*numSolutions * sizeof(double _Complex));
        double _Complex sqrt_delta = csqrt(delta);
        solution[0] = (-b - sqrt_delta) / (2 * a);
        solution[1] = (-b + sqrt_delta) / (2 * a);
        printf("This equation has 2 complex roots: %.2f - %.2fi, %.2f + %.2fi\n", creal(solution[0]), -cimag(solution[0]), creal(solution[1]), cimag(solution[1]));
    }
}

int main() {
    int numSolutions,n;
    double _Complex *solution;

    double a, b, c;
    printf("Enter coefficients (a, b, c): ");
    scanf("%lf%lf%lf", &a, &b, &c);

    SolveQuadraticEquation(a, b, c, &numSolutions, solution);

    system("pause");
    return 0;
}

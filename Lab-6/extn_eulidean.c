#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int extendedGCD(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = extendedGCD(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int main() {
    int a, b;
    printf("Enter two numbers (a and b): ");
    scanf("%d %d", &a, &b);

    int x, y;
    clock_t start_time = clock();
    int gcd = extendedGCD(a, b, &x, &y);
    clock_t end_time = clock();

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("GCD of %d and %d is %d\n", a, b, gcd);
    printf("Extended Euclidean Algorithm: %d * %d + %d * %d = %d\n", a, x, b, y, gcd);
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}

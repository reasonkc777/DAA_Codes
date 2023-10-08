#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int a; // Coefficient
    int n; // Modulus
} Congruence;

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

int chineseRemainder(Congruence congruences[], int num) {
    int prod = 1;
    for (int i = 0; i < num; i++) {
        prod *= congruences[i].n;
    }

    int result = 0;
    for (int i = 0; i < num; i++) {
        int pp = prod / congruences[i].n;
        result += congruences[i].a * modInverse(pp, congruences[i].n) * pp;
    }

    return result % prod;
}

int main() {
    int num;
    printf("Enter the number of congruences: ");
    scanf("%d", &num);

    Congruence congruences[num];

    for (int i = 0; i < num; i++) {
        printf("Enter coefficient 'a' for congruence %d: ", i + 1);
        scanf("%d", &congruences[i].a);

        printf("Enter modulus 'n' for congruence %d: ", i + 1);
        scanf("%d", &congruences[i].n);
    }

    clock_t start_time = clock();
    int result = chineseRemainder(congruences, num);
    clock_t end_time = clock();

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Solution to the system of congruences is: %d\n", result);
    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define a macro for modular exponentiation
#define MOD_EXP(base, exp, mod) ((int)(((long long)pow_mod(base, exp, mod))))

// Function to calculate (base^exp) % mod
long long pow_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Miller-Rabin primality test
bool millerRabinTest(long long n, int k) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    long long d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 3);
        long long x = MOD_EXP(a, d, n);

        if (x == 1 || x == n - 1) {
            continue;
        }

        bool prime = false;
        for (long long r = 1; r < n - 1; r *= 2) {
            x = MOD_EXP(x, 2, n);
            if (x == n - 1) {
                prime = true;
                break;
            }
        }

        if (!prime) {
            return false;
        }
    }

    return true;
}

int main() {
    long long n;
    int k;

    printf("Enter a number to test for primality: ");
    scanf("%lld", &n);

    printf("Enter the number of iterations (k) for the Miller-Rabin test: ");
    scanf("%d", &k);

    clock_t start_time = clock();
    bool isPrime = millerRabinTest(n, k);
    clock_t end_time = clock();

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    if (isPrime) {
        printf("%lld is probably prime.\n", n);
    } else {
        printf("%lld is composite.\n", n);
    }

    printf("Execution time: %f seconds\n", execution_time);

    return 0;
}

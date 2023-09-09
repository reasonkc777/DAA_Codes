#include <stdio.h>
#include <time.h>

// Function to calculate Fibonacci using memoization
int fibonacci(int n, int memo[]) {
    if (n <= 1) {
        return n;
    }
    
    if (memo[n] != -1) {
        return memo[n]; // Return the precomputed value
    }
    
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo); // Store the result in the memo array
    return memo[n];
}

int main() {
    int n;

    printf("Enter the desired Fibonacci number position: ");
    scanf("%d", &n);
    
    int memo[n + 1]; // Create an array to store computed values
    int i;
    for (i = 0; i <= n; i++) {
        memo[i] = -1; // Initialize all values as not computed
    }

    clock_t start_time = clock();
    int result = fibonacci(n, memo);
    clock_t end_time = clock();

    printf("Fibonacci(%d) = %d\n", n, result);

    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}


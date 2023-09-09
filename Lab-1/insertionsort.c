#include <stdio.h>

int main() {
    int n, i, arr[50], j, temp;

    printf("Enter total number of elements:");
    scanf("%d", &n);

    printf("Enter %d numbers:", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;  

        while ((temp < arr[j]) && (j >= 0)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }

    printf("Final sorted array:");
    for (i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }

    printf("\n");

    return 0;
}

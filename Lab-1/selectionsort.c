#include <stdio.h>

int main() {
    int n, i, arr[50], j, temp,count=0;

    printf("Enter total number of elements:");
    scanf("%d", &n);

    printf("Enter %d numbers:", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
         count++;
        for (j = i + 1; j < n; j++) {
             count++;
            if (arr[i] > arr[j]) {
                count=count+3;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Final sorted array:");
    for (i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }

  

    return 0;
}

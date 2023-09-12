#include <stdio.h>
#include<time.h>

struct MinMax {
    int min;
    int max;
};


struct MinMax findMinMax(int arr[], int start, int end) {
    struct MinMax result;
    
    if (start == end) {
        result.min = result.max = arr[start];
        return result;
    }

    if (end == start + 1) {
        if (arr[start] > arr[end]) {
            result.max = arr[start];
            result.min = arr[end];
        } else {
            result.max = arr[end];
            result.min = arr[start];
        }
        return result;
    }

    int mid = (start + end) / 2;
    struct MinMax leftResult, rightResult;

    leftResult = findMinMax(arr, start, mid);
    rightResult = findMinMax(arr, mid + 1, end);

    if (leftResult.min < rightResult.min) {
        result.min = leftResult.min;
    } else {
        result.min = rightResult.min;
    }

    if (leftResult.max > rightResult.max) {
        result.max = leftResult.max;
    } else {
        result.max = rightResult.max;
    }
    
    return result;
}

int main() {
		clock_t start_time, end_time;
    int arr[] = {2, 5, 1, 8, 9, 3, 11,15};
    start_time = clock();
    int n = sizeof(arr) / sizeof(arr[0]);
    struct MinMax result;

    result = findMinMax(arr, 0, n - 1);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);
    end_time = clock(); 
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("\nElapsed time: %.20f seconds\n", elapsed_time);
    return 0;
}




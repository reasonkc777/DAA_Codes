#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


int randomPartition(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low + 1);
    swap(arr, random, high);
    
    int pivot = arr[high];
    int i = low - 1;
    int j; 

    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return (i + 1);
}


void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);

        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 8, 63, 5, 56, 7,99};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int i;
    clock_t start_time, end_time;

    printf("Given array is \n");
    for ( i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    start_time=clock();
    randomizedQuickSort(arr, 0, arr_size - 1);

    printf("Sorted array is \n");
    for ( i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
        printf("\n");
    end_time = clock(); 
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("\nElapsed time: %.20f seconds\n", elapsed_time);

    return 0;
}


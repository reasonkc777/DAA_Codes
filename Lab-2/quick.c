 #include <stdio.h>
#include<time.h>


void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}


int partition(int arr[], int low, int high) {
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


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {1, 11, 13, 5, 7, 8,99 };
    int i;
    clock_t start_time, end_time;
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    for ( i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    start_time=clock();
    quickSort(arr, 0, arr_size - 1);

    printf("Sorted array is \n");
    for ( i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    end_time = clock(); 
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("\nElapsed time: %.20f seconds\n", elapsed_time);

    return 0;
}
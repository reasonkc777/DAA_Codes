#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Function to partition the array and place the pivot element at its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = low - 1; // Initialize the index of the smaller element
    int j; // Declare j outside the loop

    for (j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment the index of the smaller element
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

// Function to find the k-th smallest element in the array
int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pi = partition(arr, low, high);

        // If the pivot element is the k-th smallest element
        if (pi - low == k - 1)
            return arr[pi];

        // If the k-th smallest element is in the left subarray
        if (pi - low > k - 1)
            return kthSmallest(arr, low, pi - 1, k);

        // If the k-th smallest element is in the right subarray
        return kthSmallest(arr, pi + 1, high, k - pi + low - 1);
    }

    // If k is out of range
    return -1;
}

int main() {
    int arr[] = {1 ,11, 3, 5, 63, 7,99};
    int i;
    clock_t start_time, end_time;
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int k = 4; // Find the 3rd smallest element

    printf("Given array is \n");
    for ( i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    start_time=clock();
    int result = kthSmallest(arr, 0, arr_size - 1, k);

    if (result != -1)
        printf("The %dth smallest element is %d\n", k, result);
    else
        printf("Invalid k value\n");
    end_time = clock(); 
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("\nElapsed time: %.20f seconds\n", elapsed_time);

    return 0;
}



#include<stdio.h>
#include<time.h>


int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

	
		if (arr[mid] == x)
			return mid;

	
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);


		return binarySearch(arr, mid + 1, r, x);
	}


	return -1;
}


int main()
{
	int arr[] = { 2, 3, 4, 5, 6 };
	clock_t start_time, end_time;
	int x = 6;
   	start_time=clock();
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	if(result==-1){
	
	
		 printf("Element is not present in array");}
	else{
		 
	printf("Element is present at index %d ", result);
	end_time = clock(); 
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("\nElapsed time: %.20f seconds\n", elapsed_time);
	}return 0;
}


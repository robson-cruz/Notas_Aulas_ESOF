#include <stdio.h>


/*** C program to implement Interpolation Search ***/

// Function prototype
int interpolation_serach(int arr[], int value, int start, int end);


// Main function
int main(void) {
  	int vector [] = {1, 15, 19, 22, 26, 32, 46, 55, 67, 81};
	int value;
	int start = 0;
	int end = sizeof(vector) / sizeof(vector[0]);
	
	printf("\nInforme um numero inteiro: ");
	scanf("%d", &value);
	printf("\n%d\n\n", interpolation_serach(vector, value, start, end));
	
	return 0;
}


// Interpolation Search function
// If the searched value is in the array,
// then it returns the index of this value in the array,
// otherwise returns -1.
int interpolation_serach(int arr[], int value, int start, int end) {
	int index;
	
	if (start <= end && value >= arr[start] && value <= arr[end]) {
		index = start + ((double)(end - start) / (arr[end] - arr[start])) * (value - arr[start]);

		if (arr[index] == value) {
			return index;
		}

		else if (arr[index] < value) {
			return interpolation_serach(arr, value, index + 1, end);
		}
		else {
			return interpolation_serach(arr, value, start, index - 1);
		}
	} else {
		return -1;
	}
}
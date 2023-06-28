#include <stdio.h>


// Function prototype
int binary_search(int vector[], int value, int start, int end);


// Main function
int main(void) {
  	int vector [] = {1, 15, 19, 22, 26, 32, 46, 55, 67, 81};
	int start = 0;
	int end = sizeof(vector) / sizeof(int);
	int value;
	
	printf("\nInforme um numero inteiro: ");
	scanf("%d", &value);
	
	printf("\n%d\n\n", binary_search(vector, value, start, end));
	
  	return 0;
}

// Binary Search
int binary_search(int vector[], int value, int start, int end) {
	// checks if start is less than or equal to end.
	if (start <= end) {
		// If it is, it calculates the middle index as the average of start and end.
		int middle = (end + start) / 2;
		// If the value at the middle index of the vector is equal to the search value,
		// it returns the middle index.
		if (vector[middle] == value) {
			return middle;
		}
		// If the search value is less than the value at the middle index,
		// the binary_search function is called again with start and middle-1
		// as the new start and end values, respectively.
		else if (value < vector[middle]) {
			return binary_search(vector, value, start, middle-1);
		} else {
			// If the search value is greater than the value at the middle index,
			// the binary_search function is called again with middle+1 and end
			// as the new start and end values, respectively.
			return binary_search(vector, value, middle+1, end);
		}
	// If the start becomes greater than end,
	// it means the search value was not found in the vector,
	// so -1 is returned.
	} else {
		return -1;
	}
}

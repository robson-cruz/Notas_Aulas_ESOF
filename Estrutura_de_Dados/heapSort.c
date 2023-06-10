#include <stdio.h>

int change(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int heapfy(int vector[], int size_vector, int i) {
		int left, right, count, largest;
		count = 1;
		left = 2 * i + 1;
		right = 2 * i + 2;
		
		if (left < size_vector && vector[left] > vector[i]) {
			largest = left;
		}
		else {
			largest = i;
		}
		if (right < size_vector && vector[i] > vector[largest]) {
			largest = right;
		}
		if (largest != i) {
			change(&vector[i], &vector[largest]);
			count += heapfy(vector, size_vector, largest);
		}
		return count;
}


int buildHeap(int vector[], int size_vector) {
	int i, count;
	count = 0;
	
	for (i = size_vector/2; i > 0; i--) {
		count += heapfy(vector, size_vector, i);
	}
	return count;
}


int heapSort(int vector[], int size_vector) {
	int n, i, count;
	count = 0;
	count += buildHeap(vector, size_vector);
	n = size_vector;
	
	for (i = size_vector - 1; i > 0; i--) {
		change(&vector[0], &vector[i]);
		n--;
		count += heapfy(vector, n, 0);
	}
	return count;
}

int main(void) {
	int array [] = {80, 75, 60, 70, 66, 65, 55, 50, 42, 39, 13};
	printf("%d\n\n", heapSort(array, sizeof(array)/sizeof(int)));
	
	return 0;
}

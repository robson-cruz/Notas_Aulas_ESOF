#include <stdio.h>


/*** SelectionSort ***/
void selectionSort(int array[], int length) {
	int i, j, aux, count = 0;

	printf("Vetor de entrada\n");
	for (i = 0; i < length; i++) {
		printf("%02d ", array[i]);
	}
	
	for (i = 0; i < length-1; i++) {
		int min = i;
		
		for (j = i + 1; j < length; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		if (i != min) {
			aux = array[i];
			array[i] = array[min];
			array[min] = aux;
			count ++;
		}
	}

	printf("\n\nVetor ordenado com %d interações\n", count);
	for (i = 0; i < length; i++) {
		printf("%02d ", array[i]);
	}
	
}


int main(void) {
	int vector[] = {26, 32, 46, 19, 15, 67, 81, 22, 55, 1};
	int size_vector = sizeof(vector)/sizeof(int);

	selectionSort(vector, size_vector);
	
	return 0;
}
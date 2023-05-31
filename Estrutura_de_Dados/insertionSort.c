#include <stdio.h>


void insertionSort(int array[], int length) {
	int i, j, count = 0;
		
	printf("Vetor de entrada\n");
	for (i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}

	for (i = 1; i < length; i++) {
		int aux = array[i];
		j = i-1;

		while (j >= 0 && (array[j] > aux)) {
			array[j+1] = array[j];
			j--;
			count++;
		}
		array[j + 1] = aux;
	}

	printf("\n\nVetor Ordenado com %d interações\n", count);
	for (i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	
}

int main(void) {
	int vector[] = {26, 32, 46, 19, 15, 67, 81, 22};
	int size_vector = sizeof(vector)/sizeof(int);
	
	insertionSort(vector, size_vector);
}
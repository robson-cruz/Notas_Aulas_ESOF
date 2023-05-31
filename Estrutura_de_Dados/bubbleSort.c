#include <stdio.h>

/*** BubbleSort ***/
void bubbleSort(int array[], int length) {
	int i, j, aux, count = 0;
	
	printf("Vetor de entrada\n");
	for (i = 0; i < length; i++) {
		printf("%02d ", array[i]);
	}

	for (i = 0; i < length-1; i++) {
		for (j = i+1; j < length; j++) {
			if (array[i] > array[j]) {
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				count ++;
			}
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

	bubbleSort(vector, size_vector);
	
	return 0;
}
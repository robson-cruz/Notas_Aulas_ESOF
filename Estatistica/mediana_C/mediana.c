#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "mediana.h"


float mediana(float array[], int size) {
	
	float med, tmp;
	int after, before, i, j;
	int middle = size / 2;
	
	// Ordenação do vetor de dados
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (array[j] < array[i]) {
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
	for (i = 0; i < size; i++) {
		printf("a[%d] = %4.1f\n", i, array[i]);
	}
	// Calculo da mediana
	if (size % 2 == 0) {
		after = array[middle - 1];
		before = array[middle];
		med = (after + before) / 2;
	} else {
		med = array[middle];
	}
	
	setlocale(LC_ALL, "Portuguese");
	
	return med;
}

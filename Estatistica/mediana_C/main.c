#include <stdio.h>
#include <stdlib.h>
#include "mediana.h"


float mediana(float array[], int size);


int main(int argc, char *argv[]) {
	
	//float a[] = {10, 3, 4, 8, 9, 2}; // 6.0
	//float a[] = {6.0, 4.5, 5.0, 7.0, 6.5}; // 6.0
	float a[] = {3, 7, 9, 10, 4, 8, 2}; // 7
	
	int size_vector = sizeof(a) / sizeof(int);
	
	printf("\nA mediana eh: %.2f", mediana(a, size_vector));
	
	return 0;
}

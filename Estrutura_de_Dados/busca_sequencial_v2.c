#include <stdio.h>
#include <locale.h>


/*** Busca Sequencial ***/


// Prototipa��o de fun��o buscaSequencial
int buscaSequencial(int arr[], int size, int arg);

// Fun��o Principal
int main(void) {
	int vector[] = {26, 32, 46, 19, 15, 67, 81, 22, 55, 1};

	int value;
	
	
	setlocale(LC_ALL, "");
	printf("Digite um n�mero para buscar seu �ndice no vetor: \n->>> ");
	scanf("%d", &value);

	int size = sizeof(vector) / sizeof(vector[0]);
	
	int result = buscaSequencial(vector, size, value);
	
	if (result < 0) {
		printf("\nElemento %d n�o faz parte do vetor.\n", value);
	} else {
		printf("\nElemento %d encontrado no indice %d\n", value, result);
	}
	
	return 0;
}

// Implementa��o da fun��o buscaSequencial
int buscaSequencial(int arr[], int size, int arg) {
	int i;
	
	for (i = 0; i < size; i++) {
		if (arr[i] == arg) {
			return i;
		}
	}
	return -1;
}

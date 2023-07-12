#include <stdio.h>
#include <locale.h>
#define SIZE 6

/***
7 - Fa�a um programa que receba 6 numeros inteiros e mostre:
-->>> Os numeros pares digitados;
-->>> A soma dos numeros pares digitados;
-->>> Os numeros �mpares digitados;
-->>> A quantidade de numeros impares digitados;
***/

// Vari�vel Global
int i;

// Prototipa��o de fun��o
void inputData(int vetor[SIZE]);
void limparTela();
void imprimirVetor(int vetor[SIZE]);
void checaNum(int vetor[SIZE]);

// Fun��o Principal
int main(void) {
	int vetor[SIZE];
	
	setlocale(LC_ALL, "");
	
	inputData(vetor);
	limparTela();
	imprimirVetor(vetor);
	checaNum(vetor);
	
	return 0;
}

// Implementa��o da fun��o
void inputData(int vetor[SIZE]) {
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("informe o valor para o �ndice %d: ", i+1);
		scanf("%d", &vetor[i]);
	}
}

void imprimirVetor(int vetor[SIZE]) {
	printf("\nVetor: [ ");
	for (i = 0; i < SIZE; i++) {
		printf("%d ", vetor[i]);
	}
	printf("]\n");
}

void limparTela() {
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

void checaNum(int vector[SIZE]) {
	int numPares[SIZE];
	int numImpares[SIZE];
	int somaPares = 0;
	int somaImpares = 0;
	int countPares = 0;
	int countImpares = 0;
	
	for (i = 0; i < SIZE; i++) {
		if (vector[i] % 2 == 0) {
			numPares[countPares] = vector[i];
			somaPares += vector[i];
			countPares ++;
		} else {
			numImpares[countImpares] = vector[i];
			somaImpares += vector[i];
			countImpares ++;
		}
	}
	
	printf("\nN�meros pares digitados: [ ");
	for (i = 0; i < countPares; i++) {
		printf("%d ", numPares[i]);
	}
	printf("]\n");
	
	printf("Soma dos n�meros pares digitados: %d\n", somaPares);
	
	printf("\nN�meros �mpares digitados: [ ");
    	for (i = 0; i < countImpares; i++) {
    		printf("%d ", numImpares[i]);
    	}
	printf("]\n");

	printf("Quantidade de n�meros �mpares digitados: %d\n", countImpares);
}

#include <stdio.h>
#include <locale.h>
#define SIZE 10

/***
6 - Fa�a um programa que preencha um vetor com 10 n�meros reais, calcule e mostre
a quantidade de n�meros negativos e a soma dos n�meros positivos desse vetor.
***/


// Prototipa��o de fun��o
void inputData(float vetor[SIZE]);
void limparTela();
void imprimirVetor(float vetor[SIZE]);
void contaNegativos_somaPositivos(float vetor[SIZE]);

// Fun��o Principal
int main(void) {
	float vetor[SIZE];
	
	setlocale(LC_ALL, "");
	
	inputData(vetor);
	limparTela();
	imprimirVetor(vetor);
	contaNegativos_somaPositivos(vetor);
	
	return 0;
}

// Implementa��o da fun��o
void inputData(float vetor[SIZE]) {
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("informe o valor para o �ndice %d: ", i+1);
		scanf("%f", &vetor[i]);
	}
}

void contaNegativos_somaPositivos(float vector[SIZE]) {
	int i;
	float somaPositivos = 0;
	int neg = 0;
	for (i = 0; i < SIZE; i++) {
		if (vector[i] < 0) {
			neg ++;
		} else {
			somaPositivos += vector[i];
		}
	}
	printf("\nO vetor possui %d valore(s) negativo(s)\n", neg);
	printf("O vetor soma %.2f valore(s) positivo(s)\n", somaPositivos);
}

void imprimirVetor(float vetor[SIZE]) {
	int i;
	printf("\nVetor: [ ");
	for (i = 0; i < SIZE; i++) {
		printf("%.1f ", vetor[i]);
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

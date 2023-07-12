#include <stdio.h>
#include <locale.h>
#define SIZE 10

/***
4. Escreva um programa que leia 10 n�meros inteiros e os armazene em um vetor.
Imprima o vetor, o maior elemento e a posi��o que ele se encontra.
***/
// Vari�veis Globais
int i, vetor[SIZE];
int maior = 0;
int indice;

// prototipa��o de fun��es
void inputData(int vetor[SIZE]);
void imprimirVetor(int vetor[SIZE]);
void maiorValor(int vetor[SIZE]);
void limparTela();

// Fun��o Principal
int main(void) {
	setlocale(LC_ALL, "");
	
	inputData(vetor);
	limparTela();
	imprimirVetor(vetor);
	maiorValor(vetor);
	
	return 0;
}

// Implementa��o de fun��oes
void inputData(int vetor[SIZE]) {
	for (i = 0; i < SIZE; i++) {
		printf("informe o valor do �ndice %d: ", i+1);
		scanf("%d", &vetor[i]);
		
		if (vetor[i] > maior) {
			maior = vetor[i];
			indice = i;
		}
	}
}

void maiorValor(int vetor[SIZE]) {
	for (i = 0; i < SIZE; i++) {
		if (vetor[i] > maior) {
			maior = vetor[i];
			indice = i;
		}
	}
	printf("\nO maior valor do vetor � %d ", maior);
	printf("\nO indice do maior valor � %d \n", indice);
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

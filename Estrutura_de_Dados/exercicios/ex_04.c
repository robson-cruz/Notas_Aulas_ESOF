#include <stdio.h>
#include <locale.h>
#define SIZE 10

/***
4. Escreva um programa que leia 10 números inteiros e os armazene em um vetor.
Imprima o vetor, o maior elemento e a posição que ele se encontra.
***/
// Variáveis Globais
int i, vetor[SIZE];
int maior = 0;
int indice;

// prototipação de funções
void inputData(int vetor[SIZE]);
void imprimirVetor(int vetor[SIZE]);
void maiorValor(int vetor[SIZE]);
void limparTela();

// Função Principal
int main(void) {
	setlocale(LC_ALL, "");
	
	inputData(vetor);
	limparTela();
	imprimirVetor(vetor);
	maiorValor(vetor);
	
	return 0;
}

// Implementação de funçãoes
void inputData(int vetor[SIZE]) {
	for (i = 0; i < SIZE; i++) {
		printf("informe o valor do índice %d: ", i+1);
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
	printf("\nO maior valor do vetor é %d ", maior);
	printf("\nO indice do maior valor é %d \n", indice);
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

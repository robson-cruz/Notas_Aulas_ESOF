#include <stdio.h>
#include <locale.h>
#define SIZE 5

/***
5 - Fa�a um programa para ler a nota da prova de 15 alunos e armazene num vetor,
calcule e imprima a m�dia geral.
***/

// Vari�veis Globais
int i;

// prototipa��o de fun��es
void inputData(float vetor[SIZE]);
void imprimirVetor(float vetor[SIZE]);
void calcMedia(float vetor[SIZE]);
void limparTela();

// Fun��o Principal
int main(void) {
	setlocale(LC_ALL, "");
	float vetor[SIZE];
	
	inputData(vetor);
	limparTela();
	imprimirVetor(vetor);
	calcMedia(vetor);
	
	return 0;
}

// Implementa��o de fun��oes
void inputData(float vetor[SIZE]) {
	for (i = 0; i < SIZE; i++) {
		printf("informe a nota %d: ", i+1);
		scanf("%f", &vetor[i]);
	}
}

void calcMedia(float vetor[SIZE]) {
	float media;
	float soma = 0;
	
	for (i = 0; i < SIZE; i++) {
		soma += vetor[i];
	}
	media = soma / SIZE;
	
	printf("\nA m�dia das notas � %.1f \n", media);
}

void imprimirVetor(float vetor[SIZE]) {
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

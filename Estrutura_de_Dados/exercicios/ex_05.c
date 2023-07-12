#include <stdio.h>
#include <locale.h>
#define SIZE 5

/***
5 - Faça um programa para ler a nota da prova de 15 alunos e armazene num vetor,
calcule e imprima a média geral.
***/

// Variáveis Globais
int i;

// prototipação de funções
void inputData(float vetor[SIZE]);
void imprimirVetor(float vetor[SIZE]);
void calcMedia(float vetor[SIZE]);
void limparTela();

// Função Principal
int main(void) {
	setlocale(LC_ALL, "");
	float vetor[SIZE];
	
	inputData(vetor);
	limparTela();
	imprimirVetor(vetor);
	calcMedia(vetor);
	
	return 0;
}

// Implementação de funçãoes
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
	
	printf("\nA média das notas é %.1f \n", media);
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

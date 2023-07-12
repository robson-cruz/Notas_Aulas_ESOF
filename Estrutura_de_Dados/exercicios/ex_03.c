#include <stdio.h>
#include <locale.h>
#define SIZE 10
/*
3 - Fa�a um programa que receba do usu�rio um vetor com 10 posi��es. 
Em seguida dever� ser impresso o maior e o menor elemento do vetor.
*/

// Vari�veis Globais
int i, vetor[SIZE];
int menor = 0;
int maior = 0;

// prototipa��o de fun��es
void maiorMenor(int vetor[SIZE]);
void imprimirVetor(int vetor[SIZE]);
void limparTela();

// Fun��o Principal
int main(void) {
	setlocale(LC_ALL, "");
	
	maiorMenor(vetor);
	limparTela();
	imprimirVetor(vetor);
	
	return 0;
}

// Implementa��o de fun��oes
void maiorMenor(int vetor[SIZE]) {
	for (i = 0; i < SIZE; i++) {
		printf("informe o valor do �ndice %d: ", i+1);
		scanf("%d", &vetor[i]);
		
		if (vetor[i] > maior) {
			maior = vetor[i];
		} else if (vetor[i] < menor) {
			menor = vetor[i];
		}
	}
}

void imprimirVetor(int vetor[SIZE]) {
	printf("\nVetor: [ ");
	for (i = 0; i < SIZE; i++) {
		printf("%d ", vetor[i]);
	}
	printf("]\n");
	
	printf("\nMaior valor %d", maior);
	printf("\nMenor valor %d\n\n",  menor);
}

void limparTela() {
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
}

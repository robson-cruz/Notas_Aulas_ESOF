#include <stdio.h>
#include <locale.h>
#define SIZE 8

/***
Fa�a um programa que leia um vetor de 8 posi��es e, em seguida, leia tamb�m
dois valores X e Y quaisquer correspondentes a duas posi��es no vetor.
Ao final seu programa devera escrever a soma dos valores encontrados nas
respectivas posi��es X e Y.
***/

// Vari�veis Globais
int x, y, soma;

// Prototipa��o de fun��o
int somaValores(int vetor[SIZE], int x, int y);

int main(void) {
	int vetor[SIZE] = {46, 19, 15, 67, 81, 22, 55, 1};
	
	setlocale(LC_ALL, "");
	
	printf("Informe o primeiro indice do vetor, entre 0 e 7: ");
	scanf("%d", &x);
	printf("\nInforme o segundo indice do vetor, entre 0 e 7: ");
	scanf("%d", &y);
	
	int s = somaValores(vetor, x, y);
	printf("\n\nA soma entre os elementos ocupados pelos indices �: %d\n", soma);
	
	return ;
}

// Implementa��o da fun��o
int somaValores(int vector[SIZE], int x, int y) {
	soma = 0;
	if (vector[x] && vector[y]) {
		soma = vector[x] + vector[y];
	}
	
	return soma;
}

#include <stdio.h>
#include <locale.h>
#define SIZE 8

/***
Faça um programa que leia um vetor de 8 posições e, em seguida, leia também
dois valores X e Y quaisquer correspondentes a duas posições no vetor.
Ao final seu programa devera escrever a soma dos valores encontrados nas
respectivas posições X e Y.
***/

// Variáveis Globais
int x, y, soma;

// Prototipação de função
int somaValores(int vetor[SIZE], int x, int y);

int main(void) {
	int vetor[SIZE] = {46, 19, 15, 67, 81, 22, 55, 1};
	
	setlocale(LC_ALL, "");
	
	printf("Informe o primeiro indice do vetor, entre 0 e 7: ");
	scanf("%d", &x);
	printf("\nInforme o segundo indice do vetor, entre 0 e 7: ");
	scanf("%d", &y);
	
	int s = somaValores(vetor, x, y);
	printf("\n\nA soma entre os elementos ocupados pelos indices é: %d\n", soma);
	
	return ;
}

// Implementação da função
int somaValores(int vector[SIZE], int x, int y) {
	soma = 0;
	if (vector[x] && vector[y]) {
		soma = vector[x] + vector[y];
	}
	
	return soma;
}

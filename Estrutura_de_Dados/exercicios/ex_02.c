#include <stdio.h>
#include <locale.h>
#define SIZE 10

/***
Ler um vetor de 10 posições. Contar e escrever quantos valores positivos e
negativos ele possui.
***/


// Prototipação de função
void contaValores(int vetor[SIZE]);

int main(void) {
	int vetor[SIZE] = {-46, 19, -15, 67, 81, 22, 55, 1, 9, 3};
	
	setlocale(LC_ALL, "");
	
	contaValores(vetor);
	
	return 0;
}

// Implementação da função
void contaValores(int vector[SIZE]) {
	int i;
	int pos = 0;
	int neg = 0;
	for (i = 0; i < SIZE; i++) {
		if (vector[i] < 0) {
			neg ++;
		} else {
			pos ++;
		}
	}
	printf("O vetor possui %d valore(s) positivo(s) e %d negativo(s)\n", pos, neg);
}

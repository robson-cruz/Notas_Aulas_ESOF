#include <stdio.h>
#include <locale.h>
#define SIZE 6

/***
7 - Faça um programa que receba 6 numeros inteiros e mostre:
-->>> Os numeros pares digitados;
-->>> A soma dos numeros pares digitados;
-->>> Os numeros ímpares digitados;
-->>> A quantidade de numeros impares digitados;
***/

// Variável Global
int i;

// Prototipação de função
void inputData(int vetor[SIZE]);
void limparTela();
void imprimirVetor(int vetor[SIZE]);
void checaNum(int vetor[SIZE]);

// Função Principal
int main(void) {
	int vetor[SIZE];
	
	setlocale(LC_ALL, "");
	
	inputData(vetor);
	limparTela();
	imprimirVetor(vetor);
	checaNum(vetor);
	
	return 0;
}

// Implementação da função
void inputData(int vetor[SIZE]) {
	int i;
	for (i = 0; i < SIZE; i++) {
		printf("informe o valor para o índice %d: ", i+1);
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
	
	printf("\nNúmeros pares digitados: [ ");
	for (i = 0; i < countPares; i++) {
		printf("%d ", numPares[i]);
	}
	printf("]\n");
	
	printf("Soma dos números pares digitados: %d\n", somaPares);
	
	printf("\nNúmeros ímpares digitados: [ ");
    	for (i = 0; i < countImpares; i++) {
    		printf("%d ", numImpares[i]);
    	}
	printf("]\n");

	printf("Quantidade de números ímpares digitados: %d\n", countImpares);
}

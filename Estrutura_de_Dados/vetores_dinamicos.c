#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


int main(void) {
/***
Crie um programa que leia uma vari�vel e crie dois vetores din�micos, um com
o tamanho lido e outro com o dobro desse tamanho. Preencha esses vetores
respectivamente com pot�ncias de 2 e pot�ncias de 3.
a) Crie uma vari�vel inteira e dois ponteiros do tipo inteiro.
b) Pergunte ao usu�rio o tamanho do vetor din�mico e leia esse valor na vari�vel inteira.
c) Aloque dinamicamente os dois vetores usando a fun��o malloc.
d) Fa�a um la�o de repeti��o para preencher o primeiro vetor com pot�ncias de 2.
e) Fa�a um segundo la�o de repeti��o para preencher o outro vetor com pot�ncias de 3.
f ) N�o se esque�a de usar a biblioteca math.h para poder usar o c�lculo de
pot�ncia (pow).
**/
	int size, *ptr1, *ptr2;
	
	setlocale(LC_ALL, "Portuguese");
	printf("Idique o tamanho do primeiro vetor din�mico: ");
	scanf("%d", &size);
	
	// Aloca��o dos ponteiros
	ptr1 = (int *) malloc(size * sizeof(int));
	ptr2 = (int *) malloc(2 * size * sizeof(int));
	
	int i = 0;
	
	printf("\n\n");
	// Preenchendo o primeiro vetor com pot�ncias de 2
	for (i = 0; i < size; i++) {
		ptr1[i] = pow(2, i);
		printf("ptr1[%d] = %d\n", i, ptr1[i]);
	}
	printf("\n\n");
	// Preenchendo o primeiro vetor com pot�ncias de 3
	for (i = 0; i < size*2; i++) {
		ptr2[i] = pow(3, i);
		printf("ptr2[%d] = %d\n", i, ptr2[i]);
	}
	
	// Liberando a mem�ria alocada
	free(ptr1);
	free(ptr2);
	
	return 0;
}


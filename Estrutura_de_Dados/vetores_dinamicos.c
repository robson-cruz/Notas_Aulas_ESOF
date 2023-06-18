#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


int main(void) {
/***
Crie um programa que leia uma variável e crie dois vetores dinâmicos, um com
o tamanho lido e outro com o dobro desse tamanho. Preencha esses vetores
respectivamente com potências de 2 e potências de 3.
a) Crie uma variável inteira e dois ponteiros do tipo inteiro.
b) Pergunte ao usuário o tamanho do vetor dinâmico e leia esse valor na variável inteira.
c) Aloque dinamicamente os dois vetores usando a função malloc.
d) Faça um laço de repetição para preencher o primeiro vetor com potências de 2.
e) Faça um segundo laço de repetição para preencher o outro vetor com potências de 3.
f ) Não se esqueça de usar a biblioteca math.h para poder usar o cálculo de
potência (pow).
**/
	int size, *ptr1, *ptr2;
	
	setlocale(LC_ALL, "Portuguese");
	printf("Idique o tamanho do primeiro vetor dinâmico: ");
	scanf("%d", &size);
	
	// Alocação dos ponteiros
	ptr1 = (int *) malloc(size * sizeof(int));
	ptr2 = (int *) malloc(2 * size * sizeof(int));
	
	int i = 0;
	
	printf("\n\n");
	// Preenchendo o primeiro vetor com potências de 2
	for (i = 0; i < size; i++) {
		ptr1[i] = pow(2, i);
		printf("ptr1[%d] = %d\n", i, ptr1[i]);
	}
	printf("\n\n");
	// Preenchendo o primeiro vetor com potências de 3
	for (i = 0; i < size*2; i++) {
		ptr2[i] = pow(3, i);
		printf("ptr2[%d] = %d\n", i, ptr2[i]);
	}
	
	// Liberando a memória alocada
	free(ptr1);
	free(ptr2);
	
	return 0;
}


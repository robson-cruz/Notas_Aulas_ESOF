#include <stdio.h>
#include <locale.h>


void main () {
	
	int v1, v2;
	
	printf("<<< EX013 - Operadores Biwise >>>\n\n");
	printf("Digite o Primeiro Valor: ");
	scanf("%d", &v1);
	printf("\nDigite o Segundo Valor: ");
	scanf("%d", &v2);
	
	setlocale(LC_ALL, "Portuguese");
	printf("\n\n------ OPERAÇÕES BITWISE ------\n");
	printf("Calculando %d \& %d é igual a %d\n", v1, v2, (v1 & v2));
	printf("Calculando %d \| %d é igual a %d\n", v1, v2, (v1 | v2));
	printf("Calculando %d \^ %d é igual a %d\n", v1, v2, (v1 ^ v2));
}

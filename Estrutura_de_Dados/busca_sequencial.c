#include <stdio.h>
#include <locale.h>


/*** Busca Sequencial ***/
int main(void) {
	int vector[] = {26, 32, 46, 19, 15, 67, 81, 22, 55 , 1};

	int i, value;
	int vectorSize = sizeof(vector) / sizeof(vector[0]);
	
	setlocale(LC_ALL, "");
	printf("Digite um número para buscar seu indice no vator: \n->>> ");
	scanf("%d", &value);
	
	for (i = 0; i < vectorSize; i++) {
		if (vector[i] == value) {
			printf("Elemento %d encontrado no indice %d\n", value, i);
			break;
		}
	}
	if (i == vectorSize) {
		printf("Elemento não faz parte do vetor.");
	}
	
  	return 0;
}
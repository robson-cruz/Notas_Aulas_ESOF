#include <stdio.h>


/**
   Ponteiro como parâmetro de função
**/
void imprimir(int *num) {
	printf("%d\n", *num);
	*num = 8;
}

int main(void) {

	int id = 10;

	/* A função irá imprimir 10, pois a função recebe como parâmetro o
	endereço da variável id
	*/
	imprimir(&id);

	/* Aqui será impresso 8, após a chamada da função o valor d oponteiro num
	passa a receber o valor 8, como agora o ponteriro aponta para o endereço de id esta
	variável recebe o valor 8
	*/
	printf("Valor de num no main: %d", id);
	
	return 0;
}
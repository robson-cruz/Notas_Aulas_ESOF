#include <stdio.h>
#include <stdlib.h>


int main(void) {

	// Inicia uma variável do tipo inteiro
	int x;
	
	/* 
 	Inicia um ponteiro do tipo inteiro.
	Ponteiros sempre apontam para um endereço na memória.
 	Aqui o compilador irá apontar para um endereço inválido
    de memória até reservarmos um endereço válido.
 	*/
	int *ptr;
	printf("Endereço de ptr: %p\n", ptr);
	
	/* Através da função malloc, reservamos dinamicamente um espaço na memória para
	o ponteiro. Através do cast (int *) nos certificamos de que o retorno
	da função malloc seja um valor compatível com int.
	*/
	ptr = (int *) malloc(sizeof(int));

	// Testa se houve sucesso na alocação de memória para o ponteriro
	if (ptr) {
		printf("Alocação de memória efetuada no endereço: %p.\nValor de *ptr: %d\n\n", ptr, *ptr);
		/* A saída acima mostra um valor para o ponteiro, isso ocorre devido 
		o compilador buscar um bloco de 4 bytes disponível na memória do
	 	'do cumputador e atribuir seu endereço ao ponteiro, no entanto,
	  	os bytes do bloco já possuíam valores, pois a memória do computador
	   	só é zerada quando é desligado ou sua fonte de alimentação interrompida,
		ou por um comando específico do sistema operacional. As variáveis são criadas
	 	e destruídas na memória, mas os valores dos bits continuam inalterados.
	  	Para evitar que isso ocorra, sempre deve ser inicializado o valor de um
	   	ponteiro definido dinamicamente, o que poderia ser feito após o suso da função malloc.
	  	*/
	} else {
			fprintf(stderr, "Erro: Falha na alocação de memória.\n");
	}
	
	// Liberação da memória alocada dinamicamente
	free(ptr);
	
	return 0;
}
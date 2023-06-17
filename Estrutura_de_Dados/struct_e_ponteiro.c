#include <stdio.h>
#include <stdlib.h>

/***
Uma famosa f�brica de sem�foros est� testando um novo prot�tipo, menor,
mais barato e eficiente. Foi solicitado � equipe de TI um programa em linguagem
C para fazer o teste do novo hardware. O sem�foro tem tr�s objetos, cada
um cont�m um atributo cor e outro id. Devido �s limita��es de mem�ria e processamento,
� necess�ria a cria��o de um ponteiro que vai percorrendo a mem�ria
e imprimindo o valor na tela.
a) Crie uma estrutura que tenha dois atributos: cor (cadeia de caracteres) e id
(inteiro).
b) Crie tr�s vari�veis com o tipo definido no item a.
c) Crie um ponteiro do mesmo tipo.
d) Inicialize as estruturas da seguinte forma:
	� cor vermelha, id 1.
	� cor amarela, id 2.
	� cor verde, id 3.
e) Inicialize o ponteiro apontando para a primeira vari�vel criada.
f ) Por meio de opera��es aritm�ticas com ponteiros, percorra a mem�ria e imprima
o valor de cada uma das vari�veis criadas nesse programa.
***/
typedef struct {
	char cor[10];
	int id;
} semaforo;
	
	
semaforo s1 = {"vermelho", 1};
semaforo s2 = {"amarelo", 2};
semaforo s3 = {"verde", 3};
semaforo *ptr;

int main() {
	
	ptr = &s1;
	
	printf("Id %d: %s\n", (*ptr).id, (*ptr).cor);
	ptr = ptr + 1; //ptr = &s1 + 1;
	printf("Id %d: %s\n", (*ptr).id, (*ptr).cor);
	ptr = ptr + 1; //ptr = &s1 + 2;
	printf("Id %d: %s\n", (*ptr).id, (*ptr).cor);
	
	/*
	int i;
	for (i = 0; i < 3; i++) {
		printf("Id %d: %s\n", ptr->id, ptr->cor);
		ptr++;
	}
	*/
	return 0;

}

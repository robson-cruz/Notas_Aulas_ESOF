#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


// Constantes
#define E 0
#define D 1
#define R -1

// Estrutura do nó
typedef struct NO {
	int dado;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
} NO;


// Estrutura árvore
typedef struct ARVORE {
	NO *raiz;
} ARVORE;

// Declarar a árvore
ARVORE a;

// Prototipação de funções
void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val);
void insereNoArvoreOrdenada(int valor);
void preOrdem(NO* raiz);
void emOrdem(NO* raiz);
void posOrdem(NO* raiz);



// Função principal
int main (void) {
	setlocale(LC_ALL, "Portuguese");
	inicializaArvore(a);
	
	insereNoArvoreOrdenada(10);
	insereNoArvoreOrdenada(15);
	//insereNoArvoreOrdenada(15);
	insereNoArvoreOrdenada(5);
	insereNoArvoreOrdenada(3);
	insereNoArvoreOrdenada(7);
	insereNoArvoreOrdenada(12);
	insereNoArvoreOrdenada(17);
	
	printf("\nBusca pré Ordem: \n");
	preOrdem(a.raiz);
	
	printf("\nBusca em Ordem: \n");
	emOrdem(a.raiz);
	
	printf("\nBusca pós Ordem: \n");
	posOrdem(a.raiz);
	
	return 0;
}


// Função que sempre dever ser chamada ao se criar uma nova árvore
void inicializzaArvore(ARVORE arv) {
	arv.raiz = NULL;
}


// Função utilizada para inicializar um novo nó na árvore
void inicializaNo(NO* n, int val) {
	if (!n) {
		printf("Falha de alocação!\n");
		return;
	} else {
		n->pai = NULL;
		n->esq = NULL;
		n->dir NULL;
		n->dado = val;
	}
}


// Função para inserir de maneira ordenada valores menores á esquerda
// Valores maiores ou iguais vão à direita
void insereNoArvoreOrdenada(int valor) {
	NO* corrente = a.raiz;
	NO* pai;
	
	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);
	printf("Inserido nó %d. \n", novoNo->dado);
	
	if (corrente == NULL) {
		a.raiz = novoNo;
		printf("Nó inserido na raiz. \n");
		return;
	}
	
	while (corrente) {
		pai = corrente;
		if (novoNo->dado < corrente->dado) {
			corrente = corrente->esq;
			if (!corrente) {
				printf("No inserido à esquerda do nó %d. \n", pai->dado);
				pai->esq = novoNo;
				return;
			}
		} else {
			corrente = corrente->dir;
			if (!corrente) {
				printf("No inserido à direita do nó %d. \n", pai->dado);
				pai->dir = novoNo;
				return;
			}
		}
	}
}


// Executa o caminhamento pré-ordem a partir do nó indicado por "raiz"
void preOrdem(NO* raiz) {
	if (raiz) {
		printf("%d \t", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}


// Executa o caminhamento em-ordem a partir do nó indicado por "raiz"
void emOrdem(NO* raiz) {
	if (raiz) {
		emOrdem(raiz->esq);
		printf("%d \t", raiz->dado);
		emOrdem(raiz->dir);
	}
}


// Executa o caminhamento em-ordem a partir do nó indicado por "raiz"
void posOrdem(NO* raiz) {
	if (raiz) {
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf("%d \t", raiz->dado);
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Estrutura da árvore
typedef struct str_no {
	char dado;
	int esquerda;
	int direita;
	int pai;
} str_no;

// Constantes
#define TAMANHO 100
#define E 0  // esquerda
#define D 1  // direita
#define R -1  // raiz

// Variáveis
struct str_no arvore[TAMANHO];
int lado, indice = 0;
int opt = -1;
char pai, no;

// Prototipação das funções
void arvore_insere(int pai, char dado, int lado);
int arvore_procura(char dado);
void menu_mostrar(void);
void limpar_buffer_teclado(void);


// Função principal
int main (void) {
	int temp;
	
	do {
		menu_mostrar();
		scanf("%d", &opt);
		limpar_buffer_teclado();
		switch (opt) {
			case 1: {
				printf("\nDigite o valor do PAI: ");
				scanf("%d", &pai);
				limpar_buffer_teclado();
				
				printf("Digite o valor do NO: ");
				scanf("%d", &no);
				limpar_buffer_teclado();
				
				printf("Digite o lado da subarvore (E=%d/D=%d/R=%d): ", E,D,R);
				scanf("%d", &lado);
				limpar_buffer_teclado();
				
				temp = arvore_procura(pai);
				arvore_insere(temp, no, lado);

				break;
			}
			case 2: {
				printf("\nDigite o valor do NO: ");
				scanf("%d", &no);
				limpar_buffer_teclado();
				
				temp = arvore_procura(no);
				printf("No %c\nFilho Esquerda: %c\nFilho Direita: %c\n\n", arvore[temp].dado,
				arvore[arvore[temp].esquerda].dado, arvore[arvore[temp].direita].dado);
				system("pause");
				break;
			}
		}
	} while (opt != 0);
	system("pause");
	return 0;
}

// Procura nó
int arvore_procura(char dado) {
	int i, indice;
	if (indice != 0) {
		for (i = 0; i < indice; i++) {
			if (arvore[i].dado == dado)
			return(i);
		}
	} else {
		return(0);
	}
}

// Inserir nó
void arvore_insere(int pai, char dado, int lado) {
	switch (lado) {
		case E: {
			arvore[pai].esquerda = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
			break;
		}
		case D: {
			arvore[pai].esquerda = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
			break;
		}
		case R: {
			arvore[pai].dado = dado;
			arvore[indice].pai = -1;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
			break;
		}
	}
}

// Função limpar buffer do teclado
void limpar_buffer_teclado() {
	#ifdef _WIN32
		fflush(stdin);
	#else
		__fpurge(stdin);
	#endif
}

// Menu
void menu_mostrar() {
	int i;
	limpar_buffer_teclado();
	
	for (i = 0; i < indice; i++) {
		printf("| %c ", arvore[i].dado);
	}
	
	printf("\n1 - Inserir um NO na arvore");
	printf("\n2 - Pesquisar um NO na arvore");
	printf("\n0 - Sair...\n\n");
}


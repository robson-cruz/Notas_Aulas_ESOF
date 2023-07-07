#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/*** ->>>> Definindo a estrutura da lista <<<<- ***/
typedef struct no {
	int valor;
 	struct no *proximo;
} No;

/*** ->>>> Prototipação de funções <<<<- ***/
void inserir_inicio(No **lista, int num);
void inserir_fim(No **lista, int num);
void inserir_meio(No **lista, int num, int ant);
void inserir_ordenado(No **lista, int num);
No* remover(No **lista, int num);
No* buscar(No **lista, int num);
void imprimir(No *no);

/*** ->>>> Função Principal <<<<- ***/
int main(void) {
	int opcao, valor, anterior;
	No *no, *lista = NULL;
	setlocale(LC_ALL, "");
	
	do {
		printf("\n0 - Sair\n1 - Inserir no início\n2 - Inserir no fim\n3 - Inserir no meio\n4 - Inserir ordenado\n5 - Remover\n6 - Imprimir\n7 - Buscar\n");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1:
				printf("Valor: ");
				scanf("%d", &valor);
				inserir_inicio(&lista, valor);
				break;
			case 2:
				printf("Valor: ");
				scanf("%d", &valor);
				inserir_fim(&lista, valor);
				break;
			case 3:
				printf("Valor a ser inserido e valor de referência: ");
				scanf("%d%d", &valor, &anterior);
				inserir_meio(&lista, valor, anterior);
				break;
			case 4:
				printf("Valor: ");
				scanf("%d", &valor);
				inserir_ordenado(&lista, valor);
				break;
			case 5:
				printf("Valor: ");
				scanf("%d", &valor);
				no = remover(&lista, valor);
				if (no) {
					printf("Elemento: %d", no->valor);
					free(no);
				} else {
					printf("Elemento não encontrado.\n");
				}
				break;
			case 6:
				imprimir(lista);
				break;
			case 7:
				printf("Valor: ");
				scanf("%d", &valor);
				no = buscar(&lista, valor);
				if (no) {
					printf("Elemento: %d", no->valor);
					free(no);
				} else {
					printf("Elemento não encontrado.\n");
				}
				break;
			default:
				if (opcao != 0) {
					printf("Opção inválida.\n");
				}
		}
	} while (opcao != 0);
	return 0;
}

/*** Implementação de funções <<<<- ***/
void inserir_inicio(No **lista, int num) {
	No *novo = (No*)malloc(sizeof(No));

	if (novo) {
		novo->valor = num;
		novo->proximo = *lista;
		*lista = novo;
	} else {
		printf("Erro ao alocar memória.\n");
	}
}

void inserir_fim(No **lista, int num) {
	No *aux, *novo = (No*)malloc(sizeof(No));

	if (novo) {
		novo->valor = num;
		novo->proximo = NULL;
	
		if (*lista == NULL) {
			*lista = novo;
		} else {
			aux = *lista;
			while (aux->proximo) {
				aux = aux->proximo;
			}
			aux->proximo = novo;
		}
		
	} else {
		printf("Erro ao alocar memória.\n"); 	
	}
}

void inserir_meio(No **lista, int num, int ant) {
	No *aux, *novo = (No*)malloc(sizeof(No));

	if (novo) {
		novo->valor = num;
	
		if (*lista == NULL) {
			novo->proximo = NULL;
			*lista = novo;
		} else {
			aux = *lista;
			while (aux->valor != ant && aux->proximo) {
				aux = aux->proximo;
			}
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}
	} else {
		printf("Erro ao alocar memória.\n");
	}
}

void inserir_ordenado(No **lista, int num) {
	No *aux, *novo = (No*)malloc(sizeof(No));

	if (novo) {
		novo->valor = num;
	
		if (*lista == NULL) {
			novo->proximo = NULL;
			*lista = novo;
		} else if (novo->valor < (*lista)->valor) {
			novo->proximo = *lista;
			*lista = novo;
		} else {
			aux = *lista;
			while (aux->proximo && novo->valor > aux->proximo->valor) {
				aux = aux->proximo;
			}
		
			novo->proximo = aux->proximo;
			aux->proximo = novo;
		}    
	} else {
		printf("Erro ao alocar memória.\n");
	}
}

No* remover(No **lista, int num) {
	No *aux, *remove = NULL;

	if (*lista) {
		if ((*lista)->valor == num) {
			remove = *lista;
			*lista = remove->proximo;
		} else {
			aux = *lista;
			while (aux->proximo && aux->proximo->valor != num) {
				aux = aux->proximo;
			}
			if (aux->proximo) {
				remove = aux->proximo;
				aux->proximo = remove->proximo;
			}
		}
	}
	return remove;
}

No* buscar(No **lista, int num) {
	No *aux, *no = NULL;

  	aux = *lista;
  	while (aux && aux->valor != num) {
  		aux = aux->proximo;
        }
	if (aux) {
		no = aux;
	}
 	return no;
}

void imprimir(No *no) {
	printf("\nLista: ");
	while(no) {
		printf("%d ", no->valor);
		no = no->proximo;
	}
	printf("\n\n");
}

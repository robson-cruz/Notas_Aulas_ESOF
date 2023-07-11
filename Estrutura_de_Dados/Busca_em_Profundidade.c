#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef _WIN32
       #include <windows.h>
#endif

// Número máximo de vértices
#define MAXV 8

// Estrutura do nó
typedef struct str_no {
	int id;
	struct str_no* proximo;
} str_no;

// Variável global
struct str_no grafo[MAXV];

// Prototipação de funções
void buscaEmProfundidade(struct str_no g[], int inicio, int alvo);

// Função Principal
int main(void) {
	// Inicializa o grafo
	int i;
	for (i = 0; i < MAXV; i++) {
		grafo[i].id = i;
		grafo[i].proximo = NULL;
	}
	// Adiciona arestas ao grafo
	grafo[0].proximo = malloc(sizeof(str_no));
	grafo[0].proximo->id = 1;
	grafo[0].proximo->proximo = malloc(sizeof(str_no));
	grafo[0].proximo->proximo->id = 2;
	grafo[0].proximo->proximo->proximo = NULL;
	
	grafo[1].proximo = malloc(sizeof(str_no));
	grafo[1].proximo->id = 3;
	grafo[1].proximo->proximo = malloc(sizeof(str_no));
	grafo[1].proximo->proximo->id = 4;
	grafo[1].proximo->proximo->proximo = NULL;
	
	grafo[2].proximo = malloc(sizeof(str_no));
	grafo[2].proximo->id = 5;
	grafo[2].proximo->proximo = malloc(sizeof(str_no));
	grafo[2].proximo->proximo->id = 6;
	grafo[2].proximo->proximo->proximo = NULL;
	
	grafo[3].proximo = NULL;
	grafo[4].proximo = NULL;
	grafo[5].proximo = NULL;
	grafo[6].proximo = NULL;
	grafo[7].proximo = NULL;
	
	int inicio = 0; // inicia o vertice
	int alvo = 6; // vertice alvo
	
	// Manipulador de console
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// Definir cor para verde
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	// Chamada para a função busca em profundidade
	buscaEmProfundidade(grafo, inicio, alvo);
	// Resetar cor para padrão
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
	
	return 0;
}

void buscaEmProfundidade(struct str_no g[], int inicio, int alvo) {
	int pilha[MAXV]; // pilha
	bool visitado[MAXV]; // nós visitados
	int indice = 0; // índice do topo da pilha
	bool achou = false; // flag de controle (não visitados)
	int corrente = inicio;
	struct str_no *ptr;
	int i;
	printf("=-=-=-= Busca em Profundidade =-=-=-=\n\n");
	// Marcando os nós como ‘não visitados’.
	for (i=0; i < MAXV; i++) {
		visitado[i] = false;
	}
	while (true) {
		// Nó corrente não visitado? Marque como visitado.
		// Empilhe o nó corrente.
		if (!visitado[corrente]) {
			printf("\tVISITANDO: %d. \n", corrente);
			if (corrente == alvo) {
				printf("\tAlvo encontrado!\n\n\n");
				return;
			}
			visitado[corrente] = true;
			pilha[indice] = corrente;
			indice++;
		}
		// Buscando por nós adjacentes, não visitados.
		achou = false;
		for (ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo) {
			if (!visitado[ptr->id]) {
				achou = true;
				break;
			}
		}
		if (achou) {
			// Atualizando o nó corrente.
			corrente = ptr->id;
		} else {
			// Não há vértices adjacentes não visitados.
			// Tentando desempilhar o vértice do topo.
			indice--;
			if(indice == -1) {
				// Não há mais vértices não visitados.
				printf("Encerrando a busca. \n");
				break;
			}
			corrente = pilha[indice];
		}
	}
	return;
}


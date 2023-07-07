#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


/***
1 - Ler a entrada de DNA com n caracteres compostos por uma sequência de
nucleotídeos (ACTTGACCGTTA) e armazená-los em uma estrutura de FILA DINÂMICA.
2 - Ao concluir a entrada, deve remover a sequência da fila para a dupla fita
do DNA convertendo a sequência de nucleotídeos (TAACGGTCAAGT) e armazená-los em 
uma estrutura de PILHA DINÂMICA.
3 - Fazer a impressão de ambas as estruturas.
***/


// Definição da estrutura para os nós da Fila
typedef struct NoFila {
	char dna;
	struct NoFila *prox;
} NoFila;


// Definição da estrutura para a fila
typedef struct Fila{
	NoFila *inicio;
	NoFila *fim;
} Fila;


// Definição da estrutura para os nós da pilha
typedef struct NoPilha {
	char dna;
	struct NoPilha *prox;
} NoPilha;

// Definição da estrutura para a pilha
typedef struct Pilha{
	NoPilha *topo;
} Pilha;


// Prototipação de funções
Fila *criarFila();
void destruirFila(Fila* fila);
int filaVazia(Fila *fila);
void inserirNaFila(Fila *fila, char dna);
char excluirNoFila(Fila *fila);
void imprimirFila(Fila *fila);
Pilha *criarPilha();
void destruirPilha(Pilha* pilha);
int pilhaVazia(Pilha *pilha);
void inserirNaPilha(Pilha *pilha, char dna);
void imprimirPilha(Pilha *pilha);
char excluirNoPilha(Pilha* pilha);
void limparTela();
char complementoNucleotideo(char nucleotideo);


/*** Função Principal ***/
int main(void) {
	setlocale(LC_ALL, "");
	
	Fila *filaDna = criarFila();
	Pilha *pilhaDna = criarPilha();
	
	// Leitura da sequência de DNA e inserção na fila
	char dna_seq[101];
	printf("Digite a sequencia de DNA: ");
	fgets(dna_seq, sizeof(dna_seq), stdin);
	// Remove o caractere '\n' da entrada
	int len = strlen(dna_seq);
	if (dna_seq[len - 1] == '\n') {
	   dna_seq[len - 1] = '\0';
	}
	
	int i = 0;
	
	// Inserir dados na fila
	while (dna_seq[i] != '\0' && dna_seq[i] != '\n') {
		inserirNaFila(filaDna, dna_seq[i]);
		i++;
	}
	limparTela();
	
	// Impressão da fila
	imprimirFila(filaDna);
	
	// Transferência de dados da fila para a pilha com a conversão de bases
	while (!filaVazia(filaDna)) {
		char nucleotideo = excluirNoFila(filaDna);
		char complemento = complementoNucleotideo(nucleotideo);
		inserirNaPilha(pilhaDna, complemento);
	}
	
	// Impressão da pilha
    	imprimirPilha(pilhaDna);
	
	// Liberação de memória
	destruirFila(filaDna);
    	destruirPilha(pilhaDna);
	
	return 0;
}


/*** Implementação das Funções ***/
// Função para criar uma fila vazia
Fila *criarFila() {
	Fila *fila = (Fila*)malloc(sizeof(Fila));
	fila->inicio = fila->fim = NULL;
	return fila;
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *fila) {
	return fila->inicio == NULL;
}

// Função para desalocar a Fila da memória
void destruirFila(Fila* fila) {
	while (!filaVazia(fila)) {
              excluirNoFila(fila);
    	}
    	free(fila);
}

// Função para inserir um elemento na fila
void inserirNaFila(Fila *fila, char dna) {
	NoFila *novoNo = (NoFila*)malloc(sizeof(NoFila));
	novoNo->dna = dna;
	novoNo->prox = NULL;
	
	if (filaVazia(fila)) {
		fila->inicio = fila->fim = novoNo;
	} else {
		fila->fim->prox = novoNo;
		fila->fim = novoNo;
	}
}

// Função para excluir um elemento da fila
char excluirNoFila(Fila *fila) {
	if (filaVazia(fila)) {
		printf("Fila vazia! Não é possível remover elementos.\n");
		exit(EXIT_FAILURE);
	}
	
	NoFila *noInicio = fila->inicio;
	char dna = noInicio->dna;
	
	fila->inicio = noInicio->prox;
	
	if (fila->inicio == NULL) {
		fila->fim = NULL;
	}
	
	free(noInicio);
	return dna;
	
}

// Função para imprimir a fila
void imprimirFila(Fila *fila) {
	if (filaVazia(fila)) {
		printf("Fila vazia!\n");
		return;
	} else {
		NoFila *noAtual = fila->inicio;
		printf("Fila:  ");
		while (noAtual != NULL) {
			printf("%c", noAtual->dna);
			noAtual = noAtual->prox;
		}
		printf("\n");
		}
}


// Função para criar uma pilha vazia
Pilha *criarPilha() {
	Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
	pilha->topo = NULL;
	return pilha;
}

// Função para desalocar a Fila da memória
void destruirPilha(Pilha* pilha) {
	while (!pilhaVazia(pilha)) {
		excluirNoPilha(pilha);
	}
 	free(pilha);
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
	return pilha->topo == NULL;
}

// Função para inserir um elemento na pilha
void inserirNaPilha(Pilha *pilha, char dna) {
	NoPilha *novoNo = (NoPilha *)malloc(sizeof(NoPilha));
    	novoNo->dna = dna;
    	novoNo->prox = pilha->topo;
    	pilha->topo = novoNo;
}

// Função para imprimir a pilha
void imprimirPilha(Pilha *pilha) {
	if (pilhaVazia(pilha)) {
		printf("Pilha cazia!\n");
		return;
	}
	
	printf("Pilha: ");
	NoPilha *noAtual = pilha->topo;
	while (noAtual != NULL) {
		printf("%c", noAtual->dna);
		noAtual = noAtual->prox;
	}
	printf("\n");
}

// Função para remover um elemento da pilha
char excluirNoPilha(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia! Não é possível remover elementos.\n");
        exit(EXIT_FAILURE);
    }

    NoPilha *noTopo = pilha->topo;
    char dna = noTopo->dna;
    pilha->topo = noTopo->prox;
    free(noTopo);
    
    return dna;
}

// Função para converter uma sequência de nucleotídeos em seu complemento
char complementoNucleotideo(char nucleotideo) {
	switch (nucleotideo) {
		case 'A':
            	     return 'T';
	        case 'T':
	            return 'A';
	        case 'C':
	            return 'G';
	        case 'G':
	            return 'C';
	        default:
	            printf("Nucleotídeo inválido encontrado: %c\n", nucleotideo);
	            exit(EXIT_FAILURE);
    }
}

// Função para limpar a tela
void limparTela() {
	#ifdef _WIN32
 	       system("cls");
        #else
               system("clear");
        #endif
}

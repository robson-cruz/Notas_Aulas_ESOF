#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


/***
1 - Ler a entrada de DNA com n caracteres compostos por uma sequ�ncia de
nucleot�deos (ACTTGACCGTTA) e armazen�-los em uma estrutura de FILA DIN�MICA.
2 - Ao concluir a entrada, deve remover a sequ�ncia da fila para a dupla fita
do DNA convertendo a sequ�ncia de nucleot�deos (TAACGGTCAAGT) e armazen�-los em 
uma estrutura de PILHA DIN�MICA.
3 - Fazer a impress�o de ambas as estruturas.
***/


// Defini��o da estrutura para os n�s da Fila
typedef struct NoFila {
	char dna;
	struct NoFila *prox;
} NoFila;


// Defini��o da estrutura para a fila
typedef struct Fila{
	NoFila *inicio;
	NoFila *fim;
} Fila;


// Defini��o da estrutura para os n�s da pilha
typedef struct NoPilha {
	char dna;
	struct NoPilha *prox;
} NoPilha;

// Defini��o da estrutura para a pilha
typedef struct Pilha{
	NoPilha *topo;
} Pilha;


// Prototipa��o de fun��es
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


/*** Fun��o Principal ***/
int main(void) {
	setlocale(LC_ALL, "");
	
	Fila *filaDna = criarFila();
	Pilha *pilhaDna = criarPilha();
	
	// Leitura da sequ�ncia de DNA e inser��o na fila
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
	
	// Impress�o da fila
	imprimirFila(filaDna);
	
	// Transfer�ncia de dados da fila para a pilha com a convers�o de bases
	while (!filaVazia(filaDna)) {
		char nucleotideo = excluirNoFila(filaDna);
		char complemento = complementoNucleotideo(nucleotideo);
		inserirNaPilha(pilhaDna, complemento);
	}
	
	// Impress�o da pilha
    	imprimirPilha(pilhaDna);
	
	// Libera��o de mem�ria
	destruirFila(filaDna);
    	destruirPilha(pilhaDna);
	
	return 0;
}


/*** Implementa��o das Fun��es ***/
// Fun��o para criar uma fila vazia
Fila *criarFila() {
	Fila *fila = (Fila*)malloc(sizeof(Fila));
	fila->inicio = fila->fim = NULL;
	return fila;
}

// Fun��o para verificar se a fila est� vazia
int filaVazia(Fila *fila) {
	return fila->inicio == NULL;
}

// Fun��o para desalocar a Fila da mem�ria
void destruirFila(Fila* fila) {
	while (!filaVazia(fila)) {
              excluirNoFila(fila);
    	}
    	free(fila);
}

// Fun��o para inserir um elemento na fila
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

// Fun��o para excluir um elemento da fila
char excluirNoFila(Fila *fila) {
	if (filaVazia(fila)) {
		printf("Fila vazia! N�o � poss�vel remover elementos.\n");
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

// Fun��o para imprimir a fila
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


// Fun��o para criar uma pilha vazia
Pilha *criarPilha() {
	Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
	pilha->topo = NULL;
	return pilha;
}

// Fun��o para desalocar a Fila da mem�ria
void destruirPilha(Pilha* pilha) {
	while (!pilhaVazia(pilha)) {
		excluirNoPilha(pilha);
	}
 	free(pilha);
}

// Fun��o para verificar se a pilha est� vazia
int pilhaVazia(Pilha *pilha) {
	return pilha->topo == NULL;
}

// Fun��o para inserir um elemento na pilha
void inserirNaPilha(Pilha *pilha, char dna) {
	NoPilha *novoNo = (NoPilha *)malloc(sizeof(NoPilha));
    	novoNo->dna = dna;
    	novoNo->prox = pilha->topo;
    	pilha->topo = novoNo;
}

// Fun��o para imprimir a pilha
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

// Fun��o para remover um elemento da pilha
char excluirNoPilha(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia! N�o � poss�vel remover elementos.\n");
        exit(EXIT_FAILURE);
    }

    NoPilha *noTopo = pilha->topo;
    char dna = noTopo->dna;
    pilha->topo = noTopo->prox;
    free(noTopo);
    
    return dna;
}

// Fun��o para converter uma sequ�ncia de nucleot�deos em seu complemento
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
	            printf("Nucleot�deo inv�lido encontrado: %c\n", nucleotideo);
	            exit(EXIT_FAILURE);
    }
}

// Fun��o para limpar a tela
void limparTela() {
	#ifdef _WIN32
 	       system("cls");
        #else
               system("clear");
        #endif
}

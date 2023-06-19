#include <stdio.h>
#include <stdlib.h>

/***
Procedimento para remover um nó específico, com um valor especificado, de uma lista encadeada
***/

/*** Cria uma struct chamada de "no" para representar os nós de uma lista encadeada.
A palavra-chave typedef é utilizada para criar um novo tipo de dado, nesse caso, chamado de No.
Isso permite que em vez de usar struct no toda vez que quisermos declarar uma variável do tipo nó, possamos simplesmente usar No.
A struct no possui dois campos:
	valor: Um campo do tipo int que representa o valor armazenado no nó.
    Pode ser qualquer tipo de dado, dependendo da necessidade do programa.
	proximo: Um ponteiro para struct no que aponta para o próximo nó na lista encadeada.
 	Esse campo permite a conexão entre os nós, formando a estrutura sequencial da lista.
***/
typedef struct no {
	int valor;
	struct no *proximo;
} No;

/*** A função procedimento recebe como parâmetros um ponteiro para um ponteiro de No (representando a lista)
e um número inteiro num (valor a ser removido da lista).
***/
void procedimento(No **lista, int num) {
	/*** Declara duas variáveis locais: "aux" e "no".
	Ambas são ponteiros para "No", sendo que "no" é inicializado como NULL.
	***/
	No *aux, *no = NULL;
	/*** Verifica se a lista não está vazia.
    Isso é feito ao verificar se o ponteiro para o primeiro nó da lista (*lista) é diferente de NULL.
 	***/
    if (*lista != NULL) {
		/***Se o valor do primeiro nó da lista ((*lista)->valor) for igual ao número especificado (num),
  significa que o nó a ser removido é o primeiro nó da lista.
  Nesse caso, o ponteiro no é atribuído ao primeiro nó da lista (*lista) e o primeiro nó é atualizado para
  apontar para o próximo nó da lista (*lista = no->proximo). Isso remove o nó da lista.
  ***/
		if ((*lista)->valor == num) {
        	no = *lista;
        	*lista = no->proximo;
		/***
  		Caso contrário, percorre a lista para encontrar o nó anterior ao nó que contém o valor desejado. O ponteiro aux é inicializado com o primeiro nó da lista (*lista).
		Um loop while é executado enquanto o próximo nó de aux não for NULL e o valor do próximo nó não for igual ao número especificado. Isso permite percorrer a lista até encontrar o nó com o valor desejado ou chegar ao final da lista.
		Se o próximo nó de aux for diferente de NULL, significa que o nó a ser removido foi encontrado. O ponteiro no é atribuído ao próximo nó de aux e o próximo nó de aux é atualizado para apontar para o nó seguinte. Isso remove o nó da lista.
  		***/
      	} else {
        	aux = *lista; 
    		while (aux->proximo != NULL && aux->proximo->valor != num)
				aux = aux->proximo;
    		if (aux->proximo != NULL) {
      			no= aux->proximo;
				aux->proximo = no->proximo;
    		}
  		}
	}
	/***
 	Verifica se o ponteiro no é diferente de NULL. 
  	Se for, significa que um nó foi encontrado e removido da lista.
    Nesse caso, o comando free(no) é usado para liberar a memória alocada para o nó removido.
 	***/
	if (no != NULL) {
    	free(no);
  	}
}

int main(void) {
	No *lista = NULL;

	// Inserir elementos na lista
	int i;
	for (i = 1; i <= 5; i++) {
		No* novoNo = (No*)malloc(sizeof(No));
		novoNo->valor = i;
		novoNo->proximo = lista;
		lista = novoNo;
	}

	printf("Lista original: ");
	No *atual = lista;
	while (atual != NULL) {
		printf("%d ", atual->valor);
		atual = atual->proximo;
	}
	printf("\n");

	// Remover um valor da lista
	int valorRemover = 3;
	procedimento(&lista, valorRemover);

	printf("Lista após remoção do valor %d: ", valorRemover);
	atual = lista;
	while (atual != NULL) {
		printf("%d ", atual->valor);
		atual = atual->proximo;
	}
	printf("\n");

	// Liberar memória alocada
	atual = lista;
	while (atual != NULL) {
		No *proximo = atual->proximo;
		free(atual);
		atual = proximo;
	}
	
	return 0;
}
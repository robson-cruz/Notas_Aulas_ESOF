#include <stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#define TAM 100

typedef struct {
	
	//int cod;
	char nome[100];
	char cpf[11];
	char vacina[50];
	char data[10];
	char Numero_Lote[10];
	
}dados;

int cont = 0;
int cod;

void cadastroPessoa(dados cadastro[TAM]);
void motraDados(dados cadastro[TAM]);
void escreverArq(dados cadastro[]);

int main (void) {
	
	setlocale(LC_ALL, "Portuguese");
	
	dados cadastro[TAM];
	
	int op;
	
	while (op != 4) {
		printf(" 1. Cadastro\n");
		printf(" 2. Ver dados cadastrados\n");
		printf(" 3. Sair\n >>> ");
		scanf("%d", &op);
		fflush(stdin);
		printf("\n");
		
		system("cls");
		switch (op) {
			case 1:
				cadastroPessoa(cadastro);
				break;
			case 2:
				motraDados(cadastro);
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("\n Você digitou uma opção invalida. Tente novamente!\n");
		}
	}
	return 0;
}

void cadastroPessoa (dados cadastro[TAM]) {
	
	system("cls");
	char resposta = 's';
	
	while (resposta == 's' && cont <= TAM) {
		
		system("cls");
		
		printf("Nome: ");
		fflush(stdin);
		scanf("%s", &cadastro[cont].nome);
		
		printf("\nCPF: ");
		fflush(stdin);
		scanf("%s", &cadastro[cont].cpf);
		
		printf("\nVacina: ");
		fflush(stdin);
		scanf("%s", &cadastro[cont].vacina);
		
		printf("\nData: ");
		fflush(stdin);
		scanf("%s", &cadastro[cont].data);
		
		printf("\nLote: ");
		fflush(stdin);
		scanf("%s", &cadastro[cont].Numero_Lote);
		
		cont ++;
		//cadastro[cont].cod = cont;
		
		if (cont < TAM) {
			printf("\n\nDeseja cadastrar outra pessoa? [s] Sim [n] Não: ");
			fflush(stdin);
			scanf("%c", &resposta);
		}
		else {
			printf("\nSaia e entre novamente para novos cadastros!!!\n");
			resposta = 'n';
		}
	}
	//escreverArq(cadastro);
}
/*
void escreverArq(dados cadastro[]) {
	int i;
	int size_st = sizeof(dados) - 1;  // numero de pessoas cadastradas
	
	// Cria o ponteiro 'arq' do tipo FILE para receber o endereço de
	// memória de um arquivo
	FILE *arq;
	// Atribui o endereço de um arquivo em disco ao ponteriro 'arq' e
	// e abre o arquivo no modo leitura
	arq = fopen("dados.txt", "a");
	
	// Escreve os dados no arquivo
	for (i = 0; i < TAM; i++) {
		// Escreve cada registro no arquivo
		//fprintf(arq, "%d, %s, %s, %s", i, cadastro[i].nome, cadastro[i].cpf, cadastro[i].vacina, cadastro[i].data, cadastro[i].Numero_Lote);
		fwrite(cadastro, sizeof(cadastro), 1, arq);
	}
	// Fecha o arquivo
	fclose(arq);
}
*/
void motraDados(dados cadastro[TAM]) {
	
	system("cls");
	int i = 0;
	
	if (cont > 0) {
		while (i != cont) {
			for (i; i < cont; i++) {
				printf("\nCódigo: %d", i);
				//printf("\nCódigo: %s", cadastro[i].cod);
				printf("\nNome: %s", cadastro[i].nome);
				printf("\nCPF: %s", cadastro[i].cpf);
				printf("\nVacina: %s", cadastro[i].vacina);
				printf("\nData: %s", cadastro[i].data);
				printf("\nNumero do Lote: %s", cadastro[i].Numero_Lote);
				printf("\n==================================\n\n");
			}
			i ++;
		}
	}
	
}


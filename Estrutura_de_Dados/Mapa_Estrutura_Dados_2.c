#include <stdio.h>


// Protitipação de funções
int buscaBinaria(int arranjo[], int i, int f, int chave);


int main(void) {
	int vetor[] = {1, 15, 19, 22, 26, 32, 46, 55, 67, 81};
	
	int i = 0;
	int f = sizeof(vetor) / sizeof(vetor[0]);
	
	int busca = buscaBinaria(vetor, i, f, 99);
	printf("\n%d\n", busca);
	
	return 0;
}


// Função busca binária
int buscaBinaria(int arranjo[], int i, int f, int chave)
{
    if (f >= i)
    {
        int meio = i + (f - i)/2;
        if (arranjo[meio] == chave)
            return meio;
        if (arranjo[meio] > chave)
            return buscaBinaria(arranjo, i, meio-1, chave);
        return buscaBinaria(arranjo, meio+1, f, chave);
     }
     return -1;
}

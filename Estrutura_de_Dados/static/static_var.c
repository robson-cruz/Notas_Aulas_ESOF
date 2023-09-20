#include <stdio.h>

/*
Neste exemplo, a variável contador é declarada como static dentro da função contagem().
Isso significa que a variável mantém seu valor entre chamadas da função. 
*/
void contagem() {
    static int contador = 0; // A variável 'contador' é estática.
	//int contador = 0;
    contador++;
    printf("Contador: %d\n", contador);
}

int main() {
    contagem();
    contagem();
    contagem();
    return 0;
}

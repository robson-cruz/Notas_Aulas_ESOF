#include <stdio.h>

/*
Neste caso, a função funcaoEstatica() é declarada como static. 
Isso significa que ela só pode ser acessada dentro do arquivo de origem atual
e não pode ser chamada por outros arquivos de origem.
*/
static void funcaoEstatica() {
    printf("Esta é uma função estática.\n");
}

int main() {
    funcaoEstatica();
    return 0;
}

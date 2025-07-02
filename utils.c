#include <stdlib.h>
#include <stdio.h>

FILE* abrirArquivo(char* caminho, char* modo) {
    FILE* arquivo = fopen(caminho, modo);

    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s", caminho);
        return NULL;
    }

    return arquivo;
}

void limparTela() {
    system("cls");
}

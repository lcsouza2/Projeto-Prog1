#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>
#include "login.h"
#include "menus.h"
#include "exercicios.h"
#include "relatorios.h"

#define CAMINHO_ARQUIVO_RELATORIOS "./relatorios.txt"

void criarConta();
int menuPrincipal();

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao_principal;

    do {
        entrar();
        do {
            opcao_principal = menuPrincipal();
            switch (opcao_principal) {
                case 1:
                    checkOpcaoExercicio();
                    break;
                case 2:
                    checkOpcaoRelatorio();
                    break;
                case 3:
                    printf("Saindo...\n");
                    Sleep(1000);
                    break;
                default:
                    printf("\nEsta opcao nao existe, por favor escolha novamente.\n");
                    break;
            }
        } while (opcao_principal != 3 && opcao_principal != 4);
    } while (opcao_principal == 3);

    return 0;
}

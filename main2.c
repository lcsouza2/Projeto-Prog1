#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>
#include "exercicios.h"
#include "relatorios.h"

char nome[16];

// Declaração das funções
void limparTela();
void pausar();
void login(char n[16]);
int menuPrincipal();

// Implementação das funções

void limparTela() {
    system("cls");
}

void login(char n[16]) {
    int senha;
    do {
        limparTela();
        printf("=======================================\n");
        printf("             \\\\ Login // \n");
        printf("=======================================\n\n");
        printf("              Nome: ");
        scanf("%15s", n);
        printf("              Senha: ");
        scanf("%d", &senha);

        if (((stricmp(n, "rick") != 0) || (senha != 1357)) && ((stricmp(n, "luiz") != 0) || (senha != 1504))) {
            printf("\nO nome ou a senha está incorreto!\n");
            Sleep(2000);
        }
    } while (((stricmp(n, "rick") != 0) || (senha != 1357)) && ((stricmp(n, "luiz") != 0) || (senha != 1504)));

    printf("\n=======================================\n");
    printf("\nSeu login foi feito com sucesso %s.\n", n);
    Sleep(2000);
}

int menuPrincipal() {
    int opcao;
    limparTela();
    printf("=======================================================\n");
    printf("  \\\\ Boas vindas %s, planeje sua rotina aqui! // \n", nome);
    printf("=======================================================\n\n");
    printf("1. Exercícios\n");
    printf("2. Relatórios\n");
    printf("3. Sair\n");
    printf("=======================================================\n");
    printf("*Exercícios: organize sua rotina de treino.\n");
    printf("*Relatórios: todos os treinos realizados.\n");
    printf("=======================================================\n\n");
    printf("Número da opção desejada: ");
    scanf("%d", &opcao);
    return opcao;
}



// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao_principal;

    do {
        login(nome);
        do {
            opcao_principal = menuPrincipal();
            switch (opcao_principal) {
                case 1:
                    menuExercicios();
                    break;
                case 2:
                    menuRelatorios();
                    break;
                case 3:
                    printf("Saindo...\n");
                    Sleep(1000);
                    break;
                default:
                    printf("\nEsta opção não existe, por favor escolha novamente.\n");
                    pausar();
                    break;
            }
        } while (opcao_principal != 3 && opcao_principal != 4);
    } while (opcao_principal == 3);

    return 0;
}


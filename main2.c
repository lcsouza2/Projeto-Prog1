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
int menuPrincipal();

// Implementação das funções

int menuPrincipal() {
    int opcao;
    limparTela();
    printf("=======================================================\n");
    printf("        \\\ Olá! Planeje sua rotina aqui! /// \n");
    printf("=======================================================\n\n");
    printf("                1. Exercícios\n");
    printf("                2. Relatórios\n");
    printf("                3. Sair\n");
    printf("=======================================================\n");
    printf("*Exercícios: organize sua rotina de treino.\n");
    printf("*Relatórios: todos os treinos realizados.\n");
    printf("=======================================================\n\n");
    printf("Número da opção desejada: ");
    scanf("%d", &opcao);
    return opcao;
}
    setlocale(LC_ALL, "Portuguese");



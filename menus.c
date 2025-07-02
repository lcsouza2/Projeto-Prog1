#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int menuLogin() {
    int opcao;
    printf("=======================================\n");
    printf("             \\ Login /// \n");
    printf("=======================================\n\n");
    printf("           1.Entrar\n");
    printf("           2.Criar conta\n");
    printf("           3.Sair\n\n");
    printf("=======================================\n\n");
    printf("Digite o numero da opcao desejada: ");

    scanf("%d", &opcao);
    getchar();
    return opcao;
}

char* menuCadastro(char* nome) {
    printf("=======================================\n");
    printf("          \\ Criar conta /// \n");
    printf("=======================================\n");
    printf("*Para sair digite 0 em nome ou senha*\n");
    printf("*O numero maximo de caracteres para um\nnome e 40*\n");
    printf("*O numero maximo de caracteres para uma\nsenha e 15*\n");
    printf("=======================================\n\n");

    printf("            Nome: ");
    fgets(nome, 41, stdin);

    return nome;
}

int menuPrincipal() {
    int opcao;
    limparTela();
    printf("=======================================================\n");
    printf("  \\ Boas vindas, planeje sua rotina aqui! // \n");
    printf("=======================================================\n\n");
    printf("1. Exercicios\n");
    printf("2. Relatorios\n");
    printf("3. Sair\n");
    printf("=======================================================\n");
    printf("*Exercicios: organize sua rotina de treino.\n");
    printf("*Relatorios: todos os treinos realizados.\n");
    printf("=======================================================\n\n");
    printf("Numero da opcao desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

void menuExercicios() {
    printf("=======================================\n");
    printf("      \\ Menu Treino Academia //\n");
    printf("=======================================\n");
    printf("1. Criar Exercicio\n");
    printf("2. Ver Exercicios Disponiveis\n");
    printf("3. Voltar\n");
    printf("=======================================\n");
    printf("Escolha uma opcao: ");
}

void menuRelatorios() {
    printf("\n=== RELATORIOS ===\n");
    printf("1. Ver Relatorios\n");
    printf("2. Adicionar Relatorio\n");
    printf("3. Voltar\n");
    printf("=====================\n");
}

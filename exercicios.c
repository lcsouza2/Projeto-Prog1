#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "menus.h"

typedef struct {
    char nome[50];
    char musculo[50];
    char aparelho[50];
} Exercicio;


void criarExercicio();
void mostrarExercicios();

// Funcao para ler, resolver a opcao e chamar as funcoes correspondentes
void checkOpcaoExercicio() {
    int opcao;
    do {
        limparTela();
        menuExercicios();
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
            case 1:
                limparTela();
                criarExercicio();
                break;
            case 2:
                limparTela();
                mostrarExercicios();
                break;
            case 3:
                printf("Voltando ao menu anterior...\n");
                limparTela();
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);
}


void criarExercicio() {
    Exercicio novoExercicio;
    FILE *arquivo = fopen("exercicios.txt", "a");

    if (!arquivo) {
        printf("\nNao foi possivel abrir o arquivo de exercicios.\n");
        return;
    }

    printf("\n=====Criar Novo Exercicio=====\n");

    printf("Digite o nome do exercicio: ");
    scanf("%s", novoExercicio.nome);
    if (strcmp(novoExercicio.nome, "sair") == 0) {
        fclose(arquivo);
        printf("Cadastro cancelado.\n");
        return;
    }

    printf("Digite o musculo alvo: ");
    scanf("%s", novoExercicio.musculo);
    if (strcmp(novoExercicio.nome, "sair") == 0) {
        fclose(arquivo);
        printf("Cadastro cancelado.\n");
        return;
    }

    printf("Digite o aparelho usado: ");
    scanf("%s", novoExercicio.aparelho);
    if (strcmp(novoExercicio.nome, "sair") == 0) {
        fclose(arquivo);
        printf("Cadastro cancelado.\n");
        return;
    }

    fprintf(arquivo, "[EXERCICIO]\n");
    fprintf(arquivo, "NOME=%s\n", novoExercicio.nome);
    fprintf(arquivo, "MUSCULO=%s\n", novoExercicio.musculo);
    fprintf(arquivo, "APARELHO=%s\n", novoExercicio.aparelho);
    fprintf(arquivo, "[/EXERCICIO]\n");

    limparTela();

    fclose(arquivo);
}

void mostrarExercicios() {
    char nome[100], musculo[100], aparelho[100];

    FILE *arquivo = fopen("exercicios.txt", "r");
    char linha[128];
    int contador = 1;

    printf("\n\\\\ Exercicios Disponiveis ////\n");

    if (!arquivo) {
        printf("\nNao foi possivel abrir o arquivo de exercicios.\n");
        return;
    }

     printf("\n==========\n");
     while (fgets(linha, sizeof(linha), arquivo)) {
                if (strncmp("NOME=", linha, 5) == 0) {
                    sscanf(linha + 5, "%[^\n]", nome);
                }
                if (strncmp("MUSCULO=", linha, 8) == 0) {
                    sscanf(linha + 8, "%[^\n]", musculo);
                }
                if (strncmp("APARELHO=", linha, 9) == 0) {
                    sscanf(linha + 9, "%[^\n]", aparelho);
                }

                if (strncmp(linha, "[/EXERCICIO]", 12) == 0) {
                    printf("Nome do exercicio: %s\nMusculo Alvo: %s\nAparelho Usado: %s\n", nome, musculo, aparelho);
                    printf("==========\n");
                    continue;
                }
    }

    fclose(arquivo);
    printf("\n");
}

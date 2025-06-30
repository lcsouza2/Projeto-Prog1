#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "relatorios.h"

#define CAMINHO_ARQUIVO_RELATORIOS "./relatorios.txt"

struct ExercicioRelatorio {
    char nome[101];
    char series[20];
    char peso[10];
};

void menuRelatorios() {
    int opcaoRelatorio;
    do {
        limpar_tela();
        printf("\n=== RELATORIOS ===\n");
        printf("1. Ver Relatorios\n");
        printf("2. Adicionar Relatorio\n");
        printf("3. Voltar\n");
        printf("=====================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoRelatorio);

        switch (opcaoRelatorio) {
            case 1:
                verRelatorios();
                break;
            case 2:
                criarRelatorio();
                break;
            case 3:
                break;
            default:
                printf("Opcao Invalida!\n");
                pausar();
                break;
        }
    } while (opcaoRelatorio != 3);
}

void criarRelatorio() {
    FILE *arquivo;
    char temp[101];
    char dataRelatorio[12];

    arquivo = fopen(CAMINHO_ARQUIVO_RELATORIOS, "a");
    if (!arquivo) {
        printf("Nao foi possível abrir o arquivo de dados!\n");
        pausar();
        return;
    }

    printf("=====================\n");
    printf("Digite a data do relatório ou 'cancelar' para voltar ao menu: ");
    scanf("%s", dataRelatorio);

    if (strcmp(dataRelatorio, "cancelar") == 0) {
        fclose(arquivo);
        return;
    }

    fprintf(arquivo, "[RELATORIO]\n");
    fprintf(arquivo, "DATA=%s\n", dataRelatorio);

    while (1) {
        struct ExercicioRelatorio exercicioTemp;

        printf("Adicione um exercicio ou digite 'sair' para encerrar o relatorio!\n");

        printf("Digite o nome do exercicio: ");
        scanf("%s", temp);
        if (strcmp(temp, "sair") == 0) break;
        strcpy(exercicioTemp.nome, temp);

        printf("Digite o peso utilizado: ");
        scanf("%s", temp);
        if (strcmp(temp, "sair") == 0) break;
        strcpy(exercicioTemp.peso, temp);

        printf("Digite a quantidade de series no formato seriesXrepeticoes, ex. 3x12: ");
        scanf("%s", temp);
        if (strcmp(temp, "sair") == 0) break;
        strcpy(exercicioTemp.series, temp);

        fprintf(arquivo, "EXERCICIO=%s;%s;%s\n", exercicioTemp.nome, exercicioTemp.peso, exercicioTemp.series);
        printf("=====================\n");
    }

    fprintf(arquivo, "[/RELATORIO]\n\n");
    fclose(arquivo);
    printf("Relatório salvo!\n");
    pausar();
}

void verRelatorios() {
    FILE *arquivo;
    arquivo = fopen(CAMINHO_ARQUIVO_RELATORIOS, "r");
    if (!arquivo) {
        printf("Nao foi possível abrir o arquivo de dados!\n");
        pausar();
        return;
    }

    char linha[256], data[12], nome[101], peso[10], series[20];
    int encontrou = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strcmp(linha, "[RELATORIO]\n") == 0) {
            encontrou = 1;
            printf("=====================\n");
            fgets(linha, sizeof(linha), arquivo);
            sscanf(linha, "DATA=%s\n", data);
            printf("Relatorio do dia: %s\n", data);

            while (fgets(linha, sizeof(linha), arquivo) && strncmp(linha, "[/RELATORIO]", 13) != 0) {
                if (strncmp("EXERCICIO=", linha, 10) == 0) {
                    sscanf(linha + 10, "%[^;];%[^;];%[^\n];", nome, peso, series);
                    printf("Nome do exercicio: %s\nSeries Totais: %s\nPeso: %s\n", nome, series, peso);
                }
            }
        }
    }
    if (!encontrou) {
        printf("Nenhum relatório encontrado.\n");
    }
    fclose(arquivo);
    pausar();
}

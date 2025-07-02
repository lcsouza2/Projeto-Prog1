#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include "menus.h"

struct Relatorio {
    char nome[101];
    char series[20];
    char peso[10];
};

// Definição da struct ExercicioRelatorio para uso em criarRelatorio
struct ExercicioRelatorio {
    char nome[101];
    char peso[10];
    char series[20];
};

void checkOpcaoRelatorio();
void criarRelatorio();
void verRelatorios();

void checkOpcaoRelatorio() {
    int opcaoRelatorio = 0;
    do {
        limparTela();
        menuRelatorios();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoRelatorio);
        getchar();
        switch (opcaoRelatorio) {
            case 1:
                verRelatorios();
                limparTela();
                break;
            case 2:
                criarRelatorio();
                limparTela();
                break;
            case 3:
                break;
            default:
                printf("Opcao Invalida!\n");
                break;
            }
    } while (opcaoRelatorio != 3);
}

void criarRelatorio() {
    FILE *arquivo = abrirArquivo("./relatorios.txt", "a");
    char temp[101];
    char dataRelatorio[12];


    printf("=====================\n");
    printf("Digite a data do relatorio ou 'cancelar' para voltar ao menu: ");
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
    printf("Relatorio salvo!\n");
}

void verRelatorios() {
    FILE *arquivo = abrirArquivo("./relatorios.txt", "r");

    if (arquivo == NULL) {
        return;
    }
    char linha[256], data[12], nome[101], peso[10], series[20];
    int encontrou = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strncmp(linha, "[RELATORIO]", 11) == 0) {
            encontrou = 1;
            printf("=====================\n");
            if (fgets(linha, sizeof(linha), arquivo)) {
                sscanf(linha, "DATA=%s\n", data);
                printf("Relatorio do dia: %s\n", data);
            }
            while (fgets(linha, sizeof(linha), arquivo) && strncmp(linha, "[/RELATORIO]", 13) != 0) {
                if (strncmp(linha, "EXERCICIO=", 10) == 0) {
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
}

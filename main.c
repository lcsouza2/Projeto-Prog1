#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CAMINHO_ARQUIVO_RELATORIOS "./relatorios.txt"

int menuPrincipal();
int menuExercicios();
int menuRelatorios();

char verRelatorios();
void criarRelatorio();

struct ExercicioRelatorio{
    char nome[101];
    char series[20];
    char peso[10];
};


int main() {
    int opcao;
    do {
        opcao = menuPrincipal();
        switch (opcao) {
        case 1:
            menuExercicios();
            break;
        case 2:
            menuRelatorios();
        }
    } while (opcao != 3);

}


int menuPrincipal() {
    int opcaoPrincipal;
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Exercicios\n");
    printf("2. Relatorios\n");
    printf("3. Sair\n");
    printf("=====================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoPrincipal);
    return opcaoPrincipal;
}

int menuExercicios() {
    int opcaoExercicio;

    printf("\n=== EXERCICIOS ===\n");
    printf("1. Ver Exercicios\n");
    printf("2. Adicionar Exercicio\n");
    printf("3. Editar Exercicio\n");
    printf("4. Remover Exercicio\n");
    printf("5. Voltar\n");
    printf("=====================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoExercicio);

    switch (opcaoExercicio)
    {
    case 1:
        //função
        break;
    case 2:
        //função
        break;
    case 3:
        //funcao
        break;
    case 4:
        //funcao
        break;
    case 5:
        return 0;
        break;
    default:
        printf("Opcao Invalida!");
        break;
    }
}

int menuRelatorios() {
    int opcaoRelatorio;

    printf("\n=== RELATORIOS ===\n");
    printf("1. Ver Relatorios\n");
    printf("2. Adicionar Relatorio\n");
    printf("3. Remover Exercicio\n");
    printf("4. Voltar\n");
    printf("=====================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoRelatorio);

    switch (opcaoRelatorio)
    {
    case 1:
        //função
        break;
    case 2:
        criarRelatorio();
        break;
    case 3:
        //funcao
        break;
    case 4:
        return 0;
        break;
    default:
        printf("Opcao Invalida!");
        break;
    }
}

void criarRelatorio() {
    FILE *arquivo;
    char temp[101];
    char dataRelatorio[12];

    arquivo = fopen(CAMINHO_ARQUIVO_RELATORIOS, "a");

    if (!arquivo) {
        printf("Nao foi possível abrir o arquivo de dados!");
        return;
    }

    printf("=====================\n");
    printf("Digite a data do relatório ou 'cancelar' para voltar ao menu: ");
    
    scanf("%s", dataRelatorio);
    
    if (strcmp(dataRelatorio, "cancelar") != 0) { 
        fprintf(arquivo, "[RELATORIO]\n");
        
        fprintf(arquivo, "DATA=%s\n", dataRelatorio);
    } else {
        return;
    }

    do {
        struct ExercicioRelatorio exercicioTemp;

        printf("Adicione um exercicio ou digite 'sair' para encerrar o relatorio!\n");
        
        printf("Digite o nome do exercicio: ");
        scanf("%s", temp);
        if (strcmp(temp, "sair") == 0) {
            break;
        } else {
            strcpy(exercicioTemp.nome, temp);
        }

        printf("Digite o peso utilizado: ");
        scanf("%s", temp);
        if (strcmp(temp, "sair") == 0) {
            break;
        } else {
            strcpy(exercicioTemp.peso, temp);
        }

        printf("Digite a quantidade de series no formato seriesXrepeticoes, ex. 3x12: ");
        scanf("%s", temp);
        if (strcmp(temp, "sair") == 0) {
            break;
        } else {
            strcpy(exercicioTemp.series, temp);
        }

        printf("=====================\n");
        
        fprintf(arquivo, "EXERCICIO=%s;%s;%s\n", exercicioTemp.nome, exercicioTemp.peso, exercicioTemp.series);
        
    } while (1);
    
    fprintf(arquivo, "[/RELATORIO]\n\n");
    fclose(arquivo);
}

char verRelatorios() {
    FILE *arquivo;

    arquivo = fopen(CAMINHO_ARQUIVO_RELATORIOS, "r");
    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo)) {

    }
}
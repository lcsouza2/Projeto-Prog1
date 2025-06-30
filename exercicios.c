#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char nome[50];
    char musculo[50];
    char aparelho[50];
} Exercicio;

void menuExercicios();
void consultarExercicio(Exercicio escolhido);
void mostrarExercicios();
void criarExercicio();

void menuExercicios() {
    int opcao;
    Exercicio escolhido;
    strcpy(escolhido.nome, "");

    do {
        limparTela();
        printf("=======================================\n");
        printf("      \\\\ Menu Treino Academia //\n");
        printf("=======================================\n");
        printf("1. Ver Exercicios Disponiveis\n");
        printf("2. Escolher um Exercicio\n");
        printf("3. Consultar Exercicio Escolhido\n");
        printf("4. Voltar\n");
        printf("=======================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                mostrarExercicios();
                pausar();
                break;
            case 2:
                escolherExercicio(&escolhido);
                pausar();
                break;
            case 3:
                consultarExercicio(escolhido);
                pausar();
                break;
            case 4:
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                pausar();
        }
    } while (opcao != 4);
}

void criarExercicio() {
    Exercicio novoExercicio;
    FILE *arquivo = fopen("exercicios.txt", "a");

    if (!arquivo) {
        printf("\nNão foi possível abrir o arquivo de exercícios.\n");
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

    flcose(arquivo);
}

void consultarExercicio(Exercicio escolhido) {
    if (strlen(escolhido.nome) == 0) {
        printf("\n\nNenhum exercicio foi escolhido ainda.\n\n");
        return;
    }

    printf("\n--- Exercicio Escolhido ---\n");
    printf("- Nome do exercicio: %s\n", escolhido.nome);
    printf("- Musculo alvo: %s\n", escolhido.musculo);
    printf("- Aparelho usado: %s\n\n", escolhido.aparelho);
}

void mostrarExercicios() {
    FILE *arquivo = fopen("exercicios.txt", "r");
    char linha[128];
    int contador = 1;

    printf("\n\\\\ Exercicios Disponiveis ////\n");

    if (!arquivo) {
        printf("\nNão foi possível abrir o arquivo de exercícios.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        // Remove o \n do final, se houver
        linha[strcspn(linha, "\n")] = 0;
        printf("%d - %s\n", contador, linha);
        contador++;
    }

    fclose(arquivo);
    printf("\n");
}
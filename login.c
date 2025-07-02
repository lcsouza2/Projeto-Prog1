#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "utils.h"
#include "menus.h"

void criarConta() {
    FILE* conta = abrirArquivo("./conta.txt", "a");
    char nome[41];
    char senha[16];
    menuCadastro(nome);

    nome[strcspn(nome, "\n")] = 0;

    if (strcmp(nome, "0") == 0) {
        fclose(conta);
        system("cls");
    } else {
        printf("            Senha: ");
        fgets(senha, sizeof(senha), stdin);

        senha[strcspn(senha, "\n")] = 0;

        if (strcmp(senha, "0") == 0) {
            fclose(conta);
            system("cls");
        } else {
            fprintf(conta, "%s;%s\n", nome, senha);

            fclose(conta);

            printf("\n=======================================\n\n");
            printf("Sua conta foi criada com sucesso!");

            Sleep(3000);
            system("cls");
        }
    }
}

// Corrigido: retorna int para indicar sucesso (1) ou falha (0)
int entrar() {
    int opcao, entre = 0, voltar = 0;
    char nome[41], senha[16], linha[200], nc[41], sc[16];
    FILE *conta;

    conta = abrirArquivo("./conta.txt", "r");
    voltar = 1;
    entre = 1;

    Sleep(1000);
    system("cls");
    // else
    if (conta != NULL) {
        printf("========================================\n");
        printf("             \\ Entrar /// \n");
        printf("========================================\n");
        printf("*Para sair digite 0 em nome ou senha*\n");
        printf("========================================\n\n");
        printf("            Nome: ");
        fgets(nc, sizeof(nc), stdin);
        nc[strcspn(nc, "\n")] = 0;

        if (strcmp(nc, "0") == 0) {
            fclose(conta);
            entre = 0;
            system("cls");
        } else {
            printf("            Senha: ");
            fgets(sc, sizeof(sc), stdin);
            sc[strcspn(sc, "\n")] = 0; // Remove o \n
            if (strcmp(sc, "0") == 0) {
                fclose(conta);
                entre = 0;
                system("cls");
            } else {
                while (fgets(linha, sizeof(linha), conta) != NULL) {
                    linha[strcspn(linha, "\n")] = 0;

                    char *nomeToken = strtok(linha, ";");
                    char *senhaToken = strtok(NULL, ";");

                    if ((stricmp(nc, nomeToken) == 0) && (stricmp(sc, senhaToken) == 0)) {
                        entre = 1;
                        break;
                    }
                }

                if (entre == 1) {
                    printf("\n========================================\n\n");
                    printf("Seu login foi feito com sucesso.");

                    Sleep(1000);
                    system("cls");
                } else {
                    printf("\nO nome ou a senha esta errado.\n");
                    printf("Deseja criar uma conta?\n");
                    printf("1 - Sim\n");
                    printf("2 - Nao\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao);
                    getchar(); // Limpa o buffer do teclado
                    if (opcao == 1) {
                        criarConta();
                        entre = 0;
                    } else if (opcao == 2) {
                        entre = 0;
                    } else {
                        printf("Opcao invalida. Tente novamente.\n");
                        entre = 0;
                    }

                    Sleep(1000);
                    system("cls");
                }
            }
        }
    }

    return entre;
}



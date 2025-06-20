#include <stdio.h>

void mostrarMenuPrincipal();
void MenuExercicios();
void MenuRelatorios();

int main() {
    int opcaoPrincipal;

    do {
        mostrarMenuPrincipal();
        switch (opcaoPrincipal) {
        case 1:
            mostrarMenuExercicios();
            break;
        case 2:
            MostrarMenuRelatorio();
        default:
            break;
        }
    } while (opcaoPrincipal != 3)

}


void mostrarMenuPrincipal() {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Exercicios\n");
    printf("2. Relatorios\n");
    printf("3. Sair\n");
    printf("=====================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoPrincipal);
}

int MenuExercicios() {
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
        MostrarMenuPrincipal();
        break;
    default:
        printf("Opcao Invalida!")
        return
        break;
    }
}

int MenuRelatorios() {
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
        //função
        break;
    case 3:
        //funcao
        break;
    case 4:
        MostrarMenuPrincipal();
        
        break;
    default:
        printf("Opcao Invalida!");
        return;
        break;
    }
}
#include <stdio.h>

int main() {
    float total = 0;
    int opcao;
    int continuar = 1;

    while (continuar == 1) {
        printf("Escolha a moeda para adicionar:\n");
        printf("1 - R$0,50\n");
        printf("2 - R$1,00\n");
        printf("3 - R$2,00\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            total += 0.50;
        } else if (opcao == 2) {
            total += 1.00;
        } else if (opcao == 3) {
            total += 2.00;
        } else {
            printf("Opcao invalida.\n");
        }

        printf("Deseja adicionar outra moeda? (1 - sim, 0 - nao): ");
        scanf("%d", &continuar);
    }

    printf("Total acumulado no cofrinho: R$%.2f\n", total);

    return 0;
}

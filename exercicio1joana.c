#include <stdio.h>

int main() {
    float consumo[5];
    float soma = 0;
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o consumo de agua do morador %d (em m3): ", i + 1);
        scanf("%f", &consumo[i]);
        soma += consumo[i];

        if (consumo[i] <= 20) {
            printf("Morador %d: consumo dentro da media.\n", i + 1);
        } else {
            printf("Morador %d: consumo acima da media.\n", i + 1);
        }
    }

    printf("Consumo medio geral: %.2f m3\n", soma / 5);
} 

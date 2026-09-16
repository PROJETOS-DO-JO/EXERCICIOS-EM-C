#include <stdio.h>

int main() {
    int numero;
    int pares = 0;
    int impares = 0;
    int i;

    for (i = 0; i < 10; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            printf("O numero %d e par.\n", numero);
            pares++;
        } else {
            printf("O numero %d e impar.\n", numero);
            impares++;
        }
    }

    printf("Quantidade de pares: %d\n", pares);
    printf("Quantidade de impares: %d\n", impares);

    return 0;
}

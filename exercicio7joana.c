#include <stdio.h>

int main() {
    int numero, maior, menor;
    int i;

    printf("Digite o numero 1: ");
    scanf("%d", &numero);
    maior = numero;
    menor = numero;

    for (i = 2; i <= 10; i++) {
        printf("Digite o numero %d: ", i);
        scanf("%d", &numero);

        if (numero > maior) {
            maior = numero;
        }

        if (numero < menor) {
            menor = numero;
        }
    }

    printf("Maior numero: %d\n", maior);
    printf("Menor numero: %d\n", menor);
    printf("Diferenca entre maior e menor: %d\n", maior - menor);

    return 0;
}

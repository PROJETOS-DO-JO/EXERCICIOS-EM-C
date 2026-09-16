#include <stdio.h>

int main() {
    int numero, i;
    char resposta;

    do {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        for (i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", numero, i, numero * i);
        }

        printf("Deseja calcular a tabuada de outro numero? (S/N): ");
        scanf(" %c", &resposta);

    } while (resposta == 'S' || resposta == 's');

    return 0;
}

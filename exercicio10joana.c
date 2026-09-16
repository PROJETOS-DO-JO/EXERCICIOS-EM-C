#include <stdio.h>

int main() {
    int numero, i;
    int primo;
    char resposta;

    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &numero);

        primo = 1;

        if (numero < 2) {
            primo = 0;
        } else {
            for (i = 2; i < numero; i++) {
                if (numero % i == 0) {
                    primo = 0;
                }
            }
        }

        if (primo == 1) {
            printf("%d e primo.\n", numero);
        } else {
            printf("%d nao e primo.\n", numero);
        }

        printf("Deseja testar outro numero? (S/N): ");
        scanf(" %c", &resposta);

    } while (resposta == 'S' || resposta == 's');

    return 0;
}

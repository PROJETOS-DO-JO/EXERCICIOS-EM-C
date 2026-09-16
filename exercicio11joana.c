#include <stdio.h>

int main() {
    int numero, i;
    long long fatorial = 1;

    printf("Digite um numero inteiro entre 0 e 10: ");
    scanf("%d", &numero);

    while (numero < 0 || numero > 10) {
        printf("Valor invalido. Digite um numero entre 0 e 10: ");
        scanf("%d", &numero);
    }

    for (i = 1; i <= numero; i++) {
        fatorial *= i;
    }

    printf("%d! = %lld\n", numero, fatorial);

    return 0;
}

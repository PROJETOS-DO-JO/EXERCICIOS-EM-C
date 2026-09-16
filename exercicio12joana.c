#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroSecreto, palpite, tentativas;
    int acertou = 0;

    srand(time(NULL));
    numeroSecreto = rand() % 100 + 1;

    tentativas = 0;

    while (tentativas < 10 && acertou == 0) {
        printf("Digite um palpite entre 1 e 100: ");
        scanf("%d", &palpite);
        tentativas++;

        if (palpite < numeroSecreto) {
            printf("O numero secreto e maior.\n");
        } else if (palpite > numeroSecreto) {
            printf("O numero secreto e menor.\n");
        } else {
            printf("Parabens! Voce acertou!\n");
            acertou = 1;
        }
    }

    printf("Tentativas realizadas: %d\n", tentativas);

    if (acertou == 0) {
        printf("Voce nao acertou. O numero secreto era %d.\n", numeroSecreto);
    }

    return 0;
}

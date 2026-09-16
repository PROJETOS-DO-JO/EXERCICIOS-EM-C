#include <stdio.h>

int main() {
    float nota[10];
    float soma = 0;
    float media;
    int i;

    for (i = 0; i < 10; i++) {
        printf("Digite a nota do cliente %d (0 a 10): ", i + 1);
        scanf("%f", &nota[i]);
        soma += nota[i];
    }

    media = soma / 10;

    printf("Media geral do atendimento: %.2f\n", media);

    if (media < 7) {
        printf("Alerta: a media do atendimento esta abaixo do esperado.\n");
    }

    return 0;
}

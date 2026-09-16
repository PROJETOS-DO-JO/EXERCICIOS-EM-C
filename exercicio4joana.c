#include <stdio.h>

int main() {
    int passosHora;
    int totalPassos = 0;
    int horas = 0;

    while (totalPassos < 10000) {
        horas++;
        printf("Digite a quantidade de passos na hora %d: ", horas);
        scanf("%d", &passosHora);
        totalPassos += passosHora;
    }

    printf("Meta atingida!\n");
    printf("Total de passos: %d\n", totalPassos);
    printf("Horas necessarias: %d\n", horas);

    return 0;
}

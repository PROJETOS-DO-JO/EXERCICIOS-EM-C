#include <stdio.h>

int main() {
    float nota1, nota2, nota3, media;
    int continuar = 1;
    int aprovados = 0;
    int recuperacao = 0;
    int reprovados = 0;

    while (continuar == 1) {
        printf("Digite a nota 1: ");
        scanf("%f", &nota1);
        printf("Digite a nota 2: ");
        scanf("%f", &nota2);
        printf("Digite a nota 3: ");
        scanf("%f", &nota3);

        media = (nota1 + nota2 + nota3) / 3;

        if (media >= 7) {
            printf("Situacao: Aprovado\n");
            aprovados++;
        } else if (media >= 5) {
            printf("Situacao: Recuperacao\n");
            recuperacao++;
        } else {
            printf("Situacao: Reprovado\n");
            reprovados++;
        }

        printf("Deseja adicionar outro aluno? (1 - sim, 0 - nao): ");
        scanf("%d", &continuar);
    }

    printf("Total de aprovados: %d\n", aprovados);
    printf("Total em recuperacao: %d\n", recuperacao);
    printf("Total de reprovados: %d\n", reprovados);

    return 0;
}

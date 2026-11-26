#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int registro;
    int horas_aula;
} Professor;

/* le o arquivo inteiro de volta para um novo array */
Professor *lerProfessores(const char *nomeArq, int n) {
    FILE *arq = fopen(nomeArq, "rb");
    if (arq == NULL) return NULL;

    /* reserva espaco para N professores e le todos de uma vez */
    Professor *lidos = (Professor *) malloc(n * sizeof(Professor));
    if (lidos != NULL) {
        fread(lidos, sizeof(Professor), n, arq);
    }
    fclose(arq);
    return lidos;
}

int main() {
    int n, i;
    Professor *profs;
    unsigned char *buffer;
    FILE *arq;

    printf("Quantos professores deseja cadastrar? ");
    scanf("%d", &n);

    /* array dinamico com N professores */
    /* vetor dinamico: o tamanho so e conhecido durante a execucao */
    profs = (Professor *) malloc(n * sizeof(Professor));
    if (profs == NULL) {
        printf("Sem memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Professor %d - registro: ", i + 1);
        scanf("%d", &profs[i].registro);
        printf("Professor %d - horas-aula: ", i + 1);
        scanf("%d", &profs[i].horas_aula);
    }

    /* buffer bruto de bytes do mesmo tamanho */
    /* buffer bruto: so bytes, com o mesmo tamanho do vetor inteiro */
    buffer = (unsigned char *) malloc(n * sizeof(Professor));
    if (buffer == NULL) {
        printf("Sem memoria.\n");
        free(profs);
        return 1;
    }
    /* copia o vetor inteiro de structs para dentro do buffer */
    memcpy(buffer, profs, n * sizeof(Professor));

    /* grava tudo com um unico fwrite */
    arq = fopen("folha.dat", "wb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(profs);
        free(buffer);
        return 1;
    }
    /* um unico fwrite grava o bloco todo no disco */
    fwrite(buffer, n * sizeof(Professor), 1, arq);
    fclose(arq);

    /* carrega de volta para conferir */
    Professor *lidos = lerProfessores("folha.dat", n);
    if (lidos != NULL) {
        printf("\nDados lidos do arquivo:\n");
        for (i = 0; i < n; i++) {
            printf("Registro: %d | Horas-aula: %d\n", lidos[i].registro, lidos[i].horas_aula);
        }
        free(lidos);
    }

    free(profs);
    free(buffer);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[12];
    int zona;
} Eleitor;

typedef struct {
    Eleitor eleitor;   /* struct aninhada */
    int numero_voto;
} Cedula;

/* a) adiciona um voto aumentando o vetor com realloc */
Cedula *adicionarVoto(Cedula *votos, int *total, Cedula nova) {
    /* realloc aumenta o vetor em mais uma posicao, mantendo os dados antigos */
    /* usa temp para nao perder o vetor original se der erro */
    Cedula *temp = (Cedula *) realloc(votos, (*total + 1) * sizeof(Cedula));
    if (temp == NULL) {
        printf("Sem memoria.\n");
        return votos;
    }
    /* coloca o voto novo na ultima posicao e soma 1 no total */
    temp[*total] = nova;
    (*total)++;
    return temp;
}

/* b) salva todos os votos */
void salvarVotos(Cedula *votos, int total) {
    FILE *arq = fopen("urnas.bin", "wb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    /* grava todos os votos de uma vez */
    fwrite(votos, sizeof(Cedula), total, arq);
    fclose(arq);
}

/* c) descobre o tamanho do arquivo e le tudo de uma vez */
Cedula *recuperarVotos(int *total) {
    FILE *arq = fopen("urnas.bin", "rb");
    if (arq == NULL) {
        *total = 0;
        return NULL;
    }

    /* vai para o final do arquivo */
    fseek(arq, 0, SEEK_END);
    /* ftell diz em que byte o ponteiro esta = tamanho do arquivo */
    long tamanho = ftell(arq);
    /* volta para o inicio para poder ler */
    rewind(arq);

    /* tamanho total / tamanho de uma cedula = quantidade de votos */
    *total = tamanho / sizeof(Cedula);
    Cedula *votos = (Cedula *) malloc(tamanho);
    if (votos != NULL) {
        fread(votos, sizeof(Cedula), *total, arq);
    }
    fclose(arq);
    return votos;
}

int main() {
    Cedula *votos = NULL;
    int total = 0;
    char continuar;
    Cedula nova;

    /* do-while: registra pelo menos um voto */
    do {
        printf("Titulo do eleitor: ");
        /* acesso a struct aninhada: nova.eleitor.titulo */
        scanf("%11s", nova.eleitor.titulo);
        printf("Zona: ");
        scanf("%d", &nova.eleitor.zona);
        printf("Numero do voto: ");
        scanf("%d", &nova.numero_voto);

        votos = adicionarVoto(votos, &total, nova);

        printf("Registrar outro voto? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    salvarVotos(votos, total);
    free(votos);

    int qtd;
    Cedula *recuperados = recuperarVotos(&qtd);
    printf("\n%d voto(s) recuperado(s):\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("Titulo: %s | Zona: %d | Voto: %d\n",
               recuperados[i].eleitor.titulo, recuperados[i].eleitor.zona, recuperados[i].numero_voto);
    }
    free(recuperados);

    return 0;
}

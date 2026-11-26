#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char cargo[30];
    float salario;
} Funcionario;

int main() {
    Funcionario *original;
    Funcionario *backup;
    FILE *arq;

    /* a) aloca e preenche o funcionario */
    /* malloc reserva na memoria o espaco exato de um Funcionario */
    original = (Funcionario *) malloc(sizeof(Funcionario));
    if (original == NULL) {
        printf("Sem memoria.\n");
        return 1;
    }

    /* -> acessa o campo de uma struct atraves de um ponteiro */
    printf("ID: ");
    scanf("%d", &original->id);
    getchar(); /* limpa o enter que sobrou do scanf */
    printf("Cargo: ");
    fgets(original->cargo, 30, stdin);
    /* tira o \n que o fgets guarda no final do texto */
    original->cargo[strcspn(original->cargo, "\n")] = '\0';
    printf("Salario: ");
    scanf("%f", &original->salario);

    /* b) aloca o buffer de backup */
    backup = (Funcionario *) malloc(sizeof(Funcionario));
    if (backup == NULL) {
        printf("Sem memoria.\n");
        free(original);
        return 1;
    }

    /* c) copia os dados com memcpy */
    /* copia byte a byte: destino, origem, quantidade de bytes */
    memcpy(backup, original, sizeof(Funcionario));

    /* d) salva o backup em arquivo binario */
    /* "wb" = escrita em modo binario */
    arq = fopen("backup_rh.bin", "wb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(original);
        free(backup);
        return 1;
    }
    /* fwrite(o que gravar, tamanho de cada item, quantos itens, arquivo) */
    fwrite(backup, sizeof(Funcionario), 1, arq);
    fclose(arq);

    printf("\nBackup salvo: ID %d | %s | R$ %.2f\n", backup->id, backup->cargo, backup->salario);

    /* libera a memoria reservada com malloc */
    free(original);
    free(backup);
    return 0;
}

#include <stdio.h>

typedef struct {
    int conta_corrente;
    char nome[50];
    float saldo;
} Cliente;

int main() {
    Cliente c;
    FILE *arq;
    int conta, achou = 0;
    float valor;

    /* a) dados da operacao */
    printf("Numero da conta: ");
    scanf("%d", &conta);
    printf("Valor (positivo = deposito, negativo = saque): ");
    scanf("%f", &valor);

    /* b) abre em leitura/escrita */
    /* "rb+" = binario, leitura e escrita sem apagar o arquivo */
    arq = fopen("clientes.bin", "rb+");
    if (arq == NULL) {
        printf("Erro ao abrir clientes.bin\n");
        return 1;
    }

    /* c) le registro por registro */
    /* fread le um Cliente por vez; retorna 1 enquanto conseguir ler */
    while (fread(&c, sizeof(Cliente), 1, arq) == 1) {
        if (c.conta_corrente == conta) {
            /* nao deixa o saldo ficar negativo num saque */
            if (c.saldo + valor < 0) {
                printf("Saldo insuficiente.\n");
            } else {
                c.saldo = c.saldo + valor;

                /* d) volta o ponteiro um registro e sobrescreve */
                /* depois do fread o ponteiro ja passou do cliente, */
                /* entao volta o tamanho de um registro a partir da posicao atual */
                fseek(arq, -(long) sizeof(Cliente), SEEK_CUR);
                /* grava o cliente atualizado por cima do antigo */
                fwrite(&c, sizeof(Cliente), 1, arq);
                printf("Saldo de %s atualizado para R$ %.2f\n", c.nome, c.saldo);
            }
            achou = 1;
            break; /* ja achou, nao precisa ler o resto */
        }
    }

    if (!achou) {
        printf("Conta nao encontrada.\n");
    }

    fclose(arq);
    return 0;
}

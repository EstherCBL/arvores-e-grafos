#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int transacoes[] = {1001, 1020, 1055, 1100, 1200, 1300, 1500};
    int codTrans;
    int esq22, dir22, meio22, pos22;
    printf("Digite o codigo da transacao: ");
    scanf("%d", &codTrans);
    esq22 = 0;
    dir22 = 6;
    pos22 = -1;
    while (esq22 <= dir22) {
        meio22 = (esq22 + dir22) / 2;
        printf("inicio=%d meio=%d fim=%d valor=%d\n", esq22, meio22, dir22, transacoes[meio22]);
        if (transacoes[meio22] == codTrans) { pos22 = meio22; break; }
        if (transacoes[meio22] < codTrans) esq22 = meio22 + 1;
        else dir22 = meio22 - 1;
    }
    if (pos22 != -1)
        printf("Codigo encontrado na posicao %d\n", pos22);
    else
        printf("Codigo nao encontrado\n");
return 0;
}
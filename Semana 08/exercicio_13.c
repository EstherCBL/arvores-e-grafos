#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int sensores[] = {45, 12, 78, 33, 90, 21, 56, 67};
    int leitura;
    int verificacoes13;
    int pos13;
    int i13;
    printf("Digite a leitura para verificar: ");
    scanf("%d", &leitura);
    verificacoes13 = 0;
    pos13 = -1;
    for (i13 = 0; i13 < 8; i13++) {
        verificacoes13++;
        if (sensores[i13] == leitura) {
            pos13 = i13;
        }
    }
    if (pos13 != -1)
        printf("Leitura encontrada na posicao %d\n", pos13);
    else
        printf("Leitura nao encontrada\n");
    printf("Total de verificacoes: %d\n", verificacoes13);
return 0;
}
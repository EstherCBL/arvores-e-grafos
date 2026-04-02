#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int dados[] = {88, 23, 45, 12, 67, 34, 90, 10};
    int val15;
    int temp15;
    int pos15;
    int i15, j15;
    printf("Dados antes da ordenacao: ");
    for (i15 = 0; i15 < 8; i15++) printf("%d ", dados[i15]);
    printf("\n");
    for (i15 = 0; i15 < 7; i15++) {
        for (j15 = 0; j15 < 7 - i15; j15++) {
            if (dados[j15] > dados[j15 + 1]) {
                temp15 = dados[j15];
                dados[j15] = dados[j15 + 1];
                dados[j15 + 1] = temp15;
            }
        }
    }
    printf("Dados depois da ordenacao: ");
    for (i15 = 0; i15 < 8; i15++) printf("%d ", dados[i15]);
    printf("\n");
    printf("Digite o valor para buscar: ");
    scanf("%d", &val15);
    pos15 = pesquisaBinaria(dados, 0, 7, val15);
    if (pos15 != -1)
        printf("Valor encontrado na posicao %d\n", pos15);
    else
        printf("Valor nao encontrado\n");
return 0;
}
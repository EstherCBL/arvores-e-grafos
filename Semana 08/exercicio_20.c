#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int vet20[] = {10, 5, 30, 20, 15};
    int val20;
    int temp20;
    int pos20;
    int i20, j20;
    for (i20 = 0; i20 < 4; i20++) {
        for (j20 = 0; j20 < 4 - i20; j20++) {
            if (vet20[j20] > vet20[j20 + 1]) {
                temp20 = vet20[j20];
                vet20[j20] = vet20[j20 + 1];
                vet20[j20 + 1] = temp20;
            }
        }
    }
    printf("Digite o valor para buscar (lista ordenada, busca binaria): ");
    scanf("%d", &val20);
    pos20 = pesquisaBinaria(vet20, 0, 4, val20);
    if (pos20 != -1)
        printf("Valor encontrado na posicao %d\n", pos20);
    else
        printf("Valor nao encontrado\n");
return 0;
}
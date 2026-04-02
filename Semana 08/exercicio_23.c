#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int produtosVend[] = {10, 25, 10, 30, 45, 25, 60, 10};
    int idProd;
    int achou23;
    int i23;
    printf("Digite o ID do produto: ");
    scanf("%d", &idProd);
    printf("Posicoes onde o valor aparece: ");
    achou23 = 0;
    for (i23 = 0; i23 < 8; i23++) {
        if (produtosVend[i23] == idProd) {
            printf("%d ", i23);
            achou23 = 1;
        }
    }
    if (achou23 == 0) printf("Nenhuma ocorrencia encontrada");
    printf("\n");
return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int listaA[] = {34, 7, 23, 89, 12, 55, 1, 67, 90, 18};
    int val10;
    int pos10;
    printf("Digite o valor para buscar na Lista A (sequencial): ");
    scanf("%d", &val10);
    pos10 = pesquisaSequencial(listaA, 10, val10);
    if (pos10 != -1)
        printf("Encontrado na posicao %d\n", pos10);
    else
        printf("Nao encontrado\n");
return 0;
}
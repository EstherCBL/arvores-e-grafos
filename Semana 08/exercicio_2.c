#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int produtos[] = {55, 12, 89, 33, 21, 90, 44};
    int codigo;
    int pos2;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    pos2 = pesquisaSequencial(produtos, 7, codigo);
    if (pos2 != -1)
        printf("Produto encontrado na posicao %d\n", pos2);
    else
        printf("Produto nao existe no estoque\n");
return 0;
}
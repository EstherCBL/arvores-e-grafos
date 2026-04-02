#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int pedidos[] = {903, 112, 457, 221, 678, 345, 789, 150};
    int codPedido;
    int comparacoes11;
    int pos11;
    int i11;
    printf("Digite o codigo do pedido: ");
    scanf("%d", &codPedido);
    comparacoes11 = 0;
    pos11 = -1;
    for (i11 = 0; i11 < 8; i11++) {
        comparacoes11++;
        if (pedidos[i11] == codPedido) {
            pos11 = i11;
            break;
        }
    }
    if (pos11 != -1)
        printf("Pedido encontrado na posicao %d. Comparacoes: %d\n", pos11, comparacoes11);
    else
        printf("Pedido nao encontrado. Comparacoes: %d\n", comparacoes11);
return 0;
}
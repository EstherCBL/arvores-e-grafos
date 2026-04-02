#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int paginas[] = {321, 105, 876, 432, 210, 654, 999, 111};
    int idPagina;
    int comparacoes21;
    int pos21;
    int i21;
    printf("Digite o ID da pagina: ");
    scanf("%d", &idPagina);
    comparacoes21 = 0;
    pos21 = -1;
    for (i21 = 0; i21 < 8; i21++) {
        comparacoes21++;
        if (paginas[i21] == idPagina) {
            pos21 = i21;
            break;
        }
    }
    if (pos21 != -1)
        printf("Pagina encontrada na posicao %d. Comparacoes: %d\n", pos21, comparacoes21);
    else
        printf("Pagina nao visitada. Comparacoes: %d\n", comparacoes21);
return 0;
}
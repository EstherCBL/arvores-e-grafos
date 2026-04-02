#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int lista24[] = {5, 15, 25, 35, 45, 55};
    int val24;
    int esq24, dir24, meio24, achou24;
    printf("Digite o valor para encontrar a posicao de insercao: ");
    scanf("%d", &val24);
    esq24 = 0;
    dir24 = 5;
    achou24 = 0;
    while (esq24 <= dir24) {
        meio24 = (esq24 + dir24) / 2;
        if (lista24[meio24] == val24) {
            printf("Valor ja existe na posicao %d\n", meio24);
            achou24 = 1;
            break;
        }
        if (lista24[meio24] < val24) esq24 = meio24 + 1;
        else dir24 = meio24 - 1;
    }
    if (achou24 == 0)
        printf("Posicao correta para inserir: %d\n", esq24);
return 0;
}
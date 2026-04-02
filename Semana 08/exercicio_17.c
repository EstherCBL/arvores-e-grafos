#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int temperaturas[] = {15, 17, 19, 21, 23, 25, 27, 30};
    int temp17;
    int esq17, dir17, meio17, pos17;
    printf("Digite a temperatura para buscar: ");
    scanf("%d", &temp17);
    esq17 = 0;
    dir17 = 7;
    pos17 = -1;
    while (esq17 <= dir17) {
        meio17 = (esq17 + dir17) / 2;
        if (temperaturas[meio17] == temp17) { pos17 = meio17; break; }
        if (temperaturas[meio17] < temp17) esq17 = meio17 + 1;
        else dir17 = meio17 - 1;
    }
    if (pos17 != -1)
        printf("Temperatura encontrada na posicao %d\n", pos17);
    else
        printf("Temperatura nao registrada. Poderia ser inserida na posicao %d\n", esq17);
return 0;
}
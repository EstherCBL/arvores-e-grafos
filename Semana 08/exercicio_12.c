#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int agenda[] = {987654321, 991234567, 993456789, 995678901, 997890123};
    int numero12;
    int esq12, dir12, meio12, pos12;
    printf("Digite o numero de telefone: ");
    scanf("%d", &numero12);
    esq12 = 0;
    dir12 = 4;
    pos12 = -1;
    while (esq12 <= dir12) {
        meio12 = (esq12 + dir12) / 2;
        if (agenda[meio12] == numero12) { pos12 = meio12; break; }
        if (agenda[meio12] < numero12) esq12 = meio12 + 1;
        else dir12 = meio12 - 1;
    }
    if (pos12 != -1)
        printf("Numero encontrado na posicao %d\n", pos12);
    else
        printf("Numero nao encontrado\n");
return 0;
}
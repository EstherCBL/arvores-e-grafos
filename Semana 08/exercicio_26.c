#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int vvetor26[500];
    int i26;
    int melhor26, pior26;
    for (i26 = 0; i26 < 500; i26++) vvetor26[i26] = i26 + 1;
    melhor26 = pesquisaSequencial(vvetor26, 500, 1);
    pior26 = pesquisaSequencial(vvetor26, 500, 500);
    printf("Melhor caso: elemento 1 encontrado na posicao %d\n", melhor26);
    printf("Pior caso: elemento 500 encontrado na posicao %d\n", pior26);
return 0;
}
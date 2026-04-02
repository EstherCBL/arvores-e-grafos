#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int vet7[1000];
    int i7;
    int buscado7;
    int posSeq7, posBin7;
    for (i7 = 0; i7 < 1000; i7++) vet7[i7] = i7 + 1;
    buscado7 = 999;
    posSeq7 = pesquisaSequencial(vet7, 1000, buscado7);
    posBin7 = pesquisaBinaria(vet7, 0, 999, buscado7);
    printf("Sequencial encontrou %d na posicao %d\n", buscado7, posSeq7);
    printf("Binaria encontrou %d na posicao %d\n", buscado7, posBin7);
return 0;
}
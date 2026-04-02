#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int vet28[] = {11, 22, 33, 44, 55, 66, 77};
    int val28;
    int esq28, dir28, meio28, pos28;
    printf("Digite um valor para buscar (tente um que nao esta no vetor): ");
    scanf("%d", &val28);
    esq28 = 0;
    dir28 = 6;
    pos28 = -1;
    while (esq28 <= dir28) {
        meio28 = (esq28 + dir28) / 2;
        printf("Verificando posicao %d, valor %d\n", meio28, vet28[meio28]);
        if (vet28[meio28] == val28) { pos28 = meio28; break; }
        if (vet28[meio28] < val28) esq28 = meio28 + 1;
        else dir28 = meio28 - 1;
    }
    if (pos28 != -1)
        printf("Valor encontrado na posicao %d\n", pos28);
    else
        printf("Valor nao encontrado. Busca encerrada quando inicio=%d ficou maior que fim=%d\n", esq28, dir28);
return 0;
}
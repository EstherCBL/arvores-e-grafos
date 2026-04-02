#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
int vet9[] = {5, 10, 15, 20, 25, 30};
    int val9;
    int pos9;
    printf("Digite o valor para buscar: ");
    scanf("%d", &val9);
    pos9 = pesquisaBinaria(vet9, 0, 5, val9);
    if (pos9 != -1)
        printf("Indice encontrado: %d\n", pos9);
    else
        printf("Retorno: -1 (nao encontrado)\n");
return 0;
}